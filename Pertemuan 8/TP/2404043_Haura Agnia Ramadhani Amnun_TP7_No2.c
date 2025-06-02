

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prioritas; // Menyimpan prioritas pengiriman
} Barang;

typedef struct {
    Barang antrian[100]; // Menyimpan antrian barang
    int jumlah; // Menyimpan jumlah barang dalam antrian
} AntrianPengiriman;

void initAntrian(AntrianPengiriman *antrian) { // Inisialisasi antrian
    antrian->jumlah = 0; // Antrian kosong
}

int isFull(AntrianPengiriman *antrian) { // Memeriksa apakah antrian penuh
    return antrian->jumlah >= 100;
}

int isEmpty(AntrianPengiriman *antrian) { // Memeriksa apakah antrian kosong
    return antrian->jumlah == 0;
}

int isValid(AntrianPengiriman *antrian) { // Memeriksa validitas urutan pengiriman
    for (int i = 0; i < antrian->jumlah - 1; i++) {
        if (antrian->antrian[i].prioritas > antrian->antrian[i + 1].prioritas) {
            return 0; // Urutan tidak valid
        }
    }
    return 1; // Urutan valid
}

void tambahBarang(AntrianPengiriman *antrian, int prioritas) { // Menambahkan barang ke antrian
    if (!isFull(antrian)) {
        antrian->antrian[antrian->jumlah].prioritas = prioritas;
        antrian->jumlah++;
    } else {
        printf("Antrian sudah penuh, tidak bisa menambahkan barang dengan prioritas %d.\n", prioritas);
    }
}

int main() {
    AntrianPengiriman antrian;
    initAntrian(&antrian); // Inisialisasi antrian

    int jumlah_barang;
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah_barang);

    printf("Masukkan prioritas pengiriman (dipisah spasi): ");
    for (int i = 0; i < jumlah_barang; i++) {
        int prioritas;
        scanf("%d", &prioritas);
        tambahBarang(&antrian, prioritas);
    }

    // Memeriksa validitas urutan pengiriman
    if (isValid(&antrian)) {
        printf("Urutan pengiriman VALID.\n");
    } else {
        printf("Urutan pengiriman TIDAK VALID! Barang dengan prioritas lebih rendah dikirim lebih dulu.\n");
    }

    return 0;
}