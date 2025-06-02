
//Program
//Oleh : Haura Agnia Ramadhani Amnun 2404043

/*

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    char kata[10];
    scanf("%10s", kata);
    
    int panjang = strlen(kata);
    
    if (panjang<10 && panjang>2){
        char balik[10];
        for (i=0; i<panjang; i++){
            balik[i] = kata[panjang-1-i];
        }
        printf("%s", balik);
    }

    else if ( panjang<2){
        printf("Inputan minimal 2 huruf!");
    }
    else {
        printf("Kata yang anda inputkan terlalu panjang!");
    }
    return 0;
}
