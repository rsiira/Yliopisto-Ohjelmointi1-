#include <stdio.h>

int laskePaivat(int kuukausi1, int kuukausi2, int vuosiluku);
int maaritaKarkausvuosi(int vuosiluku);
int lueKokonaisluku(void);
void lueRoskat(void);

int main(){
	
	int vuosiluku;
	int kuukausi1;
	int kuukausi2;
	int paivat;
	
	printf("Anna vuosiluku: \n");

	do{
		vuosiluku = lueKokonaisluku();
		if (vuosiluku < 0){
			printf("Anna positiivinen vuosiluku: \n");
		}
	
		
	}while(vuosiluku < 0);
	
	printf("Anna ensimmaisen kuukauden numero: \n");
	
	do{
		kuukausi1 = lueKokonaisluku();
		if (kuukausi1 < 1 || kuukausi1 > 12){
			printf("Anna numero valilta 1-12: \n");
		}
		
	}while(kuukausi1 < 1 || kuukausi1 > 12);
	
	printf("Anna toisen kuukauden numero: \n");
	
	do{
		kuukausi2 = lueKokonaisluku();
		if (kuukausi2 < 1 || kuukausi2 > 12){
			printf("Anna numero valilta 1-12: \n");
		}
		
	}while(kuukausi2 < 1 || kuukausi2 > 12);
	
	paivat = laskePaivat(kuukausi1, kuukausi2, vuosiluku);
	printf("Kyseisten kuukausien valisten paivien lukumaara on %d.", paivat);
	
	return 0;
	
}

int laskePaivat(int kuukausi1, int kuukausi2, int vuosiluku){
	
	int paivat = 0;
	
	//Vaihdetaan kuukausien numerot toisin päin
	if(kuukausi2 < kuukausi1){
		kuukausi1 = kuukausi1 + kuukausi2;
		kuukausi2 = kuukausi1 - kuukausi2;
		kuukausi1 = kuukausi1 - kuukausi2;
	}
	
	while(kuukausi2 >= kuukausi1){
	
		//Tammikuu, maaliskuu, toukokuu, heinäkuu, elokuu, lokakuu, joulukuu
		if(kuukausi2 == 1 || kuukausi2 == 3 || kuukausi2 == 5 || kuukausi2 == 7 || kuukausi2 == 8 || kuukausi2 == 10 || kuukausi2 == 12){
			
			paivat += 31;
			kuukausi2--;
			
		}
		
		//Huhtikuu, kesäkuu, syyskuu, marraskuu
		else if(kuukausi2 == 4 || kuukausi2 == 6 || kuukausi2 == 9 || kuukausi2 == 11 ){
			
			paivat += 30;
			kuukausi2--;
			
		}
		
		//Helmikuu
		else if (kuukausi2 == 2){
		
		//Tarkistetaan onko vuosi karkausvuosi
			if (maaritaKarkausvuosi(vuosiluku) == 1){
				paivat += 29;
				kuukausi2--;
			}
			else{
				paivat += 28;
				kuukausi2--;
			}
		}
	
	}
	
	return paivat;
	
}
	
int maaritaKarkausvuosi(int vuosiluku){
	
	if(vuosiluku % 400 == 0 || vuosiluku % 4 == 0){
		return 1;
	}
	
	else if(vuosiluku % 100 == 0){
		return 0;
	}
	
	else{
		return 0;
	}
	
}

int lueKokonaisluku(void){
   
   int luku;
   char mki;
   int status;
   
   while((status = scanf("%d%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
      lueRoskat();
      printf("Et syottanyt kokonaislukua > ");
   }
   
   return luku;
}

void lueRoskat(void){
   
   while( fgetc(stdin) != '\n');
   
}
