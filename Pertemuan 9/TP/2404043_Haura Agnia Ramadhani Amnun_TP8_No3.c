
//Program alat bantu anak-anak
//Haura Agnia Ramadhani Amnun

/*
 Dr. Aether mengembangkan alat bantu edukatif untuk anak-anak yang sedang
belajar komputer dasar. Salah satu fitur alat tersebut adalah mengubah bilangan
biner ke desimal dengan pendekatan visual menggunakan antrian (queue). Ia ingin
Anda membuat program sederhana untuk mensimulasikan fitur ini.
Ketentuan:
• Masukkan bilangan biner sebagai string (misal: 11001).
• Setiap digit dimasukkan ke dalam queue satu per satu.
• Gunakan antrian untuk membaca digit dari depan dan konversi ke desimal.
• Tampilkan hasil akhirnya.
Input:
11001
Output:
25
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//lucu banget aether jai dokter ekhm

#define MAXQUEUESIZE 32 // Ukuran maksimum antrian

typedef struct {
    char items[MAXQUEUESIZE];
    int front;
    int tail; 
} Queue;

// Fungsi untuk menginisialisasi antrian
void initQueue(Queue* q) {
    q->front = -1;
    q->tail = -1; 
}

// Fungsi untuk memeriksa apakah antrian kosong
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Fungsi untuk memeriksa apakah antrian penuh
int isFull(Queue* q) {
    return (q->tail == MAXQUEUESIZE - 1); 
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueue(Queue* q, char item) {
    if (isFull(q)) {
        printf("Antrian penuh!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->tail++; // Mengganti rear dengan tail
    q->items[q->tail] = item;
}

// Fungsi untuk menghapus elemen dari antrian
char dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Antrian kosong!\n");
        return '\0'; // Mengembalikan karakter null jika antrian kosong
    }
    char item = q->items[q->front];
    q->front++;
    if (q->front > q->tail) {
        // Reset antrian jika sudah kosong
        q->front = -1;
        q->tail = -1; // Mengganti rear dengan tail
    }
    return item;
}

// Fungsi untuk mengonversi bilangan biner ke desimal
int binaryToDecimal(Queue* q) {
    int decimal = 0;
    int base = 1; // 2^0

    // Menghitung panjang antrian
    int length = q->tail - q->front + 1; // Mengganti rear dengan tail

    // Membaca dari antrian dan mengonversi
    for (int i = length - 1; i >= 0; i--) {
        char digit = dequeue(q);
        if (digit == '1') {
            decimal += base;
        }
        base *= 2; // Menaikkan basis (2^i)
    }

    return decimal;
}

int main() {
    char binaryString[33]; // Buffer untuk menyimpan string biner
    Queue q;

    // Inisialisasi antrian
    initQueue(&q);

    // Input bilangan biner
    printf("Masukkan bilangan biner: ");
    scanf("%s", binaryString);

    // Memasukkan setiap digit ke dalam antrian
    for (int i = 0; i < strlen(binaryString); i++) {
        // Memeriksa apakah input valid (hanya '0' dan '1')
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            printf("Input tidak valid! Hanya boleh menggunakan '0' dan '1'.\n");
            return 1; // Keluar dari program jika input tidak valid
        }
        enqueue(&q, binaryString[i]);
    }

    // Mengonversi bilangan biner ke desimal
    int decimalValue = binaryToDecimal(&q);

    // Menampilkan hasil
    printf("Output: %d\n", decimalValue);

    int recalculatedDecimal = 0;
    for (int i = 0; i < strlen(binaryString); i++) {
        if (binaryString[i] == '1') {
            recalculatedDecimal += pow(2, strlen(binaryString) - 1 - i);
        }
    }
    printf("Recalculated Output (inefficient): %d\n", recalculatedDecimal);

    return 0;
}