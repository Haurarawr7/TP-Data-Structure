
//PROGRAM 
//OLEH : HAURA AGNIA RAMADHANI AMNUN 2404043

/*
Sebuah kelas memerlukan program untuk merekap nilai siswa. Buatkan program
sederhana bahasa C untuk merekap nilai siswa dengan menggunakan konsep ADT dan
wajib menggunakan fungsi/prosedur.

Input:
Masukan jumlah mahasiswa yang ingin direkap : 4
Nama Mahasiswa 1 = Dodi
Nilai Mahasiswa 1 = 85
Nama Mahasiswa 2 = Didi
Nilai Mahasiswa 2 = 91
Nama Mahasiswa 3 = Dudu
Nilai Mahasiswa 3 = 87
Nama Mahasiswa 4 = Dodo
Nilai Mahasiswa 4 = 95

Output:
Rekap Nilai Mahasiswa:
Nama: Dodi Nilai: 85
Nama: Didi Nilai: 91
Nama: Dudu Nilai: 87
Nama: Dodo Nilai: 95
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct mahasiswa {
    char nama[100];
    int nilai;
}mhs; // persingkat jadi mhs

int main(){
    int n, i;
    printf("Masukan jumlah mahasiswa yang ingin direkap : ");
    scanf("%d", &n);
    mhs person[100];
    for(i=0; i<n; i++){
        printf("Nama Mahasiswa %d = ", i+1); //input
        scanf("%s", &person[i].nama);
        printf("Nilai Mahasiswa %d = ", i+1);
        scanf("%d", &person[i].nilai);
    }
    printf("\nRekap Nilai Mahasiswa: ");
    for(i=0; i<n; i++){
        printf("\nNama: %s Nilai: %d", person[i].nama, person[i].nilai); // output
    }
}