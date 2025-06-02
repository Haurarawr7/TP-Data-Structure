
//PROGRAM DATA SAYUR
//OLEH : HAURA AGNIA RMADHANI AMNUN 2404043
/*
Di daerah A terdapat sebuah toko sayur. Toko tersebut akan mendata sayur yang dibeli.
Bantu toko sayur tersebut dengan membuat program bahasa C untuk mendata banyak
sayur yang dibeli menggunakan konsep ADT dan wajib menggunakan fungsi/prosedur.
Input:
Masukan jumlah barang yang akan dicatat: 2
Masukan nama sayur ke-1: Bayam
Jumlah sayur yang dibeli (kg): 2
Masukan nama sayur ke-1: Kol
Jumlah sayur yang dibeli (kg): 4
Output:
Total berat sayur yang dibeli : 6 kg.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Sayuran{
    char nama[100];
    int berat;
}syr;

int main(){
    int n, i, total=0 ;
    printf("Masukan jumlah barang yang akan dicatat: ");
    scanf("%d", &n);
    syr beli[100];
    for (i=0; i<n; i++){
        printf("Masukan nama sayur ke-%d : ", i+1);
        scanf("%s", beli[i].nama);
        printf("Jumlah sayur yang dibeli (kg) : ");
        scanf("%d", &beli[i].berat);
        total = total + (beli[i].berat);
    }
    printf("\nTotal berat sayur yang dibeli : %d kg", total);

    return 0;
}