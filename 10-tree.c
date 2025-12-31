#include <stdio.h>

#define MAX 200
#define BOS -1

int tree[MAX];
int n;

// Root - Left - Right
void preorder(int i) {
    if (i >= n || tree[i] == BOS) return;
    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

// Left - Root - Right
void inorder(int i) {
    if (i >= n || tree[i] == BOS) return;
    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

// Left - Right - Root
void postorder(int i) {
    if (i >= n || tree[i] == BOS) return;
    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

// Level-order: Diziyi soldan saga yazmak
void levelorder() {
    for (int i = 0; i < n; i++) {
        if (tree[i] != BOS) printf("%d ", tree[i]);
    }
}

int main() {
    printf("Dizinin boyutu (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Gecersiz n!\n");
        return 0;
    }

    // -1 = bos dugum
    printf("Dugumleri gir (bos icin -1):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("\nPreorder: ");
    preorder(0);

    printf("\nInorder: ");
    inorder(0);

    printf("\nPostorder: ");
    postorder(0);

    printf("\nLevelorder: ");
    levelorder();

    printf("\n");
    return 0;
}
