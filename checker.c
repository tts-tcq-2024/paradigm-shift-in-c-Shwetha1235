#include <stdio.h>
#include <assert.h>
// test commit
int batteryIsOk(float temperature, float soc, float chargeRate , const char *manufacturer) {
  if(temperature < 0 || temperature > 55) {
    printf("Temperature out of range : %.2f\n",temperature);
    return 0;
  } 
  
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range : %.2f\n",soc);
    return 0;
  } 
  
  if(chargeRate < 0 || chargeRater > 1.0) {
    printf("Charge Rate out of range : %.2f\n",chargeRate);
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(60, 85, 0.9));
  assert(!batteryIsOk(25, 70, 1.2));
}
