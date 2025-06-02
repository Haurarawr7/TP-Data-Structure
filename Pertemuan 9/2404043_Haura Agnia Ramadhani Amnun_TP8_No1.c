

//Program Sistem Percetakan
//Oleh Haura Agnia Ramadhani Amnun 2404043

/*
Sebuah kantor memiliki sistem pencetakan dokumen berdasarkan urutan permintaan dari
pengguna. Setiap dokumen dimasukkan ke dalam antrian cetak sesuai waktu permintaan.
Buatlah program untuk mensimulasikannya.
Ketentuan:
• Tambahkan nama dokumen ke dalam antrian.
• Hapus dokumen dari depan antrian saat dicetak.
• Tampilkan seluruh isi antrian saat ini.
Input:
Input jumlah dokumen: 3
Masukkan nama dokumen ke-1: laporan.pdf
Masukkan nama dokumen ke-2: faktur.docx
Masukkan nama dokumen ke-3: notulen.txt
Cetak berapa dokumen : 1
Output:
Dokumen dicetak: laporan.pdf
Dokumen tersisa dalam antrian:
faktur.docx
notulen.txt
*/

#include <stdio.h>
#include <string.h>

#define MAX 5
#define MAX_NAMA 100

typedef struct queue {
    int head;
    int tail;
    char data[MAX][MAX_NAMA]; // Menyimpan nama dokumen
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

void enqueue(queue *q, char *dokumen) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->head = 0; // Jika antrian kosong, set head ke 0
        }
        q->tail = (q->tail + 1) % MAX; // Update tail
        strcpy(q->data[q->tail], dokumen); // Menyalin nama dokumen ke antrian
    } else {
        printf("Antrian Penuh!\n");
    }
}

void dequeue(queue *q) {
    if (!isEmpty(q)) {
        printf("Dokumen dicetak: %s\n", q->data[q->head]);
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
        printf("Dokumen tersisa dalam antrian:\n");
        int i = q->head;
        while (1) {
            printf("%s\n", q->data[i]);
            if (i == q->tail) break; // Jika sudah sampai tail
            i = (i + 1) % MAX; // Update index
        }
    }
}

int main() {
    queue q;
    createqueue(&q);
    
    int jumlah_dokumen;
    printf("Input jumlah dokumen: ");
    scanf("%d", &jumlah_dokumen);
    
    // Memastikan jumlah dokumen tidak melebihi kapasitas antrian
    if (jumlah_dokumen > MAX) {
        printf("Jumlah dokumen melebihi kapasitas antrian (%d).\n", MAX);
        return 1;
    }

    // Menambahkan dokumen ke dalam antrian
    for (int i = 0; i < jumlah_dokumen; i++) {
        char dokumen[MAX_NAMA];
        printf("Masukkan nama dokumen ke-%d: ", i + 1);
        scanf("%s", dokumen);
        enqueue(&q, dokumen);
    }

    // Menampilkan isi antrian saat ini
    printf("\nDokumen dalam antrian:\n");
    cetak(&q);

    // Input jumlah dokumen yang akan dicetak
    int cetak_jumlah;
    printf("\nCetak berapa dokumen: ");
    scanf("%d", &cetak_jumlah);

    // Mencetak dokumen dari antrian
    for (int i = 0; i < cetak_jumlah; i++) {
        dequeue(&q);
    }

    // Menampilkan sisa dokumen dalam antrian
    cetak(&q);

    return 0;

}