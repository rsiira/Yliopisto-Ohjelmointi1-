#include <stdio.h>
#include <string.h>

#define NIMEN_PITUUS 15
#define OPISKELIJOIDEN_LKM 10

typedef struct {
char sukunimi[NIMEN_PITUUS];
char etunimi[NIMEN_PITUUS];
int opiskelijaNumero;
int aloitusVuosi;
}OpiskelijaTietue;

OpiskelijaTietue lueOpiskelijanTiedot(void);
int etsiOpiskelija(OpiskelijaTietue op);
void tulostaOpiskelija(OpiskelijaTietue op);

int lueKokonaisluku(void);
void lueRoskat(void);

int main(){
	
	OpiskelijaTietue rekisteri[OPISKELIJOIDEN_LKM];
	int i = 0; 
	int j = 0;
	int valinta = 0;
	int tulos = 0;
	
	do{
	printf("Valitse 1) lisays, 2) etsinta, 3) selaus tai 0) lopetus.\n");
	
	valinta = lueKokonaisluku();
		
		if (valinta == 1){	

			printf("\nValittu 1) lisays.\n");
			
			/* luetaan tiedot taulukkoon */

			rekisteri[i] = lueOpiskelijanTiedot();
			i++;
			
		}
		else if (valinta == 2){	
		
			printf("\nValittu 2) etsinta.\n");
			
			/* etsit‰‰n opiskelijatiedot rekisterist‰*/
			for(j=0; j < i; j++){
				tulos = etsiOpiskelija(rekisteri[j]);
			}
			
			if(tulos == 0){
				printf("Opiskelijaa ei loydy.\n");
			}
			
			
		}
		
		else if (valinta == 3){ 
			
			printf("\nValittu 3) selaus.\n");
			
			/* tulostetaan opiskelijatiedot */
			for(j=0; j < i; j++){
				tulostaOpiskelija(rekisteri[j]);
			}
			
		}
		
		else if (valinta == 0){
		
			printf("\nOhjelma lopetettu. \n");
		}
		
		
		else{
			printf("\nVirheellinen valinta.\n");
		}
		
	}while(valinta != 0 );
	
	return 0;
}

/* lukee yhden opiskelijan:
 - sukunimen,
 - etunimen,
 - opiskelijanumeron ja
 - oppilaitokseen tulovuoden
 ja palautta tiedot OpiskeijaTietue-typpisen‰ arvona */
OpiskelijaTietue lueOpiskelijanTiedot(void){
	
	OpiskelijaTietue op;
	printf("\nAnna opiskelijan sukunimi: ");
	scanf("%s", op.sukunimi);
	printf("\nAnna opiskelijan etunimi: ");
	scanf("%s", op.etunimi);
	printf("\nAnna opiskelijanumero: ");
	scanf("%d", &op.opiskelijaNumero);
	printf("\nAnna oppilaituokseen tulovuosi: \n");
	scanf("%d", &op.aloitusVuosi);
	
	return(op);

}

/* etsii opisleijan nimell‰ ja
tulostaa kyseisen opikelijan tiedot*/

int etsiOpiskelija(OpiskelijaTietue op){
	
	char nimi[NIMEN_PITUUS];
	
	printf("Syota etsittavan opiselijan etunimi tai sukunimi: \n");
	scanf("%s", nimi);
	
	if(strcmp(nimi, op.sukunimi) == 0 || strcmp(nimi, op.etunimi) == 0){
		tulostaOpiskelija(op);
		return 1;
	}
	
	return 0;
	
}

/* tulostaa opiskelijan:
 - sukunimen,
 - etunimen,
 - opiskelijanumeron ja
 - oppilaitokseen tulovuoden */
void tulostaOpiskelija(OpiskelijaTietue op){
	
	printf("\n****************************\n");
	printf("Sukunimi: %s\n", op.sukunimi);
	printf("Etunimi: %s\n", op.etunimi);
	printf("Opiskelijanumero: %d\n", op.opiskelijaNumero);
	printf("Oppilaitokseen tulovuosi: %d\n", op.aloitusVuosi);
	printf("\n****************************\n");
}
	
int lueKokonaisluku(void){
   
   int luku;
   char mki;
   int status;
   
   while((status = scanf("%d%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
      lueRoskat();
      printf("Et syottanyt kokonaislukua. Yrita uudelleen. \n");
   }
   
   return luku;
}

void lueRoskat(void){
   
   while( fgetc(stdin) != '\n');
   
}
