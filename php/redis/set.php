<?php
$redis = new Redis();
$redis->connect('127.0.0.1', 6379);

$redisKey = 'continued_key';

//$redis->setex($redisKey, 10, 'YES');
$ret = $redis->exists($redisKey);
var_dump($ret);
return;

//$ret = $redis->incr($redisKey);
$ret = $redis->incrby($redisKey, 10);
$redis->expire($redisKey, 3);
var_dump($ret);
