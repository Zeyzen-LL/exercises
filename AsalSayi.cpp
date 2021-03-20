#include<stdio.h>

int main(){
	int sayi;
	int i,j;
	int sayac=0,kontrol;
	
	printf("bir sayi giriniz : ");
	scanf("%d",&sayi);
	
	for(i=2;i<=sayi;i++){
		kontrol=0;
		for(j=2;j<i;j++){
			if(i%j==0){
				kontrol=1;
				break;
			}
		}
//		if(kontrol==0){
//			printf("%d\n",i);
//			sayac++;
//		}
	}
//	printf("%d tane asal sayi vardir...",sayac);
	if(kontrol==0){
			printf("%d asal",sayi);
		}
	else{
		printf("%d asal degil",sayi);
	}
	return 0;
}
