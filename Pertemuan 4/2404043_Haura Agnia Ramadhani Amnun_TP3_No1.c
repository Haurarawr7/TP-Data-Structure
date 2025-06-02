
//Program Sistem Inventaris
//Oleh Haura Agnia Ramadhani Amnun

/*
1. Seorang programmer memiliki toko kelontong, dia ingin mengembangkan sistem
manajemen inventaris barang menggunakan struktur data Singly Linked List. Sistem ini
simpan daftar barang yang tersedia di toko secara dinamis dan bervariasi. Setiap
barang memiliki nama dan harga. Adapun program harus memenuhi:
a. Tambah Barang:
i. Tambah di awal daftar
ii. Tambah di akhir daftar
iii. Tambah sebelum barang tertentu
iv. Tambah setelah barang tertentu
b. Tampilkan Daftar Barang:
Pengguna dapat melihat seluruh daftar barang beserta nama dan harga yang telah
ditambahkan.
c. Keluar dari Program
Contoh Input & Output:
=== Sistem Manajemen Inventaris Toko ===
1. Tambah Barang di Awal
2. Tambah Barang di Akhir
3. Tambah Barang Sebelum Barang Tertentu
4. Tambah Barang Setelah Barang Tertentu
5. Tampilkan Daftar Barang
6. Keluar
Pilih menu: 1
Masukkan nama barang: Gula
Masukkan harga barang: 15000
Barang berhasil ditambahkan di awal daftar!

Pilih menu: 1
Masukkan nama barang: Garam
Masukkan harga barang: 10000
Barang berhasil ditambahkan di awal daftar!

Pilih menu: 5
Daftar Barang:
1. Garam - Rp 10000
2. Gula - Rp 15000

Pilih menu: 6
Keluar dari program...
*/


#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>  

// Mendefinisikan struktur Node buat simpan informasi barang
typedef struct Node {
    char nama[50];
    int harga; 
    struct Node* next; // Pointer ke node selanjutnya
} Node;

Node* head = NULL; // Pointer ke head linked list, diinisialisasi dengan NULL

// Fungsi buat menambah barang di awal daftar
void TambahAwal(char* nama, int harga) {
    Node* newnode = (Node*)malloc(sizeof(Node)); //  
    strcpy(newnode->nama, nama); // Menyalin nama barang ke node baru
    newnode->harga = harga; // Menetapkan harga barang
    newnode->next = head; // Menghubungkan node baru ke head
    head = newnode; // Memperbarui head ke node baru
    printf("Barang berhasil ditambahkan di awal daftar!\n");
}

// Fungsi buat menambah barang di akhir daftar
void TambahAkhir(char* nama, int harga) {
    Node* newnode = (Node*)malloc(sizeof(Node)); //  
    strcpy(newnode->nama, nama); // Menyalin nama barang ke node baru
    newnode->harga = harga; // Menetapkan harga barang
    newnode->next = NULL; // Karena node baru adalah yang terakhir, jadi next-nya NULL

    if (head == NULL) { // kalo daftar kosong
        head = newnode; // simpan head ke node baru
        printf("Barang berhasil ditambahkan di akhir daftar!\n");
        return;
    }

    Node* last = head; // buat pointer buat menemukan akhir daftar
    while (last->next != NULL) { // Mencari node terakhir
        last = last->next;
    }
    last->next = newnode; // Menghubungkan node terakhir dengan node baru
    printf("Barang berhasil ditambahkan di akhir daftar!\n");
}

// Fungsi buat menambah barang sebelum barang tertentu
void TambahSebelum(char* target, char* nama, int harga) {
    Node* newnode = (Node*)malloc(sizeof(Node)); // Alokasikan memori buat node baru
    strcpy(newnode->nama, nama); // Menyalin nama barang ke node baru
    newnode->harga = harga; // Menetapkan harga barang

    if (head == NULL) { 
        printf("Daftar barang kosong!\n");
        return;
    }

    if (strcmp(head->nama, target) == 0) { // kalo barang 1 adalah target
        newnode->next = head; // menghubungkan node baru ke head
        head = newnode; // simpan head ke node baru
        printf("Barang berhasil ditambahkan sebelum barang tertentu!\n");
        return;
    }

    Node* temp = head; // buat pointer buat mencari target
    while (temp->next != NULL && strcmp(temp->next->nama, target) != 0) {
        temp = temp->next; // Mencari node sebelum target
    }

    if (temp->next == NULL) {                 
        printf("Barang dengan nama '%s' tidak ditemukan!\n", target);
    } 
    else {
        newnode->next = temp->next; // Menghubungkan node baru dengan node setelah temp
        temp->next = newnode; // Menghubungkan temp dengan node baru
        printf("Barang berhasil ditambahkan sebelum barang tertentu!\n");
    }
}

