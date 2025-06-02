
//Program Pencatatan Keuangan
//Oleh Haura Agnia Ramadhani Amnun

/*
3. Sandy selalu melakukan pencatatan uang menggunakan spreadsheet, namun dia baru
belajar Singly Linked List sehingga penasaran jika pencatatan uang yang selama ini
dilakukan menggunakan program dengan Singly Linked List. Setiap transaksi terdiri dari
jumlah uang, keterangan, tanggal_transaksi. Program harus memenuhi:
a. Menambahkan transaksi baru (dengan tanggal, keterangan, dan jumlah uang).
b. Menampilkan seluruh transaksi yang telah dicatat.
c. Menghitung serta menampilkan saldo akhir (jumlah keseluruhan dari seluruh
transaksi).
d. Keluar dari program
Contoh Input & Output:
Menu:
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Tampilkan Saldo Akhir
4. Keluar


Pilihan: 1
Masukkan Tanggal (dd/mm/yyyy): 01/01/2023
Masukkan Keterangan: Gaji Bulanan
Masukkan Jumlah (positif untuk pemasukan, negatif untuk pengeluaran): 5000000
Transaksi berhasil ditambahkan!
Menu:
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Tampilkan Saldo Akhir
4. Keluar
Pilihan: 1
Masukkan Tanggal (dd/mm/yyyy): 03/01/2023
Masukkan Keterangan: Belanja Bulanan
Masukkan Jumlah (positif untuk pemasukan, negatif untuk pengeluaran): -1500000
Transaksi berhasil ditambahkan!
Menu:
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Tampilkan Saldo Akhir
4. Keluar
Pilihan: 2
Daftar Transaksi:
Tanggal Keterangan Jumlah
-----------------------------------------------------
01/01/2023 Gaji Bulanan 5000000
03/01/2023 Belanja Bulanan -1500000
Menu:
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Tampilkan Saldo Akhir
4. Keluar
Pilihan: 3
Saldo Akhir: 3500000
Menu:
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Tampilkan Saldo Akhir
4. Keluar
Pilihan: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transaksi {
    char tanggal[11]; // Format dd/mm/yyyy
    char keterangan[100];
    int jumlah;
    struct Transaksi* next;
} Transaksi;

Transaksi* head = NULL;

// Fungsi untuk menambahkan transaksi baru
void tambahTransaksi(char* tanggal, char* keterangan, int jumlah) {
    Transaksi* transaksiBaru = (Transaksi*)malloc(sizeof(Transaksi));
    strcpy(transaksiBaru->tanggal, tanggal);
    strcpy(transaksiBaru->keterangan, keterangan);
    transaksiBaru->jumlah = jumlah;
    transaksiBaru->next = head;
    head = transaksiBaru;
    printf("Transaksi berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan seluruh transaksi
void tampilkanTransaksi() {
    if (head == NULL) {
        printf("Tidak ada transaksi yang dicatat.\n");
        return;
    }

    printf("Daftar Transaksi:\n");
    printf("Tanggal\t\tKeterangan\tJumlah\n");
    printf("-----------------------------------------------------\n");
    Transaksi* temp = head;
    while (temp != NULL) {
        printf("%s\t%s\t%d\n", temp->tanggal, temp->keterangan, temp->jumlah);
        temp = temp->next;
    }
}

// Fungsi untuk menghitung dan menampilkan saldo akhir
void tampilkanSaldoAkhir() {
    int saldo = 0;
    Transaksi* temp = head;
    while (temp != NULL) {
        saldo += temp->jumlah;
        temp = temp->next;
    }
    printf("Saldo Akhir: %d\n", saldo);
}

// Fungsi utama
int main() {
    int pilihan;
    char tanggal[11];
    char keterangan[100];
    int jumlah;

    do {
        printf("Menu:\n");
        printf("1. Tambah Transaksi\n");
        printf("2. Tampilkan Transaksi\n");
        printf("3. Tampilkan Saldo Akhir\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus newline setelah input angka

        switch (pilihan) {
            case 1:
                printf("Masukkan Tanggal (dd/mm/yyyy): ");
                fgets(tanggal, sizeof(tanggal), stdin);
                tanggal[strcspn(tanggal, "\n")] = 0; // Menghapus newline
                getchar();
                printf("Masukkan Keterangan: ");
                fgets(keterangan, sizeof(keterangan), stdin);
                keterangan[strcspn(keterangan, "\n")] = 0; // Menghapus newline
                printf("Masukkan Jumlah (positif untuk pemasukan, negatif untuk pengeluaran): ");
                scanf("%d", &jumlah);
                getchar(); // Menghapus newline setelah input jumlah
                tambahTransaksi(tanggal, keterangan, jumlah);
                break;
            case 2:
                tampilkanTransaksi();
                break;
            case 3:
                tampilkanSaldoAkhir();
                break;
            case 4:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    // Membebaskan memori yang digunakan oleh daftar transaksi
    Transaksi* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

//wajar gak sih capek dan burnout? kadang binggung dan ngerasa salah jurusan...
//maaf malah curhat, lagi ngerasa salah arah padahal otu dah bayarin ukt segede itu tapi aku kayak gini...