#include <stdio.h>
#include <stdlib.h>

typedef struct agac{
	agac *sag;
	int sayi;
	agac *sol;
}agac;


agac* veriekle(agac* root, int eklenecekveri);
void arama(agac* root, int veri);
void listeleme(agac* root);
void enK(agac* root);
void enB(agac* root);

int main(){
	int dizi[]={100,110,108,120,95,93,97,80,85,83,70,75,60,87};
	int veri;
	agac* root = NULL;
	root =veriekle(root, 90);
	for (int i=0;i<14;i++){
		veriekle(root, dizi[i]);
	}
	listeleme(root);
	enK(root);
	enB(root);
	
	printf("aranaca veri....\n");
	scanf("%d",&veri);
	
	arama(root,veri);
	return 0;
}

agac* veriekle(agac* dal, int eklenecekveri){
    if (dal == NULL){
        agac* yeni=(agac*)malloc(sizeof(agac));
        yeni->sayi=eklenecekveri;
		yeni->sag=NULL;
		yeni->sol=NULL;
        return yeni;
    }
    if (eklenecekveri < dal->sayi)
        dal->sol  = veriekle(dal->sol, eklenecekveri);
    else if (eklenecekveri > dal->sayi)
        dal->sag = veriekle(dal->sag, eklenecekveri);

    return dal;


}

void listeleme(agac* root){
	if(root==NULL){
		printf("tree bossss....\n");
	}
	else{
		if(root->sol!=NULL){
			printf("\n");
			listeleme(root->sol);
		}
		printf("%d ",root->sayi);
		if(root->sag!=NULL){
			listeleme(root->sag);
			printf("\n   ");
		}
	}
}


void arama(agac* root, int veri){
	int sol,sag;
	if(root->sayi==veri){
		printf("aranan deger : %d\n",root->sayi);
	}
	else if(root->sayi > veri){
			arama(root->sol,veri);
			
	}
	else if(root->sayi < veri){
			arama(root->sag,veri);
	}
	else{
		printf("veri bulunamadý....\n");
	}
}

void enK(agac* root){
	while(root->sol!=NULL){
		root=root->sol;
	}
	printf("\nen kucuk eleman : %d\n",root->sayi);
}
void enB(agac* root){
	while(root->sag!=NULL){
		root=root->sag;
	}
	printf("en buyun eleman : %d\n",root->sayi);
}

//void silme(agac* root, silSayi){
	
	
	
//}




