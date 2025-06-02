
// Program mencari pedang yamato
// Haura Agnia Ramadhani Amnun 2404043

/*
Vergil sedang mencari pedang legendaris "Yamato" yang tersembunyi di salah satu node
dalam sebuah Binary Search Tree. Pedang itu hanya bisa ditemukan jika nilai node yang dicari
sesuai dengan kode yang diberikan oleh roh pohon. Vergil memberikan Anda tugas untuk
mencari apakah nilai tertentu (misalnya: 25) ada di dalam pohon tersebut:
Pohon BST sudah dibangun terlebih dahulu dengan nilai: 40, 25, 60, 10, 30, 50, 70.
Ketentuan:

• Buat BST dari angka-angka yang disebutkan.
• Buat fungsi untuk mencari nilai tertentu dalam BST.
• Cetak apakah pedang ditemukan atau tidak.

Input:
25
Output:
Pedang ditemukan!
Input:
15
Output:
Pedang tidak ditemukan.
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk simpul dalam Binary Tree
typedef struct Node {
    struct Node *left;  // Pointer ke  kiri
    struct Node *right; // Pointer ke  kanan
    int label;          // Nilai yang disimpan di simpul
} BTNode;

// Fungsi untuk membuat simpul baru
BTNode *createNode(int data) {
    BTNode *new = (BTNode *)malloc(sizeof(BTNode));
    new->label = data; // Set nilai simpul
    new->left = NULL;  // Inisialisasi  kiri menjadi NULL
    new->right = NULL; // Inisialisasi  kanan menjadi NULL
    return new;        // Kembalikan simpul baru
}

// Fungsi untuk menambahkan nilai ke dalam Binary Search Tree
void insert(BTNode **root, int data) {
    if (*root == NULL) {
        *root = createNode(data); // Jika pohon kosong, buat simpul baru
    } else if (data <= (*root)->label) { // Jika data kurang dari atau sama dengan label simpul
        insert(&(*root)->left, data); // Masukkan ke  kiri
    } else {
        insert(&(*root)->right, data); // Masukkan ke  kanan
    }
}

// Fungsi untuk mencari nilai dalam BST
int search(BTNode *root, int data) {
    if (root == NULL) {
        return 0; // Jika simpul kosong, nilai tidak ditemukan
    }
    if (root->label == data) {
        return 1; // Jika nilai ditemukan
    } else if (data < root->label) {
        return search(root->left, data); // Cari di  kiri
    } else {
        return search(root->right, data); // Cari di  kanan
    }
}

// Fungsi utama
int main() {
    BTNode *root = NULL; // Inisialisasi root pohon menjadi NULL

    // Membuat BST dengan nilai yang telah ditentukan
    int values[] = {40, 25, 60, 10, 30, 50, 70};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        insert(&root, values[i]); // Tambahkan nilai ke dalam BST
    }

    int searchValue;
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &searchValue); // Minta pengguna memasukkan nilai yang ingin dicari

    // Mencari nilai dalam BST
    if (search(root, searchValue)) {
        printf("Pedang ditemukan!\n"); // Jika nilai ditemukan
    } else {
        printf("Pedang tidak ditemukan.\n"); // Jika nilai tidak ditemukan
    }

    return 0; // Kembalikan 0 untuk menandakan program selesai
}