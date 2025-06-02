
//Program Sistem vaksinasi
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Klinik Miyuki memiliki sistem vaksinasi terjadwal, dan setiap pasien menerima
waktu layanan yang berbeda tergantung pada kondisi mereka. Estimasi waktu
tunggu pasien berikutnya bergantung pada total waktu pasien sebelumnya.
Program Anda diminta untuk:
• Menyimpan waktu layanan masing-masing pasien ke dalam antrian.
• Menampilkan semua data layanan yang dimasukkan.
• Menghitung estimasi waktu tunggu untuk masing-masing pasien
berdasarkan total waktu layanan sebelumnya.
Input:
Input jumlah pasien (maks 5): 4
Masukkan waktu layanan pasien 1: 5
Masukkan waktu layanan pasien 2: 10
Masukkan waktu layanan pasien 3: 7
Masukkan waktu layanan pasien 4: 8
Output:
Data waktu layanan:
5 10 7 8
Estimasi waktu tunggu:
Pasien 1: 0 menit
Pasien 2: 5 menit
Pasien 3: 15 menit
Pasien 4: 22 menit
*/

#include <stdio.h>

#define MAXPASIEN 5

int main() {
    int jumlahpasien;
    int waktulayanan[MAXPASIEN];
    int totalwaktu = 0;

    // Input jumlah pasien
    printf("Input jumlah pasien (maks %d): ", MAXPASIEN);
    scanf("%d", &jumlahpasien);

    // Validasi jumlah pasien
    if (jumlahpasien > MAXPASIEN) {
        printf("Jumlah pasien tidak boleh lebih dari %d.\n", MAXPASIEN);
        return 1;
    }

    // Input waktu layanan untuk setiap pasien
    for (int i = 0; i < jumlahpasien; i++) {
        printf("Masukkan waktu layanan pasien %d: ", i + 1);
        scanf("%d", &waktulayanan[i]);
    }

    // Menampilkan data waktu layanan
    printf("\nData waktu layanan:\n");
    for (int i = 0; i < jumlahpasien; i++) {
        printf("%d ", waktulayanan[i]);
    }
    printf("\n");

    // Menghitung estimasi waktu tunggu (dengan kesalahan)
    printf("\nEstimasi waktu tunggu:\n");
    for (int i = 0; i < jumlahpasien; i++) {
        printf("Pasien %d: %d menit\n", i + 1, totalwaktu);
        totalwaktu += waktulayanan[i] + 1; 
    }

    return 0;
}
