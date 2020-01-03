#include <stdio.h>

int main (void){
	
	double tuntipalkka = 0.0;
	double tunnit = 0.0;
	double palkka = 0.0;
	double veroprosentti = 0.0;
	double verottajan_osuus = 0.0;
	double palkansaajan_osuus = 0.0;
	
	//Kysy ja tallenna työntekijän tuntipalkka.
	printf("Anna tyontekijan tuntipalkka: \n");
	scanf("%lf", &tuntipalkka);
	
	//Kysy ja tallenna tehdyt tunnit.
	printf("Anna tyontekijan tehdyt tunnit: \n");
	scanf("%lf", &tunnit);
	
	//Kysy ja tallenna veroprosentti.
	printf("Anna veroprosentti: \n");
	scanf("%lf", &veroprosentti);
	
	//Lasketaan palkka kertomalla tehdyt tunnit tuntipalkalla.
	palkka = tunnit * tuntipalkka;
	
	//Lasketaan verottajan osuus palkasta.
	verottajan_osuus = veroprosentti * palkka / 100;
	
	//Lasketaan palkansaajan osuus palkasta.
	palkansaajan_osuus = palkka - verottajan_osuus;
	
	printf("Verottajan osuus palkasta on %.2lf.\n", verottajan_osuus);
	printf("Palkansaajan osuus palkasta on %.2lf.", palkansaajan_osuus);
	
	return 0;	
	
}
