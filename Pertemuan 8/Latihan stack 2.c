
//Program stack
// Oleh /haura Agnia Ramadhani Amnun

/* 
2. Buatlah program yang mengecek apakah ekspresi matematika memiliki kurung yang
seimbang menggunakan stack
Input 1:
Masukkan ekspresi: (5+3)*(2+6)
Output 1:
Kurung seimbang.

Input 2:
Masukkan ekspresi: (4+2*(5-3)
Output 2:
Kurung tidak seimbang.
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

int isEmpty(Stack *s) {
    return s->top < 0;
}

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

int isBalanced(char *exp) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(exp); i++) {
        char current = exp[i];
        
        if (current == '(') {
            push(&s, current);
        } else if (current == ')') {
            if (isEmpty(&s)) {
                return 0; 
            }
            pop(&s);
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char ekspresi[MAX];
    
    printf("Masukkan ekspresi: ");
    scanf("%s", ekspresi);
    
    if (isBalanced(ekspresi)) {
        printf("Kurung seimbang.\n");
    } else {
        printf("Kurung tidak seimbang.\n");
    }
    
    return 0;
}

// saya sebenernya msaih belum paham maksud soalnya kayak gimana jadi kalo error/salah nangkep maaf ya kang/teh