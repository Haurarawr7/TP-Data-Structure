
//Program Perpustakaan
//Oleh : Haura Agnia Ramadhani Amnun

/*
Pada sebuah perpustakaan terdapat banyak buku. Perpustakaan biasanya
meminjamkan buku untuk umum. Bantu pustakawan membuat sebuah program
dengan bahasa c untuk data peminjaman buku tersebut dengan menggunakan konsep
ADT dan wajib menggunakan fungsi/prosedur.

Input:
Masukan jumlah buku yang dipinjam: 2
Buku yang dipinjam :
Struktur Data
Basis Data
Nama Peminjam : Agus
Tanggal Pinjam : 5
Tanggal Pengembalian : 9
Output:
Nama Peminjam : Agus
Buku yang dipinjam :
Struktur Data
Basis Data
Lama Peminjaman: 4 hari
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    char judul[100]; // Array untuk menyimpan judul buku
    int tanggal_pinjam;
    int tanggal_pengembalian;
    int jumlah_buku; // Menyimpan jumlah buku yang dipinjam
} Peminjam;

// Fungsi untuk menginput data
void inputPeminjaman(Peminjam peminjam) {
    printf("Masukkan jumlah buku yang dipinjam: ");
    scanf("%d", &peminjam.jumlah_buku);
    
    printf("Buku yang dipinjam:\n");
    for (int i = 0; i < peminjam.jumlah_buku; i++) {
        printf("Masukkan judul buku %d: ", i + 1);
        scanf(" %[^\n]", peminjam.judul[i]); 
    }
    
    printf("Nama Peminjam: ");
    scanf(" %[^\n]", peminjam.nama); 
    printf("Tanggal Pinjam: ");
    scanf("%d", &peminjam.tanggal_pinjam);
    printf("Tanggal Pengembalian: ");
    scanf("%d", &peminjam.tanggal_pengembalian);
}

// Fungsi untuk menampilkan data peminjaman
void tampilkanPeminjaman(Peminjam peminjam) {
    printf("\nNama Peminjam: %s", peminjam.nama);
    printf("\nBuku yang dipinjam:\n");
    for (int i = 0; i < peminjam.jumlah_buku; i++) {
        printf("%s\n", peminjam.judul[i]);
    }
    printf("Lama Peminjaman: %d hari\n", peminjam.tanggal_pengembalian - peminjam.tanggal_pinjam);
}

int main() {
    Peminjam peminjam;

    // Input data peminjaman
    inputPeminjaman(peminjam); // Memanggil fungsi untuk input data

    // Menampilkan data peminjaman
    tampilkanPeminjaman(peminjam); // Memanggil fungsi untuk menampilkan data

    return 0;
}