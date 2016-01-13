<?php
/**
 * @file
 * jdt_content_type_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function jdt_content_type_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create new note'.
  $permissions['create new note'] = array(
    'name' => 'create new note',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'delete any note'.
  $permissions['delete any note'] = array(
    'name' => 'delete any note',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'delete own note'.
  $permissions['delete own note'] = array(
    'name' => 'delete own note',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'edit any note'.
  $permissions['edit any note'] = array(
    'name' => 'edit any note',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'edit own note'.
  $permissions['edit own note'] = array(
    'name' => 'edit own note',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'read any notes'.
  $permissions['read any notes'] = array(
    'name' => 'read any notes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'read own notes'.
  $permissions['read own notes'] = array(
    'name' => 'read own notes',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  return $permissions;
}
