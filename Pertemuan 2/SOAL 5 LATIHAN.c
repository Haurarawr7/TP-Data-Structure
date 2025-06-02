
//Program Hitung Keliling Bidang 2d
//Oleh: Haura Agnia Ramadhani Amnun

/*
Menghitung keliling bidang datar sesuai dari jarak antar titik yang diinputkan.
Lihat contoh titik koordinat berikut:

Setelah di tarik garis antar titik dan menjadi betuk sebuah bidang datar

Carilah kelilingnya!, gunakan konsep ADT.
Pastikan inputan titik korddinat searah jarum jam!!

Input
5
Masukan Titik ke-1(x,y):2 1
Masukan Titik ke-2(x,y):3 4
Masukan Titik ke-3(x,y):5 3
Masukan Titik ke-4(x,y):5 2
Masukan Titik ke-5(x,y):4 1
Output
Jadi keliling bidang adalah: 9.813
*/

#include <stdio.h>
#include <math.h>

// Struktur untuk menyimpan titik koordinat
typedef struct {
    float x;
    float y;
} Titik;

// Fungsi untuk menghitung jarak antara dua titik
float hitungJarak(Titik a, Titik b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Fungsi untuk menghitung keliling bidang
float hitungKeliling(Titik titik[], int jumlahTitik) {
    float keliling = 0.0;
    for (int i = 0; i < jumlahTitik; i++) {
        keliling += hitungJarak(titik[i], titik[(i + 1) % jumlahTitik]);
    }
    return keliling;
}

int main() {
    int jumlahTitik;
    Titik titik[100];

    printf("Masukkan jumlah titik: ");
    scanf("%d", &jumlahTitik);

    // Memastikan jumlah titik valid
    if (jumlahTitik < 3) {
        printf("Jumlah titik harus lebih dari 2 untuk membentuk bidang datar.\n");
        return 0;
    }

    // Input titik koordinat
    for (int i = 0; i < jumlahTitik; i++) {
        printf("Masukkan Titik ke-%d (x,y): ", i + 1);
        scanf("%f %f", &titik[i].x, &titik[i].y);
    }

    // Hitung keliling
    float keliling = hitungKeliling(titik, jumlahTitik);
    printf("Jadi keliling bidang adalah: %.3f\n", keliling);

    return 0;
}