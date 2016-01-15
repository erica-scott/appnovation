<?php
/**
 * @file
 * jdt_content_type_article.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function jdt_content_type_article_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:two_columns';
  $panelizer->title = 'Two Columns';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6ebe6329-95cd-4d36-a237-6215cb0d83d5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5a0382f5-ec92-48f7-8b0d-3b909c742110';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'large',
        'image_link' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5a0382f5-ec92-48f7-8b0d-3b909c742110';
    $display->content['new-5a0382f5-ec92-48f7-8b0d-3b909c742110'] = $pane;
    $display->panels['left'][0] = 'new-5a0382f5-ec92-48f7-8b0d-3b909c742110';
    $pane = new stdClass();
    $pane->pid = 'new-faab4d42-9401-41b6-824d-eb437c689c45';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'fromto' => 'both',
        'multiple_from' => '',
        'multiple_number' => '',
        'multiple_to' => '',
        'show_remaining_days' => FALSE,
        'show_repeat_rule' => 'show',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'faab4d42-9401-41b6-824d-eb437c689c45';
    $display->content['new-faab4d42-9401-41b6-824d-eb437c689c45'] = $pane;
    $display->panels['left'][1] = 'new-faab4d42-9401-41b6-824d-eb437c689c45';
    $pane = new stdClass();
    $pane->pid = 'new-716e4df1-56ac-43c6-981c-b8d4b20093eb';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contributors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '716e4df1-56ac-43c6-981c-b8d4b20093eb';
    $display->content['new-716e4df1-56ac-43c6-981c-b8d4b20093eb'] = $pane;
    $display->panels['left'][2] = 'new-716e4df1-56ac-43c6-981c-b8d4b20093eb';
    $pane = new stdClass();
    $pane->pid = 'new-6d4f9bd0-1f38-4efa-be70-33dc2ef27b23';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_slug';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6d4f9bd0-1f38-4efa-be70-33dc2ef27b23';
    $display->content['new-6d4f9bd0-1f38-4efa-be70-33dc2ef27b23'] = $pane;
    $display->panels['left'][3] = 'new-6d4f9bd0-1f38-4efa-be70-33dc2ef27b23';
    $pane = new stdClass();
    $pane->pid = 'new-b6e2d5fc-d8ee-467d-ab58-c7a19244b278';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b6e2d5fc-d8ee-467d-ab58-c7a19244b278';
    $display->content['new-b6e2d5fc-d8ee-467d-ab58-c7a19244b278'] = $pane;
    $display->panels['left'][4] = 'new-b6e2d5fc-d8ee-467d-ab58-c7a19244b278';
    $pane = new stdClass();
    $pane->pid = 'new-90933376-7651-4657-b839-5a897db57d48';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '90933376-7651-4657-b839-5a897db57d48';
    $display->content['new-90933376-7651-4657-b839-5a897db57d48'] = $pane;
    $display->panels['left'][5] = 'new-90933376-7651-4657-b839-5a897db57d48';
    $pane = new stdClass();
    $pane->pid = 'new-49c25e7e-b750-4cfe-a9b5-44e39166daf7';
    $pane->panel = 'left';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '49c25e7e-b750-4cfe-a9b5-44e39166daf7';
    $display->content['new-49c25e7e-b750-4cfe-a9b5-44e39166daf7'] = $pane;
    $display->panels['left'][6] = 'new-49c25e7e-b750-4cfe-a9b5-44e39166daf7';
    $pane = new stdClass();
    $pane->pid = 'new-e940c662-9034-4ee6-9899-cab68a6b4ad8';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_article_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'e940c662-9034-4ee6-9899-cab68a6b4ad8';
    $display->content['new-e940c662-9034-4ee6-9899-cab68a6b4ad8'] = $pane;
    $display->panels['left'][7] = 'new-e940c662-9034-4ee6-9899-cab68a6b4ad8';
    $pane = new stdClass();
    $pane->pid = 'new-3e1f1c64-7135-48af-8769-33b8b9b8fb48';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3e1f1c64-7135-48af-8769-33b8b9b8fb48';
    $display->content['new-3e1f1c64-7135-48af-8769-33b8b9b8fb48'] = $pane;
    $display->panels['right'][0] = 'new-3e1f1c64-7135-48af-8769-33b8b9b8fb48';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5a0382f5-ec92-48f7-8b0d-3b909c742110';
  $panelizer->display = $display;
  $export['node:article:two_columns'] = $panelizer;

  return $export;
}
