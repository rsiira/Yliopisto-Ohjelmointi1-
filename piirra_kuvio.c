#include <stdio.h>

int main (){

	int i = 0;
	int j = 0;

	for(i=6; i>=1; i--){
		for(j=1; j<=i; j++){
			
			printf("*");
		}
		
		printf("\n");
	}
	
}
