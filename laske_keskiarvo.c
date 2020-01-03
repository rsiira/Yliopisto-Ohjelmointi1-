#include <stdio.h>

int main (){

	float luku = -1;
	float n = 0;
	float summa = 0;
	float keskiarvo = 0.0;
	
	printf("Syota lukuja Enter valilyontina. Lopeta syottamalla 0.\n");
	while (luku != 0){
		scanf("%f", &luku);
		summa = summa + luku;
		if(luku != 0){
			n++;	
		}
	}
	
	keskiarvo = summa / n;
	printf("Keskiarvo on %.2f.", keskiarvo);
	return 0;
}
