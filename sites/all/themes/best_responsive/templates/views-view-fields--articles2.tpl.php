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

<?php $key = $keys[$fields['title']->raw]; ?>

<div class="title">
	<?php if(!empty($articles[$key])) { print $articles[$key]['title']; } ?>
</div>
<div class="links">
	<?php if(isset($add_links[$fields['title']->raw])) { print $add_links[$fields['title']->raw]; } ?>
	<?php if(isset($note_links[$fields['title']->raw])) { print " - " . $note_links[$fields['title']->raw]; } ?>
</div> 
<div class="slug">
	<?php if(!empty($articles[$key]['field_field_slug'])) : ?>
		<span class="slug-quotes">"</span>
		<span class="slug-quote"><?php print $articles[$key]['field_field_slug']; ?></span>
		<span class="slug-quotes">"</span>
	<?php endif; ?>
</div>
<div class="date" style="font-weight:bold;">
	<?php if(!empty($articles[$key]['field_field_date'])) { print $articles[$key]['field_field_date']; } ?>
</div>
<div class="body" style="text-align:justify;">
	<?php if(!empty($articles[$key]['field_body'])) { print $articles[$key]['field_body']; } ?>
</div>
<div class="image" style="align:center;">
	<?php if(!empty($articles[$key]['field_field_article_image'])) { print $articles[$key]['field_field_article_image']; } ?>
</div>
<div class="contributors" style="font-style:italic; text-indent:15px; font-size:20px;">
	<?php if(!empty($articles[$key]['field_field_contributors'])) { print '- ' . $articles[$key]['field_field_contributors']; } ?>
</div>
<div class="related_articles">
	<?php if (!empty($articles[$key]['field_field_related_articles'])) : ?>
		<span class="related_articles_label" style="font-weight:bold;">Related Articles:</span>
		<?php print $articles[$key]['field_field_related_articles']; ?>
	<?php endif; ?>
</div>

<br>
<hr>
