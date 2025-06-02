
//Program
//Oleh : Haura Agnia Ramadhani Amnun 2404043

/*
Buatlah program menggunakan array untuk menghitung volume kubus sesuai dengan jumlah kubus yang diinginkan, dengan jumlah kubus > 0!
Input Format
4
2
7
1
3

Constraints
Input pertama merupakan jumlah kubus

Output Format
8
343
1
27

Sample Input 0
4
2
7
1
3

Sample Output 0
8
343
1
27

Sample Input 1
1
10

Sample Output 1
1000

Sample Input 2
0

Sample Output 2
Inputan harus lebih dari 0
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, hasil;
        
    scanf("%d", &n);
    
    int arr[n];
    
    if(n<=0){
        printf("Inputan harus lebih dari 0");
    }
    else{
        for(i=0; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        for(i=0; i<=n-1;i++){
            hasil = arr[i]*arr[i]*arr[i];
            printf("%d\n",hasil);
        }
        
    }
        
    return 0;
}
