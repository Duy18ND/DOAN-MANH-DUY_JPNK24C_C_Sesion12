#include<stdio.h>
int main(){
result();	
}
void result(){
	int rows,cols;
	printf("Nhap do dai rows la :");
	scanf("%d",&rows);
	printf("Nhap do dai cols la :");
	scanf("%d",&cols);
	int arr[rows][cols];
	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			printf("nhap arr[%d][%d] la : ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0; i < rows; i++){
		printf("\n");
		for(int j=0; j < cols; j++){
			printf("%4d",arr[i][j]);
	}
}
}
