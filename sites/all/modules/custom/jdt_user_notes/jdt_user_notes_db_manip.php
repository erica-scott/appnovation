<?php
/**
 * @file
 * Custom file to include database manipulation functions.
 */

/**
 * DB Function - Select.
 *
 * $fields - An array of fields to select from table.
 *
 * $conditions - A multidimensional array, with arguments and relationship.
 *
 * $options - An array of the other options for the select.
 */
function jdt_user_notes_dbselect($fields, $conditions, $options) {
  $result = db_select('jdt_user_notes', 'j', $options);
  if (is_array($fields)) {
    $result->fields('j', $fields);
  }
  else {
    $result->fields($fields);
  }
  foreach ($conditions as $condition) {
      $result->condition($condition['arg1'], $condition['arg2'], $condition['relationship']);
  }
  $res = $result->countQuery()->execute();
  
  if ($res->fetchField() > 0) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * DB Function - Insert.
 *
 * $fields - An array of fields to insert (key = column, value = value)
 *
 * $options - An array of any extra options for this insert.
 */
function jdt_user_notes_dbinsert($fields, $options) {
  $result = db_insert('jdt_user_notes', $options)
    ->fields($fields);
    ->execute();

  return $result;
}

/**
 * DB Function - Update.
 *
 * $fields - An array of fields to insert (key = column, value = value)
 *
 * $conditions - A multidimensional array, with arguments and relationship.
 *
 * $options - An array of any extra options for this update.
 */
/*function jdt_user_notes_dbupdate($fields, $conditions, $options) {
  $result = db_update('jdt_user_notes', $options)
    ->fields($fields)
        foreach ($conditions as $condition) {
      ->condition($condition['arg1'], $condition['arg2'], $condition['relationship'])
        }
          ->execute();

        return $result;
}*/

/**
 * DB Function - Delete.
 *
 * $conditions - A multidimensional array, with arguments and relationship.
 *
 * $options - An array of any extra options for this update.
 */
/*function jdt_user_notes_dbdelete($conditions, $options) {
  $result = db_delete('jdt_user_notes', $options)
        foreach ($conditions as $condition) {
      ->condition($condition['arg1'], $condition['arg2'], $condition['relationship'])
        }
          ->execute();

        return $result;
}*/
