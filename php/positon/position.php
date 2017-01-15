<?php
/**
 * 中国行政区编码
 * http://www.mingluji.com/%E8%A1%8C%E6%94%BF%E5%8C%BA%E5%8F%B7%E4%BB%A3%E7%A0%81#.E5.8C.97.E4.BA.AC
 */

//2016年十一活动 国内地址
$homeCodeMap = array(
    '530000' => '云南',
    '330100' => '杭州',
    '650000' => '新疆',
    '460200' => '三亚',
    '120000' => '天津',
    '370200' => '青岛',
    '350200' => '厦门',
    '110000' => '北京',
    '320100' => '南京',
    '500000' => '重庆',
    '630000' => '青海',
    '620100' => '兰州',
    '450300' => '桂林',
    '320500' => '苏州',
    '310000' => '上海',
    '610100' => '西安',
    '510100' => '成都',
    '540000' => '西藏',
    '210200' => '大连',
    '430100' => '长沙',
    '440100' => '广州',
    '150000' => '内蒙古',
    '820000' => '澳门',
    '810000' => '香港',
    '710000' => '台湾',
    '440300' => '深圳',
);

$homeShortCodeMap = array(
    '530' => '云南',
    '330' => '杭州',
    '650' => '新疆',
    '460' => '三亚',
    '120' => '天津',
    '370' => '青岛',
    '350' => '厦门',
    '110' => '北京',
    '500' => '重庆',
    '630' => '青海',
    '620' => '兰州',
    '450' => '桂林',
    '310' => '上海',
    '610' => '西安',
    '510' => '成都',
    '540' => '西藏',
    '210' => '大连',
    '430' => '长沙',
    '4401' => '广州',
    '150' => '内蒙古',
    '820' => '澳门',
    '810' => '香港',
    '710' => '台湾',
    '3201'=> '南京',
    '3205'=> '苏州',
    '4403'=> '深圳',
);

//国外地址
$abroadMap = array(
    'US'     => '美国',
    'UK'     => '英国',
    'GB'     => '英国',
    'TH'     => '泰国',
    'JP'     => '日本',
    'FR'     => '法国',
    'GR'     => '希腊',
    'CH'     => '瑞士',
    'CA'     => '加拿大',
    'AU'     => '澳大利亚',
    'NZ'     => '新西兰',
    'KR'     => '韩国',
    'IT'     => '意大利',
    'DE'     => '德国',
    'RU'     => '俄罗斯',
    'ES'     => '西班牙',
    'MV'     => '马尔代夫',
    'MX'     => '墨西哥',
    'SG'     => '新加坡',
    'MU'     => '毛里求斯',
    'MY'     => '马来西亚',
    'ID'     => '巴厘岛',
    'MP'     => '塞班岛',
    'AE'     => '迪拜',
    'TR'     => '土耳其',
);

//国外地址
$abroadPosition = array(
    '美国'     => '',
    '英国'     => '',
    '泰国'     => '',
    '日本'     => '',
    '法国'     => '',
    '希腊'     => '',
    '瑞士'     => '',
    '迪拜'     => '',
    '加拿大'   => '',
    '澳大利亚' => '',
    '新西兰'   => '',
    '韩国'     => '',
    '意大利'   => '',
    '德国'     => '',
    '俄罗斯'   => '',
    '西班牙'   => '',
    '塞班岛'   => '',
    '马尔代夫' => '',
    '墨西哥'   => '',
    '新加坡'   => '',
    '土耳其'   => '',
    '巴厘岛'   => '',
    '毛里求斯' => '',
    '马来西亚' => '',
);

//国外经纬度地址转化 服务配置
$conf=array(
    'servers'=>array(array(
        'host'=>'106.75.73.39','port'=>'8099'
    )),
    'timeout'=>1000,
    'connect_timeout' => 100,
);

$getParams = array(
    'v'  => '20160530',
    'client_secret'  => 'B120GLHHSB5KGCC3B5YIVS1AJFBEJPG5GR10Y5SRVZTQEL2D',
    'client_id'      => 'JLZV5ATZVPTRWY1ZCFZAHKARS3FLYIPVCTDWC5PVFQNA0SHR',
);

$homeProvinceMap = array(
    '110000' => '北京市',
    '120000' => '天津市',
    '310000' => '上海市',
    '500000' => '重庆市',
    '130000' => '河北省',
    '140000' => '山西省',
    '210000' => '辽宁省',
    '220000' => '吉林省',
    '230000' => '黑龙江省',
    '320000' => '江苏省',
    '330000' => '浙江省',
    '340000' => '安徽省',
    '350000' => '福建省',
    '360000' => '江西省',
    '370000' => '山东省',
    '410000' => '河南省',
    '420000' => '湖北省',
    '430000' => '湖南省',
    '440000' => '广东省',
    '460000' => '海南省',
    '510000' => '四川省',
    '520000' => '贵州省',
    '530000' => '云南省',
    '610000' => '陕西省',
    '620000' => '甘肃省',
    '630000' => '青海省',
    '710000' => '台湾',
    '810000' => '香港',
    '820000' => '澳门',
    '150000' => '内蒙古自治区',
    '450000' => '广西壮族自治区',
    '540000' => '西藏自治区',
    '640000' => '宁夏回族自治区',
    '650000' => '新疆维吾尔自治区',
);

$provinceShortCodeMap = array(
    '110' => '北京市',
    '120' => '天津市',
    '310' => '上海市',
    '500' => '重庆市',
    '130' => '河北省',
    '140' => '山西省',
    '210' => '辽宁省',
    '220' => '吉林省',
    '230' => '黑龙江省',
    '320' => '江苏省',
    '330' => '浙江省',
    '340' => '安徽省',
    '350' => '福建省',
    '360' => '江西省',
    '370' => '山东省',
    '410' => '河南省',
    '420' => '湖北省',
    '430' => '湖南省',
    '440' => '广东省',
    '460' => '海南省',
    '510' => '四川省',
    '520' => '贵州省',
    '530' => '云南省',
    '610' => '陕西省',
    '620' => '甘肃省',
    '630' => '青海省',
    '710' => '台湾',
    '810' => '香港',
    '820' => '澳门',
    '150' => '内蒙古自治区',
    '450' => '广西壮族自治区',
    '540' => '西藏自治区',
    '640' => '宁夏回族自治区',
    '650' => '新疆维吾尔自治区',
);
