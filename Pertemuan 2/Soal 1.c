
//Program Mahasiswa
//Haura Agnia Ramadhani Amnun 2404043

#include <stdio.h>
#include <stdlib.h>

typedef struct mahasiswa{
    char nama[20];
    int usia;
    char alamat[100];
    char kelas;
}mhs;

int main(){
    int n, i, j;
    printf("Input Banyak Mahasiswa: ");
    scanf("%d", &n);
    mhs person[100];
    for (i=0; i<n; i++){
        printf("Data Mahasiswa ke %d", i+1);
        printf("\nNama : ");
        scanf("%s", &person[i].nama);
        printf("Usia: ");
        scanf("%d", &person[i].usia);
        printf("Alamat: ");
        scanf("%s", &person[i].alamat);
        printf("Kelas: ");
        scanf("%s", &person[i].kelas);
    }
    printf("HASIL : ");
    for (i=0; i<n; i++){
        printf("Data Mahasiswa");
        printf("\nNama : %s", person[i].nama);
        printf("\nUsia : %d", person[i].usia);
        printf("\nAlamat : %s", person[i].alamat);
        printf("\nKelas : %c", person[i].kelas);
    }
}