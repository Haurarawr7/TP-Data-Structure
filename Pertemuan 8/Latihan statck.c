
//Program stack 1
// Oleh /haura Agnia Ramadhani Amnun

/* 
1. Buatlah program yang meminta user memasukkan sebuah kata, lalu program akan
memballikkan kata tersebut menggunakan stack
Input:
Masukkan kata: HELLO
Output:
Kata setelah dibalik: OLLEH 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) { //inisialisasi ulang biar gak langsung berhenti
    s->top = -1;
}

int isFull(Stack *s) { // klo full
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) { //klo kosong
    return s->top < 0;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    } else {
        printf("Stack penuh!\n");
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack kosong!\n");
    }
}

void balik(Stack *s, char *kata) {
    // Push setiap karakter dari kata ke stack
    for (int i = 0; i < strlen(kata); i++) {
        push(s, kata[i]);
    }
    
    // Pop karakter dari stack untuk membalikkan kata
    printf("Kata setelah dibalik: ");
    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }
    printf("\n");
}

int main() {
    Stack s;
    char kata[20];
    char jawaban;

    do {
        initStack(&s); 
        printf("Masukkan kata: ");
        scanf("%s", kata);
        
        balik(&s, kata);

        printf("Apakah ingin mengulangi kembali? (Y/N): ");
        scanf(" %c", &jawaban); \
        
    } while (jawaban == 'Y' || jawaban == 'y'); // Perbaikan logika di sini

    printf("Terima kasih!\n");
    return 0;
}
