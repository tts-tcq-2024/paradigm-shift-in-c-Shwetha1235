#include <stdio.h>

#include <assert.h>

int temp_check(float temperature) {

   if (temperature < 0 || temperature > 45) {

       printf("Temperature is out of range!\n");

       return 0; 

   }

   return 1;

}

int soc_check(float soc) {

   if (soc < 20 || soc > 80) {

       printf("State of Charge is out of range!\n");

       return 0; 

   }

   return 1;

}

int charge_rate_check(float charge_rate) {

   if (charge_rate > 0.8) {

       printf("Charge rate is out of range!\n");

       return 0; 

   }

   return 1;

}

int battery_is_ok(float temperature, float soc, float charge_rate) {

   return temp_check(temperature) && soc_check(soc) && charge_rate_check(charge_rate);

}

int main() {

// Temperature < 0, rest optimal

  assert(!battery_is_ok(-0.1, 70, 0.1));

  // Temperature > 45, rest optimal

  assert(!battery_is_ok(45.1, 70, 0.3));

  // SOC < 20, rest optimal

  assert(!battery_is_ok(25, 19, 0.4) );

  // SOC > 80, rest optimal

  assert(!battery_is_ok(26, 85, 0.5));

  // Charge Rate > 0.8, rest optimal

  assert(!battery_is_ok(30, 60, 0.81));

  // All optimal values

  assert(battery_is_ok(30, 60, 0.7));

   return 0;

}
 
