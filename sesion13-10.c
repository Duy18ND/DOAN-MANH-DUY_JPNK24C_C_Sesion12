#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];      
int size = 0;      

// Ham nhap so phan tu va gia tri
void input_array() {
    printf("Nhap so phan tu: ");
    scanf("%d", &size);
    if (size > MAX) {
        printf("So phan tu vuot qua gioi han cho phep (max %d).\n", MAX);
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("Nhap gia tri phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Ham in cac gia tri cua mang
void print_array() {
    if (size == 0) {
        printf("Mang hien tai rong.\n");
        return;
    }
    printf("Gia tri cac phan tu trong mang: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham them phan tu tai vi tri mong muon 
void add_element() {
    int pos, value;
    printf("Nhap vi tri can them (0 den %d): ", size);
    scanf("%d", &pos);
    if (pos < 0 || pos > size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    // Dich chuyen cac phan tu tai vi tri phia sau
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

// Ham sua phan tu tai vi tri mong muon
void edit_element() {
    int pos, value;
    printf("Nhap vi tri can sua (0 den %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    arr[pos] = value;
}

// Ham xoa phan tu tai vi tri mong muon
void delete_element() {
    int pos;
    printf("Nhap vi tri can xoa (0 den %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    // Dich chuyen cac phan tu ve phia truoc
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Hàm sap xep mang tang dan
void sort_ascending() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sap xep mang giam dan
void sort_descending() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tim kiem tuyen tinh
int linear_search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Hàm tim kiem nhi phan
int binary_search(int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm hien thi menu
void menu() {
    printf("\n1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n");
    printf("    a. Giam dan\n");
    printf("    b. Tang dan\n");
    printf("7. Tim kiem phan tu nhap vao\n");
    printf("    a. Tim kiem tuyen tinh\n");
    printf("    b. Tim kiem nhi phan\n");
    printf("8. Thoat\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Moi ban lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                input_array();
                break;
            case 2:
                print_array();
                break;
            case 3:
                add_element();
                break;
            case 4:
                edit_element();
                break;
            case 5:
                delete_element();
                break;
            case 6:
                {
                    char sub_choice;
                    printf("a. Giam dan\nb. Tang dan\n");
                    printf("Chon lua chon sap xep: ");
                    scanf(" %c", &sub_choice);
                    if (sub_choice == 'a') {
                        sort_descending();
                    } else if (sub_choice == 'b') {
                        sort_ascending();
                    } else {
                        printf("Lua chon khong hop le.\n");
                    }
                }
                break;
            case 7:
                {
                    int value, result;
                    char search_choice;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &value);
                    printf("a. Tim kiem tuyen tinh\nb. Tim kiem nhi phan\n");
                    printf("Chon lua chon tim kiem: ");
                    scanf(" %c", &search_choice);
                    if (search_choice == 'a') {
                        result = linear_search(value);
                        if (result != -1) {
                            printf("Phan tu %d tim thay o vi tri %d.\n", value, result);
                        } else {
                            printf("Phan tu %d khong tim thay.\n", value);
                        }
                    } else if (search_choice == 'b') {
                 
                        sort_ascending();
                        result = binary_search(value);
                        if (result != -1) {
                            printf("Phan tu %d tim thay o vi tri %d.\n", value, result);
                        } else {
                            printf("Phan tu %d khong tim thay.\n", value);
                        }
                    } else {
                        printf("Lua chon khong hop le.\n");
                    }
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}

