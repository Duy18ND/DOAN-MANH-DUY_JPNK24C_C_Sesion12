#include<stdio.h>
#include<math.h>
int main() {
    int number, result;

    printf("Moi ban nhap so nguyen bat ky: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Giai thua khong ton tai cho so am.\n");
        return 1;  
    }

    result = GiaiThua(number);  
    printf("Giai thua cua %d la %d\n", number, result);

    return 0;
}
	int GiaiThua(int number) {
    int age = 1;  
    for (int i = 1; i <= number; i++) {
        age *= i;
    }
    return age;
}

