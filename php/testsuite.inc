<?php

class Test {
    protected $group = NULL;

    public function __construct($group) {
        $this->group = $group;
    }

    public function assertTrue($condition, $name) {
        $this->test($condition, $name, true);
    }

    public function assertFalse($condition, $name) {
        $this->test($condition, $name, false);
    }

    protected function test($condition, $name, $expected) {
        if ($condition === $expected) {
            echo "[{$this->group}] Test Passed: {$name}\n";
        } else {
            echo "[{$this->group}] *** Test Failed ***: {$name}\n";
        }
    }
}
