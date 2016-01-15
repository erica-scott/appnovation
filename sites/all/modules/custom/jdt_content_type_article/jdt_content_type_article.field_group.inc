<?php
/**
 * @file
 * jdt_content_type_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jdt_content_type_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_info|node|article|form';
  $field_group->group_name = 'group_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '40',
    'children' => array(
      0 => 'field_contributors',
      1 => 'field_related_articles',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-additional-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_additional_info|node|article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Info');

  return $field_groups;
}
