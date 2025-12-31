#include <stdio.h>

#define MAX 100


void matrisOku(int mat[MAX][MAX], int satir, int sutun) {

    printf("Matrisi giriniz:\n");

    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int sifirOlmayanSayisiBul(int mat[MAX][MAX], int satir, int sutun) {

    int sayac = 0;
    
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (mat[i][j] != 0)
                sayac++;
        }
    }

    return sayac;
}

void sparseDonustur(int mat[MAX][MAX], int satir, int sutun, int sparse[MAX][3]) {
    int k = 1;
    int nonZero = sifirOlmayanSayisiBul(mat, satir, sutun);

    sparse[0][0] = satir;
    sparse[0][1] = sutun;
    sparse[0][2] = nonZero;



    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

}



// Sparse matrisi yazdırır.

void sparseYazdir(int sparse[MAX][3], int satirSayisi) {

    printf("\nSparse Matrix (Triplet Form):\n");
    printf("Satir\tSutun\tDeger\n");

    for (int i = 0; i < satirSayisi; i++) {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

}

int main() {

    int satir, sutun;
    int matris[MAX][MAX];
    int sparse[MAX][3];

    printf("Satir sayisini giriniz: ");
    scanf("%d", &satir);
    printf("Sutun sayisini giriniz: ");
    scanf("%d", &sutun);
    matrisOku(matris, satir, sutun);
    sparseDonustur(matris, satir, sutun, sparse);
    sparseYazdir(sparse, sparse[0][2] + 1);
    return 0;

}

