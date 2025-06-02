#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    struct Edge* next_jalur;
    struct Simpul* tujuan;
    int nilai;
} Edge;

typedef struct Simpul {
    Edge* jalur;
    struct Simpul* next;
    char nama[50]; 
} Simpul;

typedef struct Graph {
    Simpul* first;
} Graph;

// Fungsi untuk membuat graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->first = NULL;
    return graph;
}

// Fungsi untuk menambahkan simpul
Simpul* createSimpul(Graph* G, const char* nama) {
    Simpul* simpulBaru = (Simpul*)malloc(sizeof(Simpul));
    strcpy(simpulBaru->nama, nama);
    simpulBaru->jalur = NULL;
    simpulBaru->next = NULL;

    if (G->first == NULL) {
        G->first = simpulBaru;
    } else {
        Simpul* akhir = G->first;
        while (akhir->next != NULL) {
            akhir = akhir->next;
        }
        akhir->next = simpulBaru;
    }
    return simpulBaru; // Mengembalikan simpul baru
}

// Fungsi untuk menambahkan jalur antar-simpul
void addEdge(Simpul* awal, Simpul* akhir, int nilai) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->nilai = nilai;
    newEdge->next_jalur = NULL;
    newEdge->tujuan = akhir;

    if (awal->jalur == NULL) {
        awal->jalur = newEdge;
    } else {
        Edge* jalurAkhir = awal->jalur;
        while (jalurAkhir->next_jalur != NULL) {
            jalurAkhir = jalurAkhir->next_jalur;
        }
        jalurAkhir->next_jalur = newEdge;
    }

    // Tambahkan edge balik untuk jalur bidirectional
    newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->nilai = nilai;
    newEdge->next_jalur = NULL;
    newEdge->tujuan = awal;

    if (akhir->jalur == NULL) {
        akhir->jalur = newEdge;
    } else {
        Edge* jalurAkhir = akhir->jalur;
        while (jalurAkhir->next_jalur != NULL) {
            jalurAkhir = jalurAkhir->next_jalur;
        }
        jalurAkhir->next_jalur = newEdge;
    }
}

// Fungsi untuk mencetak graph
void cetakGraph(Graph* G) {
    Simpul* tempSimpul = G->first;
    if (tempSimpul != NULL) {
        while (tempSimpul != NULL) {
            printf("Lokasi: %s\n", tempSimpul->nama);
            Edge* tempEdge = tempSimpul->jalur;
            while (tempEdge != NULL) {
                printf("- Terhubung dengan: %s (cost %d)\n", tempEdge->tujuan->nama, tempEdge->nilai);
                tempEdge = tempEdge->next_jalur;
            }
            printf("\n");
            tempSimpul = tempSimpul->next;
        }
    } else {
        printf("Graph Kosong\n");
    }
}

// Fungsi untuk mencari simpul berdasarkan nama
Simpul* cariSimpul(const char* c, Graph* G) {
    Simpul* bantu = G->first;
    while (bantu != NULL) {
        if (strcmp(bantu->nama, c) == 0) {
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL; // Jika tidak ditemukan
}

// Fungsi utama
int main() {
    Graph* g = createGraph();

    // Menambahkan simpul
    createSimpul(g, "Kolam");
    createSimpul(g, "Ladang Bunga");
    createSimpul(g, "Gua Kupu-Kupu");
    createSimpul(g, "Rumah Tikus Tanah");
    createSimpul(g, "Istana Peri");
    createSimpul(g, "Rumah Thumbelina");

    // Cari simpul berdasarkan nama
    Simpul* kolam = cariSimpul("Kolam", g);
    Simpul* ladangBunga = cariSimpul("Ladang Bunga", g);
    Simpul* guaKupukupu = cariSimpul("Gua Kupu-Kupu", g);
    Simpul* rumahTikus = cariSimpul("Rumah Tikus Tanah", g);
    Simpul* istanaPeri = cariSimpul("Istana Peri", g);
    Simpul* rumahThumbelina = cariSimpul("Rumah Thumbelina", g);

    // Menyambungkan lokasi dengan jalur 
    addEdge(kolam, ladangBunga, 1);
    addEdge(ladangBunga, guaKupukupu, 1);
    addEdge(guaKupukupu, rumahTikus, 1);
    addEdge(rumahTikus, istanaPeri, 1);
    addEdge(istanaPeri, rumahThumbelina, 1);
    addEdge(guaKupukupu, rumahThumbelina, 1);

    // Cetak graph untuk lihat hasil koneksi
     printf("------------ GRAPH ------------");
    cetakGraph(g);

    return 0;
}