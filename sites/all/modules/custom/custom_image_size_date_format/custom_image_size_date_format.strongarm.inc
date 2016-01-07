<?php
/**
 * @file
 * custom_image_size_date_format.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function custom_image_size_date_format_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_jdt_custom';
  $strongarm->value = 'F j, Y - H:i';
  $export['date_format_jdt_custom'] = $strongarm;

  return $export;
}
