
//Program Pencatatan pertandingan
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Seorang dosen ingin mengelola daftar nilai mahasiswa menggunakan single linked list
untuk mata kuliah yang dia ajar.
Aturan dalam sistem:
- Daftar nilai mahasiswa diurutkan berdasarkan yang lebih dulu mengumpulkan tugas
(insert akhir)
- Dosen dapat melihat daftar nilai mahasiswa
- Jika ada kesalahan pencatatan nilai, dosen bisa memperbarui nilai mahasiswa
berdasarkan NIM (char) mahasiswa.
- Jika seorang mahasiswa mengundurkan diri dari mata kuliah ini, maka nilainya akan
dihapus dari daftar.
- Dosen juga bisa menghitung statistik nilai, termasuk: nilai rata-rata, nilai tertinggi,
dan nilai terendah
Input & Output:
=== Menu Manajemen Nilai Mahasiswa ===
1. Tambah Mahasiswa di Akhir
2. Tampilkan Daftar Nilai
3. Hapus Mahasiswa Terakhir
4. Hitung Statistik Nilai
5. Update Nilai Mahasiswa
6. Keluar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nim[20];
    char nama[50];
    float nilai;
    struct Node* next;
} Node;

typedef struct DaftarMahasiswa {
    Node* head;
} DaftarMahasiswa;

// Fungsi untuk membuat daftar mahasiswa
DaftarMahasiswa* buatDaftarMahasiswa() {
    DaftarMahasiswa* daftar = (DaftarMahasiswa*)malloc(sizeof(DaftarMahasiswa));
    daftar->head = NULL;
    return daftar;
}

// Fungsi untuk menambahkan mahasiswa di akhir
void tambahMahasiswaAkhir(DaftarMahasiswa* daftar, const char* nim, const char* nama, float nilai) {
    Node* node_baru = (Node*)malloc(sizeof(Node));
    strcpy(node_baru->nim, nim);
    strcpy(node_baru->nama, nama);
    node_baru->nilai = nilai;
    node_baru->next = NULL;

    if (daftar->head == NULL) {
        daftar->head = node_baru;
    } else {
        Node* saat_ini = daftar->head;
        while (saat_ini->next != NULL) {
            saat_ini = saat_ini->next;
        }
        saat_ini->next = node_baru;
    }
}

// Fungsi untuk menampilkan daftar nilai mahasiswa
void tampilkanDaftarNilai(DaftarMahasiswa* daftar) {
    Node* saat_ini = daftar->head;
    if (saat_ini == NULL) {
        printf("Daftar nilai mahasiswa kosong.\n");
        return;
    }
    printf("Daftar Nilai Mahasiswa:\n");
    printf("-------------------------------------\n");
    while (saat_ini != NULL) {
        printf("NIM: %s | Nama: %s | Nilai: %.2f\n", saat_ini->nim, saat_ini->nama, saat_ini->nilai);
        saat_ini = saat_ini->next;
    }
    printf("-------------------------------------\n");
}

// Fungsi untuk menghitung statistik nilai
void hitungStatistikNilai(DaftarMahasiswa* daftar) {
    Node* saat_ini = daftar->head;
    if (saat_ini == NULL) {
        printf("Daftar nilai mahasiswa kosong.\n");
        return;
    }

    float total_nilai = 0;
    float nilai_tertinggi = saat_ini->nilai;
    float nilai_terendah = saat_ini->nilai;
    int jumlah_mahasiswa = 0;

    while (saat_ini != NULL) {
        total_nilai += saat_ini->nilai;
        if (saat_ini->nilai > nilai_tertinggi) {
            nilai_tertinggi = saat_ini->nilai;
        }
        if (saat_ini->nilai < nilai_terendah) {
            nilai_terendah = saat_ini->nilai;
        }
        jumlah_mahasiswa++;
        saat_ini = saat_ini->next;
    }

    float rata_rata = total_nilai / jumlah_mahasiswa;
    printf("Statistik Nilai Mahasiswa:\n");
    printf("Rata-rata Nilai: %.2f\n", rata_rata);
    printf("Nilai Tertinggi: %.2f\n", nilai_tertinggi);
    printf("Nilai Terendah : %.2f\n", nilai_terendah);
}

// Fungsi untuk menghapus mahasiswa terakhir
void hapusMahasiswaTerakhir(DaftarMahasiswa* daftar) {
    if (daftar->head == NULL) {
        printf("Daftar nilai mahasiswa kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    Node* saat_ini = daftar->head;
    Node* sebelumnya = NULL;

    while (saat_ini->next != NULL) {
        sebelumnya = saat_ini;
        saat_ini = saat_ini->next;
    }

    if (sebelumnya == NULL) {
        // Hanya ada satu mahasiswa
        free(daftar->head);
        daftar->head = NULL;
    } else {
        free(saat_ini);
        sebelumnya->next = NULL;
    }

    printf("Mahasiswa terakhir dalam daftar telah dihapus.\n");
}

// Fungsi untuk memperbarui nilai mahasiswa
void updateNilaiMahasiswa(DaftarMahasiswa* daftar, const char* nim, float nilai_baru) {
    Node* saat_ini = daftar->head;
    while (saat_ini != NULL) {
        if (strcmp(saat_ini->nim, nim) == 0) {
            saat_ini->nilai = nilai_baru;
            printf("Nilai mahasiswa dengan NIM %s berhasil diperbarui menjadi %.2f!\n", nim, nilai_baru);
            return;
        }
        saat_ini = saat_ini->next;
    }
    printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
}

// Fungsi utama
int main() {
    DaftarMahasiswa* daftar = buatDaftarMahasiswa();
    int pilihan;
    char nim[20], nama[50];
    float nilai;

    do {
        printf("\n=== Menu Manajemen Nilai Mahasiswa ===\n");
        printf("1. Tambah Mahasiswa di Akhir\n");
        printf("2. Tampilkan Daftar Nilai\n");
        printf("3. Hapus Mahasiswa Terakhir\n");
        printf("4. Hitung Statistik Nilai\n");
        printf("5. Update Nilai Mahasiswa\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                printf("Masukkan Nilai: ");
                scanf("%f", &nilai);
                tambahMahasiswaAkhir(daftar, nim, nama, nilai);
                break;
            case 2:
                tampilkanDaftarNilai(daftar);
                break;
            case 3:
                hapusMahasiswaTerakhir(daftar);
                break;
            case 4:
                hitungStatistikNilai(daftar);
                break;
            case 5:
                printf("Masukkan NIM mahasiswa yang ingin diperbarui: ");
                scanf("%s", nim);
                printf("Masukkan Nilai Baru: ");
                scanf("%f", &nilai);
                updateNilaiMahasiswa(daftar, nim, nilai);
                break;
            case 6:
                printf("Terima kasih! Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    // Membersihkan memori
    while (daftar->head != NULL) {
        hapusMahasiswaTerakhir(daftar);
    }
    free(daftar);

    return 0;
}

//Kak maafnya aku besok mutusin nge lepas organisai/ukm atau engga soalnya aku gak kayak akbar wkwk
//Aku capek tapi aku keren kan di umu 17 tahun ini aku bisa sampai di titik ini?
// Semangat ya kak