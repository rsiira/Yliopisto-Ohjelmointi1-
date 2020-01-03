#include <stdio.h>

int maaritaKarkausvuosi(int vuosiluku);

int main(){
	
	int vuosiluku;
	printf("Anna vuosiluku: \n");
	scanf("%d", &vuosiluku);
	
	if (maaritaKarkausvuosi(vuosiluku)==1){
		printf("Vuosi on karkausvuosi.");
	}
	else{
		printf("Vuosi ei ole karkausvuosi.");
	}
	
	return 0;
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
