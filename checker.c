#include <stdio.h>
#include <assert.h>
 
int TempOk(float temperature){
    if(temperature < 0 || temperature > 45){
        printf("Temperature out of range!\n");
        return 0;
    }
    return 1;
}
int SocOk(float soc){
    if(soc < 20 || soc > 80){
        printf("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}
int ChargeOk(float chargeRate){
    if(chargeRate > 0.8){
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
 
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
   return TempOk(temperature) && SocOk(soc) && ChargeOk(chargeRate);
}
 
int main() {
// Temperature < 0, rest optimal
  assert(!batteryIsOk(-0.1, 70, 0.1));
  // Temperature > 45, rest optimal
  assert(!batteryIsOk(50.1, 70, 0.3));
  // SOC < 20, rest optimal
  assert(!batteryIsOk(30, 17, 0.3) );
  // SOC > 80, rest optimal
  assert(!batteryIsOk(26, 90, 0.5));
  // Charge Rate > 0.8, rest optimal
  assert(!batteryIsOk(30, 60, 0.9));
  // All optimal values
  assert(batteryIsOk(30, 60, 0.7));
   return 0;
}
