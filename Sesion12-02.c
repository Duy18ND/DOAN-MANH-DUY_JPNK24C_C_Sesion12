#include<stdio.h>
void In(int arr[],int size){
	for(int i=0; i<size; i++){
		printf("%d \t",arr[i]);
	}
}
int main(){
	int size;
printf("Nhap kich co cua mang la : ");
scanf("%d",&size);

int arr[size];

for(int i=0; i<size; i++){
	printf("Phan tu thu %d la : ",i+1);
	scanf("%d",&arr[i]);
}

	In(arr,size);
	
return 0;
}
