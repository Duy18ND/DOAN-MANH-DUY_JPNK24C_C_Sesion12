#include <stdio.h>
#include <math.h>
int result(int number) {
    if (number <= 1) {
        return 0; 
    }
    if (number == 2) {
        return 1;
    }
    if (number % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1; 
}

int main() {
    int number;


    printf("Nhap so can kiem tra la: ");
    scanf("%d", &number);


    if (result(number)) {
        printf("So %d la So nguyen to\n", number);
    } else {
        printf("So %d khong phai la So nguyen to\n", number);
    }

    return 0;
}

