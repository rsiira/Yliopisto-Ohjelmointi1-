#include <stdio.h>

int main (){
	
	int sivu = 0;
	int i;
	int j;
	
	printf("Anna nelion sivun pituus: ");
	scanf("%d", &sivu);
	
	if (sivu >= 1 && sivu <= 20){
		
		for(i=1; i<=sivu; i++){
			for(j=1; j<=sivu; j++){
				
				printf("*");
			}
			
			printf("\n");
		}
		
	}
	
	else{
		printf("Anna luku valilta 1-20.");
	}
	
	return 0;	
}
