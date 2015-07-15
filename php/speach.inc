<?php
class SpeachEngine {
    protected $speach_speed = NULL;
    public function say($communication) { }
}

class TextSpeachEngine extends SpeachEngine {
    public function __construct($options = array()) {
        // Words per minute
        // Human speach is normally 110 - 150 words per minute.
        $this->wpm = isset($options['speed']) ?  $options['speed'] : 150;
    }

    public function say($communication) {
        $words = str_word_count($communication, 1, ':.!?');
        $len = count($words);

        for ($i = 0; $i < $len - 1; $i++) {
            $this->output($words[$i] . " ");
            usleep( (1 / ($this->wpm / 60)) * 1000000 );
        }
        $this->output($words[$i] . "\n");
    }

    protected function output($text) {
        echo $text;
    }
}

class TestSuiteSpeachEngine extends SpeachEngine {
    public function say($communication) {
        return $this->output($communication);
    }

    protected function output($text) {
        echo $text . "\n";
        return $text;
    }
}
