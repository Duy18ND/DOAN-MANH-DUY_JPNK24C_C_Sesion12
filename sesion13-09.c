#include <stdio.h>
#include <math.h>

#define MAX 100

// Khai bao mang
int arr[MAX][MAX];

// ham MENU
void menu() {
    printf("\n1. Nhap gia tri cac phan tu cua mang (2 chieu)\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra các phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat\n");
}

// Ham kiem tra so nguyen to
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Ham Nhap gia tri mang
void arr_input(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap gia tri arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Ham in ma tran
void matrix(int rows, int cols) {
    printf("Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// Hàm in cac phan tu o goc ma tran
void print_corners(int rows, int cols) {
    printf("Cac phan tu o goc:\n");
    printf("arr[0][0] = %d\n", arr[0][0]);
    printf("arr[0][%d] = %d\n", cols - 1, arr[0][cols - 1]);
    printf("arr[%d][0] = %d\n", rows - 1, arr[rows - 1][0]);
    printf("arr[%d][%d] = %d\n", rows - 1, cols - 1, arr[rows - 1][cols - 1]);
}

// Hàm in các phan tu tren duong biên ma tran
void print_border(int rows, int cols) {
    printf("Cac phan tu nam tren duong bien:\n");

    // In hàng dau và cuoi
    for (int i = 0; i < cols; i++) {
        printf("%d\t", arr[0][i]); // Hàng dau
    }
    for (int i = 0; i < cols; i++) {
        printf("%d\t", arr[rows - 1][i]); // Hàng cuoi
    }

    // In cot dau và cot cuoi
    for (int i = 1; i < rows - 1; i++) {
        printf("%d\t", arr[i][0]); // Cot dau
        printf("%d\t", arr[i][cols - 1]); // Cot cuoi
    }
    printf("\n");
}

// Hàm in các phan tu tren duong cheo chinh và cheo phu
void print_diagonals(int rows, int cols) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");

    // Chéo chinh
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d\t", arr[i][i]); // Chéo chinh
    }
    printf("\n");

    // Chéo phu
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d\t", arr[i][cols - 1 - i]); // Chéo phu
    }
    printf("\n");
}

// Hàm in các so nguyên to trong ma tran
void print_primes(int rows, int cols) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (is_prime(arr[i][j])) {
                printf("%d\t", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int choice;
    int rows, cols;

    do {
        menu();
        printf("Moi ban lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhap so dong (rows): ");
                scanf("%d", &rows);
                printf("Nhap so cot (cols): ");
                scanf("%d", &cols);
                arr_input(rows, cols);
                break;
            case 2:
                matrix(rows, cols);
                break;
            case 3:
                print_corners(rows, cols);
                break;
            case 4:
                print_border(rows, cols);
                break;
            case 5:
                print_diagonals(rows, cols);
                break;
            case 6:
                print_primes(rows, cols);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

