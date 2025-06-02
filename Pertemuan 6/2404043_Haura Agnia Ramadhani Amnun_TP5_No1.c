#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char nama[30];
    char nim[10];
    char kategori[10];
    int nilai;
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* buatNode(int id, char* nama, char* nim, char* kategori, int nilai) {
    struct Node* nodeBaru = (struct Node*)malloc(sizeof(struct Node));
    nodeBaru->id = id;
    strcpy(nodeBaru->nama, nama);
    strcpy(nodeBaru->nim, nim);
    strcpy(nodeBaru->kategori, kategori);
    nodeBaru->nilai = nilai;
    nodeBaru->prev = NULL; // kosong karena biar bisa di isi alamat adt lain
    nodeBaru->next = NULL; // kosong karena biar bisa di isi alamat adt lain
    return nodeBaru;
}

// Fungsi untuk menambahkan data ke dalam linked list
void tambahData(struct Node** head, struct Node** tail, int* count, char* nama, char* nim, char* kategori, int nilai) {
    struct Node* nodeBaru = buatNode(++(*count), nama, nim, kategori, nilai);

    if (*head == NULL) {
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        struct Node* temp = *head;
        while (temp != NULL && temp->nilai >= nilai) {
            temp = temp->next;
        }

        if (temp == NULL) { // Sisipkan di akhir
            (*tail)->next = nodeBaru;
            nodeBaru->prev = *tail;
            *tail = nodeBaru;
        } else if (temp == *head) { // Sisipkan di awal
            nodeBaru->next = *head;
            (*head)->prev = nodeBaru;
            *head = nodeBaru;
        } else { // Sisipkan di tengah
            nodeBaru->prev = temp->prev;
            nodeBaru->next = temp;
            temp->prev->next = nodeBaru; // menunjuk ke arah adt sebelumnya kemusian di adt tersebut ditunjuk bagian nextnya jadi alamat node baru
            temp->prev = nodeBaru;
        }
    }
}

// Fungsi untuk menampilkan data dari awal ke akhir
void tampilkanDariAwal(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Nama: %s, NIM: %s, Kategori: %s, Nilai: %d\n", temp->id, temp->nama, temp->nim, temp->kategori, temp->nilai);
        temp = temp->next; // temp pindah ke adt setelahnya
    }
}

// Fungsi untuk menampilkan data dari akhir ke awal
void tampilkanDariAkhir(struct Node* tail) {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("ID: %d, Nama: %s, NIM: %s, Kategori: %s, Nilai: %d\n", temp->id, temp->nama, temp->nim, temp->kategori, temp->nilai);
        temp = temp->prev; // temp pindah ke adt sebelumnya
    }
}

// Fungsi untuk menampilkan data berdasarkan kategori
void tampilkanBerdasarkanKategori(struct Node* head, char* kategori) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->kategori, kategori) == 0) {
            printf("ID: %d, Nama: %s, NIM: %s, Kategori: %s, Nilai: %d\n", temp->id, temp->nama, temp->nim, temp->kategori, temp->nilai);
        }
        temp = temp->next;
    }
}

//Program Utama
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int count = 0;
    int pilihan;
    char nama[30], nim[10], kategori[10];
    int nilai;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan List dari Awal ke Akhir\n");
        printf("3. Tampilkan List dari Akhir ke Awal\n");
        printf("4. Tampilkan List Kategori SNBP\n");
        printf("5. Tampilkan List Kategori SNBT\n");
        printf("6. Tampilkan List Kategori Mandiri\n");
        printf("7. Keluar\n");
        printf("Pilih menu (1-7): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                printf("Masukkan Kategori (SNBP/SNBT/Mandiri): ");
                scanf("%s", kategori);
                printf("Masukkan Nilai: ");
                scanf("%d", &nilai);
                tambahData(&head, &tail, &count, nama, nim, kategori, nilai);
                printf("Data berhasil ditambahkan.\n");
                break;

            case 2:
                printf("Tampilkan List dari Awal ke Akhir:\n");
                tampilkanDariAwal(head);
                break;

            case 3:
                printf("Tampilkan List dari Akhir ke Awal:\n");
                tampilkanDariAkhir(tail);
                break;

            case 4:
                printf("Tampilkan List Kategori SNBP:\n");
                tampilkanBerdasarkanKategori(head, "SNBP");
                break;

            case 5:
                printf("Tampilkan List Kategori SNBT:\n");
                tampilkanBerdasarkanKategori(head, "SNBT");
                break;

            case 6:
                printf("Tampilkan List Kategori Mandiri:\n");
                tampilkanBerdasarkanKategori(head, "Mandiri");
                break;

            case 7:
                printf("Keluar dari program.\n");
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}