# tiny32_PR-3000-H-N01
Example code tiny32 interface with PR-3000-H-N01 RS485 Soil Humidity Sensor 

**** You have to install library below **** 
1)
git clone https://github.com/tenergyinnovation/tiny32_v3.git


**** Infomation link **** 
https://www.cybertice.com/product/4885/rs485-soil-humidity-sensor-%E0%B9%80%E0%B8%8B%E0%B9%87%E0%B8%99%E0%B9%80%E0%B8%8B%E0%B8%AD%E0%B8%A3%E0%B9%8C%E0%B8%A7%E0%B8%B1%E0%B8%94%E0%B8%84%E0%B8%A7%E0%B8%B2%E0%B8%A1%E0%B8%8A%E0%B8%B4%E0%B9%89%E0%B8%99%E0%B9%83%E0%B8%99%E0%B8%94%E0%B8%B4%E0%B8%99-pr-3000-h-n01?_gl=1*1o21m30*_up*MQ..&gclid=Cj0KCQjw8amWBhCYARIsADqZJoVOMnpWdfQDVAx3z1yY9Xmayxeov8NxiulCFcXwrRpk-1PasUKHViIaAgOgEALw_wcB



*** Work around for fix bug of Complier ***
Incase we have to interface more than 1 sensor with ModbusRTU bus, we have to re-begin interface port again before and after read PR-3000-H-N01 sensor, please see example cord below

/***************************************************************************************/

#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu;

float temperature,humidity;


void setup()
{
    Serial.begin(115200);
    Serial.printf("\r\n**** tiny32_PR-3000-H-N01_getAll ****\r\n");
    mcu.library_version();
    mcu.PR3000_H_N01_begin(RXD3,TXD3);
    mcu.XY_MD02_begin(RXD2,TXD2);
    mcu.PYR20_begin(RXD2,TXD2);
    mcu.buzzer_beep(2);
}


void loop()
{

    mcu.PR3000_H_N01_begin(RXD3,TXD3); //<= fix bug 
    humidity = mcu.PR3000_H_N01_humidity();
    Serial.printf("Humidity => %.1f%c\r\n",humidity,37);
    mcu.XY_MD02_begin(RXD2,TXD2); //<= fix bug 

    temperature = mcu.XY_MD02_tempeature(id); 
    humidity = mcu.XY_MD02_humidity(id);
    Serial.printf("Temperature[%d] => %.1f C\r\n",id,temperature);
    Serial.printf("Humidity[%d] => %.1f%c\r\n",id,humidity,37);

    int16_t _pyranormeter = mcu.PYR20_read(id);
    Serial.printf("Info: Solar Radiation = %d W/m^2\r\n",_pyranormeter);

    Serial.println("-------------------------------");


  vTaskDelay(1000);
}

/***************************************************************************************/
