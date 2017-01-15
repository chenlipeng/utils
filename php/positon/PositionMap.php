<?php

/**
 * 由经纬度转换为行政区编码 编码为六位 若返回FALSE 则表明地址为国外 
 * @copyright Copyright (c) 2014-2016 oneniceapp.com, Inc. All Rights Reserved
 * @author chenlipeng <chenlipeng@oneniceapp.com> 
 */
class DataType_PositionMap {

    public static function longLat2CityCode($long, $lat) {
        $str = file_get_contents(dirname(__FILE__) . '/pkl_deflate.json');
        $str = gzinflate($str);
        $long = intval($long*1000);
        $lat= intval($lat*1000);
        $start_x = 73550;
        $start_y = 18100;
        $step_x = 24;
        $step_y = 18;
        $long_int = intval(($long - $start_x) / $step_x);
        $lat_int = intval(($lat - $start_y) / $step_y);

        $pkl = explode("\n", $str);
        $pklItem = json_decode($pkl[$long_int], true);
        if ($long_int >=0 && $lat_int >=0 && $pklItem[$lat_int]!=0) {
            return strval($pklItem[$lat_int]);
        }
        return false;
    }
}
