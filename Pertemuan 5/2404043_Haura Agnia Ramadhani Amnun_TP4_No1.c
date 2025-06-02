
//Program klinik
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Suatu hari, sistem antrean klinik mengalami kendala karena pencatatan pasien masih
dilakukan secara manual. Hal ini menyebabkan beberapa masalah, seperti pasien yang
datang lebih awal tidak selalu mendapat giliran yang seharusnya, kesalahan pencatatan
usia pasien, serta kesulitan dalam menangani pasien prioritas. Oleh karena itu, seorang
programmer diminta untuk membuat sistem antrean berbasis Single Linked List untuk
mengatasi masalah ini.
- Pendaftaran pasien baru
Setiap pasien yang datang akan ditambahkan ke dalam antrean, saat ini ada tiga
pasien yang baru mendaftar dalam urutan kedatangan:
ID: 101, Nama: “Alya”, Usia: 25
ID: 102, Nama: “Budi”, Usia: 40
ID: 103, Nama: “Citra”, Usia 35
- Menampilkan daftar antrean pasien
Klinik ingin melihat daftar antrean pasien dari awal hingga akhir untuk memastikan
siapa yang harus dilayani selanjutnya
- Menambahkan pasien prioritas di awal antrean
Seorang pasien bernama Dodi (ID:104, Usia: 60) mengalami kondisi darurat dan
harus langsung ditempatkan di awal antrean

- Memperbarui data pasien
Setelah diperiksa ulang, ditemukan kesalahan dalam pencatatan usia pasien Budi,
usia yang tercatat 40 tahun harus diperbarui menjadi 45 tahun.
- Menghapus pasien yang sudah selesai diperiksa
Pasien bernama Dodi sudah selesai diperiksa dan harus dihapus dari antrean
Output:
Sebelum operasi lainnya:
Daftar antrean pasien:
ID: 101, Nama: Alya, Usia: 25
ID: 102, Nama: Budi, Usia: 40
ID: 103, Nama: Citra, Usia: 35

Setelah penambahan pasien:
Pasien dengan nama Dodi berhasil ditambahkan
ID: 104, Nama: Dodi, Usia: 60
ID: 101, Nama: Alya, Usia: 25
ID: 102, Nama: Budi, Usia: 40
ID: 103, Nama: Citra, Usia: 35

Setelah memperbarui data:
Usia pasien dengan ID 102 diperbarui menjadi 45.
Daftar antrean pasien:
ID: 100, Nama: Dodi, Usia: 60
ID: 101, Nama: Alya, Usia: 25
ID: 102, Nama: Budi, Usia: 45
ID: 103, Nama: Citra, Usia: 35

Setelah menghapus pasien pertama dalam antrean:
Pasien dengan ID 104 berhasil dihapus dari antrean
Daftar antrean pasien:
ID: 101, Nama: Alya, Usia: 25
ID: 102, Nama: Budi, Usia: 45
ID: 103, Nama: Citra, Usia: 35
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id_pasien;
    char nama[50];
    int usia;
    struct Node* next;
} Node;

typedef struct Antrian {
    Node* depan;
    Node* belakang;
} Antrian;

// Fungsi untuk membuat antrian
Antrian* buatAntrian() {
    Antrian* antrian = (Antrian*)malloc(sizeof(Antrian));
    antrian->depan = NULL;
    antrian->belakang = NULL;
    return antrian;
}

// Fungsi untuk menambahkan pasien ke antrian
void tambahAntrian(Antrian* antrian, int id_pasien, const char* nama, int usia) {
    Node* node_baru = (Node*)malloc(sizeof(Node));
    node_baru->id_pasien = id_pasien;
    strcpy(node_baru->nama, nama);
    node_baru->usia = usia;
    node_baru->next = NULL;

    if (antrian->belakang == NULL) {
        antrian->depan = antrian->belakang = node_baru;
    } else {
        antrian->belakang->next = node_baru;
        antrian->belakang = node_baru;
    }
}

