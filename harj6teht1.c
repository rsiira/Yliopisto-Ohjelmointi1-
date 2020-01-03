#include <stdio.h>
#include <ctype.h>
#include <string.h>

void suuraakkosiksi(char str[]);
 
void pienaakkosiksi(char str[]);

int main(){
	
	char merkkijono[20]; //vain 20 merkkiä
	
	printf("Anna merkkijono (max 20 merkkia): \n");
	scanf("%s", &merkkijono);
	
	printf("syotit: \n");
	printf("%s\n", merkkijono);
	
	suuraakkosiksi(merkkijono);
	printf("Suuraakkosina: \n");
	printf("%s\n", merkkijono);
	
	pienaakkosiksi(merkkijono);
	printf("Pienaakkosina: \n");
	printf("%s\n", merkkijono);
	
	return 0;
	
	
}

void suuraakkosiksi(char str[]){
	
	int i = 0;
	
	for(i=0; i<strlen(str); i++){
		
		str[i] = toupper(str[i]);
		
	}
	
}
 
void pienaakkosiksi(char str[]){
	
	int i = 0;
	
	for(i=0; i<strlen(str); i++){
		
		str[i] = tolower(str[i]);
		
	}
}
