<?php

class Map {
    protected $id = NULL;
    protected $axis = NULL;

    public function __construct($options) {
        $this->id = $options['id'];
        $this->axis = $options['axis'];
    }
}

class PerceptualMap extends Map {
    public function __construct($options) {
        if (!isset($options['axis']) || count($options['axis']) != 2)
            throw new Exception('Perceptual map "' . $options['id'] . '" must have exactly two pairs of axis groups.');

        foreach ($options['axis'] as $axis_pair) {
            if (count($axis_pair) != 2)
                throw new Exception('Perceptual map "' . $options['id'] . '" must have exactly two axis per axis group.');
        }

        parent::__construct($options);
    }
}
