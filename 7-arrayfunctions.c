#include <stdio.h>

#define MAX 100

void yazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

void ekle(int dizi[], int *boyut, int index, int deger) {
    if (*boyut >= MAX) return;
    if (index < 0 || index > *boyut) return;

    // Elemanlari saga kaydir
    for (int i = *boyut; i > index; i--) {
        dizi[i] = dizi[i - 1];
    }

    dizi[index] = deger;
    (*boyut)++;
}


void sil(int dizi[], int *boyut, int index) {
    if (*boyut <= 0) return;
    if (index < 0 || index >= *boyut) return;

    for (int i = index; i < *boyut - 1; i++) {
        dizi[i] = dizi[i + 1];
    }

    (*boyut)--;
}

int main() {
    int dizi[MAX] = {1, 2, 3, 4};
    int boyut = 4;

    yazdir(dizi, boyut);


    ekle(dizi, &boyut, 2, 5);
    yazdir(dizi, boyut);

    sil(dizi, &boyut, 3);
    yazdir(dizi, boyut);

    return 0;
}
