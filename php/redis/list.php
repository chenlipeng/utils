<?php
$redis = new Redis();
$redis->connect('127.0.0.1', 6379);
//sleep(10);

$listKey = 'new_list';
/*
for ($index = 0; $index < 100; ++$index) {
	$redis->lpush($listKey, $index);
}
*/


$ret = $redis->lrange($listKey, 0, 10 - 1);
var_dump($ret);

return;

$keys = array('name', 'name2', 'name1');
$ret = $redis->mget($keys);
$ret = array_combine($keys, $ret);
var_dump($ret);
$ret = array_filter($ret);
var_dump($ret);
return;
$ret = array_count_values($ret);
var_dump($ret);
return;

$str = '{"time":"2017-04-07 22:26:46","country":1,"mobile":"15273771992","uid":26173828,"execute_time":{"time1":1491575191.5901,"time2":1491575191.775,"time3":1491575191.7857,"time4":1491575191.792,"time5":1491575191.8375,"time6":1491575206.8547,"time7":1491575206.9286,"time8":1491575206.9305}}';
//var_dump(json_decode($str, TRUE));

$listKey = 'list';
//$redis->rpush($listKey, 'D');
$redis->lSet($listKey, 1, 'X');
$len = $redis->llen($listKey);
$range = $redis->lrange($listKey, 0, -1);
var_dump($len, $range);

for ($lIndex = 0; $lIndex < $len; ++$lIndex) {
	$value = $redis->lIndex($listKey, $lIndex);
	var_dump($value);
}
$redis->close();
