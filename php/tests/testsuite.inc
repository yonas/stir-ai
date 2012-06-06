<?php
require_once 'testsuite_init.inc';

class Test {
    protected $group = NULL;

    public function __construct($group) {
        $this->group = $group;
    }

    public function assertTrue($name, $condition) {
        $this->test($name, $condition, true);
    }

    public function assertFalse($name, $condition) {
        $this->test($name, $condition, false);
    }

    protected function test($name, $condition, $expected) {
        if ($condition === $expected) {
            echo "\n[{$this->group}] Test Passed: {$name}\n";
        } else {
            echo "\n[{$this->group}] *** Test Failed ***: {$name}\n";
        }
    }
}
