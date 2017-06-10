<?php

$redis = new Redis();
$redis->connect('127.0.0.1', 6379);
$key = 'sorted_set';

/*
$index = 0;
do {
	$redis->zadd($key, 100 - $index, $index);
} while ($index++ < 100);
*/

$ret = $redis->zrevrange($key, 0, 10, TRUE);
var_dump($ret);
