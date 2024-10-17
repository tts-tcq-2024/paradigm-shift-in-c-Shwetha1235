#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "temperatureCheck.h"
#include "chargeRateCheck.h"
#include "socStateCheck.h"
#include "testPrintMessage.h"

int batteryIsOk(float temperature, float soc, float charge_rate,int language) {
   return temp_Ok(temperature,language) && soc_Ok(soc,language) && charge_Ok(charge_rate,language);
}

int main() {

  assert(!batteryIsOk(-0.2, 70, 0.1,1));
  assert(!batteryIsOk(50.1, 70, 0.3,1));
  assert(!batteryIsOk(25, 18, 0.3,2) );
  assert(!batteryIsOk(26, 90, 0.5,1));
  assert(!batteryIsOk(30, 60, 0.9,2));
  assert(batteryIsOk(25, 60, 0.7,1));
}
 
