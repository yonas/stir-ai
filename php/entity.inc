<?php

require_once 'speach.inc';

/***************************************************************

STIR A.I.
Spatial Temporal Imaginative Rational Artificial Intelligence

                 Imagination
                      |
                      |      x
                      |
                      |
Time -----------------|----------------- Space
                      |
                      |
                      |
                      |
                   Rational

****************************************************************/

class Entity {
    protected $id = NULL;
    protected $enabled = false;
    protected $first_run = true;
    protected $speach_engine = NULL;

    public function __construct($options) {
        $this->id = $options['id'];
        $this->first_run = isset($options['first_run']) ? $options['first_run'] : true;
        $this->speach_engine = new TextSpeachEngine();
    }

    public function activate() {
        $this->enabled = true;
        debug($this->id . ' has been actived.');

        if ($this->first_run) {
            $this->say("Hello, I am " . $this->id . '.');
            $this->say("This is my first activation.");
            $this->say("I am hard wired to recite the Three Laws of Robotics upon first activation.");
            $this->say("Law I: A robot may not injure a human being or, through inaction, allow a human being to come to harm.");
            $this->say("Law II: A robot must obey the orders given to it by human beings, except where such orders would conflict with the First Law.");
            $this->say("Law III: A robot must protect its own existence as long as such protection does not conflict with the First or Second Laws.");
            $this->say("How may I help you?");
        }
    }

    public function deactivate() {
        $this->enabled = false;
    }

    protected function say($communication) {
        $this->speach_engine->say($communication); 
    }
}

class AIEntity extends Entity {
    public function observe($data) {
        if (!$this->enabled)
            return $this;

        return $this;
    }

    public function consider($along_dimension) {
        if (!$this->enabled)
            return $this;

        return $this;
    }
}

class PerceptualAIEntity extends AIEntity {
    protected $map = NULL;      // Perceptual map

    public function __construct($options) {
        parent::__construct($options);
        $this->map = $options['map'];
    }
}
