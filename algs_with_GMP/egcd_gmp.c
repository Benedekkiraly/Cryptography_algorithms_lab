#include <stdio.h>
#include <gmp.h>

void extended_euclidean_algorithm(int a, int b){

	mpz_t x1, x2, y1, y2, a1, b1;
	mpz_init_set_ui(x1, 0);
	mpz_init_set_ui(x2, 1);
	mpz_init_set_ui(y1, 1);
	mpz_init_set_ui(y2, 0);
	mpz_init_set_ui(a1, a);
	mpz_init_set_ui(b1, b);  
	mpz_t q, r, x, y, temp;
	
	if (mpz_get_ui(b1) == 0) {
	//return
	 printf("EGCD of inputs is:");
	 mpz_out_str(stdout,10,a1);
	 printf ("\n");
    }
	while(mpz_get_ui(b1) > 0){
		mpz_init(q);
		mpz_init(r);
		mpz_init(x);
		mpz_init(y);
		mpz_init(temp);

		mpz_fdiv_q(q, a1, b1); 
		mpz_mul(temp,q,b1);
		mpz_sub(r, a1,temp);
		mpz_mul(temp,x1,q);
		mpz_sub(x,x2,temp);
		mpz_mul(temp,q,y1);
		mpz_sub(y,y2,temp);
		
		mpz_set(a1,b1);
		mpz_set(b1,r);
		mpz_set(x2,x1);
		mpz_set(x1,x);
		mpz_set(y2,y1);
		mpz_set(y1,y);
	}
	//return
	printf("EGCD of inputs is:");
	mpz_out_str(stdout,10,a1);
	printf ("\n");
}

int main() {

    //change values of x and y for EGCD inputs
    int x = 4;
    int y = 2;
    extended_euclidean_algorithm(x,y);
    return 0;	
}