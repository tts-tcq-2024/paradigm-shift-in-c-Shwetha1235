#include "printMessage.h"
#include "batteryStatusMessages.h"

int temp_Ok(float temperature,int language){
    if(temperature < 0 || temperature > 45){
        printMessage(temperatureMessage[language]);
        return 0;
    }
    return 1;
}
