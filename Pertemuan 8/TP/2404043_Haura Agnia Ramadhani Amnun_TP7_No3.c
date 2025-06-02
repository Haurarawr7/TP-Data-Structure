
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nama[50];      // Menyimpan nama pelanggan
    char nomor_meja[10]; // Menyimpan nomor meja pelanggan
} Pelanggan;

typedef struct {
    Pelanggan stack[100]; // Menyimpan stack pelanggan
    int top; // Menyimpan indeks teratas stack
} StackPelanggan;

void initStack(StackPelanggan *stack) { // Inisialisasi stack
    stack->top = -1; // Stack kosong
}

int isFull(StackPelanggan *stack) { // Memeriksa apakah stack penuh
    return stack->top >= 100 - 1;
}

int isEmpty(StackPelanggan *stack) { // Memeriksa apakah stack kosong
    return stack->top < 0;
}

void push(StackPelanggan *stack, Pelanggan pelanggan) { // Menambahkan pelanggan ke stack
    if (!isFull(stack)) {
        stack->stack[++(stack->top)] = pelanggan;
    } else {
        printf("Stack sudah penuh, tidak bisa menambahkan pelanggan %s.\n", pelanggan.nama);
    }
}

Pelanggan pop(StackPelanggan *stack) { // Mengambil pelanggan dari stack
    if (!isEmpty(stack)) {
        return stack->stack[(stack->top)--];
    } else {
        Pelanggan kosong = {"", ""}; // Mengembalikan pelanggan kosong jika stack kosong
        printf("Stack kosong, tidak ada pelanggan yang bisa dilayani.\n");
        return kosong;
    }
}

int main() {
    StackPelanggan stack;
    initStack(&stack); // Inisialisasi stack

    int jumlah_pelanggan;
    printf("Masukkan jumlah pelanggan: ");
    scanf("%d", &jumlah_pelanggan);

    for (int i = 0; i < jumlah_pelanggan; i++) {
        Pelanggan pelanggan;
        printf("Data Pelanggan ke-%d:\n", i + 1);
        printf("Nama: ");
        scanf("%s", pelanggan.nama);
        printf("Nomor Meja: ");
        scanf("%s", pelanggan.nomor_meja);
        push(&stack, pelanggan); // Menambahkan pelanggan ke stack
    }

    // Melayani pelanggan satu per satu
    while (!isEmpty(&stack)) {
        Pelanggan dilayani = pop(&stack);
        printf("Melayani Pelanggan: %s\n", dilayani.nama);
        printf("Nomor Meja: %s\n", dilayani.nomor_meja);
    }

    return 0;
}