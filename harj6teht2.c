#include <stdio.h>
#include <ctype.h>
#include <string.h>

void kopioiMerkkijono(char merkkijono[], char kopio_merkkijono[]);

void pienaakkosiksi(char str[]);

int main(){
	
	char merkkijono[20]; //vain 20 merkkiä
	char kopio_merkkijono[20];
	int tulos = 0;
	
	printf("Anna merkkijono (max 20 merkkia): \n");
	scanf("%s", &merkkijono);
	
	//Kopioidaan merkkijono
	kopioiMerkkijono(merkkijono, kopio_merkkijono);
	
	//Muutetaan molemmat merkkijonot pienaakkosiksi
	pienaakkosiksi(merkkijono);
	pienaakkosiksi(kopio_merkkijono);
    
    //Vertaillaan merkkijonoja
    tulos = strcmp(merkkijono, kopio_merkkijono);
    
    if(tulos == 0){
    	
    	printf("Merkkijono on palindromi.");
	}
	
	else if(tulos != 0){
		
		printf("Merkkijono ei ole palindromi.");
		
	}

	return 0;
}

void kopioiMerkkijono(char merkkijono[], char kopio_merkkijono[]){
	
	int i;
	
	for(i = 0; i < strlen(merkkijono); i++){
		
		kopio_merkkijono[i] = merkkijono[strlen(merkkijono)-1-i];
		
	}
	
	kopio_merkkijono[i] = '\0'; //Lisätään NULL (merkkijonon lopetusmerkki)
	
}

void pienaakkosiksi(char str[]){
	
	int i = 0;
	
	for(i=0; i<strlen(str); i++){
		
		str[i] = tolower(str[i]);
		
	}
}
