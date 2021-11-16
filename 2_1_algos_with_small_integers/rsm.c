#include <stdio.h>
//2.3 exc, Repeated square-and-multiply algorithm for exponentiation
int RSM(int a,int k[],int len, int n) {
    
    int b;
    if (len == 0) {
        return 1;
    }
    int A = a;
    if (k[0] == 1) {
        b = a;
    }
    for (int i=1;i<len;i++) {
        A = A^2 % n;
        if (k[i] == 1) {
            b = A*b % n;
        }
    }
    return A;
}
  
// Driver code
int main()
{    
    int a = 9;
    int arr[] = {0,2,3,4,5,6,7}; //length of the power in bits
    int n = 14;
    int len = (sizeof (arr) / sizeof (arr[0])) ;
    printf("\nRSM is %d",RSM(a,arr,len,n));
    
    return 0;
}