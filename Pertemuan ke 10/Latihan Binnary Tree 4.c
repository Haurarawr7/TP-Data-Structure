
//Program membuka kunci gerbang
//Haura Agnia Ramadhani Amnun

/*
Lady masuk ke dalam labirin berbentuk pohon biner. Untuk membuka kunci gerbang, dia
harus mengetahui berapa banyak node daun (leaf node) di dalam pohon tersebut. Setiap node
daun adalah portal ke dimensi tersembunyi.
Tugasmu adalah membantu Lady dengan membuat program yang menerima beberapa angka
sebagai input untuk membentuk BST, lalu menghitung jumlah leaf node dalam pohon tersebut.
Ketentuan:

• Program menerima n angka dari pengguna (maksimal 10 angka).
• Bangun BST.
• Hitung jumlah node yang tidak memiliki \ kiri maupun kanan (leaf).

Input:
Masukkan jumlah data: 7
Masukkan angka: 50 30 70 20 40 60 80
Output:
Jumlah node daun: 4
*/

#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk simpul dalam Binary Tree
typedef struct Node {
    struct Node *left;  // Pointer ke kiri
    struct Node *right; // Pointer ke kanan
    int label;          // Nilai yang disimpan di simpul
} BTNode;

// Fungsi untuk membuat simpul baru
BTNode *createNode(int data) {
    BTNode *new = (BTNode *)malloc(sizeof(BTNode));
    new->label = data; // Set nilai simpul
    new->left = NULL;  // Inisialisasi ke kiri menjadi NULL
    new->right = NULL; // Inisialisasi ke kanan menjadi NULL
    return new;        // Kembalikan simpul baru
}

// Fungsi untuk menambahkan nilai ke dalam Binary Search Tree
void insert(BTNode **root, int data) {
    if (*root == NULL) {
        *root = createNode(data); // Jika pohon kosong, buat simpul baru
    } else if (data <= (*root)->label) { // Jika data kurang dari atau sama dengan label simpul
        insert(&(*root)->left, data); // Masukkan ke kiri
    } else {
        insert(&(*root)->right, data); // Masukkan ke kanan
    }
}

// Fungsi untuk menghitung jumlah node daun (leaf node)
int countLeafNodes(BTNode *root) {
    if (root == NULL) {
        return 0; // Jika simpul kosong, tidak ada node daun
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Jika simpul adalah daun, hitung sebagai 1
    }
    // Hitung jumlah node daun di kiri dan kanan
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Fungsi utama
int main() {
    BTNode *root = NULL; // Inisialisasi root pohon menjadi NULL
    int n; // Jumlah data yang akan dimasukkan

    printf("Masukkan jumlah data (maksimal 10): ");
    scanf("%d", &n); // Minta pengguna memasukkan jumlah data

    if (n > 10) {
        printf("Jumlah data tidak boleh lebih dari 10.\n");
        return 1; // Keluar jika jumlah data lebih dari 10
    }

    int numbers[10]; // Array untuk menyimpan angka yang dimasukkan pengguna

    printf("Masukkan angka: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]); // Minta pengguna memasukkan angka
        insert(&root, numbers[i]); // Tambahkan angka ke dalam BST
    }

    // Hitung dan tampilkan jumlah node daun
    int leafCount = countLeafNodes(root);
    printf("Jumlah node daun: %d\n", leafCount);

    return 0; // Kembalikan 0 untuk menandakan program selesai
}