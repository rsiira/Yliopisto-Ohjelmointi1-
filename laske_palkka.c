#include <stdio.h>

int main (void){
	
	double tuntipalkka = 0.0;
	double tunnit = 0.0;
	double palkka = 0.0;
	
	//Kysy ja tallenna ty�ntekij�n tuntipalkka.
	printf("Anna ty�ntekij�n tuntipalkka: \n");
	scanf("%lf", &tuntipalkka);
	
	//Kysy ja tallenna tehdyt tunnit.
	printf("Anna ty�ntekij�n tehdyt tunnit: \n");
	scanf("%lf", &tunnit);
	
	//Lasketaan palkka kertomalla tehdyt tunnit tuntipalkalla.
	palkka = tunnit * tuntipalkka;
	
	printf("Palkka on %.2lf", palkka); //Tulostaa palkan kahdella desimaalilla.
	
	return 0;	
	
}
