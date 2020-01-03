#include <stdio.h>
#include <math.h>

int	korotaPotenssiin (	int luku,	int potenssi );

int main(){
	
	int luku, potenssi, arvo;
	printf("Anna luku: \n");
	scanf("%d", &luku);
	printf("Anna potenssi: \n");
	scanf("%d", &potenssi);
	
	arvo = korotaPotenssiin(luku, potenssi);
	printf("Arvo: %d", arvo);
	
	return 0;
	
}

int	korotaPotenssiin (	int luku,	int potenssi ){
	
	int i;
	int arvo = 1;
	
	if(potenssi > 0){
		for(i=0; i<potenssi; i++){
			arvo *= luku;
		}
		
		return arvo;
		
	}
	else{
		printf("Potenssin on oltava positiivinen kokonaisluku");
	}
}

