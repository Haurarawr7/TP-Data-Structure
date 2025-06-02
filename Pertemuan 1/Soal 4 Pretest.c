
//Program
//Oleh : Haura Agnia Ramadhani Amnun 2404043

/*

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, max =0, min=100;
    float total= 0;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for (i=0; i<=n; i++){
        scanf("%d", &arr[i]);
        total +=arr[i];
        if (arr[i]>max){
        max=arr[i];
        }
    
        if (arr[i]<max && arr[i]>0){
        min=arr[i];
        }
    }
    
    
    printf("Nilai tertinggi: %d\n", max);
    printf("Nilai terendah: %d\n", min);
    printf("Rata-rata: %.2f\n", total/n);
       
    return 0;
}

