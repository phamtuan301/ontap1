#include <stdio.h>
#include <string.h>
struct Dish {
    int id;
    char name[100];
    float price;
};
struct Dish menu[100] = {
    {1, "Com rang", 35000},
    {2, "Pho", 35000},
    {3, "Bun cha", 30000},
    {4, "Com rang dua bo", 40000},
    {5, "Nem nuong", 30000}
};
int main() {
    int choice;
	int index;
	int length = 5;
	char nameSearch[100];
    while (1) {
        printf("MENU:\n");
        printf("1. In ra gia tri cac phan tu co trong menu mon an\n");
        printf("2. Them mot phan tu tai vi tri chi dinh\n");
        printf("3. Sua mot phan tu tai vi tri chi dinh\n");
        printf("4. Xoa mot phan tu tai vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				printf("Menu:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s: %f\n", menu[i].id, menu[i].name, menu[i].price);
                }
                break;
            case 2:
                printf("Nhap vi tri them phan tu: ");
                scanf("%d", &index);
                if (index >= 0 && index <= length) {
                    for (int i = 5; i > index; i--) {
                        menu[i] = menu[i - 1];
                    }
                    printf("Nhap mon an: ");
                    getchar();  
                    fgets(menu[index].name, 100, stdin);
                    printf("Nhap gia: ");
                    scanf("%f", &menu[index].price);
                    length++;  
                } else {
                    printf("Moi ban nhap lai vi tri muon them\n");
                }
                break;
            case 3:
                printf("Nhap vi tri muon sua: ");
                scanf("%d", &index);
                if (index >= 0 && index < length) {
                    printf("Nhap ten mon thay the: ");
                    fgets(menu[index].name, 100, stdin);
                    printf("Nhap gia mon an moi: ");
                    scanf("%f", &menu[index].price);
                } else {
                    printf("Moi ban nhap lai vi tri trong menu\n");
                }
                break;
            case 4:
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &index);
                if (index >= 0 && index < length) {
                    for (int i = index; i < length - 1; i++) {
                        menu[i] = menu[i + 1];
                    }
                    length--;  
                } else {
                    printf("Moi ban nhap lai vi tri\n");
                }
                break;
            case 5:
                for (int i = 0; i < length ; i++) {
                    for (int j = 0; j < length-1-i; j++) {
                        if (menu[j].price > menu[j+1].price) {
                            struct Dish temp = menu[j];
                            menu[i] = menu[j+1];
                            menu[j] = temp;
                        }
                    }
                }
                break;
            case 6:
                printf("Nhap ten mon an can tim: ");
                getchar();
                fgets(nameSearch, 100, stdin);
                int found = -1;
                for (int i = 0; i < length; i++) {
                    if (strcmp(menu[i].name, nameSearch) == 0) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    printf("Tim thay mon an tai vi tri %d trong menu:\n", found + 1);
                    printf("%d: %s %f\n", menu[found].id, menu[found].name, menu[found].price);
                } else {
                    printf("Mon an khong co trong menu\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le vui long chon lai\n");
        }
    }
}
