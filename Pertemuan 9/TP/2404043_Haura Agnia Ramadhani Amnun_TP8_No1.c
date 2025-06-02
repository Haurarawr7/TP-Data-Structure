
//Program Sistem Klinik
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Klinik Satomi yang berlokasi di pusat kota baru saja mengembangkan sistem antrian
digital untuk memudahkan pelayanan pasien. Dr. Satomi ingin mengembangkan
program sederhana berbasis menu interaktif untuk membantu staf administrasi
dalam mengelola daftar pasien.
Fitur yang harus disediakan oleh program:
• Menambahkan pasien baru dengan nama dan usia ke dalam antrian.
• Memanggil pasien berikutnya berdasarkan urutan antrian (FIFO).
• Menampilkan seluruh pasien dalam antrian (dari awal hingga akhir).
• Keluar dari program.
Ketentuan:
• Gunakan struktur data queue (FIFO) berbasis linked list atau array dinamis.
• Tampilkan menu berulang sampai user memilih keluar.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data pasien
typedef struct Pasien {
    char nama[100];
    int usia;
    struct Pasien* next; // Pointer ke pasien berikutnya
} Pasien;

// Struktur untuk antrian
typedef struct Queue {
    Pasien* front; // Pointer ke pasien terdepan
    Pasien* rear;  // Pointer ke pasien terakhir
    int size;      // Menyimpan ukuran antrian
} Queue;

// Fungsi untuk membuat antrian
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0; // Inisialisasi ukuran antrian
    return q;
}

// Fungsi untuk memeriksa apakah antrian kosong
int isEmpty(Queue* q) {
    return (q->size == 0);
}

// Fungsi untuk memeriksa apakah antrian penuh
int isFull(Queue* q) {
    // Dalam linked list, antrian tidak pernah penuh
    return 0; // Selalu mengembalikan 0 karena linked list bersifat dinamis
}

// Fungsi untuk menambahkan pasien baru ke dalam antrian
void enqueue(Queue* q, char* nama, int usia) {
    if (isFull(q)) {
        printf("Antrian penuh, tidak dapat menambahkan pasien.\n");
        return;
    }

    Pasien* newPasien = (Pasien*)malloc(sizeof(Pasien));
    strcpy(newPasien->nama, nama);
    newPasien->usia = usia;
    newPasien->next = NULL;

    if (q->rear == NULL) {
        // Jika antrian kosong
        q->front = newPasien;
        q->rear = newPasien;
    } else {
        // Tambahkan pasien ke akhir antrian
        q->rear->next = newPasien;
        q->rear = newPasien;
    }
    q->size++; // Increment ukuran antrian
    printf("Pasien %s telah ditambahkan ke antrian.\n", nama);
}

// Fungsi untuk memanggil pasien berikutnya
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Antrian kosong, tidak ada pasien yang dapat dipanggil.\n");
        return;
    }

    Pasien* temp = q->front;
    printf("Memanggil pasien: %s, Usia: %d\n", temp->nama, temp->usia);
    q->front = q->front->next;

    if (q->front == NULL) {
        // Jika antrian menjadi kosong
        q->rear = NULL;
    }

    free(temp); // Menghapus pasien yang telah dipanggil
    q->size--;  // Decrement ukuran antrian
}

// Fungsi untuk menampilkan seluruh pasien dalam antrian
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Antrian kosong.\n");
        return;
    }

    Pasien* temp = q->front;
    printf("Daftar pasien dalam antrian:\n");
    while (temp != NULL) {
        printf("Nama: %s, Usia: %d\n", temp->nama, temp->usia);
        temp = temp->next;
    }
}

// Fungsi untuk membersihkan antrian
void clearQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Fungsi utama
int main() {
    Queue* q = createQueue();
    int pilihan;
    char nama[100];
    int usia;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Pasien\n");
        printf("2. Panggil Pasien Berikutnya\n");
        printf("3. Tampilkan Seluruh Pasien\n");
        printf("4. Keluar\n");
        printf("Pilih opsi (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama pasien: ");
                scanf("%s", nama);
                printf("Masukkan usia pasien: ");
                scanf("%d", &usia);
                enqueue(q, nama, usia);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Keluar dari program.\n");
                clearQueue(q);
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}
