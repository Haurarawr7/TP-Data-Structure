
//Program Perbaikan Sistem tiket
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Dalam sebuah antrian terdapat deretan nomor tiket. Karena kesalahan sistem, semua
nomor ganjil harus diproses lebih dulu, diikuti oleh semua nomor genap, tanpa mengubah
urutan relatif dalam masing-masing kelompok.
Ketentuan:
• Baca input nomor tiket dan masukkan ke dalam queue.
• Buat ulang queue berdasarkan ketentuan di atas.
• Tampilkan queue hasil penyusunan ulang.
Input:
Masukkan jumlah elemen: 6
Masukkan elemen queue: 8 3 6 1 9 4
Output:
Queue setelah disusun ulang:
3 1 9 8 6 4
*/ 

#include <stdio.h>

#define MAX 5

typedef struct queue {
    int head;
    int tail;
    int data[MAX]; // Menyimpan nomor antrean
} queue;

void createqueue(queue *q) {
    q->head = -1;
    q->tail = -1;
}

int isEmpty(queue *q) {
    return (q->head == -1 && q->tail == -1);
}

int isFull(queue *q) {
    return ((q->tail + 1) % MAX == q->head);
}

void enqueue(queue *q, int nomor) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->head = 0; // Jika antrian kosong, set head ke 0
        }
        q->tail = (q->tail + 1) % MAX; // Update tail
        q->data[q->tail] = nomor; // Menyimpan nomor antrean ke antrian
    } else {
        printf("Antrian Penuh!\n");
    }
}

void dequeue(queue *q, int *nomor) {
    if (!isEmpty(q)) {
        *nomor = q->data[q->head]; // Ambil nomor antrean yang dilayani
        if (q->head == q->tail) {
            // Jika hanya ada satu elemen
            q->head = q->tail = -1;
        } else {
            q->head = (q->head + 1) % MAX; // Update head
        }
    } else {
        printf("Antrian Kosong\n");
    }
}

void cetak(queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong.\n");
    } else {
        printf("Sisa antrean:\n");
        int i = q->head;
        while (1) {
            printf("%d\n", q->data[i]);
            if (i == q->tail) break; // Jika sudah sampai tail
            i = (i + 1) % MAX; // Update index
        }
    }
}

int main() {
    queue q;
    createqueue(&q);
    
    int jumlah_pengunjung;
    printf("Masukkan jumlah pengunjung: ");
    scanf("%d", &jumlah_pengunjung);
    
    // Memastikan jumlah pengunjung tidak melebihi kapasitas antrian
    if (jumlah_pengunjung > MAX) {
        printf("Jumlah pengunjung melebihi kapasitas antrian (%d).\n", MAX);
        return 1;
    }

    // Menambahkan nomor antrean ke dalam antrian
    for (int i = 0; i < jumlah_pengunjung; i++) {
        int nomor;
        printf("Masukkan nomor antrean ke-%d: ", i + 1);
        scanf("%d", &nomor);
        enqueue(&q, nomor);
    }

    // Input jumlah pelanggan yang dilayani
    int jumlah_dilayani;
    printf("Jumlah Pelanggan yang dilayani: ");
    scanf("%d", &jumlah_dilayani);

    // Mencetak nomor antrean yang dilayani
    printf("Nomor antrean yang telah dilayani: ");
    for (int i = 0; i < jumlah_dilayani; i++) {
        int nomor_dilayani;
        dequeue(&q, &nomor_dilayani);
        if (i > 0) {
            printf(", "); // Menambahkan koma untuk pemisah
        }
        printf("%d", nomor_dilayani);
    }
    printf("\n");

    // Menampilkan sisa antrean
    cetak(&q);

    return 0;
}