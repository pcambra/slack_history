<?php
/**
 * @file
 * Default theme implementation for messages with avatars.
 *
 * Available variables:
 * - $message: message to render.
 */
?>

<span><img src="<?php print $message['user_avatar'] ?>" /> </span>
<span><?php print $message['user_name'] ?>: </span>
<span><?php print $message['text'] ?></span>
