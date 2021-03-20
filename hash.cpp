#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
//#define MAX_ROW  6
struct yapi{
	int index;
	int data;
	yapi* sonraki;
};
void sifirla(yapi dizi[],int elemansayisi);
void veriekle(int ogrveri,yapi dizi[],int MAX_ROW);
void verilistele(yapi dizi[],int MAX_ROW);
void veriarama(int veri, int satir, yapi dizi[]);
	
int main(){
	setlocale(LC_ALL,"Turkish");
	int veri;
	int MAX_ROW=6;
	int ogrenci[]={12,423,53,56,7,968,23,453,58,2,436,7,34,535,68,2,6};
	yapi dizi[6];
	sifirla(dizi,MAX_ROW);
	for (int i = 0; i<sizeof(ogrenci)/sizeof(int); i++)
	{
		veriekle(ogrenci[i],dizi,MAX_ROW);
	}
	verilistele(dizi,MAX_ROW);

	printf("aranacak veri.....");
	scanf("%d",&veri);
	
	veriarama(veri, MAX_ROW, dizi);

	return 0;
}

void sifirla(yapi dizi[],int MAX_ROW){
	for(int i=0;i<MAX_ROW;i++){
		dizi[i].index=0;
		dizi[i].data=0;
		dizi[i].sonraki=NULL;
	}
}

void veriekle(int ogrveri,yapi dizi[],int MAX_ROW){
	int nereyeekle=ogrveri%MAX_ROW;
	yapi* temp;
	if(dizi[nereyeekle].index==0){
		dizi[nereyeekle].index=1;
		dizi[nereyeekle].data=ogrveri;
	}
	else{
		if(dizi[nereyeekle].sonraki==NULL){
			dizi[nereyeekle].sonraki=(yapi*)malloc(sizeof(yapi));
			temp=dizi[nereyeekle].sonraki;
			temp->data=ogrveri;
			temp->sonraki=NULL;
		}
		else{	
			temp=dizi[nereyeekle].sonraki;
			while(temp->sonraki!=NULL){
				temp=temp->sonraki;
			}
			temp->sonraki=(yapi*)malloc(sizeof(yapi));
			temp=temp->sonraki;
			temp->data=ogrveri;
			temp->sonraki=NULL;
		}
	}
}

void verilistele(yapi dizi[],int MAX_ROW){
	for(int i=0;i<MAX_ROW;i++){
		if(dizi[i].index==0){
			printf("%d hashli sayi yok...\n",i);
		}else{
			int sayac=1;
			if(dizi[i].sonraki==NULL){
				printf("%d.satirin %d.sütunundaki veri: %d\n",i,sayac,dizi[i].data);
			}else{
				yapi* temp=dizi[i].sonraki;
				while(temp!=NULL){
					printf("%d.satirin %d.sütunundaki veri: %d\n",i,sayac,temp->data);
					sayac++;
					temp=temp->sonraki;
				}
			}
		}
	}
}

void veriarama(int veri, int satir, yapi dizi[]){
	int arama=veri%satir;
	yapi* temp=NULL;
	int sayac=1;
	int kontrol=0;

	temp=&dizi[arama];
	while(temp!=NULL){
		if(temp->data==veri){
			printf("%d.satirin %d.sütunundaki veri: %d\n",arama,sayac,temp->data);
			kontrol=1;
		}
		sayac++;
		temp=temp->sonraki;
	}
	if(kontrol==0){
		printf("%d verisi bu hash de yok...\n",veri);
	}
	
}


