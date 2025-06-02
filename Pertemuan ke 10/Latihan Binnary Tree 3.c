
// Program mencari pedang yamato
// Haura Agnia Ramadhani Amnun 2404043

/*
Untuk menghancurkan gerbang dimensi iblis, Dante harus melewati sistem keamanan yang
berupa pohon. Setiap level pohon mewakili lapisan dunia iblis yang harus ditembus. Tugasmu
adalah menghitung kedalaman maksimum dari sebuah Binary Search Tree yang dibentuk dari
beberapa angka yang diberikan oleh Dante.
Ketentuan:

• Program menerima n buah angka dari pengguna (maksimal 10 angka).
• Bangun BST dari angka-angka tersebut.
• Hitung dan tampilkan kedalaman maksimum dari pohon.
Input:
Masukkan jumlah data: 6
Masukkan angka: 50 30 70 20 40 80
Output:
Kedalaman maksimum pohon: 3
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

// Fungsi untuk menghitung kedalaman maksimum dari BST
int maxDepth(BTNode *root) {
    if (root == NULL) {
        return 0; // Jika simpul kosong, kedalaman adalah 0
    } else {
        // Hitung kedalaman  kiri dan kanan, ambil yang maksimum
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; // Tambahkan 1 untuk simpul saat ini
    }
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

    // Hitung dan tampilkan kedalaman maksimum pohon
    int depth = maxDepth(root);
    printf("Kedalaman maksimum pohon: %d\n", depth);

    return 0; // Kembalikan 0 untuk menandakan program selesai
}
