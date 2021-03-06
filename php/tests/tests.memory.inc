<?php

require_once 'testsuite.inc';

/////////////////////////////////////////////////////////
// Memory Tests
//

$test = new Test('Memory');

// recall with no information
$test->assertTrue('Recall with no information', $entity->consider('when')->repeat() == "I don't have enough information.");

// remember unknown observation
$test->assertTrue('Recall unknown observation', $entity->remember(array('when' => 1, 'how' => 'the rock dropped'))->repeat() == "I don't remember that.");

// recall time of last observation
$entity->observe(array(0 => array('when' => 1, 'how' => 'the rock dropped')));
$test->assertTrue('Recall time of last observation', $entity->consider('when')->repeat() == "At time 1.");

// recall time of last observation after another observation
$entity->observe(array(0 => array('when' => 1, 'how' => 'the rock dropped')));
$entity->observe(array(0 => array('when' => 2, 'how' => 'the rock dropped')));
$test->assertTrue('Recall time of last observation after another observation', $entity->consider('when')->repeat() == "At time 2.");

// recall time of last two observations that were the same
$entity->observe(array(0 => array('when' => 1, 'how' => 'the rock dropped')));
$entity->observe(array(0 => array('when' => 2, 'how' => 'the rock dropped')));
$test->assertTrue('Recall time of last two observations of the same process', $entity->question('when', 'the rock dropped')->repeat() == "At time 1 and time 2.");

// remember unknown observation
$test->assertTrue('Recall unknown observation', $entity->remember(array('when' => 100, 'how' => 'the rock dropped'))->repeat() == "I don't remember that.");

// remember known observation
$test->assertTrue('Recall known observation', $entity->remember(array('when' => 1, 'how' => 'the rock dropped'))->repeat() == "Yes, I remember that.");
