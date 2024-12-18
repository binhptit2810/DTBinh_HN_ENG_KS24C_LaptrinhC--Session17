#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ham nhap chuoi
void nhapChuoi(char **chuoi) {
    char temp[1000];
    printf("Nhap chuoi: ");
    scanf(" %[^\n]", temp);
    *chuoi = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    if (*chuoi != NULL) {
        strcpy(*chuoi, temp);
    } else {
        printf("Khong the cap phat bo nho!\n");
    }
}
// Ham in chuoi
void inChuoi(char *chuoi) {
    if (chuoi != NULL) {
        printf("Chuoi da nhap: %s\n",chuoi);
    } else {
        printf("Chua nhap chuoi!\n");
    }
}
// Ham dem chu cai trong chuoi
int demChuCai(char *chuoi) {
    int dem = 0;
    if (chuoi != NULL) {
        for (int i = 0; chuoi[i] != '\0'; i++) {
            if ((chuoi[i] >= 'A' && chuoi[i] <= 'Z') || (chuoi[i] >= 'a' && chuoi[i] <= 'z')) {
                dem++;
            }
        }
    }
    return dem;
}

// Ham dem chu so trong chuoi
int demChuSo(char *chuoi) {
    int dem = 0;
    if (chuoi != NULL) {
        for (int i = 0; chuoi[i] != '\0'; i++) {
            if (chuoi[i] >= '0' && chuoi[i] <= '9') {
                dem++;
            }
        }
    }
    return dem;
}

// Ham dem ky tu dac biet trong chuoi
int demKyTuDacBiet(char *chuoi) {
    int dem = 0;
    if (chuoi != NULL) {
        for (int i = 0; chuoi[i] != '\0'; i++) {
            if (!((chuoi[i] >= 'A' && chuoi[i] <= 'Z') || 
                  (chuoi[i] >= 'a' && chuoi[i] <= 'z') || 
                  (chuoi[i] >= '0' && chuoi[i] <= '9'))) {
                dem++;
            }
        }
    }
    return dem;
}
int main() {
    char *chuoi = NULL; 
    int luaChon;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (chuoi != NULL) {
                    free(chuoi); 
                }
                nhapChuoi(&chuoi);
                break;
            case 2:
                inChuoi(chuoi);
                break;
            case 3:
                printf("So luong chu cai trong chuoi la: %d\n", demChuCai(chuoi));
                break;
            case 4:
                printf("So luong chu so trong chuoi la: %d\n", demChuSo(chuoi));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi la: %d\n", demKyTuDacBiet(chuoi));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 6);
    if (chuoi != NULL) {
        free(chuoi);
    }
    return 0;
}

