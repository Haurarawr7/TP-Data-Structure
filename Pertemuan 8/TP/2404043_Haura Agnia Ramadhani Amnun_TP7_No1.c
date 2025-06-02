#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char merek[50];
} Sepatu;

typedef struct {
    Sepatu rak[6];
    int top;
} RakSepatu;

void initRak(RakSepatu *rak) { // Inisialisasi rak
    rak->top = -1; // Rak kosong
}

int isFull(RakSepatu *rak) { // Memeriksa apakah rak penuh
    return rak->top == 6 - 1;
}

int isEmpty(RakSepatu *rak) { // Memeriksa apakah rak kosong
    return rak->top < 0;
}

void tambahSepatu(RakSepatu *rak, const char *merek) { // Menambahkan sepatu ke rak
    if (!isFull(rak)) {
        rak->top++;
        strcpy(rak->rak[rak->top].merek, merek);
        printf("Sepatu '%s' ditambahkan ke rak.\n", merek);
    } else {
        printf("Rak sudah penuh, tidak bisa menambahkan sepatu '%s'.\n", merek);
    }
}

void ambilSepatu(RakSepatu *rak) { // Mengambil sepatu dari rak
    if (!isEmpty(rak)) {
        printf("Sepatu '%s' diambil dari rak.\n", rak->rak[rak->top].merek);
        rak->top--;
    } else {
        printf("Rak kosong, tidak ada sepatu yang bisa diambil.\n");
    }
}

void tampilkanRak(RakSepatu *rak) { // Menampilkan isi rak
    if (!isEmpty(rak)) {
        printf("Isi rak (dari atas ke bawah):\n");
        for (int i = rak->top; i >= 0; i--) {
            printf("%s\n", rak->rak[i].merek);
        }
    } else {
        printf("Rak kosong.\n");
    }
}

int main() {
    RakSepatu rak;
    initRak(&rak); // Inisialisasi rak
    char merek[50];
    char jawaban;

    // Menambahkan sepatu dari input pengguna
    do {
        printf("Masukkan merek sepatu yang ingin ditambahkan (maksimal 50 karakter): ");
        scanf("%s", merek);
        tambahSepatu(&rak, merek);

        printf("Apakah Anda ingin menambahkan sepatu lagi? (Y/N): ");
        scanf(" %c", &jawaban); // Spasi sebelum %c untuk mengabaikan karakter newline
    } while (jawaban == 'Y' || jawaban == 'y');

    // Mengambil sepatu dari rak
    printf("Apakah Anda ingin mengambil sepatu dari rak? (Y/N): ");
    scanf(" %c", &jawaban);
    if (jawaban == 'Y' || jawaban == 'y') {
        ambilSepatu(&rak);
    }

    // Tampilkan isi rak
    tampilkanRak(&rak);

    return 0;
}