/***********************************************************************
 * Project      :     tiny32_PR-3000-H-N01_getAll
 * Description  :     Get value from PR-3000-H-N01 RS485 Soil Humidity Sensor 
 *                    (This sensor fixed id=2 and fix baudrate = 4800 can't change)  
 * Hardware     :     tiny32_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/07/2022
 * Revision     :     1.0
 * Rev1.0       :     Origital
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu;

float temperature,humidity;


void setup()
{
    Serial.begin(115200);
    Serial.printf("\r\n**** tiny32_PR-3000-H-N01_getAll ****\r\n");
    mcu.library_version();
    mcu.PR3000_H_N01_begin(RXD2,TXD2);
    mcu.buzzer_beep(2);
}


void loop()
{
  if(mcu.PR3000_H_N01(temperature,humidity)) //fix id=1
  {
    Serial.printf("Temperature => %.1f C\r\n",temperature);
    Serial.printf("Humidity => %.1f%c\r\n",humidity,37);
  }
  else
  {
    Serial.printf("Error: Can't get data from PR-3000-H-N01 sensor!!!\r\n");
  }
  Serial.println("-------------------------------");
  vTaskDelay(1000);
}