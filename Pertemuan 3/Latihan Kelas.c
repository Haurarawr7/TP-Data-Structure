 
//Program Linklist
//Oleh Haura Agnia Ramadhani Amnun

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//membuat Link list
typedef struct Node{
    int id;
    char nama[20];
    int usia;
    struct Node *next; //menambahkan alamat ADT selanjutnya di akhir
} Node;

//Membuat ADT
Node* createNode(int id, char nama[], int umur){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->nama, nama);
    newNode->usia = umur;
    newNode->next = NULL;
    return newNode;
}

//Menambahkan awal ADT
void insertAwal(struct Node** head, int id, char nama[], int umur){
    Node* newNode = createNode(id, nama, umur);
        newNode->next = *head;
        *head = newNode;
}

//Menambahkan sebelum ADT setelahnya
void addBefore(int id, char nama[], int usia, int idCari, Node **head) {
    Node *temp = *head;
    Node *prev = NULL;

    Node *newNode = createNode(id, nama, usia);

    // Jika List Berada di depan
    if (temp != NULL && temp->id == idCari) {
        newNode->next = temp;
        *head = newNode;
        return;
    }

    while (temp != NULL && temp->id != idCari) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = newNode;
        newNode->next = temp;
    }
}

//Menambahkan setelah ADT lain
void addAfter(int id, char nama[], int usia, int idCari, Node **head) {
    Node *temp = *head;

    while (temp != NULL && temp->id != idCari) {
        temp = temp->next;
    }

    Node *newNode = createNode(id, nama, usia);
    
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//Menambahkan akhir ADT
void insertAkhir(struct Node** head, int id, char nama[], int umur){
    struct Node* newNode = createNode(id, nama, umur);
    if (*head == NULL) {
        *head = newNode;
        } 
    else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

//Mencetak 
void cetak(Node *head) {
    Node *temp = head;
    if(temp == NULL){
        printf("List kosong\n");
    }
    while(temp!= NULL){
        printf("id : %d\n", temp -> id);
        printf("nama : %s\n", temp -> nama);
        printf("umur : %d\n", temp -> usia);
        temp = temp -> next;
    }
}

//Update data
void updateNode(Node** head, int idCari, char newNama[], int newUmur){
    Node*temp = *head;
    while(temp != NULL){
        if(temp->id == idCari){
            strcpy(temp->nama, newNama);
            temp->usia = newUmur;
            printf("Data Id %d berhasil diperbarui\n", idCari);
            return;
        }
        temp = temp->next;
    }
    printf("Data Id %d tidak ditemukan", idCari);
}

//Delete ADT awal
void DeleteAwal(Node**head){
    if(*head == NULL){
        printf("Linked list kosong!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next; // harus pake kurung untuk akses pointer
    free(temp);
}

void DeleteAkhir(Node ** head){
    if(*head == NULL){
        printf("Linked list kosong!\n");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        *head = NULL;
    }
    else{
        prev->next = NULL;
    }
    free(temp);
}

void DeleteTengah(Node**head, int idCari){
    Node *temp = *head;
    Node *prev = NULL;

    while(temp != NULL && temp->id != idCari){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Data Id %d tidak ditemukan", idCari);
        return;
    }
    if(prev == NULL){
        *head = temp->next;
    }
    else{
        prev->next = temp->next;
        temp->next = NULL;
    }
    free(temp);

}

//Program Utama
int main(){
    Node* head = NULL;
    int id, umur;
    char nama[100];
    int pilihan;
    
    
    insertAkhir(&head, 1, "Icha", 20);
    insertAwal(&head, 2, "Raka", 21);
    insertAkhir(&head, 3, "Dika", 22);
    addBefore(4, "Mughits", 20, 3, &head);
    addAfter(5, "Mughits", 20, 4, &head);
    printf(("\nLinked List setelah insert"));
    cetak(head);
    updateNode(&head, 3, "Haura", 20 );
    printf(("\nLinked List setelah insert2"));
    cetak(head);
    DeleteAwal(&head);
    printf(("\nLinked List setelah insert3"));
    cetak(head);
    DeleteAkhir(&head);
    printf(("\nLinked List setelah insert4"));
    cetak(head);
    DeleteTengah(&head, 4);
    printf(("\nLinked List setelah insert5"));
    cetak(head);


}

