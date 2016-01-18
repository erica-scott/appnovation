<?php
/**
 * Implements hook_html_head_alter().
 * This will overwrite the default meta character type tag with HTML5 version.
 */
function best_responsive_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Insert themed breadcrumb page navigation at top of the node content.
 */
function best_responsive_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Use CSS to hide titile .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // comment below line to hide current page to breadcrumb
$breadcrumb[] = drupal_get_title();
    $output .= '<nav class="breadcrumb">' . implode(' » ', $breadcrumb) . '</nav>';
    return $output;
  }
}

/**
 * Override or insert variables into the page template.
 */
function best_responsive_preprocess_page(&$vars) {
  if (isset($vars['main_menu'])) {
    $vars['main_menu'] = theme('links__system_main_menu', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('links', 'main-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['main_menu'] = FALSE;
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_menu'] = theme('links__system_secondary_menu', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['secondary_menu'] = FALSE;
  }
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function best_responsive_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

/**
 * Override or insert variables into the node template.
 */
function best_responsive_preprocess_node(&$variables) {
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
  $variables['date'] = t('!datetime', array('!datetime' =>  date('j F Y', $variables['created'])));
}

function best_responsive_page_alter($page) {
  // <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1"/>
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
    'name' =>  'viewport',
    'content' =>  'width=device-width, initial-scale=1, maximum-scale=1'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

function best_responsive_preprocess_views_view_fields(&$vars) {
  if (isset($vars['view']->name)) {
    $function = __FUNCTION__ . '__' . $vars['view']->name . '__' . $vars['view']->current_display;

    if (function_exists($function)) {
      $function($vars);
    }
  }
}

function best_responsive_preprocess_views_view_fields__articles2__block(&$vars) {
  global $user;

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  ctools_add_js('ajax-responder');

  $view = $vars['view'];

  $fields = array(
    'field_field_slug',
    'field_field_date',
    'field_body',
    'field_field_contributors',
    'field_field_related_articles',
  );

  foreach ($view->result as $key => $result) {
    $articles[$key]['title'] = $result->node_title;
    $keys[$articles[$key]['title']] = $key;
    
    $contributors = $result->field_field_contributors[0]['rendered']['#markup'];

    if ($contributors == $user->name) {
      $add_path = 'node/' . $result->nid . '/add/nojs';
      $add_link = l(t('Add Note'), $add_path, array(
        'attributes' => array(
          'class' => 'ctools-use-modal',
        ),
      ));

      $add_links[$articles[$key]['title']] = $add_link;
    }

    $notes = db_select('jdt_user_notes', 'j')
      ->fields('j')
      ->condition('article_nid', $result->nid)
      ->condition('author_uid', $user->uid)
      ->countQuery()
      ->execute()
      ->fetchField();

    if ($notes > 0) {
      $note_path = 'node/' . $result->nid . '/notes';
      $note_link = l(t('My Notes'), $note_path, array());

      $note_links[$articles[$key]['title']] = $note_link;
    }

    foreach ($fields as $field) {
      $articles[$key][$field] = NULL;

      if (!empty($result->$field)) {
        $arr = $result->$field;
        $articles[$key][$field] = $arr[0]['rendered']['#markup'];

        $pattern = '/<[\s\":a-zA-Z0-9=-]{1,}>/';
        $articles[$key][$field] = preg_replace($pattern, '', $articles[$key][$field]);

        $pattern = '/<[\/\s\":a-zA-Z0-9=-]{1,}>/';
        $articles[$key][$field] = preg_replace($pattern, '', $articles[$key][$field]);
      }
    }
  }

  $vars['articles'] = $articles;
  $vars['keys'] = $keys;
  $vars['add_links'] = $add_links;
  $vars['note_links'] = $note_links;
}

/**
 * Add javascript files for front-page jquery slideshow.
 */
if (drupal_is_front_page()) {
  drupal_add_js(drupal_get_path('theme', 'best_responsive') . '/js/flexslider-min.js');
  drupal_add_js(drupal_get_path('theme', 'best_responsive') . '/js/slide.js');
}
