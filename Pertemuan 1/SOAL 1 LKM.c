
//Program BAhasa bRo (profBro gak jelas kali)
// Oleh Haura Agnia Ramadhani Amnun 2404043

/* 
Prof Bro menemukan bahasa baru, yaitu Bahasa bRo. Dalam Bahasa bRo, pada sebuah
kata mungkin saja terdapat huruf besar dan huruf kecil yang bercampur. Kali ini, Prof Bro
memiliki sebuah kata dalam Bahasa bRo. Tanpa alasan yang jelas, ia meminta Anda
untuk mengubah kata tersebut, agar untuk setiap huruf besar yang ada diganti menjadi
huruf kecil, dan untuk setiap huruf kecil yang ada diganti menjadi huruf besar.
Penggantian ini dilakukan dengan huruf yang sama.
Input:
SupeRDede
Output:
sUPErdEDE
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char kata[100]; 

    printf("Masukkan kata dalam Bahasa bRo: ");
    scanf("%s", kata); 

    for (int i = 0; kata[i] != '\0'; i++) {
        if (kata[i] >= 'A' && kata[i] <= 'Z') {
            switch (kata[i]) {
                case 'A': kata[i] = 'a'; break;
                case 'B': kata[i] = 'b'; break;
                case 'C': kata[i] = 'c'; break;
                case 'D': kata[i] = 'd'; break;
                case 'E': kata[i] = 'e'; break;
                case 'F': kata[i] = 'f'; break;
                case 'G': kata[i] = 'g'; break;
                case 'H': kata[i] = 'h'; break;
                case 'I': kata[i] = 'i'; break;
                case 'J': kata[i] = 'j'; break;
                case 'K': kata[i] = 'k'; break;
                case 'L': kata[i] = 'l'; break;
                case 'M': kata[i] = 'm'; break;
                case 'N': kata[i] = 'n'; break;
                case 'O': kata[i] = 'o'; break;
                case 'P': kata[i] = 'p'; break;
                case 'Q': kata[i] = 'q'; break;
                case 'R': kata[i] = 'r'; break;
                case 'S': kata[i] = 's'; break;
                case 'T': kata[i] = 't'; break;
                case 'U': kata[i] = 'u'; break;
                case 'V': kata[i] = 'v'; break;
                case 'W': kata[i] = 'w'; break;
                case 'X': kata[i] = 'x'; break;
                case 'Y': kata[i] = 'y'; break;
                case 'Z': kata[i] = 'z'; break;
            }
        }
        else if (kata[i] >= 'a' && kata[i] <= 'z') {
            switch (kata[i]) {
                case 'a': kata[i] = 'A'; break;
                case 'b': kata[i] = 'B'; break;
                case 'c': kata[i] = 'C'; break;
                case 'd': kata[i] = 'D'; break;
                case 'e': kata[i] = 'E'; break;
                case 'f': kata[i] = 'F'; break;
                case 'g': kata[i] = 'G'; break;
                case 'h': kata[i] = 'H'; break;
                case 'i': kata[i] = 'I'; break;
                case 'j': kata[i] = 'J'; break;
                case 'k': kata[i] = 'K'; break;
                case 'l': kata[i] = 'L'; break;
                case 'm': kata[i] = 'M'; break;
                case 'n': kata[i] = 'N'; break;
                case 'o': kata[i] = 'O'; break;
                case 'p': kata[i] = 'P'; break;
                case 'q': kata[i] = 'Q'; break;
                case 'r': kata[i] = 'R'; break;
                case 's': kata[i] = 'S'; break;
                case 't': kata[i] = 'T'; break;
                case 'u': kata[i] = 'U'; break;
                case 'v': kata[i] = 'V'; break;
                case 'w': kata[i] = 'W'; break;
                case 'x': kata[i] = 'X'; break;
                case 'y': kata[i] = 'Y'; break;
                case 'z': kata[i] = 'Z'; break;
            }
        }
    }

    printf("Hasil Tukar: %s\n", kata); 

    return 0; 
}