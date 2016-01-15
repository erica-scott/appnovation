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
ctools_include('modal');
ctools_include('ajax');
ctools_modal_add_js();
ctools_add_js('ajax-responder');

$views[$view->result[0]->node_title] = $view->result[0]->nid;
$views[$view->result[1]->node_title] = $view->result[1]->nid;

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

$path = $path = 'node/' . $views[$title] . '/add/nojs';
$link = l(t('Add Note'), $path, array(
  'attributes' => array(
    'class' => 'ctools-use-modal',
  ),
));
?>

<div class="title">
	<?php print $fields['title']->content; ?>
</div>
<div class="add_link">
	<?php print $link; ?>
</div>
<div class="slug">
	<span class="slug-quotes">"</span>
	<span class="slug-quote"><?php print $fields['field_slug']->content; ?></span>
	<span class="slug-quotes">"</span>
</div>
<div class="date" style="font-weight:bold;">
	<?php print $fields['field_date']->content; ?>
</div>
<div class="body" style="text-align:justify;">
	<?php print $fields['body']->content; ?>
</div>
<div class="image" style="align:center;">
	<?php print $fields['field_article_image']->content; ?>
</div>
<div class="contributors" style="font-style:italic; text-indent:15px; font-size:20px;">
	<?php print '- ' . $fields['field_contributors']->content; ?>
</div>
<div class="related_articles">
	<?php if (!empty($fields['field_related_articles']->content)) : ?>
		<span class="related_articles_label" style="font-weight:bold;">Related Articles:</span>
		<?php print $fields['field_related_articles']->content; ?>
	<?php endif; ?>
</div>

</div>
<br>
<hr>