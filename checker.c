#include <stdio.h>
#include <assert.h>

int Temp_Ok(float temperature) {
   if (temperature < 0 || temperature > 45) {
       printf("Temperature is out of range!\n");
       return 0; 
   }
   return 1;
}

int Soc_Ok(float soc) {
   if (soc < 20 || soc > 80) {
       printf("State of Charge is out of range!\n");
       return 0; 
   }
   return 1;
}

int Charge_Ok(float charge_rate) {
   if (charge_rate > 0.8) {
       printf("Charge rate is out of range!\n");
       return 0; 
   }
   return 1;
}

int batteryisok(float temperature, float soc, float charge_rate) {
   return Temp_Ok(temperature) && Soc_Ok(soc) && Charge_Ok(charge_rate);
}

int main() {

// Temperature < 0
  assert(!batteryisok(-0.2, 70, 0.1));

  // Temperature > 45
  assert(!batteryisok(50.1, 70, 0.3));

  // SOC < 20
  assert(!batteryisok(25, 18, 0.3) );

  // SOC > 80
  assert(!batteryisok(26, 90, 0.5));

  // Charge Rate > 0.8
  assert(!batteryisok(30, 60, 0.9));

  // All optimal values
  assert(batteryisok(25, 60, 0.7));

   return 0;

}
 
