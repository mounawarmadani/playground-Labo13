#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

int _is_prime(int nbr)
{
	int i, sqrt_nbr, premier=1;

	if (nbr%2==0 && nbr!=2) {
		premier=0;
	}
	else {
		// sqrt_nbr = (int)sqrt(nbr) + 1;
		sqrt_nbr = nbr/2;
		i=3;
		while (i<=sqrt_nbr && nbr%i!=0) i=i+2;

		if (nbr%i==0 && nbr!=i)
			premier=0;
		else
			premier=1;
	}	
	return premier;
}

int main(void) {
	int i;
	int prime_test[20]={1,2,3,4,5,6,7,8,9,10,11,12,71,100,121,1013,5041,6241,7919,69169};
    int ok=1;
	
    for (i=0;i<20;i++) {		
		if (_is_prime(prime_test[i]) == is_prime(prime_test[i])) {
            ok = ok && 1;
        }
        else {
            ok = ok && 0;
            printf("TECHIO> message --channel \"TEST ERREUR\" 'Error function fail test (%d)'\n",prime_test[i]);
        }
    }
        
    if(ok)
        printf("TECHIO> success true\n");
    else  
		printf("TECHIO> success false\n");

	return 0;
}
