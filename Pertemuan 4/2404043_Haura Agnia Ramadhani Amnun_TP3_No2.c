
//Program Pendaftaran Pasien
//Oleh HauraAgnia Ramadhani Amnun

/*
Sebuah klinik kesehatan ingin mengembangkan sistem pendaftaran pasien
menggunakan bahasa pemrograman C. Sistem ini harus menggunakan Single Linked List
untuk menyimpan daftar pasien yang mendaftar. Setiap pasien memiliki nama, usia,
jenis kelamin, dan kategori. Adapun sistem harus memenuhi:
a. Tambah Pasien:
i. Pengguna dapat menambahkan pasien baru dengan memasukkan nama.
ii. Pasien dapat ditambahkan dengan pilihan berikut:
1. Tambah di awal daftar (prioritas)
2. Tambah di akhir daftar (pendaftaran biasa)
3. Tambah sebelum pasien tertentu (prioritas lebih tinggi dari pasien lain
yang telah terdaftar)
4. Tambah setelah pasien tertentu (agar pasien bisa berada di dekat anggota
keluarganya yang sudah terdaftar)

b. Tampilkan Daftar Pasien:
Menampilkan seluruh pasien dalam daftar dengan nama pasien dan detail yang lain.
c. Keluar dari Program:
Pengguna dapat keluar dari sistem jika tidak ingin menambah atau melihat daftar
pasien lagi.
Contoh Input & Output:
=== Sistem Antrian Pendaftaran Pasien ===
1. Tambah Pasien di Awal (Prioritas)
2. Tambah Pasien di Akhir (Pendaftaran Biasa)
3. Tambah Pasien Sebelum Pasien Tertentu
4. Tambah Pasien Setelah Pasien Tertentu
5. Tampilkan Daftar Pasien
6. Keluar
Pilih menu: 2
Masukkan nama pasien: Dudi
Masukkan usia pasien: 30
Masukkan jenis kelamin: L
Pasien Budi - Biasa berhasil ditambahkan!

Pilih menu: 2
Masukkan nama pasien: Siti
Masukkan usia pasien: 25
Masukkan jenis kelamin: P
Pasien Siti - Biasa berhasil ditambahkan!

Pilih menu: 3
Masukkan nama pasien: Pak Joko
Masukkan usia pasien: 50
Masukkan jenis kelamin: L
Masukkan nama pasien sebelum siapa ingin ditambahkan? Budi
Pasien Pak Joko - Sebelum berhasil ditambahkan sebelum Budi!

Pilih menu: 5
Daftar Pasien:
No Nama Usia Jenis Kelamin
1 Pak Joko 50 L
2 Dudi 30 L
3 Siti 25 P

Pilih menu: 6
Keluar dari program...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pasien {
    char nama[50];
    int usia;
    char jenisKelamin;
    struct Pasien* next;
} Pasien;

Pasien* head = NULL;

// Fungsi untuk menambahkan pasien di awal daftar
void tambahPasienAwal(char* nama, int usia, char jenisKelamin) {
    Pasien* pasienBaru = (Pasien*)malloc(sizeof(Pasien));
    strcpy(pasienBaru->nama, nama);
    pasienBaru->usia = usia;
    pasienBaru->jenisKelamin = jenisKelamin;
    pasienBaru->next = head;
    head = pasienBaru;
    printf("Pasien %s - Prioritas berhasil ditambahkan!\n", nama);
}

// Fungsi untuk menambahkan pasien di akhir daftar
void tambahPasienAkhir(char* nama, int usia, char jenisKelamin) {
    Pasien* pasienBaru = (Pasien*)malloc(sizeof(Pasien));
    strcpy(pasienBaru->nama, nama);
    pasienBaru->usia = usia;
    pasienBaru->jenisKelamin = jenisKelamin;
    pasienBaru->next = NULL;

    if (head == NULL) {
        head = pasienBaru;
    } else {
        Pasien* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pasienBaru;
    }
    printf("Pasien %s - Biasa berhasil ditambahkan!\n", nama);
}

// Fungsi untuk menambahkan pasien sebelum pasien tertentu
void tambahPasienSebelum(char* namaBaru, int usia, char jenisKelamin, char* namaSebelum) {
    Pasien* pasienBaru = (Pasien*)malloc(sizeof(Pasien));
    strcpy(pasienBaru->nama, namaBaru);
    pasienBaru->usia = usia;
    pasienBaru->jenisKelamin = jenisKelamin;

    if (head == NULL) {
        printf("Daftar pasien kosong!\n");
        free(pasienBaru);
        return;
    }

    if (strcmp(head->nama, namaSebelum) == 0) {
        pasienBaru->next = head;
        head = pasienBaru;
        printf("Pasien %s - Sebelum berhasil ditambahkan sebelum %s!\n", namaBaru, namaSebelum);
        return;
    }

    Pasien* temp = head;
    while (temp->next != NULL && strcmp(temp->next->nama, namaSebelum) != 0) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Pasien dengan nama %s tidak ditemukan!\n", namaSebelum);
        free(pasienBaru);
    } else {
        pasienBaru->next = temp->next;
        temp->next = pasienBaru;
        printf("Pasien %s - Sebelum berhasil ditambahkan sebelum %s!\n", namaBaru, namaSebelum);
    }
}

// Fungsi untuk menambahkan pasien setelah pasien tertentu
void tambahPasienSetelah(char* namaBaru, int usia, char jenisKelamin, char* namaSetelah) {
    Pasien* pasienBaru = (Pasien*)malloc(sizeof(Pasien));
    strcpy(pasienBaru->nama, namaBaru);
    pasienBaru->usia = usia;
    pasienBaru->jenisKelamin = jenisKelamin;

    if (head == NULL) {
        printf("Daftar pasien kosong!\n");
        free(pasienBaru);
        return;
    }

    Pasien* temp = head;
    while (temp != NULL && strcmp(temp->nama, namaSetelah) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Pasien dengan nama %s tidak ditemukan!\n", namaSetelah);
        free(pasienBaru);
    } else {
        pasienBaru->next = temp->next;
        temp->next = pasienBaru;
        printf("Pasien %s - Setelah berhasil ditambahkan setelah %s!\n", namaBaru, namaSetelah);
    }
}

// Fungsi untuk menampilkan daftar pasien
void tampilkanDaftarPasien() {
    if (head == NULL) {
        printf("Daftar pasien kosong!\n");
        return;
    }

    printf("Daftar Pasien:\n");
    printf("No Nama Usia Jenis Kelamin\n");
    Pasien* temp = head;
    int no = 1 ;
    while (temp != NULL) {
        printf("%d %s %d %c\n", no, temp->nama, temp->usia, temp->jenisKelamin);
        temp = temp->next;
        no++;
    }
}

// Fungsi utama
int main() {
    int pilihan;
    char nama[50];
    int usia;
    char jenisKelamin;
    char namaSebelum[50];
    char namaSetelah[50];

    do {
        printf("=== Sistem Antrian Pendaftaran Pasien ===\n");
        printf("1. Tambah Pasien di Awal (Prioritas)\n");
        printf("2. Tambah Pasien di Akhir (Pendaftaran Biasa)\n");
        printf("3. Tambah Pasien Sebelum Pasien Tertentu\n");
        printf("4. Tambah Pasien Setelah Pasien Tertentu\n");
        printf("5. Tampilkan Daftar Pasien\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus newline setelah input angka

        switch (pilihan) {
            case 1:
                printf("Masukkan nama pasien: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                printf("Masukkan usia pasien: ");
                scanf("%d", &usia);
                getchar();
                printf("Masukkan jenis kelamin (L/P): ");
                scanf("%c", &jenisKelamin);
                tambahPasienAwal(nama, usia, jenisKelamin);
                break;
            case 2:
                printf("Masukkan nama pasien: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Masukkan usia pasien: ");
                scanf("%d", &usia);
                getchar();
                printf("Masukkan jenis kelamin (L/P): ");
                scanf("%c", &jenisKelamin);
                tambahPasienAkhir(nama, usia, jenisKelamin);
                break;
            case 3:
                printf("Masukkan nama pasien: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Masukkan usia pasien: ");
                scanf("%d", &usia);
                getchar();
                printf("Masukkan jenis kelamin (L/P): ");
                scanf("%c", &jenisKelamin);
                printf("Masukkan nama pasien sebelum siapa ingin ditambahkan? ");
                fgets(namaSebelum, sizeof(namaSebelum), stdin);
                namaSebelum[strcspn(namaSebelum, "\n")] = 0;
                tambahPasienSebelum(nama, usia, jenisKelamin, namaSebelum);
                break;
            case 4:
                printf("Masukkan nama pasien: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Masukkan usia pasien: ");
                scanf("%d", &usia);
                getchar();
                printf("Masukkan jenis kelamin (L/P): ");
                scanf("%c", &jenisKelamin);
                printf("Masukkan nama pasien setelah siapa ingin ditambahkan? ");
                fgets(namaSetelah, sizeof(namaSetelah), stdin);
                namaSetelah[strcspn(namaSetelah, "\n")] = 0;
                tambahPasienSetelah(nama, usia, jenisKelamin, namaSetelah);
                break;
            case 5:
                tampilkanDaftarPasien();
                break;
            case 6:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    return 0;
} 

//Aku capek namain 1 1 per baris jadi yaudah lah ya
//Mohon maaf dan trima kasih
