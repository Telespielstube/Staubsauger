#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H
class Display {

  private:
    //

  public:
    /* Shows value for first line on lcd. 
     *  
     *  @param *token   extracted first substring from message payload.
     *  @param *topic   matching topic for value.
     */
    void showValue1(char *token, char *topic);
    /* Shows value for first line on lcd. 
     *  
     *  @param *token   extracted second substring from message payload.
     *  @param *topic   matching topic for value.
     */
    void showValue2(char *token, char *topic);
    /* Shows temperature values on lcd.
     *  
     *  @param *temperature   temperature value.
     *  @param *humidity      humidity value.
     */
    void showTemperature(char *temperature, char *humidity);
    /* Shows fine dust values on lcd.
     * 
     * @param *pm25   particulate matter (PM) value 2.5.
     * @param *pm10   particulate matter (PM) value 10.
     */
    void showFineDust(char *PM25, char *PM10);

};
#endif
