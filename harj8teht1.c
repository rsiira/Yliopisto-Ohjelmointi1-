#include <stdio.h>
#include <string.h>

#define NIMEN_PITUUS 15

typedef struct {
char sukunimi[NIMEN_PITUUS];
char etunimi[NIMEN_PITUUS];
int opiskelijaNumero;
int aloitusVuosi;
}OpiskelijaTietue;

OpiskelijaTietue lueOpiskelijanTiedot(void);
int etsiOpiskelija(OpiskelijaTietue op, char *nimi);
void tulostaOpiskelija(OpiskelijaTietue op);

void lisaaOpiskelijanTiedot (OpiskelijaTietue op);
void etsiTiedostosta(char *nimi);
void tulostaTiedosto(void);


int lueKokonaisluku(void);
void lueRoskat(void);

int main(){
	
	int valinta = 0;
	char nimi[NIMEN_PITUUS];
	
	do{
	printf("Valitse 1) lisays, 2) etsinta, 3) selaus tai 0) lopetus.\n");
	
	valinta = lueKokonaisluku();
		
		if (valinta == 1){	

			printf("\nValittu 1) lisays.\n");
			
			/* luetaan tiedot tiedostoon */
			lueOpiskelijanTiedot();

			
		}
		else if (valinta == 2){	
		
			printf("\nValittu 2) etsinta.\n");
			
			printf("Syota etsittavan opiselijan etunimi tai sukunimi: \n");
			scanf("%s", nimi);
			
			/* etsitään opiskelijatiedot tiedostosta*/
			etsiTiedostosta(nimi);
			
		}
		
		else if (valinta == 3){ 
			
			printf("\nValittu 3) selaus.\n");
			
			/* tulostetaan opiskelijatiedot */
			tulostaTiedosto();
			
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
 ja palautta tiedot OpiskeijaTietue-typpisenä arvona */
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
	lisaaOpiskelijanTiedot(op);
	return(op);

}

//lisää opiskelijan tiedot tietueesta tiedostoon
void lisaaOpiskelijanTiedot ( OpiskelijaTietue op) {
FILE *tiedosto;

if( (tiedosto = fopen ("opiskelijat.dat", "a")) == NULL){
	printf("\nTiedostoa ei voitu avata\n");
	}
	
else{
	rewind( tiedosto ); 
 	
	fprintf( tiedosto, "%-14s %-14s %-8d %-4d\n", op.sukunimi, op.etunimi, op.opiskelijaNumero, op.aloitusVuosi);
	fclose( tiedosto );
	} 
}

/* Vertaa löytyykö parametrina annettua opiskelijaa.
Tulostaa opiskelijan tiedot, jos opiskelija löytyy.
Palauttaa 1, jos opiskelija löytyy, 
muutoin palauttaa 0.*/

int etsiOpiskelija(OpiskelijaTietue op, char *nimi){
	
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

//Etsii opiskelijan tiedostosta
void etsiTiedostosta(char *nimi){
	
	FILE * tiedosto;
	OpiskelijaTietue op;
	int tulos = 0;
	
 	if (( tiedosto = fopen ("opiskelijat.dat", "r" )) == NULL )
 		printf("\nTiedoston avaaminen avaaminen epäonnistui");
 	else {

 		fscanf(tiedosto, "%s%s%d%d", op.sukunimi, op.etunimi, &op.opiskelijaNumero, &op.aloitusVuosi);
		
		while( !feof( tiedosto)) {
 			
 			tulos = etsiOpiskelija(op, nimi);
 			fscanf(tiedosto, "%s%s%d%d", op.sukunimi, op.etunimi, &op.opiskelijaNumero, &op.aloitusVuosi);
 		}
 		
 	fclose (tiedosto);
 	
 	}
	 	
	if(tulos == 0){
		printf("Opiskelijaa ei loydy.\n");
	}
}

//tulostaa koko tiedoston
void tulostaTiedosto(void){
	
	FILE * tiedosto;
	OpiskelijaTietue op;
	
 	if (( tiedosto = fopen ("opiskelijat.dat", "r" )) == NULL )
 		printf("\nTiedoston avaaminen avaaminen epäonnistui");
 	else {

 		fscanf(tiedosto, "%s%s%d%d", op.sukunimi, op.etunimi, &op.opiskelijaNumero, &op.aloitusVuosi);
		
		while( !feof( tiedosto)) {
 			
 			tulostaOpiskelija(op);
 			fscanf(tiedosto, "%s%s%d%d", op.sukunimi, op.etunimi, &op.opiskelijaNumero, &op.aloitusVuosi);
 		}
 		
 	fclose (tiedosto);
 	
 	}	
	
}

//apufunktiot
	
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
