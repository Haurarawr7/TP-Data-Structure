
//Program jual beli ayam
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Pak Budi berencana melakukan jual beli ayam pada 7 hari pertama di bulan yang akan
datang. Pak Budi akan membeli ayam dan akan menjual ayamnya kembali di hari yang
sama. Dibawah ini adalah data Pembelian dan Penjualan ayam Pak Budi di 7 hari pertama
bulan tersebut:
Tanggal Beli Tanggal Jual
1       100     1    40
2       0       2    23
3       31      3    0
4       178     4    128
5       13      5    0
6       0       6    15
7       31      7    4
Buatlah program agar bisa mengeluarkan 7 baris nilai sisa Ayam setiap tanggal tersebut!

Input:
(Tidak ada Input)

Output:
60
37
68
118
131
116
143
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int pembelian[7] = {100, 0, 31, 178, 13, 0, 31};
    int penjualan[7] = {40, 23, 0, 128, 0, 15, 4};
    
    int sisaayam = 0;

    for (int i = 0; i < 7; i++) {
        sisaayam += pembelian[i];  
        sisaayam -= penjualan[i];   
        printf("%d\n", sisaayam);   
    }
    return 0;
}