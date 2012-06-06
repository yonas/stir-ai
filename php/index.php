<?php

require_once 'debug.inc';
require_once 'axis.inc';
require_once 'perceptual_map.inc';
require_once 'entity.inc';

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

$axis_groups = array(
                    array(new TimeAxis(), new SpaceAxis()),
                    array(new ImaginationAxis(), new RationalAxis()),
               );

$map = new PerceptualMap(array(
                'id' => 'STIR A.I. Perceptual Map',
                'version' => '1.0',
                'axis' => $axis_groups,
       ));

$entity = new PerceptualAIEntity(array(
                'id' => 'Commander Data',
                'version' => '1.0',
                'map' => $map,
          ));

$entity->activate();
$entity->observe('xxx')->consider('why');
$entity->observe('xxx')->consider('how');
