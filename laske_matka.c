#include <stdio.h>
#include <math.h>
#include <inttypes.h>

const double VALOVUOSI = 9.46 * pow(10.0, 15.0); 
const double AANENNOPEUS =  343;

int main (void){

	double matka = 0.0;
	double aika_sekunteina = 0.0;
	double aika_vuosina = 0.0;
	
	//Lasketaan matka Proxima Centauriin.
	matka = 4.2 * VALOVUOSI; 
	
	//Lasketaan matkaan kuluva aika sekunteina.
	aika_sekunteina = matka / AANENNOPEUS;
	
	//Muutetaan sekunnit vuosiksi.
	aika_vuosina = aika_sekunteina/(60 * 60 * 24 * 365.25);
	
	printf("Matkaan kuluva aika on %.2lf.", aika_vuosina);
	
	return 0;
	
}
