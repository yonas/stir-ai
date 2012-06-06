<?php

class Memory {
    protected $memory = NULL;
    protected $size = 0;
    protected $capacity = 0;

    public function __construct($options = array()) {
        $this->capacity = 10000000;
        $this->memory = array();
    }

    public function capacity() { }
    public function store($data) { }
    public function remember($dimensions) { }
    public function fetch($dimensions) { }
}

class SimpleMemory {
    public function capacity() {
        return $this->capacity;
    }

    public function store($data) {
        if ($this->size >= $this->capacity) {
            // free up some space
        }

        $dimensions = array_keys($data);

        $data0 = $data[$dimensions[0]];
        $data1 = $data[$dimensions[1]];

        if (!is_array($memory[$dimensions[0]]))
            $this->memory[$dimensions[0]] = array();
        
        $this->memory[$dimensions[0]][$dimensions[1]] = $data[$dimensions[0]][$dimensions[1]];

        $this->size++;
    }

    public function remember($dimensions) {
        return (isset($this->memory[$dimensions[0]]) &&
                isset($this->memory[$dimensions[0]][$dimensions[1]]));
    }

    public function fetch($dimensions) {
        if (!$this->remember($dimensions))
            return false;

        return $this->memory[$dimensions[0]][$dimensions[1]];
    }
}
