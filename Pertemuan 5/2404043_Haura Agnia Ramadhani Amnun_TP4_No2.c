
//Program Pencatatan pertandingan
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Sebuah liga sepak bola amatir memiliki sistem pencatatan jadwal pertandingan yang
menggunakan Single Linked List.
Aturan dalam sistem ini:
- Jadwal pertandingan baru akan ditammbahkan di akhir daftar
- jika ada pertandangin penting, jadwalnya bisa disisipkan di tengah daftar pada posisi
tertentu (insert tengah)
- panitia dapat melihat seluruh jadwal pertandingan
- jika ada kesalahan pencatatan, nama tim atau jadwal pertandingan bisa diperbarui
berdasarkan ID pertandingan
- jika suatu pertandingan dibatalkan, maka pertandingan tersebut dihapus dari posisi
tengah dalam daftar (hapus tengah)
- untuk mempermudah panitia dalam memasukkan data, terdapat berbagai pilihan
menu pada sistem tersebut
Menu:
1. Tambah petandingan di akhir
2. Tambah pertandingan di tengah
3. Lihat jadwal pertandingan
4. Perbarui data pertandingan
5. Hapus pertandingan di tengah
6. Keluar

Input (Insert Data):
1
101
Team Alpha
Team Beta
1
102
Team Gamma
Team Delta
2
103
Team Epsilon
Team Zeta
2
3
Output:
Daftar Pertandingan:
ID: 101 | Team Alpha vs Team Beta
ID: 103 | Team Epsilon vs Team Zeta
ID: 102 | Team Gamma vs Team Delta

Input (Update Data):
4
102
Team Gamma FC
Team Delta United
Output:
Pertandingan ID 102 berhasil diperbarui!

Input (Hapus Data):
5
2
Output:
Pertandingan di posisi 2 berhasil dihapus!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id_pertandingan;
    char tim1[50];
    char tim2[50];
    struct Node* next;
} Node;

typedef struct Jadwal {
    Node* head;
} Jadwal;

// Fungsi untuk membuat jadwal
Jadwal* buatJadwal() {
    Jadwal* jadwal = (Jadwal*)malloc(sizeof(Jadwal));
    jadwal->head = NULL;
    return jadwal;
}

// Fungsi untuk menambahkan pertandingan di akhir
void tambahPertandinganAkhir(Jadwal* jadwal, int id_pertandingan, const char* tim1, const char* tim2) {
    Node* node_baru = (Node*)malloc(sizeof(Node));
    node_baru->id_pertandingan = id_pertandingan;
    strcpy(node_baru->tim1, tim1);
    strcpy(node_baru->tim2, tim2);
    node_baru->next = NULL;

    if (jadwal->head == NULL) {
        jadwal->head = node_baru;
    } else {
        Node* saat_ini = jadwal->head;
        while (saat_ini->next != NULL) {
            saat_ini = saat_ini->next;
        }
        saat_ini->next = node_baru;
    }
}

// Fungsi untuk menambahkan pertandingan di tengah
void tambahPertandinganTengah(Jadwal* jadwal, int id_pertandingan, const char* tim1, const char* tim2, int posisi) {
    Node* node_baru = (Node*)malloc(sizeof(Node));
    node_baru->id_pertandingan = id_pertandingan;
    strcpy(node_baru->tim1, tim1);
    strcpy(node_baru->tim2, tim2);
    node_baru->next = NULL;

    if (posisi == 1) {
        node_baru->next = jadwal->head;
        jadwal->head = node_baru;
        return;
    }

    Node* saat_ini = jadwal->head;
    for (int i = 1; i < posisi - 1 && saat_ini != NULL; i++) {
        saat_ini = saat_ini->next;
    }

    if (saat_ini == NULL) {
        printf("Posisi tidak valid, pertandingan ditambahkan di akhir.\n");
        free(node_baru);
        tambahPertandinganAkhir(jadwal, id_pertandingan, tim1, tim2);
    } else {
        node_baru->next = saat_ini->next;
        saat_ini->next = node_baru;
    }
}

