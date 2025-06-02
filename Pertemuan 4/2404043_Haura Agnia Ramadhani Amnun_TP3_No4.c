
//Program Ururan keberangkatan Kereta Api
//Oleh Haura Agnia Ramadhani Amnun

/*
4. Sebuah perusahaan kereta api ingin membuat sistem untuk mengatur urutan
keberangkatan penumpang di berbagai stasiun. Setiap penumpang memiliki nama,
nomor tiket, kondisi (darurat, reguler, sebelum, sesudah), stasiun keberangkatan.
Pengguna dapat menambahkan penumpang ke dalam daftar berdasarkan metode
berikut:
a. Tambah penumpang:
i. Tambah di awal daftar (untuk penumpang yang memiliki jadwal keberangkatan
lebih awal atau keadaan darurat)
ii. Tambah di akhir daftar (untuk penumpang reguler yang mengikuti antrian
normal)
iii. Tambah sebelum penumpang tertentu (untuk penumpang yang ingin masuk
sebelum penumpang lain karena kondisi tertentu)
iv. Tambah setelah penumpang tertentu (agar keluarga atau teman dalam satu
kelompok dapat berangkat bersama)
b. Pengguna dapat melihat daftar penumpang berdasarkan urutan keberangkatan.
c. Program berjalan hingga pengguna memilih keluar.
Contoh Input & Output:
=== Sistem Manajemen Perjalanan Kereta Api ===
1. Tambah Penumpang
2. Tampilkan Daftar Penumpang
3. Keluar
Pilih menu: 1
Masukkan nama penumpang: Siti
Masukkan nomor tiket: K123
Masukkan stasiun keberangkatan: Stasiun Gambir
Masukkan kondisi: reguler
Penumpang Siti berhasil ditambahkan dengan prioritas reguler!
Pilih menu: 1
Masukkan nama penumpang: Agus
Masukkan nomor tiket: K122
Masukkan stasiun keberangkatan: Stasiun Gambir
Masukkan kondisi: sebelum
Masukkan nama penumpang sebelum siapa ingin ditambahkan? Siti
Penumpang Agus berhasil ditambahkan sebelum Siti!
Pilih menu: 2
Daftar Penumpang:
1. Agus - Tiket K122 - Stasiun Gambir - sebelum
2. Siti - Tiket K123 - Stasiun Gambir - reguler
Pilih menu: 3
Keluar dari program...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Penumpang {
    char nama[50];
    char nomorTiket[20];
    char stasiunKeberangkatan[50];
    char kondisi[20];
    struct Penumpang* next;
} Penumpang;

Penumpang* head = NULL;

// Fungsi untuk menambahkan penumpang di awal daftar
void tambahPenumpangAwal(char* nama, char* nomorTiket, char* stasiunKeberangkatan, char* kondisi) {
    Penumpang* penumpangBaru = (Penumpang*)malloc(sizeof(Penumpang));
    strcpy(penumpangBaru->nama, nama);
    strcpy(penumpangBaru->nomorTiket, nomorTiket);
    strcpy(penumpangBaru->stasiunKeberangkatan, stasiunKeberangkatan);
    strcpy(penumpangBaru->kondisi, kondisi);
    penumpangBaru->next = head;
    head = penumpangBaru;
    printf("Penumpang %s berhasil ditambahkan dengan prioritas %s!\n", nama, kondisi);
}

// Fungsi untuk menambahkan penumpang di akhir daftar
void tambahPenumpangAkhir(char* nama, char* nomorTiket, char* stasiunKeberangkatan, char* kondisi) {
    Penumpang* penumpangBaru = (Penumpang*)malloc(sizeof(Penumpang));
    strcpy(penumpangBaru->nama, nama);
    strcpy(penumpangBaru->nomorTiket, nomorTiket);
    strcpy(penumpangBaru->stasiunKeberangkatan, stasiunKeberangkatan);
    strcpy(penumpangBaru->kondisi, kondisi);
    penumpangBaru->next = NULL;

    if (head == NULL) {
        head = penumpangBaru;
    } else {
        Penumpang* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = penumpangBaru;
    }
    printf("Penumpang %s berhasil ditambahkan dengan prioritas %s!\n", nama, kondisi);
}

// Fungsi untuk menambahkan penumpang sebelum penumpang tertentu
void tambahPenumpangSebelum(char* namaBaru, char* nomorTiket, char* stasiunKeberangkatan, char* kondisi, char* namaSebelum) {
    Penumpang* penumpangBaru = (Penumpang*)malloc(sizeof(Penumpang));
    strcpy(penumpangBaru->nama, namaBaru);
    strcpy(penumpangBaru->nomorTiket, nomorTiket);
    strcpy(penumpangBaru->stasiunKeberangkatan, stasiunKeberangkatan);
    strcpy(penumpangBaru->kondisi, kondisi);

    if (head == NULL) {
        printf("Daftar penumpang kosong!\n");
        free(penumpangBaru);
        return;
    }

    if (strcmp(head->nama, namaSebelum) == 0) {
        penumpangBaru->next = head;
        head = penumpangBaru;
        printf("Penumpang %s berhasil ditambahkan sebelum %s!\n", namaBaru, namaSebelum);
        return;
    }

    Penumpang* temp = head;
    while (temp->next != NULL && strcmp(temp->next->nama, namaSebelum) != 0) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Penumpang dengan nama %s tidak ditemukan!\n", namaSebelum);
        free(penumpangBaru);
    } else {
        penumpangBaru->next = temp->next;
        temp->next = penumpangBaru;
        printf("Penumpang %s berhasil ditambahkan sebelum %s!\n", namaBaru, namaSebelum);
    }
}

// Fungsi untuk menambahkan penumpang setelah penumpang tertentu
void tambahPenumpangSetelah(char* namaBaru, char* nomorTiket, char* stasiunKeberangkatan, char* kondisi, char* namaSetelah) {
    Penumpang* penumpangBaru = (Penumpang*)malloc(sizeof(Penumpang));
    strcpy(penumpangBaru->nama, namaBaru);
    strcpy(penumpangBaru->nomorTiket, nomorTiket);
    strcpy(penumpangBaru->stasiunKeberangkatan, stasiunKeberangkatan);
    strcpy(penumpangBaru->kondisi, kondisi);

    if (head == NULL) {
        printf("Daftar penumpang kosong!\n");
        free(penumpangBaru);
        return;
    }

    Penumpang* temp = head;
    while (temp != NULL && strcmp(temp->nama, namaSetelah) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Penumpang dengan nama %s tidak ditemukan!\n", namaSetelah);
        free(penumpangBaru);
    } else {
        penumpangBaru->next = temp->next;
        temp->next = penumpangBaru;
        printf("Penumpang %s berhasil ditambahkan setelah %s!\n", namaBaru, namaSetelah);
    }
}

// Fungsi untuk menampilkan daftar penumpang
void tampilkanDaftarPenumpang() {
    if (head == NULL) {
        printf("Tidak ada penumpang yang terdaftar.\n");
        return;
    }

    printf("Daftar Penumpang:\n");
    int nomor = 1;
    Penumpang* temp = head;
    while (temp != NULL) {
        printf("%d. %s - Tiket %s - %s - %s\n", nomor++, temp->nama, temp->nomorTiket, temp->stasiunKeberangkatan, temp->kondisi);
        temp = temp->next;
    }
}

// Fungsi utama
int main() {
    int pilihan;
    char nama[50];
    char nomorTiket[20];
    char stasiunKeberangkatan[50];
    char kondisi[20];
    char namaSebelum[50];
    char namaSetelah[50];

    do {
        printf("=== Sistem Manajemen Perjalanan Kereta Api ===\n");
        printf("1. Tambah Penumpang\n");
        printf("2. Tampilkan Daftar Penumpang\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus newline setelah input angka

        switch (pilihan) {
            case 1:
                printf("Masukkan nama penumpang: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                getchar();
                printf("Masukkan nomor tiket: ");
                fgets(nomorTiket, sizeof(nomorTiket), stdin);
                nomorTiket[strcspn(nomorTiket, "\n")] = 0; // Menghapus newline
                getchar();
                printf("Masukkan stasiun keberangkatan: ");
                fgets(stasiunKeberangkatan, sizeof(stasiunKeberangkatan), stdin);
                stasiunKeberangkatan[strcspn(stasiunKeberangkatan, "\n")] = 0; // Menghapus newline
                getchar();
                printf("Masukkan kondisi (darurat, reguler, sebelum, sesudah): ");
                fgets(kondisi, sizeof(kondisi), stdin);
                kondisi[strcspn(kondisi, "\n")] = 0; // Menghapus newline

                if (strcmp(kondisi, "darurat") == 0) {
                    tambahPenumpangAwal(nama, nomorTiket, stasiunKeberangkatan, kondisi);
                } else if (strcmp(kondisi, "reguler") == 0) {
                    tambahPenumpangAkhir(nama, nomorTiket, stasiunKeberangkatan, kondisi);
                } else if (strcmp(kondisi, "sebelum") == 0) {
                    printf("Masukkan nama penumpang sebelum siapa ingin ditambahkan? ");
                    fgets(namaSebelum, sizeof(namaSebelum), stdin);
                    namaSebelum[strcspn(namaSebelum, "\n")] = 0; // Menghapus newline
                    tambahPenumpangSebelum(nama, nomorTiket, stasiunKeberangkatan, kondisi, namaSebelum);
                } else if (strcmp(kondisi, "sesudah") == 0) {
                    printf("Masukkan nama penumpang setelah siapa ingin ditambahkan? ");
                    fgets(namaSetelah, sizeof(namaSetelah), stdin);
                    namaSetelah[strcspn(namaSetelah, "\n")] = 0; // Menghapus newline
                    tambahPenumpangSetelah(nama, nomorTiket, stasiunKeberangkatan, kondisi , namaSetelah);
                } else {
                    printf("Kondisi tidak valid! Silakan coba lagi.\n");
                }
                break;
            case 2:
                tampilkanDaftarPenumpang();
                break;
            case 3:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 3);

    // Membebaskan memori yang digunakan oleh daftar penumpang
    Penumpang* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

//Apa aku nyerah aja ya...