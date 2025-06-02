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
    char nama;
} Simpul;

typedef struct Graph {
    Simpul* first;
} Graph;

Simpul* createSimpul(Graph* G, char nama) {
    Simpul* simpulBaru = (Simpul*)malloc(sizeof(Simpul));
    simpulBaru->nama = nama;
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
}

void cetakGraph(Graph* G) {
    Simpul* tempSimpul = G->first;
    if (tempSimpul != NULL) {
        while (tempSimpul != NULL) {
            printf("\nSimpul %c\n", tempSimpul->nama);
            Edge* tempEdge = tempSimpul->jalur;
            while (tempEdge != NULL) {
                printf("terhubung dengan simpul %c, dengan Cost %d\n", tempEdge->tujuan->nama, tempEdge->nilai);
                tempEdge = tempEdge->next_jalur;
            }
            tempSimpul = tempSimpul->next;
        }
    } else {
        printf("Graph Kosong\n");
    }
}

Simpul* cariSimpul(char c, Graph* G) {
    Simpul* hasil = NULL;
    Simpul* bantu = G->first;
    int ketemu = 0;
    while (bantu != NULL && ketemu == 0) {
        if (bantu->nama == c) {
            hasil = bantu;
            ketemu = 1;
        } else {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delEdge(char tujuan, Simpul *awal) {
    Edge *hapus = awal->jalur;
    if (hapus == NULL) {
        printf("Tidak ada jalur simpul tujuan\n");
        return;
    }

    Edge *prev = NULL;
    int ketemu = 0; // Corrected initialization

    while (hapus != NULL && ketemu == 0) {
        if (hapus->tujuan->nama == tujuan) { // Corrected field access
            ketemu = 1;
        } else {
            prev = hapus;
            hapus = hapus->next_jalur;
        }
    }

    if (ketemu) {
        if (prev == NULL) {
            awal->jalur = hapus->next_jalur;
        } else {
            prev->next_jalur = hapus->next_jalur;
        }
        free(hapus);
    } else {
        printf("Jalur ke simpul %c tidak ditemukan\n", tujuan);
    }

}

void delsimpul (char c, Graph g){
    Simpul *hapus = g->first;
    if (hapus == NULL) {
        printf("Tidak ada simpul dengan info karakter masukan\n");
        return;
    }

    if(ketemu){
        Simpul *temp = g->first;

        while (temp != NULL){
            if(temp != hapus){
                delEdge(hapus->label, temp);
            }
            temp = temp->next;
        }
        if (prev == NULL){
            g->first = hapus->next;
            hapus->next = NULL;
        }
        else{
            if (hapus->next == NULL){
                prev->next = NULL;
            }
            else{
                prev->next = hapus->next;
                hapus->next = NULL;
            }
        }
        free(hapus);
    }
}


int main() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->first = NULL;

    Simpul *A, *B, *C, *D, *E;

    createSimpul(g, 'A');
    createSimpul(g, 'B');
    createSimpul(g, 'C');
    createSimpul(g, 'D');
    createSimpul(g, 'E');

    A = cariSimpul('A', g);
    B = cariSimpul('B', g);
    C = cariSimpul('C', g);
    D = cariSimpul('D', g);
    E = cariSimpul('E', g);

    addEdge(A, B, 3);
    addEdge(B, E, 2);
    addEdge(B, D, 1);
    addEdge(C, A, 2);
    addEdge(D, C, 3);
    addEdge(E, C, 1);
    addEdge(E, D, 4);

    printf("------------ GRAPH ------------");
    cetakGraph(g);

    // Free allocated memory
    freeGraph(g);

    return 0;
}
