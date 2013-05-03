<?php

/**
 * @file
 * This is the template file for the porcus object page.
 *
 * @TODO: add documentation about file and available variables
 */
$islandora_content = $islandora_object['PORCUS']->content;
?>

<div class="islandora-porcus-object islandora">
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
