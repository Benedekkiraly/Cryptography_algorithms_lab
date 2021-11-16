#include <stdio.h>
#include <gmp.h>

//2.3 exc, Repeated square-and-multiply algorithm for exponentiation using GMP's  MPZ functions
void RSM(int a,int k[],int len, int n) {
    
    mpz_t b,A,N, temp;
    
	mpz_init_set_ui(b, 0);
	mpz_init_set_ui(A, a);
	mpz_init_set_ui(N, n);
	mpz_init_set_ui(temp,0);
	
    if (len == 0) {
     printf("RSM of inputs is: 1");
	 printf ("\n");
    }
    
    if (k[0] == 1) {
        mpz_set(b,A);
    }
    for (int i=1;i<len;i++) {
        
        mpz_pow_ui(temp,A,2);
        mpz_mod(A, temp, N);
        
        if (k[i] == 1) {
            
        mpz_mul(temp,A,b);
        mpz_mod(b,temp,N);
        
        }
    }
	//return
	printf("RSM of inputs is:");
	mpz_out_str(stdout,10,A);
	printf ("\n");
}
  
// Driver code
int main()
{    
    int a = 9;
    int arr[] = {0,2,3,4,5,6,7}; //length of the power in bits
    int n = 14;
    int len = (sizeof (arr) / sizeof (arr[0])) ;
    RSM(a,arr,len,n);
    return 0;
}