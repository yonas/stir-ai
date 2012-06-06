<?php

require_once 'speach.inc';
require_once 'memory.inc';

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
    protected $version = NULL;
    protected $enabled = false;
    protected $first_run = true;
    protected $speach_engine = NULL;
    protected $last_communication = NULL;

    public function __construct($options) {
        $this->id = $options['id'];
        $this->version = $options['version'];
        $this->first_run = isset($options['first_run']) ? $options['first_run'] : true;
        $this->speach_engine = isset($options['speach_engine']) ? $options['speach_engine'] : new TextSpeachEngine();
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
            $this->first_run = false;
        }

        $this->say("How may I help you?");
    }

    public function deactivate() {
        $this->enabled = false;
        debug($this->id . ' has been deactived.');
    }

    public function version() {
        return $this->version;
    }

    public function repeat() {
        if (!isset($this->last_communication))
            return $this->speach_engine->say('I did not say anything.');

        return $this->speach_engine->say($this->last_communication); 
    }

    protected function say($communication) {
        $this->last_communication = $communication;
        $this->speach_engine->say($communication); 
    }
}

class AIEntity extends Entity {
    protected $last_observation = NULL;
    protected $memory = NULL;

    public function __construct($options) {
        parent::__construct($options);
        $this->memory = new SimpleMemory();
    }
    
    public function observe($data) {
        if (!$this->enabled)
            return $this;

        if (is_array($data)) {
            foreach ($data as $d) {
                $this->record_observation($d);
            }
        } else {
            $this->record_observation($data);
        }

        return $this;
    }

    public function consider($dimension) {
        if (!$this->enabled)
            return $this;

        // get the last piece of data that we observed
        if (!isset($this->last_observation)) {
            $this->say("I don't have enough information.");
        } else {
            $this->consider_observation($this->last_observation, $dimenison);
        }

        return $this;
    }

    public function remember($data) {
        if (!$this->enabled) 
            return $this;

        if (!($this->last_observation = $this->memory->fetch($data))) {
            $this->say("I don't remember that.");
        } else {
            $this->say("Yes, I remember that.");
        }

        return $this;
    }

    protected function record_observation($observation) { }
    protected function consider_observation($observation, $dimension) { }
}

class PerceptualAIEntity extends AIEntity {
    protected $map = NULL;      // Perceptual map

    public function __construct($options) {
        parent::__construct($options);
        $this->map = $options['map'];
    }

    protected function record_observation($observation) {
        $dimensions = array_keys($observation);
        $this->memory->store($observation);
        $this->last_observation = $observation;
    }   

    protected function consider_observation($observation, $along_dimension) {
        // Magic time

        $dimensions = array_keys($observation);

        if (in_array('time', $dimensions) && in_array('how', $dimensions)) {
            switch ($along_dimension) {
                case 'how':
                    break;
                case 'why':
                    break;
                case 'when':
                    break;
                case 'where':
                    break;
            }
        }
        else if (in_array('how', $dimensions) && in_array('where', $dimensions)) {
            switch ($along_dimension) {
                case 'how':
                    break;
                case 'why':
                    break;
                case 'when':
                    break;
                case 'where':
                    break;
            }
        }
        else if (in_array('where', $dimensions) && in_array('why', $dimensions)) {
            switch ($along_dimension) {
                case 'how':
                    break;
                case 'why':
                    break;
                case 'when':
                    break;
                case 'where':
                    break;
            }
        }
        else if (in_array('why', $dimensions) && in_array('when', $dimensions)) {
            switch ($along_dimension) {
                case 'how':
                    break;
                case 'why':
                    break;
                case 'when':
                    break;
                case 'where':
                    break;
            }
        }
    }
}
