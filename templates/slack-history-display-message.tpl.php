<?php
/**
 * @file
 * Default theme implementation for messages.
 *
 * Available variables:
 * - $message: message to render.
 */
?>

<span><?php print render($message['user_name']) ?>: </span>
<span><?php print render($message['text']) ?></span>
