
//Program jual beli buah
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Pak Dika membuka sebuah toko buah. Setiap harinya Pak Dika mencatat jumlah buah
yang masuk dan keluar. Dalam mencatat, buah direpresentasikan dalam array dengan
menunjukan jenis buah tertentu. Selama melakukan pencatatan, Pak Dika mengalami
kesulitan karena pencatatan dilakukan secara manual. Bantulah Pak Dika dengan
membuat sebuah program yang dapat menghitung stok akhir untuk setiap jenis buah
selama 7 hari!
Ketentuan Input:
- Baris pertama berisi jumlah jenis buah (N)
- Baris kedua berisi stok awal masing-masing buah
- 7 baris berikutnya adalah array masing-masing buah yang berisi N elemen (jumlah
buah masuk dan jumlah buah keluar untuk setiap jenis buah per hari)
Ketentuan output:
- Cetak stok akhir setiap jenis buah setelah 7 hari
Input:
3
50 30 20
10 5 3
5 2 1
20 10 5
15 5 2
10 2 3
8 3 1
12 6 4

Output:
Stok buah ke-1: 92
Stok buah ke-2: 41
Stok buah ke-3: 29
*/


#include <stdio.h>

int main() {
    int n, i, j; 
    printf("Masukkan jumlah jenis buah: "); // pusing kalo gak dinamain , hehe
    scanf("%d", &n);

    int stokawal[n]; 
    for (i = 0; i < n; i++) {
        printf("Masukkan stok awal masing-masing buah: ");
        scanf("%d", &stokawal[i]);
    }

    int pembelian[14][n]; 
    int penjualan[14][n]; 

    printf("Masukkan jumlah pembelian dan penjualan untuk setiap jenis buah:\n");
    for (i = 0; i < 14; i++) {
        printf("Hari %d:\n", i + 1);
        printf("Pembelian: ");
        for (int j = 0; j < n; j++) {
            scanf("%d", &pembelian[i][j]);
        }
        printf("Penjualan: ");
        for (j = 0; j < n; j++) {
            scanf("%d", &penjualan[i][j]);
        }
    }

    int stokakhir[n];
    for (i = 0; i < n; i++) {
        stokakhir[i] = stokawal[i]; 
        for (j = 0; j < 14; j++) {
            stokakhir[i] += pembelian[j][i]; 
            stokakhir[i] -= penjualan[j][i]; 
        }
    }

    printf("\nStok akhir setiap jenis buah setelah 14 hari:\n");
    for (int i = 0; i < n; i++) {
        printf("Stok akhir buah ke-%d: %d\n", i + 1, stokakhir[i]);
    }

    return 0;
}