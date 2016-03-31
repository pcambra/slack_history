<?php

/**
 * @file
 */

/**
 * Admin form for managing the slack history variables.
 *
 * Moving the settings form to a new file helps with performance as there's less
 * PHP code in the module file.
 */
function slack_history_settings($form, &$form_state) {
  $form['slack_history_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Slack endpoint url'),
    '#description' => t('This url will be used as base to query the Slack API. Do not include trailing slashes.'),
    '#required' => TRUE,
    '#default_value' => variable_get('slack_history_endpoint', ''),
    '#element_validate' => array('slack_history_endpoint_settings_element_validate'),
  );
  $form['slack_history_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Slack token'),
    '#description' => t('Auth token to query the Slack API'),
    '#required' => TRUE,
    '#default_value' => variable_get('slack_history_token', ''),
  );
  $form['slack_history_channel'] = array(
    '#type' => 'textfield',
    '#title' => t('Slack channel'),
    '#description' => t('Slack channel to get messages from. If empty, all channels will be used.'),
    // Channel is supposed to be optional in Slack API but calling channels
    // history endpoint with no channel returns an error.
    '#required' => TRUE,
    '#default_value' => variable_get('slack_history_channel', ''),
  );
  $form['slack_history_messages_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of messages'),
    '#description' => t('Number of messages to display.'),
    '#default_value' => variable_get('slack_history_messages_count', 10),
  );

  // Add a custom validation for the url.
  $form['#validate'][] = 'slack_history_settings_validate';

  // This will make Drupal to take care of our form automatically.
  return system_settings_form($form);
}

/**
 * Form validation handler for slack_history_settings().
 */
function slack_history_settings_validate($form, &$form_state) {
  if (!valid_url($form_state['values']['slack_history_endpoint'], TRUE)) {
    form_set_error('slack_history_endpoint', t('Please enter a valid URL'));
  }
}

/**
 * Element validate callback that remove slashes from the beginning and end of
 * the endpoint value.
 */
function slack_history_endpoint_settings_element_validate($element, &$form_state) {
  $value = trim($element['#value'], '\\/');
  form_set_value($element, $value, $form_state);
}
