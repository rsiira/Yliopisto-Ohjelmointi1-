#include <stdio.h>
#include <inttypes.h>

int64_t laske_kertoma(int8_t n);

int64_t main() {

    int i = 1;
    while(i >= 1 && i <= 5){
    	printf("Luvun %d kertoma on %lld.\n", i, laske_kertoma(i));
    	i++; 	
	}
    

    return 0;
}

int64_t laske_kertoma(int8_t n){
	
	/*
	Palauttaa annetun luvun kertoman. Jos funktiota kutsutaan 
	suuremmalla arvolla kuin 20, se palauttaa arvon -1.
	*/
	
	int64_t kertoma = 1; 
	int i;
	
	if (n > 20){
		return -1;
	} 
	
	else{
		for (i = n; i > 0; i--){
			kertoma *= i; //kertoma = kertoma * i 
		}
		
		return kertoma; 
	}
	
}
