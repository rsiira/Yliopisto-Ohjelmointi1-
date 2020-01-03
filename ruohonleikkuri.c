#include <stdio.h>
#include <math.h>

const double RUOHONLEIKKURIN_NOPEUS = 5.0; //km/h

//Laskee pinta-alan parametreill‰ pituus ja leveys.
double laske_ala (double pituus, double leveys);

int main(){
	
	double tontin_leveys = 0.0;
	double tontin_pituus = 0.0;
	double talon_leveys = 0.0;
	double talon_pituus = 0.0;
	double tontin_ala = 0.0;
	double talon_ala = 0.0;
	double leikattava_ala = 0.0;
	double leikattavat_kilometrit = 0.0;
	double aika = 0.0;
	
	//Kysyt‰‰n tontin leveys.
	printf("Anna tontin leveys metreina: \n");
	scanf("%lf", &tontin_leveys);
	
	//Kysyt‰‰n tontin pituus.
	printf("Anna tontin pituus metreina: \n");
	scanf("%lf", &tontin_pituus);
	
	//Kysyt‰‰n talon leveys.
	printf("Anna talon leveys metreina: \n");
	scanf("%lf", &talon_leveys);
	
	//Kysyt‰‰n talon pituus.
	printf("Anna talon pituus metreina: \n");
	scanf("%lf", &talon_pituus);
	
	//Lasketaan tontin ala ja talon ala.
	tontin_ala = laske_ala(tontin_pituus, tontin_leveys);
	talon_ala = laske_ala(talon_pituus, talon_leveys);
	
	//Lasketaan leikattava ala.
	leikattava_ala = tontin_ala - talon_ala;
	
	//Lasketaan leikattavat metrit ja muunnetaan ne kilometreiksi.
	leikattavat_kilometrit = (leikattava_ala / 0.7) / 1000; 
	
	//Lasketaan leikkaukseen kuluva aika tuneita ja muunnetaan se minuuteiksi.
	aika = (leikattavat_kilometrit / RUOHONLEIKKURIN_NOPEUS) * 60;
	
	printf("Nurmikon leikkaamisen arvioitu aika on %.0fl minuuttia.", aika);
}

double laske_ala (double pituus, double leveys){
	
	double ala = pituus * leveys;
	return ala;
	
}
