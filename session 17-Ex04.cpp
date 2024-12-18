#include <stdio.h>
#include <stdlib.h>

// Ham kiem tra so nguyen to
int laSoNguyenTo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
// Ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int)); 
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1); 
    }
    printf("Nhap %d phan tu:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
// Ham in cac phan tu la so chan
void inSoChan(int *arr, int n) {
    printf("Cac phan tu chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
// Ham in cac phan tu la so nguyen to
void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
// Ham dao nguoc mang
void daoNguocMang(int *arr, int n) {
    printf("Mang sau khi dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Ham sap xep mang theo chieu tang dan
void sapXepTangDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Ham sap xep mang theo chieu giam dan
void sapXepGiamDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Ham tim kiem phan tu trong mang
int timKiemPhanTu(int *arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int *arr = NULL;
    int n, luaChon, x, viTri; 
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("    1. Tang dan\n");
        printf("    2. Giam dan\n");
        printf("6. Tim kiem phan tu\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (arr != NULL) {
                    inSoChan(arr, n);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 3:
                if (arr != NULL) {
                    inSoNguyenTo(arr, n);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 4:
                if (arr != NULL) {
                    daoNguocMang(arr, n);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    printf("Lua chon: \n");
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    int luaChonSapXep;
                    scanf("%d", &luaChonSapXep);
                    if (luaChonSapXep == 1) {
                        sapXepTangDan(arr, n);
                        printf("Mang sau khi sap xep tang dan: ");
                        for (int i = 0; i < n; i++) {
                            printf("%d ", arr[i]);
                        }
                        printf("\n");
                    } else if (luaChonSapXep == 2) {
                        sapXepGiamDan(arr, n);
                        printf("Mang sau khi sap xep giam dan: ");
                        for (int i = 0; i < n; i++) {
                            printf("%d ", arr[i]);
                        }
                        printf("\n");
                    } else {
                        printf("Lua chon khong hop le.\n");
                    }
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 6:
                if (arr != NULL) {
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &x);
                    viTri = timKiemPhanTu(arr, n, x);
                    if (viTri != -1) {
                        printf("Phan tu %d duoc tim thay tai chi so %d.\n", x, viTri);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", x);
                    }
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 7);
    if (arr != NULL) {
        free(arr);
    }
    return 0;
}

