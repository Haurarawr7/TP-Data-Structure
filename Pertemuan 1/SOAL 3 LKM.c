
//Program 
// Oleh Haura Agnia Ramadhani Amnun

/*
Pak Dengklek adalah seorang peternak Sapi, Ayam dan Kambing. Setiap ternak memiliki
jumlah peningkatan ternak yang berbeda-beda setiap bulannya. Jumlah peningkatan
ternak untuk Sapi adalah dua kali lipat dari bulan sebelumnya, Untuk ayam adalah
jumlah ayam ditambah dengan tiga kali jumlah sapi di bulan sebelumnya dan untuk
kambing adalah jumlah kambing di tambah dengan setengah dari peningkatan ayam.
Hitung Peningkatan Jumlah ternak untuk 2 bulan terakhir dengan menginputkan jumlah
ternak Sapi, Ayam dan Kambing pada awal bulan!
Input:
10
10
10
Output:
Bulan ke-1
Sapi = 10
Ayam = 10
Kambing = 10
Bulan ke-2
Sapi = 20
Ayam = 40
Kambing = 30
*/

#include <stdio.h>

int main() {
    int sapi, ayam, kambing;

    printf("Masukkan jumlah Sapi: ");
    scanf("%d", &sapi);
    printf("Masukkan jumlah Ayam: ");
    scanf("%d", &ayam);
    printf("Masukkan jumlah Kambing: ");
    scanf("%d", &kambing);

    printf("Bulan ke-1\n");
    printf("Sapi = %d\n", sapi);
    printf("Ayam = %d\n", ayam);
    printf("Kambing = %d\n", kambing);

    
    int sapi_bulan_2 = sapi * 2; 
    int ayam_bulan_2 = ayam + (3 * sapi); 
    int kambing_bulan_2 = kambing + (ayam / 2); 

    printf("Bulan ke-2\n");
    printf("Sapi = %d\n", sapi_bulan_2);
    printf("Ayam = %d\n", ayam_bulan_2);
    printf("Kambing = %d\n", kambing_bulan_2);

    return 0; 
}