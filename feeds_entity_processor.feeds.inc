<?php

/**
 * @file
 * Feeds hooks.
 */

/**
 * Implements hook_feeds_entity_processor_properties().
 */
function _feeds_entity_processor_properties() {
  $path = backdrop_get_path('module', 'feeds_entity_processor') . '/src/Property';

  $info = array();

  // Default handler. Used when there is no specific handler for the given
  // property.
  $info['default'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyDefault',
      'file' => 'FeedsEntityProcessorPropertyDefault.php',
      'path' => $path,
    ),
  );

  $info['boolean'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyBoolean',
      'file' => 'FeedsEntityProcessorPropertyBoolean.php',
      'path' => $path,
    ),
  );
  $info['date'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyDate',
      'file' => 'FeedsEntityProcessorPropertyDate.php',
      'path' => $path,
    ),
  );
  $info['entity'] = array(
    'handler' => array(
      'class' => 'FeedsEntityProcessorPropertyEntity',
      'file' => 'FeedsEntityProcessorPropertyEntity.php',
      'path' => $path,
    ),
  );

  // Create handler for each entity type.
  $entity_info = entity_get_info();
  foreach ($entity_info as $entity_type => $entity_type_info) {
    $info[$entity_type] = array(
      'handler' => array(
        'class' => 'FeedsEntityProcessorPropertyEntityType',
        'file' => 'FeedsEntityProcessorPropertyEntityType.php',
        'path' => $path,
      ),
    );
  }

  return $info;
}
