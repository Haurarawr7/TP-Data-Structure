
//Program menghitung hasil penjualan
// Oleh Haura Agnia Ramadhani Amnun

/*
Ibu Asri membuka sebuah bisnis makanan. Dia memiliki daftar harga untuk setiap jenis
makanan yang dia jual dalam bentuk array. Namun, Ibu Asri membutuhkan bantuan
untuk menghitung pendapatan dari penjualan dari bisnis makanannya. Setiap jenis
makanan yang Ibu Asri jual memiliki kuantitas penjualan masing-masing. Bantulah Ibu
Asri dengan membuat sebuah program untuk menghitung total pendapatan dari
penjualannya tersebut!
Input:
Jumlah Jenis Makanan : 4
Harga Jenis Makanan ke-1 : 1000
Kuantitas yang terjual ke-1 : 3
Harga Jenis Makanan ke-2 : 2000
Kuantitas yang terjual ke-2 : 2
Harga Jenis Makanan ke-3 : 3000
Kuantitas yang terjual ke-3 : 2
Harga Jenis Makanan ke-4 : 4000
Kuantitas yang terjual ke-4 : 1
Output:
Total Pendapatan Ibu Asri adalah : 17000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int jumlahMakanan, i;
    int harga[100], kuantitas[100];
    int totalPendapatan = 0;

    printf("Jumlah Jenis Makanan: ");
    scanf("%d", &jumlahMakanan);

    for (i = 0; i < jumlahMakanan; i++) {
        printf("Harga Jenis Makanan ke-%d: ", i + 1);
        scanf("%d", &harga[i]);
        printf("Kuantitas yang terjual ke-%d: ", i + 1);
        scanf("%d", &kuantitas[i]);
    }

    for (i = 0; i < jumlahMakanan; i++) {
        totalPendapatan += harga[i] * kuantitas[i];
    }

    printf("Total Pendapatan Ibu Asri adalah: %d\n", totalPendapatan);

    return 0; // Mengembalikan 0 sebagai tanda program selesai
}