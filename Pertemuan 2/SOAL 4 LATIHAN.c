
//Program data produksi
// Oleh Haura Agnia ramadhani Amnun 2404043

/*
Sebuah perusahaan manufaktur membutuhkan program untuk mengelola data
produksi barang-barangnya. Bantu perusahaan tersebut dengan membuat program
menggunakan konsep ADT dalam bahasa C untuk mencatat produksi barang dan total
dari jumlah produksi seluruh barang.
Jika inputan awal kurang dari 1, tampilkan “Tidak ada barang yang akan diproduksi” dan
program wajib menggunakan fungsi/prosedur.
Input:
Masukkan jumlah barang yang diproduksi: 3
Barang 1:
Nama Barang: Meja
Bahan Baku: Kayu
Harga Jual (Rp): 500000
Jumlah Produksi: 50
Barang 2:
Nama Barang: Kursi
Bahan Baku: Besi
Harga Jual (Rp): 300000
Jumlah Produksi: 100
Output:

Data Produksi Ke-1:
Nama Barang: Meja
Bahan Baku: Kayu
Harga Jual (Rp): 500000
Jumlah Produksi: 50
Data Produksi Ke-2:
Nama Barang: Kursi
Bahan Baku: Besi
Harga Jual (Rp): 300000
Jumlah Produksi: 100
Total Barang yang diproduksi = 150
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data barang
typedef struct {
    char nama[50];
    char bahanBaku[50];
    int hargaJual;
    int jumlahProduksi;
} Barang;

// Fungsi Input
void inputBarang(Barang *barang, int index) {
    printf("Barang %d:\n", index + 1);
    printf("Nama Barang: ");
    scanf(" %[^\n]", barang[index].nama);
    printf("Bahan Baku: ");
    scanf(" %[^\n]", barang[index].bahanBaku);
    printf("Harga Jual (Rp): ");
    scanf("%d", &barang[index].hargaJual);
    printf("Jumlah Produksi: ");
    scanf("%d", &barang[index].jumlahProduksi);
}

// Fungsi Output
void tampilkanBarang(Barang *barang, int jumlahBarang) {
    int totalProduksi = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        printf("\nData Produksi Ke-%d:\n", i + 1);
        printf("Nama Barang: %s\n", barang[i].nama);
        printf("Bahan Baku: %s\n", barang[i].bahanBaku);
        printf("Harga Jual (Rp): %d\n", barang[i].hargaJual);
        printf("Jumlah Produksi: %d\n", barang[i].jumlahProduksi);
        totalProduksi += barang[i].jumlahProduksi;
    }
    printf("\nTotal Barang yang diproduksi = %d\n", totalProduksi);
}

int main() {
    int jumlahBarang;
    Barang barang[100];

    printf("Masukkan jumlah barang yang diproduksi: ");
    scanf("%d", &jumlahBarang);

    if (jumlahBarang < 1) {
        printf("Tidak ada barang yang akan diproduksi\n");
        return 0;
    }

    // Input data barang
    for (int i = 0; i < jumlahBarang; i++) {
        inputBarang(barang, i);
    }

    // Tampilkan data barang
    tampilkanBarang(barang, jumlahBarang);

    return 0;
}