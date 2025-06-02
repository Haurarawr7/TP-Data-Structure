
//Program stack
// Oleh /haura Agnia Ramadhani Amnun

/* 
3. Buatlah program yang menerima sebuah kata dari user dan menggunakan Stack untuk
mengecek apakah kata tersebut adalah palindrom.
Input 1:
KATAK
Output 1:
Palindrom

Input 2:
HELLO
Output 2:
Bukan Palindrom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
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
    } 
}

int isPalindrome(char *kata) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(kata); i++) {
        push(&s, kata[i]);
    }
    
    // Cek palindrom
    for (int i = 0; i < strlen(kata); i++) {
        if (pop(&s) != kata[i]) {
            return 0; // bukan palindrom
        }
    }
    
    return 1; // Palindrom
}

int main() {
    char kata[MAX];
    
    printf("Masukkan kata: ");
    scanf("%s", kata);
    
    if (isPalindrome(kata)) {
        printf("Palindrom\n");
    } else {
        printf("Bukan Palindrom\n");
    }
    
    return 0;
}