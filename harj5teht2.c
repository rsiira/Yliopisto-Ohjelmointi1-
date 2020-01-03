#include <stdio.h>

void tulosta_taulukko(int taulukko[]);
int lueKokonaisluku(void);
void lueRoskat(void);

int main(){
	
	int taulukko[10];
	int kopio_taulukko[10];
	int i = 0;
	
	printf("Syota kokonaisluku valilta -10 ...+10.\n");
	
	for(i = 0; i < 10; i++){
		
		do{	
			taulukko[i] = lueKokonaisluku();
			if(taulukko[i]<-10 || taulukko[i]>10){
				printf("Syota kokonaisluku valilta -10 ...+10.\n");		
			}
		}while(taulukko[i]<-10 || taulukko[i]>10);
		
	}
	
	printf("\n");
	
	for(i = 0; i < 10; i++){
		
		kopio_taulukko[i] = taulukko[9-i];
		
	}
	
	tulosta_taulukko(taulukko);
	tulosta_taulukko(kopio_taulukko);
	
	return 0;
	
}

void tulosta_taulukko(int taulukko[]){
	
	int i = 0;
	for(i = 0; i < 10; i++){
		
		printf("%d\n", taulukko[i]);
		
	}
	printf("\n");
	
	
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
