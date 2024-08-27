#include <stdio.h>
#include <assert.h>

// Function to check if a parameter is within range and report the issue
int checkParameterInRange(float value, float min, float max, const char *parameterName) {
    if(value < min) {
        printf("%s below minimum limit: %.2f (Min: %.2f)\n", parameterName, value, min);
        return 0;
    } 
    if(value > max) {
        printf("%s above maximum limit: %.2f (Max: %.2f)\n", parameterName, value, max);
        return 0;
    }
    return 1;
}

// Function to check overall battery health
int batteryIsOk(float temperature, float soc, float chargeRate, const char *manufacturer) {
    return checkParameterInRange(temperature, 0, 55, "Temperature") &
           checkParameterInRange(soc, 20, 80, "State of Charge") &
           checkParameterInRange(chargeRate, 0, 1.0, "Charge Rate");
}

// Main function to test the battery health
int main() {
    assert(batteryIsOk(25, 70, 0.7, "Manufacturer1"));
    assert(!batteryIsOk(60, 70, 0.7, "Manufacturer1")); // Temperature out of range (above)
    assert(!batteryIsOk(-5, 70, 0.7, "Manufacturer1")); // Temperature out of range (below)
    assert(!batteryIsOk(25, 85, 0.7, "Manufacturer1")); // SOC out of range (above)
    assert(!batteryIsOk(25, 15, 0.7, "Manufacturer1")); // SOC out of range (below)
    assert(!batteryIsOk(25, 70, 1.2, "Manufacturer1")); // Charge rate out of range (above)
    assert(!batteryIsOk(25, 70, -0.1, "Manufacturer1")); // Charge rate out of range (below)
    printf("All tests passed.\n");
    return 0;
}
