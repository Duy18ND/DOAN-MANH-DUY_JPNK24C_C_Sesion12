//cho nguoi dung nhap so nguyen va tim so lon nhat
#include<stdio.h>
int main(){
result();
return 0;	
}
void result(){
	int size,big_numbers;
	//Khai Bao kich co mang
	printf("Nhap do dai cua mang 1 chieu la : ");
	scanf("%d",&size);  
	
	int arr[size];
	
	//Khai bao phan tu trong mang
	for(int i =0;i<size; i++){
		printf("Phan tu thu %d la : ",i+1);
		scanf("%d",&arr[i]);	
	}
	//in phan tu sau khi nhap
	printf("Phan tu sau khi nhap la: \n");
		for(int i =0;i<size; i++ ){
		printf("%d\n",arr[i]);
}
	//tim so lon nhat
		big_numbers = arr[0];
		for(int i=0; i<size; i++){
			if(arr[i] > big_numbers){
			big_numbers = arr[i];
			}
		}
		//in ra
		printf("So nhat nhat trong mang la: %d",big_numbers);
	}

