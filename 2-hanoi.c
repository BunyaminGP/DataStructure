#include <stdio.h>

// Tower of Hanoi recursive fonksiyonu
// n: disk sayisi, k: kaynak, y: yardimci, h: hedef
void hanoi(int n, char k, char y, char h) {

    // Temel durum: tek disk varsa doğrudan hedefe taşınır.
    if (n == 1) {
        printf("Disk 1: %c -> %c tasindi\n", k, h);
        return;
    }

    // n-1 diski kaynaktan yardimciya taşı.
    hanoi(n - 1, k, h, y);

    // En büyük diski kaynaktan hedefe taşı.
    printf("Disk %d: %c -> %c tasindi\n", n, k, h);

    // n-1 diski yardimcidan hedefe taşı.
    hanoi(n - 1, y, k, h);
}

int main() {
    int diskSayisi = 3;

    // A: kaynak, B: yardimci, C: hedef
    hanoi(diskSayisi, 'A', 'B', 'C');

    return 0;
}
