#include <stdio.h>
#include <math.h>

void luePisteet(double taulukko[ ][2], int koko);

void tulostaTaulukko(double taulukko[ ][2], int koko);

double laskeEtaisyys(double x1, double y1, double x2, double y2 );



int main(){
	
	double pisteet[10][2];
	int i = 0;
	double summa = 0;
	
	printf("Anna 10 pisteen koordinaatit (x, y): \n");
	luePisteet(pisteet, 10);

	printf("Annetut koordinaatit: \n");
	tulostaTaulukko(pisteet, 10);
	
	for(i = 0; i < 10; i++){
		
		summa = summa + laskeEtaisyys(pisteet[i][0], pisteet[i][1], pisteet[i+1][0], pisteet[i+1][1]);
		
	}
	
	printf("Annettujen koordinaattien kautta kuljetun matkan pituus on %.2lf.", summa);
	
	return 0;
}


void luePisteet(double taulukko[ ][2], int koko){
	
	int i = 0;
	for(i = 0; i < koko; i++){
		
		scanf("%2lf %2lf", &taulukko[i][0], &taulukko[i][1]);
		
	}
	
}

void tulostaTaulukko(double taulukko[ ][2], int koko){

	int i = 0;
	for(i = 0; i < koko; i++){
		
		printf("(%.2lf, %.2lf)\n", taulukko[i][0], taulukko[i][1]);
		
	}
	printf("\n");
 	
 	
}

double laskeEtaisyys( double x1, double y1, double x2, double y2 ){
	
	
	double etaisyys = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	
	return etaisyys;
	
}
