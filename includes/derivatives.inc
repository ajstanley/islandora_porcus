<?php

/**
 * @file
 * Creates additional datatreams for ingested object
 */

/**
 * Creates derivatives for object.
 * 
 * The islandora_porcus_islandora_porcusCModel_islandora_object_ingested hook
 * calls this function. This function receives a copy of the uningested 
 * islandora object and uses the OBJ datastream to create the derivative pig
 * latin stream.
 * 
 * Each datastream is constructed, labeled, assigned a mimetype, and given 
 * content, either from a string, or read in from a file location.
 *
 * @param FedoraObject $object
 *   The object that will be used to generate/store the derivatives.
 *
 * @return bool
 *   TRUE if successful, FALSE otherwise.
 */
function islandora_porcus_create_all_derivatives(FedoraObject $object) {
  if (!isset($object["OBJ"])) {
    drupal_set_message(t("Could not create derivatives for %s.  No file was uploaded.", array("%s" => $object->id), "error"));
    return FALSE;
  }
  $path = drupal_get_path('module', 'islandora_porcus');
  $mime_detect = new MimeDetect();
  $ext = $mime_detect->getExtension($object['OBJ']->mimeType);
  $file_name = str_replace(":", "-", $object->id) . ".OBJ.{$ext}";
  $file_uri = file_create_filename($file_name, 'temporary://');
  // Add thumbnail.
  $ds = $object->constructDatastream('TN', "M");
  $ds->label = 'TN';
  $ds->mimetype = 'image/png';
  $ds->setContentFromFile("$path/images/piggie.png");
  $object->ingestDatastream($ds);
  // Create and add pig latin datastream.
  $pig_latin = islandora_porcus_transform_text($object['OBJ']->content);
  $ds = $object->constructDatastream('PORCUS', "M");
  $ds->label = 'Transformed Text';
  $ds->mimetype = 'text/plain';
  $ds->setContentFromString($pig_latin);
  $object->ingestDatastream($ds);
  file_unmanaged_delete($file_uri);
  return TRUE;
}

/**
 * Transforms input text to pig latin.
 *
 * @param string $input_text
 *   Text to be transformed.
 *
 * @return string
 *   The transformed text.
 */
function islandora_porcus_transform_text($input_text) {
  preg_match_all('/\b[^\s]+\b/', $input_text, $matches);
  $min_word_length = intval(variable_get('islandora_porcus_wordlength', '1'));
  $callback = function($word) use ($min_word_length) {
        return strlen($word) >= $min_word_length;
      };
  $dirty_words = array_filter($matches[0], $callback);
  $clean_words = array_unique($dirty_words);

  $vowels = array('a', 'e', 'i', 'o');
  foreach ($clean_words as $word) {
    $letters = str_split($word);
    $initial = array_shift($letters);
    $isCapital = ctype_upper($initial);
    $initial = strtolower($initial);
    if (in_array($initial, $vowels)) {
      $pig_word = $initial . implode('', $letters) . 'way';
    }
    else {
      $pig_word = implode('', $letters) . $initial . 'ay';
      if($isCapital){
        $pig_word = ucwords($pig_word);
      }
    }
    $input_text = preg_replace("/\b$word\b/", $pig_word, $input_text);
  }
  return $input_text;
}
