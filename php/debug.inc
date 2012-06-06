<?php

$debug = true;

function enable_debug() {
    global $debug;
    $debug  = true;
}

function disable_debug() {
    global $debug;
    $debug  = false;
}

function debug($text) {
    global $debug;

    if ($debug)
        echo $text . "\n";
}
