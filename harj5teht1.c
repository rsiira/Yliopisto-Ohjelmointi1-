#include <stdio.h>
#include <math.h>

double laskeParkkimaksu(double aika);

int main(){
	
	int i = 0;
	int j = 0;
	double veloitus = 0.0;
	double tunnit[10]; //vain 10 asiakasta mahdollista
	double tunnit_yht = 0.0;
	double summa_yht = 0.0;
	
	do{
		
		printf("Anna asiakkaan pysakointiaika tunteina: \n");	
		printf("Lopeta syottamalla 0.\n");
		scanf("%lf", &tunnit[j]);
		j++; 
	}while (tunnit[j-1] != 0 && j != 10); //vain 10 asiakkaan tiedot  
	
	printf("Asiakas		Tunnit		Veloitus\n");
	
	for(i=1; i<=j; i++){
		
		if(tunnit[i-1] != 0){
			veloitus = laskeParkkimaksu(tunnit[i-1]);
			printf("%d		%.1lf		%.2lf\n", i, tunnit[i-1], veloitus);
			tunnit_yht += tunnit[i-1];
			summa_yht += veloitus;
		}
 
	}
	
	printf("Yhteensa:	%.1lf		%.2lf", tunnit_yht, summa_yht);
	
	return 0;
	
}

double laskeParkkimaksu(double aika){
	
	if(aika <= 3.0){	
		return 2.0;	
	}
	else if(aika > 3 && aika <= 19){
		return 2.0 + 0.5 * ceil(aika - 3);
		
	}
	else if(aika > 19){
		return 10;
	}
		
}
