#include <stdio.h>
#include <math.h>

int main(){
	
	double lampotila_celsius = 0.0;
	double lampotila_kelvin = 0.0;
	double lampotila_fahrenheit = 0.0;
	
	//Kysy ja tallenna l�mp�tila celsius-asteissa.
	printf("Anna lampotila Celsius-asteina: \n");
	scanf("%lf", &lampotila_celsius);
	
	//Lasketaan l�mp�tila Kelvin-asteina.
	lampotila_kelvin = lampotila_celsius + 273.15;
	
	//Lasketaan l�mp�tila Fahrenheit-asteina.
	lampotila_fahrenheit = lampotila_celsius * 1.8 + 32;
	
	//Tulostetaan l�mp�tila Kelvin- ja Fahrenheit- asteina.
	printf("Lampotila Kelvin-asteina on %.2lf.\n", lampotila_kelvin);
	printf("Lampotila Fahrenheit-asteina on %.2lf.", lampotila_fahrenheit);
	
	return 0;
	
}
