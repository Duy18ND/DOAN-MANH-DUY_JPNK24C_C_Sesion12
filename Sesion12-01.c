#include<stdio.h>
int sum(a,b){
return a+b;
}
int main(){
	int x,y,result;
	printf("Nhap so thu nhat la: ");
	scanf("%d",&x);
	printf("Nhap so thu hai la: ");
	scanf("%d",&y);
	result = sum(x,y);
	printf("Tong cua hai so la: %d + %d = %d",x,y,result);
	return 0;
}