// Fungsi untuk menampilkan jadwal pertandingan
void tampilkanJadwal(Jadwal* jadwal) {
    Node* saat_ini = jadwal->head;
    if (saat_ini == NULL) {
        printf("Jadwal pertandingan kosong.\n");
        return;
    }
    printf("Daftar Pertandingan:\n");
    while (saat_ini != NULL) {
        printf("ID: %d | %s vs %s\n", saat_ini->id_pertandingan, saat_ini->tim1, saat_ini->tim2);
        saat_ini = saat_ini->next;
    }
}

// Fungsi untuk memperbarui data pertandingan
void perbaruiPertandingan(Jadwal* jadwal, int id_pertandingan, const char* tim1, const char* tim2) {
    Node* saat_ini = jadwal->head;
    while (saat_ini != NULL) {
        if (saat_ini->id_pertandingan == id_pertandingan) {
            strcpy(saat_ini->tim1, tim1);
            strcpy(saat_ini->tim2, tim2);
            printf("Pertandingan ID %d berhasil diperbarui!\n", id_pertandingan);
            return;
        }
        saat_ini = saat_ini->next;
    }
    printf("Pertandingan dengan ID %d tidak ditemukan.\n", id_pertandingan);
}

// Fungsi untuk menghapus pertandingan di tengah
void hapusPertandinganTengah(Jadwal* jadwal, int posisi) {
    if (jadwal->head == NULL) {
        printf("Jadwal pertandingan kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    Node* saat_ini = jadwal->head;

    if (posisi == 1) {
        jadwal->head = saat_ini->next;
        free(saat_ini);
        printf("Pertandingan di posisi %d berhasil dihapus!\n", posisi);
        return;
    }

    Node* sebelumnya = NULL;
    for (int i = 1; i < posisi && saat_ini != NULL; i++) {
        sebelumnya = saat_ini;
        saat_ini = saat_ini->next;
    }

    if (saat_ini == NULL) {
        printf("Posisi tidak valid, tidak ada pertandingan yang dihapus.\n");
        return;
    }

    sebelumnya->next = saat_ini->next;
    free(saat_ini);
    printf("Pertandingan di posisi %d berhasil dihapus!\n", posisi);
}

// Fungsi utama
int main() {
    Jadwal* jadwal = buatJadwal();
    int pilihan, id_pertandingan, posisi;
    char tim1[50], tim2[50];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah pertandingan di akhir\n");
        printf("2. Tambah pertandingan di tengah\n");
        printf("3. Lihat jadwal pertandingan\n");
        printf("4. Perbarui data pertandingan\n");
        printf("5. Hapus pertandingan di tengah\n");
        printf("6. Keluar\n");
        printf("Pilih opsi (1-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan ID Pertandingan: ");
                scanf("%d", &id_pertandingan);
                printf("Masukkan Nama Tim 1: ");
                scanf("%s", tim1);
                printf("Masukkan Nama Tim 2: ");
                scanf("%s", tim2);
                tambahPertandinganAkhir(jadwal, id_pertandingan, tim1, tim2);
                break;
            case 2:
                printf("Masukkan ID Pertandingan: ");
                scanf("%d", &id_pertandingan);
                printf("Masukkan Nama Tim 1: ");
                scanf("%s", tim1);
                printf("Masukkan Nama Tim 2: ");
                scanf("%s", tim2);
                printf("Masukkan Posisi untuk menyisipkan: ");
                scanf("%d", &posisi);
                tambahPertandinganTengah(jadwal, id_pertandingan, tim1, tim2, posisi);
                break;
            case 3:
                tampilkanJadwal(jadwal);
                break;
            case 4:
                printf("Masukkan ID Pertandingan yang ingin diperbarui: ");
                scanf("%d", &id_pertandingan);
                printf("Masukkan Nama Tim 1 Baru: ");
                scanf("%s", tim1);
                printf("Masukkan Nama Tim 2 Baru: ");
                scanf("%s", tim2);
                perbaruiPertandingan(jadwal, id_pertandingan, tim1, tim2);
                break;
            case 5:
                printf("Masukkan Posisi pertandingan yang ingin dihapus: ");
                scanf("%d", &posisi);
                hapusPertandinganTengah(jadwal, posisi);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    // Membersihkan memori
    while (jadwal->head != NULL) {
        hapusPertandinganTengah(jadwal, 1);
    }
    free(jadwal);

    return 0;
}
