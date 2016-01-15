<?php
/**
 * @file
 * Template file to describe the format of the view 'Articles'
 */
?>
<style>
.title {
	font-weight: bold;
	font-size: 25px;
}
.slug {
	text-indent: 50px;
}
.slug-quotes {
	font-weight: bold;
	font-size: 25px;
}
.slug-quote {
	font-style: italic;
}
</style>

<?php
global $user;

ctools_include('modal');
ctools_include('ajax');
ctools_modal_add_js();
ctools_add_js('ajax-responder');

for ($i = 0; $i < sizeof($view->result); $i++) {
	$views[$view->result[$i]->node_title] = $view->result[$i]->nid;
}

foreach ($fields as $field) {
	$pattern = '/<[\s\":a-zA-Z0-9=-]{1,}>/';
	$field->content = preg_replace($pattern, '', $field->content);

	if (strpos($field->content, 'href') === false) {
		$pattern = '/<[\/\s\":a-zA-Z0-9=-]{1,}>/';
		$field->content = preg_replace($pattern, '', $field->content);
	} 
	else {
		$field->content = str_replace('</span>', '', $field->content);
	}
}
$title = preg_replace('/<[\s\"\/a-zA-Z0-9-=]{1,}>/', '', $fields['title']->content);

$add_path = 'node/' . $views[$title] . '/add/nojs';
$add_link = l(t('Add Note'), $add_path, array(
  'attributes' => array(
    'class' => 'ctools-use-modal',
  ),
));

$notes = db_select('jdt_user_notes', 'j')
	->fields('j')
	->condition('article_nid', $views[$title])
	->condition('author_uid', $user->uid)
	->countQuery()
	->execute()
	->fetchField();

if ($notes > 0) {
	$note_path = 'node/' . $views[$title] . '/notes';
	$note_link = l(t('My Notes'), $note_path, array());
}
?>

<div class="title">
	<?php if(!empty($fields['title']->content)) { print $fields['title']->content; } ?>
</div>
<div class="links">
	<?php print $add_link; ?>
	<?php if(isset($note_link)) { print ' - ' . $note_link; } ?>
</div>
<div class="slug">
	<?php if(!empty($fields['field_slug']->content)) : ?>
		<span class="slug-quotes">"</span>
		<span class="slug-quote"><?php print $fields['field_slug']->content; ?></span>
		<span class="slug-quotes">"</span>
	<?php endif; ?>
</div>
<div class="date" style="font-weight:bold;">
	<?php if(!empty($fields['field_date']->content)) { print $fields['field_date']->content; } ?>
</div>
<div class="body" style="text-align:justify;">
	<?php if(!empty($fields['body']->content)) { print $fields['body']->content; } ?>
</div>
<div class="image" style="align:center;">
	<?php if(!empty($fields['field_article_image']->content)) { print $fields['field_article_image']->content; } ?>
</div>
<div class="contributors" style="font-style:italic; text-indent:15px; font-size:20px;">
	<?php if(!empty($fields['field_contributors']->content)) { print '- ' . $fields['field_contributors']->content; } ?>
</div>
<div class="related_articles">
	<?php if (!empty($fields['field_related_articles']->content)) : ?>
		<span class="related_articles_label" style="font-weight:bold;">Related Articles:</span>
		<?php print $fields['field_related_articles']->content; ?>
	<?php endif; ?>
</div>

<br>
<hr>