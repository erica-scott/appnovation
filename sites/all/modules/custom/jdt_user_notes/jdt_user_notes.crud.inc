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
/**
 * TODO: Ensure only add if it's an article.
 */
function jdt_user_notes_create($fields) {
  $table = 'jdt_user_notes';
  $res = db_insert($table)
    ->fields(array(
      'article_nid' => $fields['article_nid'],
      'author_uid' => $fields['author_uid'],
      'note_text' => $fields['note_text'],
      'note_title' => $fields['note_title'],
    ))
    ->execute();

  return $res;
}

/**
 * R - Read.
 *
 * Takes note_id and returns associative array of that row.
 */
function jdt_user_notes_read($note_id) {
  $table = 'jdt_user_notes';
  $table_abbr = 'j';

  $res = db_select($table, $table_abbr)
    ->fields($table_abbr)
    ->condition('note_id', $note_id)
    ->execute()
    ->fetchAssoc();

  return $res;
}

/**
 * R- Read.
 *
 * Returns all notes for a specified article created by the user.
 */
function jdt_user_notes_read_article($article_nid, $author_uid) {
  $table = 'jdt_user_notes';
  $table_abbr = 'j';

  $res = db_select($table, $table_abbr)
    ->fields($table_abbr)
    ->condition('article_nid', $article_nid)
    ->condition('author_uid', $author_uid)
    ->execute();

  $result = array();
  while ($row = $res->fetchAssoc()) {
    $result[] = $row;
  }

  return $result;
}

/**
 * U - Update.
 *
 * Takes note_id and the fields to update, and returns rows affected.
 */
function jdt_user_notes_update($note_id, $fields) {
  $table = 'jdt_user_notes';
  $res = db_update($table)
    ->fields(array(
      'article_nid' => $fields['article_nid'],
      'author_uid' => $fields['author_uid'],
      'note_title' => $fields['note_title'],
      'note_text' => $fields['note_text'],
    ))
    ->condition('note_id', $note_id)
    ->execute();

  return $res;
}

/**
 * D - Delete.
 *
 * Takes the id of the note to be deleted, and returns rows affected.
 */
function jdt_user_notes_delete($note_id) {
  $table = 'jdt_user_notes';
  $res = db_delete($table)
    ->condition('note_id', $note_id)
    ->execute();

  return $res;
}
