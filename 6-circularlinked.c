#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* dugumOlustur(int veri) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = veri;
    yeni->next = yeni; 
    return yeni;
}

void yazdir(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

void arayaEkle(struct Node* head, int sonra, int eklenecek) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        if (temp->data == sonra) {
            struct Node* yeni = dugumOlustur(eklenecek);
            yeni->next = temp->next;
            temp->next = yeni;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

struct Node* sil(struct Node* head, int silinecek) {
    if (head == NULL) return NULL;

    struct Node* temp = head;
    struct Node* onceki = NULL;

    if (head->next == head && head->data == silinecek) {
        free(head);
        return NULL;
    }

    do {
        if (temp->data == silinecek) {
            if (temp == head) {
                // head siliniyorsa
                onceki = head;
                while (onceki->next != head)
                    onceki = onceki->next;

                head = head->next;
                onceki->next = head;
            } else {
                onceki->next = temp->next;
            }
            free(temp);
            return head;
        }
        onceki = temp;
        temp = temp->next;
    } while (temp != head);

    return head;
}

int main() {
    struct Node* head = dugumOlustur(1);
    struct Node* ikinci = dugumOlustur(2);
    struct Node* ucuncu = dugumOlustur(3);

    head->next = ikinci;
    ikinci->next = ucuncu;
    ucuncu->next = head;

    yazdir(head);

    arayaEkle(head, 1, 4);
    yazdir(head);

    head = sil(head, 4);
    yazdir(head);

    head = sil(head, 3);
    yazdir(head);

    return 0;
}
