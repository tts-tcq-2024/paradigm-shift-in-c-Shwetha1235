#include <stdio.h>
#include <assert.h>

int isBatteryInRange(float temperature, float soc, float chargeRate) {
    if ((temperature >= 0 && temperature <= 45) &&
        (soc >= 20 && soc <= 80) &&
        (chargeRate <= 0.8)) {
        return 1;
    }
    
    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
    }
    if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
    }
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
    }
    
    return 0;
}

int main() {
    // Temperature < 0, rest optimal
    assert(!isBatteryInRange(-0.1, 70, 0.1));
    // Temperature > 45, rest optimal
    assert(!isBatteryInRange(50.1, 70, 0.3));
    // SOC < 20, rest optimal
    assert(!isBatteryInRange(30, 17, 0.3));
    // SOC > 80, rest optimal
    assert(!isBatteryInRange(26, 90, 0.5));
    // Charge Rate > 0.8, rest optimal
    assert(!isBatteryInRange(30, 60, 0.9));
    // All optimal values
    assert(isBatteryInRange(30, 60, 0.7));
    return 0;
}
