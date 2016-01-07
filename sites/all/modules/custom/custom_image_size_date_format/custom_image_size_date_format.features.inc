<?php
/**
 * @file
 * custom_image_size_date_format.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_image_size_date_format_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function custom_image_size_date_format_image_default_styles() {
  $styles = array();

  // Exported image style: jdt_custom.
  $styles['jdt_custom'] = array(
    'label' => 'jdt_custom',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
