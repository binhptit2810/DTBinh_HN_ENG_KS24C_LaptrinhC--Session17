#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ham nhap chuoi
void nhapChuoi(char **chuoi) {
    char temp[1000]; 
    printf("Nhap chuoi: ");
    scanf(" %[^\n]", temp); 
    *chuoi = (char *)malloc((strlen(temp) + 1) * sizeof(char)); // Cap phat bo nho dong
    if (*chuoi != NULL) {
        strcpy(*chuoi, temp); 
    } else {
        printf("Khong the cap phat bo nho!\n");
    }
}
// Ham in chuoi dao nguoc
void inChuoiDaoNguoc(char *chuoi) {
    if (chuoi != NULL) {
        int len = strlen(chuoi);
        printf("Chuo dao nguoc: ");
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", chuoi[i]);
        }
        printf("\n");
    } else {
        printf("Chua nhap chuoi!\n");
    }
}
// Ham dem so luong tu trong chuoi
int demSoLuongTu(char *chuoi) {
    int dem = 0;
    if (chuoi != NULL) {
        int i = 0;
        int inWord = 0; 
        while (chuoi[i] != '\0') {
            if ((chuoi[i] != ' ') && (chuoi[i] !='\t')&&(chuoi[i] != '\n')){
                if (inWord == 0) {
                    dem++; 
                }
                inWord = 1;
            } else {
                inWord = 0; 
            }
            i++;
        }
    }
    return dem;
}
// Ham so sanh chuoi
void soSanhChuoi(char *chuoi1, char *chuoi2) {
    if (chuoi1 != NULL && chuoi2 != NULL) {
        int len1 = strlen(chuoi1);
        int len2 = strlen(chuoi2);
        if (len1 < len2) {
            printf("Chuoi 2 dai hon chuoi 1\n");
        } else if (len1 > len2) {
            printf("Chuoi 1 dai hon chuoi 2\n");
        } else {
            printf("Hai chuoi co do dai bang nhau\n");
        }
    } else {
        printf("Chua nhap chuoi!\n");
    }
}
// Ham in hoa tat ca chu cai trong chuoi
void inHoaTatCaChuCai(char *chuoi) {
    if (chuoi != NULL) {
        for (int i = 0; chuoi[i] != '\0'; i++) {
            if (chuoi[i] >= 'a' && chuoi[i] <= 'z') {
                chuoi[i] = chuoi[i] - 'a' + 'A'; 
            }
        }
        printf("Chuoi in hoa: %s\n", chuoi);
    } else {
        printf("Chua nhap chuoi!\n");
    }
}
// Ham them chuoi khac vao chuoi ban dau
void themChuoi(char **chuoi1) {
    char temp[1000]; 
    printf("Nhap chuoi can them: ");
    scanf(" %[^\n]", temp);
    *chuoi1 = (char *)realloc(*chuoi1, (strlen(*chuoi1) + strlen(temp) + 1) * sizeof(char));
    if (*chuoi1 != NULL) {
        strcat(*chuoi1, temp); 
        printf("Chuoi sau khi them: %s\n", *chuoi1);
    } else {
        printf("Khong the cap phat bo nho!\n");
    }
}
int main() {
    char *chuoi = NULL; 
    int luaChon;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
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
                inChuoiDaoNguoc(chuoi);
                break;
            case 3:
                printf("So luong tu trong chuoi la: %d\n", demSoLuongTu(chuoi));
                break;
            case 4: {
                char *chuoi2 = NULL;
                nhapChuoi(&chuoi2);
                soSanhChuoi(chuoi, chuoi2);
                free(chuoi2); 
                break;
            }
            case 5:
                inHoaTatCaChuCai(chuoi);
                break;
            case 6:
                themChuoi(&chuoi);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 7);
    if (chuoi != NULL) {
        free(chuoi);
    }
    return 0;
}

