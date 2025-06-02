
// Program memecahkan gulungan kuno
// Haura Agnia Ramadhani Aanun

/* 
Setelah melintasi celah dimensi, Nero menemukan sebuah gulungan kuno berisi perintah:
"Masukkan 5 angka, dan susun sebagai Binary Search Tree. Untuk membuka gerbang
berikutnya, tampilkan hasil penyusunan pohon tersebut secara in-order traversal."
Namun gulungan itu tidak memberikan angka secara langsung. Nero kini harus memasukkan
sendiri angka-angka tersebut. Sebagai temannya, bantu Nero membuat program yang
menerima 5 input angka dari user dan mencetak hasil in-order traversal dari BST yang
dibentuk.
Ketentuan:
• Program harus meminta pengguna untuk memasukkan 5 angka.
• Buat BST dari angka-angka tersebut.
• Tampilkan hasil traversal in-order.
Input:
Masukkan 5 angka: 45 12 78 34 56
Output:
In-order Traversal: 12 34 45 56 78
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk simpul dalam Binary Tree
typedef struct Node {
    struct Node *left;  // Pointer ke kiri
    struct Node *right; // Pointer ke kanan
    int label;          // Nilai yang disimpan dalam simpul
} BTNode; // Binary Tree Node

// Fungsi untuk membuat simpul baru
BTNode *createNode(int data) {
    BTNode *new = (BTNode *)malloc(sizeof(BTNode)); // Alokasikan memori untuk simpul baru
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
        insert(&(*root)->left, data); // Rekursif untuk menambahkan ke  kiri
    } else {
        insert(&(*root)->right, data); // Rekursif untuk menambahkan ke  kanan
    }
}

// Fungsi untuk melakukan in-order traversal pada BST
void inorder(BTNode *root) {
    if (root == NULL) return; // Jika simpul kosong, keluar dari fungsi
    
    inorder(root->left); // Traversal  kiri
    printf("%d ", root->label); // Cetak nilai simpul
    inorder(root->right); // Traversal  kanan
}

// Fungsi utama
int main() {
    BTNode *root = NULL; // Inisialisasi root pohon menjadi NULL
    int numbers[5];      // Array untuk menyimpan 5 angka yang dimasukkan pengguna

    printf("Masukkan 5 angka: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]); // Minta pengguna memasukkan angka
        insert(&root, numbers[i]); // Tambahkan angka ke dalam BST
    }

    printf("In-order Traversal: ");
    inorder(root); // Tampilkan hasil in-order traversal
    printf("\n"); // Cetak newline setelah traversal

    return 0; // Kembalikan 0 untuk menandakan program selesai
}