#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cake{
    char code[4][6] = {"CK001", "CK009", "CK017", "CK023"};
    char name[4][25] = {"Blueberry Cake", "Chocochip Cake", "Mayonaise Cake", "Strawberry ShortCake"};
    int stok[4] = {13, 5, 24, 7};
    double harga[4] = {25000, 20000, 30000, 175000};
};

int main(){
    cake shop1;
    int menu = 0;
    char cakeCode[6];
    int flag = 0, banyakBeli, banyakTambah;
    double total = 0;
    do{
        system("CLS");
        puts("BLUE CAKE SHOP CASHIER");
        puts("======================");
        puts("");             
        puts("No. | Cake Code | Cake Name            | Available | Price ");
        puts("---------------------------------------------------------------");
        printf("01. | CK001     | Blueberry Cake       | %9.d | Rp. 25000,-\n", shop1.stok[0]);
        printf("02. | CK009     | Chocochip Cake       | %9.d | Rp. 20000,-\n", shop1.stok[1]);
        printf("03. | CK017     | Mayonaise Cake       | %9.d | Rp. 30000,-\n", shop1.stok[2]);
        printf("04. | CK023     | Strawberry ShortCake | %9.d | Rp. 17500,-\n", shop1.stok[3]);
        puts("---------------------------------------------------------------\n");
        puts("");
        puts("Menu :");
        puts("1. Sell");
        puts("2. Add Stock");
        puts("3. Exit");
        printf("Input choice : ");
        scanf("%d", &menu); getchar();
        switch (menu){
        case 1:
            do{
                printf("\nInput Cake Code [5 chars]: ");
                scanf("%s", &cakeCode); getchar();
                for (int i = 0; i < 4; i++){
                    if (strcmp(cakeCode, shop1.code[i]) == 0){
                        flag = 1;
                        printf("Input Quality [0..%d]: ", shop1.stok[i]);
                        scanf("%d", &banyakBeli); getchar();
                        while (banyakBeli < 0 || banyakBeli > shop1.stok[i]){
                            puts("");
                            puts("...The quantity of cake is not enough...");
                            printf("Input Quality [0..%d]: ", shop1.stok[i]);
                            scanf("%d", &banyakBeli); getchar();
                        }
                        
                        puts("");
                        puts("");
                        int *kurangStok = &shop1.stok[i];
                        total = shop1.harga[i]*banyakBeli;

                        printf("Total price is : Rp %0.lf,- x %d = Rp %.0lf,-\n\n", shop1.harga[i], banyakBeli, total);
                        *kurangStok = shop1.stok[i] - banyakBeli;
                        puts(" --- Thank You ---");
                        break;
                    }
                }
                if (flag == 0){
                    printf("\n--- The Cake Code doesn't exist ---\n");
                    getchar();
                }

            } while (flag == 0);
            break;

        case 2:
            flag = 0;
            do{
                printf("\nInput Cake Code [5 chars]: ");
                scanf("%s", &cakeCode); getchar();
                for (int i = 0; i < 4; i++){
                    if (strcmp(cakeCode, shop1.code[i]) == 0){
                        flag = 1;
                        printf("Input Quality [0..10]: ");
                        scanf("%d", &banyakTambah); getchar();
                        while (banyakTambah < 0 || banyakTambah > 10){
                            printf("Input Quality [0..10]: ", shop1.stok[i]);
                            scanf("%d", &banyakTambah); getchar();
                        }
                        
                        puts("");
                        puts("");
                        int *addStok = &shop1.stok[i];
                        *addStok = shop1.stok[i] + banyakTambah;
                        puts("  --- Adding Stock Success ---");
                        getchar();
                        break;
                    }
                }
                if (flag == 0){
                    printf("\n--- The Cake Code doesn't exist ---\n");
                    getchar();
                }

            } while (flag == 0);
            break;
        }
    }while (menu != 3);

    return 0;
}

