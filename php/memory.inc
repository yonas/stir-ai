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

class SimpleMemory extends Memory {
    public function capacity() {
        return $this->capacity;
    }

    /* $data = array(
     *   'when' => 1234
     *   'how'  => 'the rock dropped.')
     */
    public function store($data) {
        if ($this->size >= $this->capacity) {
            // free up some space
        }

        ksort($data); // sort by keys for consistent entry into $memory
        $data = array_reverse($data);// todo: remove
        $dimensions = array_keys($data);
        $dimension1 = $dimensions[0];
        $dimension2 = $dimensions[1];

        $data1 = $data[$dimension1];
        $data2 = $data[$dimension2];

        if (!isset($this->memory[$dimension1]))
            $this->memory[$dimension1] = array();
        
        if (!isset($this->memory[$dimension1][$data1]))
            $this->memory[$dimension1][$data1] = array();

        $this->memory[$dimension1][$data1][$dimension2] =  $data2;

        $this->size++;
    }

    public function remember($data) {
        if ($this->fetch($data))
            return true;

        return false;
    }

    public function fetch($data) {
        ksort($data); // sort by keys for consistent entry into $memory
        $data = array_reverse($data); // todo: remove
        $dimensions = array_keys($data);
        $dimension1 = $dimensions[0];
        $dimension2 = $dimensions[1];

        $data1 = $data[$dimension1];
        $data2 = $data[$dimension2];

        if (isset($this->memory[$dimension1]) &&
            isset($this->memory[$dimension1][$data1]) &&
            isset($this->memory[$dimension1][$data1][$dimension2]) &&
            isset($this->memory[$dimension1][$data1][$dimension2][$data2]))
        {
            return $this->memory[$dimension1][$data1][$dimension2][$data2];
        } else {
            return false;
        }
    }

    public function look_back($dimension1, $query) {
        $results = array();

        $query_dimensions = array();
        switch ($dimension1) {
            case 'why':
            case 'how':
                $query_dimensions = array('when', 'where');
                break;
            case 'when':
            case 'where':
                $query_dimensions = array('how', 'why');
                break;
        }

        foreach ($this->memory[$dimension1] as $data1 => $dimension2) {
            foreach ($dimension2 as $d2_name => $data2) {
                if (in_array($d2_name, $query_dimensions) && $data2 == $query) {
                    $results[] = $data1;
                }
            }
        }

        return $results;
    }
}
