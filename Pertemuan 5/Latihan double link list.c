
//Program Doublelinklist
//Oleh Haura Agnia Ramadhani Amnun

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//membuat Link list
typedef struct List{
    int id, nilai;
    int nama[50], nim[20];
    struct List *next; //menambahkan alamat ADT selanjutnya di akhir
    struct List *prev;
} List;

List* createList(int id, int nilai, char nama[], char nim[]){
    List* baru = (List*)malloc(sizeof(List));
    baru->id = id;
    baru->nilai = nilai;
    strcpy(baru->nama, nama);
    strcpy(baru->nim, nim);
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void addAwal(int id, int nilai, char nama[], char nim[], List ** head){
    List* baru = createList(id, nilai, nama, nim);
    baru->next = *head;
    (*head)->prev = baru;
    *head = baru;
}

void addAkhir(int id, int nilai, char nama[], char nim[], List ** head){
    List *temp = *head;
    if (*head == NULL) {
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    List* baru = createList(id, nilai, nama, nim);
    temp->next = baru;
    baru->prev = temp;
    
}

void addbefore(int id, int nilai, char nama[], char nim[], char cariNim, List ** head){
    List* baru = createList(id, nilai, nama, nim);
    List *temp = *head;
    if (*head == NULL) {
        return;
        }
    while (strcmp(temp->nim, cariNim) != 0) {
        temp = temp->next;
    }

    baru->prev = temp->prev;
    baru->next = temp;
    temp->prev->next = baru;
    temp->prev = baru;
}

void addAfter(int id, int nilai, char nama[], char nim[], char cariNIM[], List **head) {
    List *baru = createList(id, nilai, nama, nim);
    List *temp = *head;

    if (*head == NULL)
    {
        return;
    }
    
    while (temp->next != NULL && strcmp(temp->nim, cariNIM) != 0)
    {
        temp = temp->next;
    }
    
    baru->next = temp->next;
    baru->prev = temp;
    temp->next->prev = baru;
    temp->next = baru;
}

void cetak(List *head){
    List *temp = head;

    while(temp != NULL){
        printf("%d\n", temp -> id);
        printf("%d\n", temp -> nilai);
        printf("%s\n", temp -> nama);
        printf("%s\n", temp -> nim);
        temp = temp -> next;
    }    
}

int main(){
    List* head = NULL;
    int id, nilai;
    char nama[50], nim[50], cariNIM[50];
    addAwal(1, 90, "Haura", "A1602101", &head);
    addAwal(2, 80, "Agnia", "A1602102", &head);
    cetak(head);
}