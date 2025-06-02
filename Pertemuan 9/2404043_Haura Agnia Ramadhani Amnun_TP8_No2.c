
//Program Sistem Bioskop
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Sistem tiket bioskop melayani pengunjung berdasarkan urutan kedatangan. Setiap
pengunjung memiliki nomor antrean. Buat program yang:
• Menambahkan nomor antrean ke queue.
• Menghapus nomor antrean saat pelanggan dilayani.
• Menampilkan seluruh nomor antrean yang masih menunggu.
Input:
Masukkan jumlah pengunjung: 4
Masukkan nomor antrean ke-1: 101
Masukkan nomor antrean ke-2: 102
Masukkan nomor antrean ke-3: 103
Masukkan nomor antrean ke-4: 104
Jumlah Pelanggan yang dilayani : 2
Output:
Nomor antrean yang telah dilayani: 101, 102
Sisa antrean:
103
104
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
