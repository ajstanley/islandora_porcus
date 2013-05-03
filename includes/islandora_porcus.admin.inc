<?php
/**
 * @file
 * islandora_porcus.admin.inc
 */

/**
 * Admin from.
 * @return array
 *  Returns admin form.
 */
function islandora_porcus_admin() {
  $form = array();


  $form['islandora_porcus_wordlength'] = array(
    '#type' => 'textfield',
    '#title' => t('Word Length'),
    '#default_value' => variable_get('islandora_porcus_wordlength', '1'),
    '#description' => t('Minimum length of word to be transformed'),
    '#size' => 4,
  );

  return system_settings_form($form);
}