// Fungsi untuk menampilkan daftar antrian pasien
void tampilkanAntrian(Antrian* antrian) {
    Node* saat_ini = antrian->depan;
    if (saat_ini == NULL) {
        printf("Antrian kosong.\n");
        return;
    }
    printf("Daftar antrian pasien:\n");
    while (saat_ini != NULL) {
        printf("ID: %d, Nama: %s, Usia: %d\n", saat_ini->id_pasien, saat_ini->nama, saat_ini->usia);
        saat_ini = saat_ini->next;
    }
}

// Fungsi untuk menambahkan pasien prioritas di awal antrian
void tambahPrioritas(Antrian* antrian, int id_pasien, const char* nama, int usia) {
    Node* node_baru = (Node*)malloc(sizeof(Node));
    node_baru->id_pasien = id_pasien;
    strcpy(node_baru->nama, nama);
    node_baru->usia = usia;
    node_baru->next = antrian->depan;
    antrian->depan = node_baru;

    if (antrian->belakang == NULL) {
        antrian->belakang = node_baru;
    }
}

// Fungsi untuk memperbarui usia pasien
void perbaruiUsia(Antrian* antrian, int id_pasien, int usia_baru) {
    Node* saat_ini = antrian->depan;
    while (saat_ini != NULL) {
        if (saat_ini->id_pasien == id_pasien) {
            saat_ini->usia = usia_baru;
            return;
        }
        saat_ini = saat_ini->next;
    }
    printf("Pasien dengan ID %d tidak ditemukan.\n", id_pasien);
}

// Fungsi untuk menghapus pasien dari antrian
void hapusAntrian(Antrian* antrian) {
    if (antrian->depan == NULL) {
        printf("Antrian kosong, tidak ada pasien untuk dihapus.\n");
        return;
    }
    Node* temp = antrian->depan;
    antrian->depan = antrian->depan->next;

    if (antrian->depan == NULL) {
        antrian->belakang = NULL;
    }
    printf("Pasien dengan ID %d berhasil dihapus dari antrian.\n", temp->id_pasien);
    free(temp);
}

// Fungsi utama
int main() {
    Antrian* antrian = buatAntrian();
    int pilihan, id_pasien, usia;
    char nama[50];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Pasien\n");
        printf("2. Tampilkan Antrian\n");
        printf("3. Tambah Pasien Prioritas\n");
        printf("4. Perbarui Usia Pasien\n");
        printf("5. Hapus Pasien dari Antrian\n");
        printf("6. Keluar\n");
        printf("Pilih opsi (1-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan ID Pasien: ");
                scanf("%d", &id_pasien);
                printf("Masukkan Nama Pasien: ");
                scanf("%s", nama);
                printf("Masukkan Usia Pasien: ");
                scanf("%d", &usia);
                tambahAntrian(antrian, id_pasien, nama, usia);
                printf("Pasien dengan ID %d berhasil ditambahkan.\n", id_pasien);
                break;
            case 2:
                tampilkanAntrian(antrian);
                break;
            case 3:
                printf("Masukkan ID Pasien Prioritas: ");
                scanf("%d", &id_pasien);
                printf("Masukkan Nama Pasien Prioritas: ");
                scanf("%s", nama);
                printf("Masukkan Usia Pasien Prioritas: ");
                scanf("%d", &usia);
                tambahPrioritas(antrian, id_pasien, nama, usia);
                printf("Pasien prioritas dengan ID %d berhasil ditambahkan.\n", id_pasien);
                break;
            case 4:
                printf("Masukkan ID Pasien yang ingin diperbarui: ");
                scanf("%d", &id_pasien);
                printf("Masukkan Usia Baru: ");
                scanf("%d", &usia);
                perbaruiUsia(antrian, id_pasien, usia);
                break;
            case 5:
                hapusAntrian(antrian);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    // Membersihkan memori
    while (antrian->depan != NULL) {
        hapusAntrian(antrian);
    }
    free(antrian);

    return 0;
}