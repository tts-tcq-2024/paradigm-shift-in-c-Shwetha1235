#include <stdio.h>
#include <assert.h>

// Function to check if the temperature is within range
int isTemperatureOk(float temperature) {
    if (temperature < 0) {
        printf("Temperature below minimum limit: %.2f (Min: 0)\n", temperature);
        return 0;
    }
    if (temperature > 55) {
        printf("Temperature above maximum limit: %.2f (Max: 55)\n", temperature);
        return 0;
    }
    return 1;
}

// Function to check if the SOC is within range
int isSocOk(float soc) {
    if (soc < 20) {
        printf("State of Charge below minimum limit: %.2f (Min: 20)\n", soc);
        return 0;
    }
    if (soc > 80) {
        printf("State of Charge above maximum limit: %.2f (Max: 80)\n", soc);
        return 0;
    }
    return 1;
}

// Function to check if the charge rate is within range
int isChargeRateOk(float chargeRate) {
    if (chargeRate < 0) {
        printf("Charge Rate below minimum limit: %.2f (Min: 0)\n", chargeRate);
        return 0;
    }
    if (chargeRate > 1.0) {
        printf("Charge Rate above maximum limit: %.2f (Max: 1.0)\n", chargeRate);
        return 0;
    }
    return 1;
}

// Function to check overall battery health
int batteryIsOk(float temperature, float soc, float chargeRate, const char *manufacturer) {
    int temperatureStatus = isTemperatureOk(temperature);
    int socStatus = isSocOk(soc);
    int chargeRateStatus = isChargeRateOk(chargeRate);
    
    // Combining the results into a single return statement
    return temperatureStatus && socStatus && chargeRateStatus;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7, "Manufacturer1"));
    assert(!batteryIsOk(60, 70, 0.7, "Manufacturer1"));  // Temperature out of range (above)
    assert(!batteryIsOk(-5, 70, 0.7, "Manufacturer1"));  // Temperature out of range (below)
    assert(!batteryIsOk(25, 85, 0.7, "Manufacturer1"));  // SOC out of range (above)
    assert(!batteryIsOk(25, 15, 0.7, "Manufacturer1"));  // SOC out of range (below)
    assert(!batteryIsOk(25, 70, 1.2, "Manufacturer1"));  // Charge rate out of range (above)
    assert(!batteryIsOk(25, 70, -0.1, "Manufacturer1")); // Charge rate out of range (below)
    
    printf("All tests passed.\n");
    return 0;
}
