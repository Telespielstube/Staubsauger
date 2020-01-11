#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H
class Display {

  private:
    //

  public:
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
    /* Shows fine dust values on lcd.
     * 
     * @param *error  Error message that publisher unexpectedly disconnected from broker. 
     */
    void showError(char *error);

};
#endif
