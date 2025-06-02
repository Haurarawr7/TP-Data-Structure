
//Program ADT dan Pointer 
//Oleh Haura Agnia Ramadhani Amnun

/* 
1. Buatlah program untuk menyimpan dan menampilkan data dosen (id, NIDN, Nama, dan Prodi) menggunakan konsep ADT struct. 
2. Melanjutkan dari program nomor 1 buatlah fungsi/prosedur untuk mencocokan berdasar kesamaan prodi. 
3. Melanjutkan dari program nomor 2 buatlah fungsi/prosedur untuk edit. 
4. Melanjutkan dari program nomor 3 buatlah fungsi/prosedur untuk delete. 
5. Satukan fungsi/prosedur yang sudah dibuat menjadi program utuh dan pastikan beberapa syarat di bawah ini terpenuhi. 
Persyaratan:
- Buat program dengan menu (misalnya: Tambah Data, Tampilkan Data, Edit Data, Hapus Data, Keluar).
- Pastikan data inputan unik (NIDN dan nama tidak boleh ada yang sama).
- Edit data berdasarkan NIDN (pengguna hanya bisa mengedit data menggunakan NIDN sebagai acuan).
- Hapus data dengan aturan tertentu: 
a. Tampilkan semua data beserta indeks sebelum penghapusan. 
b. Data yang dihapus tidak boleh menggunakan ID lama lagi. 
c. Setelah penghapusan, data yang ada harus mengisi indeks yang kosong. 
d. Tampilkan semua data beserta indeks setelah penghapusan. 

Pada menu tampilkan data terdapat pilihan 
1. Tampilkan data secara umum (semua data ditampilkan) dan, 
2. Tampilkan data secara khusus (Prodi yang sama). 
Data yang ditampilkan adalah (NIDN, Nama, dan Prodi).
Contoh Instruksi 4 poin d: data awal sebelum dihapus 
indeks 0 : (1, 2315432, andika, Pilkom), 
indeks 1 : (2, 2306541, mughits, Ilkom), 
indeks 2 : (3, 2301234, ica, Ilkom), 
indeks 3 : (4, 2315478, raka, Pilkom). 
Data setelah dihapus 
indeks 0 : (1, 2315432, andika, Pilkom), 
indeks 1 : (2, 2306541, mughits, Ilkom), 
indeks 2 : (4, 2315478, raka, Pilkom).

Contoh instruksi 5 bagian tampil khusus. 
Misal yang ingin ditampilkan adalah dari prodi ilkom Data yang tersedia dipenyimpanan (tidak perlu ditampilkan) 
(1, 2315432, andika, Pilkom), 
(2, 2306541, mughits, Ilkom), 
(3, 2301234, ica, Ilkom), 
(4, 2315478, raka, Pilkom). 

Data yang ditampilkan 
NIDN = 2306541 
Nama = mughits 
Prodi = Ilkom 
NIDN = 2301234 
Nama = ica 
Prodi = Ilkom

*/

#include <stdio.h>
#include <string.h>



// Definisi struct untuk Dosen
typedef struct {
    int id;
    char nidn[20];
    char nama[50];
    char prodi[50];
} Dosen;

// Fungsi untuk menampilkan data dosen
void tampilkanDosen(Dosen dosen[], int jumlah) {
    printf("Data Dosen:\n");
    printf("ID\tNIDN\t\tNama\t\tProdi\n"); //  \t membantu untuk menyusun kolom-kolom data dengan rapi, sehingga lebih mudah dibaca
    printf("---------------------------------------------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d\t%s\t%s\t%s\n", dosen[i].id, dosen[i].nidn, dosen[i].nama, dosen[i].prodi);
    }
}

// Fungsi untuk menampilkan data dosen berdasarkan prodi
void tampilkanDosenBerdasarkanProdi(Dosen dosen[], int jumlah) {
    char prodi[50];
    printf("Masukkan Prodi yang ingin ditampilkan (jika tidak ingat tekan 1 untuk menampilkan secara umum): ");
    scanf(" %[^\n]", prodi);
    if (prodi == 1){
        tampilkanDosen(dosen, jumlah);
    }
    else{
        printf("Data Dosen dengan Prodi %s:\n", prodi);
        printf("NIDN\t\tNama\t\tProdi\n");
        printf("---------------------------------------------\n");
        for (int i = 0; i < jumlah; i++) {
            if (strcmp(dosen[i].prodi, prodi) == 0) { //membandingkan dua prodi dosen
                printf("%s\t%s\t%s\n", dosen[i].nidn, dosen[i].nama, dosen[i].prodi);
            }
        }
    }
   
}

// Fungsi untuk memeriksa keunikan NIDN dan Nama agar tidak sama
int isUnique(Dosen dosen[], int jumlahDosen, char *nidn, char *nama) {
    for (int i = 0; i < jumlahDosen; i++) {
        if (strcmp(dosen[i].nidn, nidn) == 0 || strcmp(dosen[i].nama, nama) == 0) {
            return 0; // Tidak unik
        }
    }
    return 1; // Unik
}

