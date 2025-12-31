#include <stdio.h>

#define MAX 1000

typedef struct {
    int dizi[MAX];
    int boyut;
} Heap;

// Ortak fonksiyonlar

// İki elemanı yer değiştirir
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapYazdir(Heap *h) {
    printf("Heap: ");
    for (int i = 0; i < h->boyut; i++) {
        printf("%d ", h->dizi[i]);
    }
    printf("\n");
}

// Max heap fonksiyonları


void maxHeapifyAsagi(Heap *h, int i) {
    while (1) {
        int sol = 2 * i + 1;
        int sag = 2 * i + 2;
        int enBuyuk = i;

        if (sol < h->boyut && h->dizi[sol] > h->dizi[enBuyuk]) enBuyuk = sol;
        if (sag < h->boyut && h->dizi[sag] > h->dizi[enBuyuk]) enBuyuk = sag;

        if (enBuyuk == i) break;
        swap(&h->dizi[i], &h->dizi[enBuyuk]);
        i = enBuyuk;
    }
}


void maxHeapifyYukari(Heap *h, int i) {
    while (i > 0) {
        int ebeveyn = (i - 1) / 2;
        if (h->dizi[ebeveyn] >= h->dizi[i]) break;
        swap(&h->dizi[ebeveyn], &h->dizi[i]);
        i = ebeveyn;
    }
}

void maxHeapEkle(Heap *h, int deger) {
    if (h->boyut >= MAX) {
        printf("Hata: Heap dolu!\n");
        return;
    }
    h->dizi[h->boyut] = deger;
    maxHeapifyYukari(h, h->boyut);
    h->boyut++;
}

int maxHeapCikar(Heap *h) {
    if (h->boyut <= 0) {
        printf("Hata: Heap bos!\n");
        return -1;
    }
    int kok = h->dizi[0];
    h->boyut--;
    h->dizi[0] = h->dizi[h->boyut];
    maxHeapifyAsagi(h, 0);
    return kok;
}

// Minimum Heap fonksiyonları


void minHeapifyAsagi(Heap *h, int i) {
    while (1) {
        int sol = 2 * i + 1;
        int sag = 2 * i + 2;
        int enKucuk = i;

        if (sol < h->boyut && h->dizi[sol] < h->dizi[enKucuk]) enKucuk = sol;
        if (sag < h->boyut && h->dizi[sag] < h->dizi[enKucuk]) enKucuk = sag;

        if (enKucuk == i) break;
        swap(&h->dizi[i], &h->dizi[enKucuk]);
        i = enKucuk;
    }
}

void minHeapifyYukari(Heap *h, int i) {
    while (i > 0) {
        int ebeveyn = (i - 1) / 2;
        if (h->dizi[ebeveyn] <= h->dizi[i]) break;
        swap(&h->dizi[ebeveyn], &h->dizi[i]);
        i = ebeveyn;
    }
}


void minHeapEkle(Heap *h, int deger) {
    if (h->boyut >= MAX) {
        printf("Hata: Heap dolu!\n");
        return;
    }
    h->dizi[h->boyut] = deger;
    minHeapifyYukari(h, h->boyut);
    h->boyut++;
}


int minHeapCikar(Heap *h) {
    if (h->boyut <= 0) {
        printf("Hata: Heap bos!\n");
        return -1;
    }
    int kok = h->dizi[0];
    h->boyut--;
    h->dizi[0] = h->dizi[h->boyut];
    minHeapifyAsagi(h, 0);
    return kok;
}

int main() {
    Heap maxH = {.boyut = 0};
    Heap minH = {.boyut = 0};

    int sayilar[] = {10, 4, 15, 20, 0, 7, 8};
    int n = (int)(sizeof(sayilar) / sizeof(sayilar[0]));

    // Max-Heap test
    printf("MAX HEAP TEST\n");
    for (int i = 0; i < n; i++) maxHeapEkle(&maxH, sayilar[i]);
    heapYazdir(&maxH);
    printf("Cikan (max): %d\n", maxHeapCikar(&maxH));
    heapYazdir(&maxH);

    printf("\nMIN HEAP TEST\n");
    for (int i = 0; i < n; i++) minHeapEkle(&minH, sayilar[i]);
    heapYazdir(&minH);
    printf("Cikan (min): %d\n", minHeapCikar(&minH));
    heapYazdir(&minH);

    return 0;
}
