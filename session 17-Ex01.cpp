#include <stdio.h>
#include <stdlib.h>

// ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    //cap phat bo nho cho mang
    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("khong the cap phat bo nho cho mang\n");
        *n = 0; 
        return;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
// ham hien thi mang
void hienThiMang(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong hoac chua duoc khoi tao\n");
        return;
    }
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// ham tinh do dai mang
int doDaiMang(int n) {
    return n;
}
// ham tinh tong cac phan tu trong mang
int tinhTong(int *arr, int n) {
    if (n == 0) return 0;
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}
// ham tim phan tu lon nhat trong mang
int phanTuLonNhat(int *arr, int n) {
    if (n == 0) return 0;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int *arr = NULL; 
    int n = 0;       
    int luaChon;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon chua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                if (arr != NULL) {
                    free(arr); 
                }
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai cua mang la : %d\n", doDaiMang(n));
                break;
            case 4:
                printf("Tong cac phan tu trong mang la: %d\n", tinhTong(arr, n));
                break;
            case 5:
                if (n > 0) {
                    printf("phan tu lon nhat trong mang la: %d\n",phanTuLonNhat(arr, n));
                } else {
                    printf("Mang khong co phan tu!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 6);
    if (arr != NULL) {
        free(arr);
    }
    return 0;
}