// Fungsi untuk menambah data dosen
void tambahDosen(Dosen dosen[], int *jumlahDosen) {
    if (*jumlahDosen >= 100) {
        printf("Data dosen sudah penuh!\n");
        return;
    }
    
    char nidn[20], nama[50];
    printf("Masukkan NIDN Dosen: ");
    scanf("%s", nidn);
    printf("Masukkan Nama Dosen: ");
    scanf(" %[^\n]", nama);
    
    if (!isUnique(dosen, *jumlahDosen, nidn, nama)) {
        printf("NIDN atau Nama sudah ada. Silakan coba lagi.\n");
        return;
    }
    
    dosen[*jumlahDosen].id = *jumlahDosen + 1; // ID otomatis
    strcpy(dosen[*jumlahDosen].nidn, nidn);
    strcpy(dosen[*jumlahDosen].nama, nama);
    printf("Masukkan Prodi Dosen: ");
    scanf(" %[^\n]", dosen[*jumlahDosen].prodi);
    
    (*jumlahDosen)++;
    printf("Data dosen berhasil ditambahkan!\n");
}

// Fungsi untuk mengedit data dosen berdasarkan NIDN
void editDosen(Dosen dosen[], int jumlahDosen) {
    char nidn[20];
    printf("Masukkan NIDN Dosen yang ingin diedit: ");
    scanf("%s", nidn);
    
    for (int i = 0; i < jumlahDosen; i++) {
        if (strcmp(dosen[i].nidn, nidn) == 0) {
            printf("Masukkan Nama Dosen: ");
            scanf(" %[^\n]", dosen[i].nama);
            printf("Masukkan Prodi Dosen: ");
            scanf(" %[^\n]", dosen[i].prodi);
            printf("Data dosen berhasil diedit!\n");
            return;
        }
    }
    printf("Dosen dengan NIDN %s tidak ditemukan!\n", nidn);
}

// Fungsi untuk menghapus data dosen
void hapusDosen(Dosen dosen[], int *jumlahDosen) {
    char nidn[20];
    printf("Data sebelum dihapus:\n");
    tampilkanDosen(dosen, *jumlahDosen);
    
    printf("Masukkan NIDN Dosen yang ingin dihapus: ");
    scanf("%s", nidn);
    
    int found = 0;
    for (int i = 0; i < *jumlahDosen; i++) {
        if (strcmp(dosen[i].nidn, nidn) == 0) {
            found = 1;
            for (int j = i; j < *jumlahDosen - 1; j++) {
                dosen[j] = dosen[j + 1]; // Menggeser data ke depan
            }
            (*jumlahDosen)--; // Mengurangi jumlah dosen
            printf("Data dosen berhasil dihapus!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Dosen dengan NIDN %s tidak ditemukan!\n", nidn); 
    } else {
        printf("Data setelah dihapus:\n");
        tampilkanDosen(dosen, *jumlahDosen);
    }
}

//program utama
int main() {
    Dosen dosen[100];
    int jumlahDosen = 0;
    int pilihan;
    char lanjut;
    int pilih;

    //Menampilkan menu
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Dosen\n");
        printf("2. Tampilkan Data Dosen\n");
        printf("3. Edit Data Dosen\n");
        printf("4. Hapus Data Dosen\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            do {
                tambahDosen(dosen, &jumlahDosen);
                char lanjut;
                printf("Apakah Lanjut? (y/n): ");
                scanf(" %c", &lanjut);
                if (lanjut != 'y' && lanjut != 'Y') {
                    break;
                }
            } while (1);
            break;

            case 2:
            printf("\n1. Tampilkan data umum");
            printf("\n2. Tampilkan data khusus");
            printf("\n3. Kembali");
            printf("\n Pilih: ");
            scanf("%d", &pilih);
            if(pilih == 1){ //jika user menekan 1 maka data akan ditampilkan secara umum
                do {
                    tampilkanDosen(dosen, jumlahDosen);
                    char lanjut;
                    printf("Apakah Lanjut? (y/n): ");
                    scanf(" %c", &lanjut); 
                    if (lanjut != 'y' && lanjut != 'Y') { //jika y/Y maka program kembali di jalankan hingga user menekan n atau huruf/angka yang lain
                        break;
                    }
                } while (1);
                break;
            }
            else if (pilih == 2){ //jika user menekan 2 maka data akan ditampilkan berdasarkan prodi
                do {
                    tampilkanDosenBerdasarkanProdi(dosen, jumlahDosen);
                    char lanjut;
                    printf("Apakah Lanjut? (y/n): ");
                    scanf(" %c", &lanjut);
                    if (lanjut != 'y' && lanjut != 'Y') { //jika y/Y maka program kembali di jalankan hingga user menekan n atau huruf/angka yang lain
                        break;
                    }
                } while (1);
                break;
            }
            else{ //jika user menekan 3 atau yang lain maka kembali kemenu
                break;
            }
            case 3:
                do {
                    editDosen(dosen, jumlahDosen);
                    char lanjut;
                    printf("Apakah Lanjut? (y/n): ");
                    scanf(" %c", &lanjut);
                    if (lanjut != 'y' && lanjut != 'Y') { //jika y/Y maka program kembali di jalankan hingga user menekan n atau huruf/angka yang lain
                        break;
                    }
                } while (1);
                break;
            case 4:
                do {
                    hapusDosen(dosen, &jumlahDosen);
                    char lanjut;
                    printf("Apakah Lanjut? (y/n): ");
                    scanf(" %c", &lanjut);
                    if (lanjut != 'y' && lanjut != 'Y') { //jika y/Y maka program kembali di jalankan hingga user menekan n atau huruf/angka yang lain
                        break;
                    }
                } while (1);
                break;
            case 5:
                printf("Keluar dari program.\n"); //program akan berakhir 
                break;
        }
    } 
    while (pilihan != 5); //program akan berakhir jika user meng inputkan angka yang salah
    
    return 0;
}