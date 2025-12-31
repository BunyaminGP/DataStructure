#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

char stack[MAX];
int top = -1;

/*
 Stack islemleri
 Basit bir dizi kullanarak stack oluşturdum
*/
void push(char x) {
    if (top >= MAX - 1) return;
    stack[++top] = x;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

/*
 Operator onceliklerini belirleyen fonksiyon
 Buyuk sayi = daha yuksek oncelik
*/
int oncelik(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

/*
 ^ operatoru sağ birlesimlidir
 Diğer operatorler sol birleşimlidir
*/
int sagBirlesimliMi(char op) {
    return op == '^';
}

int operatorMu(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

/*
 Infix ifadeyi Shunting Yard algoritmasi ile
 postfix ifadeye dönüştürür.
*/
void infixToPostfix(char *exp) {
    char cikti[MAX];
    int k = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // Bosluklari gormezden geliyorum
        if (isspace((unsigned char)c)) continue;

        // Harf veya rakam ise direkt ciktiya eklenir
        if (isalnum((unsigned char)c)) {
            cikti[k++] = c;
        }
        // Sol parantez stack'e atilir
        else if (c == '(') {
            push(c);
        }
        // Sağ parantez gelirse sol paranteze kadar pop yapılır.
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                cikti[k++] = pop();
            }
            if (top != -1) pop(); // Sol parantez atilir
        }
        // Operator ise oncelik ve birleşimlilik kontrol edilir.
        else if (operatorMu(c)) {

            while (top != -1 && operatorMu(peek())) {
                char tepe = peek();

                int pTop = oncelik(tepe);
                int pCur = oncelik(c);

                /*
                 Sol birleşimli operatorlerde >=
                 Sağ birleşimli (^) operatorunde >
                */
                if ((!sagBirlesimliMi(c) && pTop >= pCur) ||
                    ( sagBirlesimliMi(c) && pTop >  pCur)) {
                    cikti[k++] = pop();
                } else {
                    break;
                }
            }
            push(c);
        }
    }

    // Stack'te kalan operatorler çıktıya eklenir.
    while (top != -1) {
        char t = pop();
        if (t != '(') cikti[k++] = t;
    }

    cikti[k] = '\0';
    printf("Postfix Ifade: %s\n", cikti);
}

int main() {
    char ifade[] = "a+b*(c^d-e)^(f+g*h)-i";

    // Ornek infix ifade ile test ediliyor
    printf("Infix Ifade: %s\n", ifade);
    infixToPostfix(ifade);

    return 0;
}
