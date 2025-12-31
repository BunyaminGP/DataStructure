#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next; // ileri
    struct Node* prev; // geri
};

struct Node* dugumOlustur(int veri) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = veri;
    yeni->next = NULL;
    yeni->prev = NULL;
    return yeni;
}

void yazdir(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void arayaEkle(struct Node* head, int sonra, int eklenecek) {
    while (head != NULL && head->data != sonra) {
        head = head->next;
    }
    if (head == NULL) return;

    struct Node* yeni = dugumOlustur(eklenecek);

    yeni->next = head->next;
    yeni->prev = head;

    if (head->next != NULL)
        head->next->prev = yeni;

    head->next = yeni;
}


struct Node* sil(struct Node* head, int silinecek) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != silinecek) {
        temp = temp->next;
    }
    if (temp == NULL) return head;

    if (temp == head) {
        head = temp->next;
        if (head != NULL) head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

int main() {
    struct Node* head = dugumOlustur(45);
    struct Node* ikinci = dugumOlustur(46);
    struct Node* ucuncu = dugumOlustur(47);

    head->next = ikinci;
    ikinci->prev = head;
    ikinci->next = ucuncu;
    ucuncu->prev = ikinci;

    yazdir(head);
    arayaEkle(head, 46,48);
    yazdir(head);
    head = sil(head, 45);
    yazdir(head);

    return 0;
}
