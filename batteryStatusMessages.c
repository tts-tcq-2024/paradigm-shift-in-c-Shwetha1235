#include <stdio.h>                                                 
 void checkEvenOdd(int number) {
    if (number % 2 == 0) {
       printf("%d is Even\n", number);
    } else {
        printf("%d is Odd\n", number);
    }
}
int main() {
    checkEvenOdd(5);
    checkEvenOdd(10);
    return 0;
}
