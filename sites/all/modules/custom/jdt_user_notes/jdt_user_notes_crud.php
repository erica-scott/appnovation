<?php
/**
 * @file
 * CRUD File for Database Manipulations.
 */

/**
 * C - Create.
 *
 * Takes array of fields, returns rows affected.
 */
function create($fields) {
  $table = 'jdt_user_notes';
  $res = db_insert($table)
    ->fields(array(
      'article_nid' => $fields['article_nid'],
      'author_uid' => $fields['author_uid'],
      'note_text' => $fields['note_text'],
    ))
    ->execute();

  return $res;
}

/**
 * R - Read
 *
 * Takes note_id and returns associative array of that row.
 */
function read($note_id) {
  $table = 'jdt_user_notes';
  $table_abbr = 'j';
  $res = db_select($table, $table_abbr)
    ->fields($table_abbr)
    ->condition('note_id', $note_id, '=')
    ->execute();

  $result = array();
  while ($row = $res->fetchAssoc()) {
    $result[] = $row;
  }

  return $result;
}

/**
 * U - Update
 *
 * Takes note_id and the fields to update, and returns rows affected.
 */
function update($note_id, $fields) {
  $table = 'jdt_user_notes';
  $res = db_update($table)
    ->fields(array(
      'article_nid' => $fields['article_nid'],
      'author_uid' => $fields['author_uid'],
      'note_text' => $fields['note_text'],
    ))
    ->condition('note_id', $note_id, '=')
    ->execute();

  return $res;
}

/**
 * D - Delete
 * 
 * Takes the id of the note to be deleted, and returns rows affected.
 */
function delete($note_id) {
  $table = 'jdt_user_notes';
  $res = db_delete($table)
    ->condition('note_id', $note_id, '=')
    ->execute();

  return $res;
}
