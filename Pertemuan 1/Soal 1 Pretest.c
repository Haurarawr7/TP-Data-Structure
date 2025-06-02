#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, a, hasil;
    
    scanf("%d", &n);
    
    int arr[n];
    if (n<=2){
        printf("Harus lebih dari 2!");
    }
    else if((n%2)==0){
        for (i=0; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        hasil= arr[0]*arr[n-1];
        printf("Hasil: %d", hasil);
    }
    else {
        printf("Harus genap!");
    }
    return 0;
}
