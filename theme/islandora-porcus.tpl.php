<?php
/**
 * @file
 * This is the template file for the porcus object page.
 *
 * Here we build an html page using the variables passed in by 
 * the islandora_porcus_preprocess_islandora_porcus
 * function.  Elements such as labels and buttons can be added here
 */
$islandora_content = $islandora_object['PORCUS']->content;
$path = drupal_get_path('module', 'islandora_porcus');
drupal_add_css("$path/css/islandora_porcus.css");
drupal_add_js("$path/js/islandora_porcus.js");
?>

<div class="islandora-porcus-object islandora">
  <button id="porcus_image">Bring Back That Pig!</button>
  <div class ="porcus_thumb">
    <?php print $variables['islandora_thumbnail_img'] ?>
  </div>
  <div class="islandora-basic-image-content-wrapper clearfix">
    <?php if (isset($islandora_content)): ?>
      <div class="islandora-porcus-content">
        <?php print $islandora_content; ?>
      </div>
    <?php endif; ?>
  </div>
