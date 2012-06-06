<?php

class Axis {
    protected $label = NULL;

    public function __construct($options) {
        $this->label = $options['label'];
    }

    public function label($label = NULL) {
        if (isset($label)) {
            $this->label = $label;
        }

        return $this->label;
    }
}

class ImaginationAxis extends Axis { 
    public function __construct($options = array()) {
        if (!isset($options['label']))
            $options['label'] = 'Why'; 

        parent::__construct($options);
    }
}

class RationalAxis extends Axis {
    public function __construct($options = array()) {
        if (!isset($options['label']))
            $options['label'] = 'How'; 

        parent::__construct($options);
    }
}

class TimeAxis extends Axis {
    public function __construct($options = array()) {
        if (!isset($options['label']))
            $options['label'] = 'When'; 

        parent::__construct($options);
    }
}

class SpaceAxis extends Axis {
    public function __construct($options = array()) {
        if (!isset($options['label']))
            $options['label'] = 'Where'; 

        parent::__construct($options);
    }
}

class AxisPair {
    protected $objects = NULL;

    public function __construct() {
        $this->objects = array();
    }

    public function add($x, $y) {
        $objects[$x][] = $y;
    }

    public function get($x) {
        return $objects[$x];
    }

    public function find($y) {
    }
}
