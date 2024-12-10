#include <stdio.h>
#include <math.h>
int result(int number) {
    int sum =0;
    for(int i=1; i<number;i++){
    	if(number % i == 0){
    		sum +=i;
		}
	}
	if(sum == number){
		return 1;
	}else{
		return 0;
	}
}

int main() {
    int number;


    printf("Nhap so can kiem tra la: ");
    scanf("%d", &number);


    if (result(number)) {
        printf("So %d la so hoan hao\n", number);
    } else {
        printf("So %d khong phai la So hoan hao\n", number);
    }

    return 0;
}

