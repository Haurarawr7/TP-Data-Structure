
//Program
// Oleh Haura Agnia Ramadhani Amnun

/*
Andika dan teman temannya sedang memainkan permainan mencari harta karun, harta karun dicari dari peta harta karun (berupa baris string) yang memiliki tanda “x” pada petanya, apabila suatu peta harta karun tidak memiliki tanda “x” maka dalam peta tersebut tidak ada harta karunnya, jika ada tanda “x” berarti peta tersebut memiliki harta karun. Bantulah Andika untuk menemukan lokasi harta karun dari peta (berupa baris string) yang diinputkan.
Syarat :
- Maksimal string 20 karakter, minimal 10 karakter.
- Gunakan konsep array.
- Lokasi harta berupa index pada array.
Input Format
bfahfavfgxjbfas
Constraints
-
Output Format
Harta karun terletak pada index 9
Sample Input 0
bfahfavfgxjbfas
Sample Output 0
Harta karun terletak pada index 9
Sample Input 1
advadcwbad
Sample Output 1
Peta tidak memiliki harta karun!
Sample Input 2
Advadcwbadadacdvbexgjarrat
Sample Output 2
Peta terlalu luas, Andika pusing!!!
Sample Input 3
auofxji
Sample Output 3
Peta terlalu sempit, Tidak seru!!!
*/

#include <stdio.h>
#include <string.h>

int main() {
    char peta[100];
    int panjang, index_harta;

    scanf("%20s", peta); 

    panjang = strlen(peta);

    if (panjang >= 20) {
        printf("Peta terlalu luas, Andika pusing!!!\n");
        return 0;
    } else if (panjang < 10) {
        printf("Peta terlalu sempit, Tidak seru!!!\n");
        return 0;
    }
    else{
        index_harta = strchr(peta, 'x') - peta; 

        if (index_harta >= 0 && index_harta < panjang) {
            printf("Harta karun terletak pada index %d\n", index_harta);
        } 
        else {
          printf("Peta tidak memiliki harta karun!\n");
        }
    }
    

    return 0;
}
