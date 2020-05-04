<?php

$redis = new Redis();
$redisKey = 'info_hash';
$redis->connect('localhost');

//001. hSet
$redis->hset($redisKey, 'gender', 'male');

//002. hSetNx
$redis->hsetnx($redisKey, 'gender', 'males');

//003. hMset
$redis->hmset($redisKey, array('gender'	=> 'female'));

//004. hGet
$ret = $redis->hget($redisKey, 'gender');
var_dump($ret);

//005. hMget
$ret = $redis->hmget($redisKey, array('gender', 'age'));
var_dump($ret);

//006. hLen
$ret = $redis->hLen($redisKey);
var_dump($ret);

//007. hDel
$redis->hDel($redisKey, 0);

//008. hKeys
$ret = $redis->hKeys($redisKey);
var_dump($ret);

//009. hVals
$ret = $redis->hVals($redisKey);
var_dump($ret);

//010. hGetAll
$ret = $redis->hgetall($redisKey);
var_dump($ret);

//011. hExists
$ret = $redis->hExists($redisKey, 0);
var_dump($ret);

//012. hIncrBy
$redis->hdel($redisKey, 'age');
$ret = $redis->hIncrBy($redisKey, 'age', 11);
var_dump($ret);

//013. hIncrByFloat 貌似存在一些精度问题
$ret = $redis->hIncrByFloat($redisKey, 'age', -11.1);
var_dump($ret);