// Fungsi buat menambah barang setelah barang tertentu
void TambahSetelah(char* target, char* nama, int harga) {
    Node* newnode = (Node*)malloc(sizeof(Node)); 
    strcpy(newnode->nama, nama); // Menyalin nama barang ke node baru
    newnode->harga = harga; // Menetapkan harga barang

    Node* temp = head; // buat pointer buat mencari target
    while (temp != NULL) { // Mencari target
        if (strcmp(temp->nama, target) == 0) { // kalo target ditemukan
            newnode->next = temp->next;// Menghubungkan node baru dengan node setelah temp
            temp->next = newnode ; // menghubungkan temp dengan node baru
            printf("Barang berhasil ditambahkan setelah barang tertentu!\n");
            return;
        }
        temp = temp->next;// lanjut pencarian ke node selanjutnya
    }
    printf("Barang dengan nama '%s' tidak ditemukan!\n", target); // kalo target tidak ditemukan
}

// Fungsi buat menampilkan daftar barang
void display() {
    if (head == NULL) { // Kalo daftar kosong
        printf("Daftar barang kosong!\n");
        return;
    }
    printf("Daftar Barang:\n"); // Menampilkan header daftar barang
    Node* temp = head; // buat pointer buat iterasi
    int index = 1; // Indeks buat penomoran barang
    while (temp != NULL) { // Selama barang masih ada 
        printf("%d. %s - Rp %d\n", index, temp->nama, temp->harga); // Menampilkan nama dan harga barang
        temp = temp->next; // lanjut ke node selanjutnya
        index++;  
    }
}

// Fungsi utama
int main() {
    int pilih;  
    char nama[50]; 
    char target[50];  
    int harga; 

    while (1) {                                  
        printf("\n=== Sistem Manajemen Inventaris Toko ===\n");
        printf("1. Tambah Barang di Awal\n");
        printf("2. Tambah Barang di Akhir\n");
        printf("3. Tambah Barang Sebelum Barang Tertentu\n");
        printf("4. Tambah Barang Setelah Barang Tertentu\n");
        printf("5. Tampilkan Daftar Barang\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih); // Mengambil input pilihan dari pengguna
        getchar(); // Menghapus newline dari input buffer

        switch (pilih) { 
            case 1:
                printf("Masukkan nama barang: ");
                fgets(nama, sizeof(nama), stdin); // Mengambil nama barang
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                printf("Masukkan harga barang: ");
                scanf("%d", &harga); // Mengambil harga barang
                TambahAwal(nama, harga); // Memanggil fungsi buat menambah barang di awal
                break;
            case 2:
                printf("Masukkan nama barang: ");
                fgets(nama, sizeof(nama), stdin); // Mengambil nama barang
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                printf("Masukkan harga barang: ");
                scanf("%d", &harga); // Mengambil harga barang
                TambahAkhir(nama, harga); // Memanggil fungsi buat menambah barang di akhir
                break;
            case 3:
                printf("Masukkan nama barang sebelumnya: ");
                fgets(target, sizeof(target), stdin); // Mengambil nama target
                target[strcspn(target, "\n")] = 0; // Menghapus newline
                printf("Masukkan nama barang: ");
                fgets(nama, sizeof(nama), stdin); // Mengambil nama barang
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                printf("Masukkan harga barang: ");
                scanf("%d", &harga); // Mengambil harga barang
                TambahSebelum(target, nama, harga); // Memanggil fungsi buat menambah barang sebelum target
                break;
            case 4:
                printf("Masukkan nama barang setelahnya: ");
                fgets(target, sizeof(target), stdin); // Mengambil nama target
                target[strcspn(target, "\n")] = 0; // Menghapus newline
                printf("Masukkan nama barang: ");
                fgets(nama, sizeof(nama), stdin); // Mengambil nama barang
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline
                printf("Masukkan harga barang: ");
                scanf("%d", &harga); // Mengambil harga barang
                TambahSetelah(target, nama, harga); // Memanggil fungsi buat menambah barang setelah target
                break;
            case 5:
                display(); // Memanggil fungsi display buat menampilkan daftar barang
                break;
            case 6:
                printf("Keluar dari program...\n"); 
                return 0; default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    }
}

//Mohon maaf dan trima kasih