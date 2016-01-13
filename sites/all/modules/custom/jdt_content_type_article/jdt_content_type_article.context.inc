<?php
/**
 * @file
 * jdt_content_type_article.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function jdt_content_type_article_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_data_context';
  $context->description = 'Positioning of the site_data block';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-navigation' => array(
          'module' => 'system',
          'delta' => 'navigation',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jdt_user_notes-site_data' => array(
          'module' => 'jdt_user_notes',
          'delta' => 'site_data',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positioning of the site_data block');
  $export['site_data_context'] = $context;

  return $export;
}
