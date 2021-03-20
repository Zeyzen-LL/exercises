#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct polinom { 
			int katsayi;  
			int us;  
			struct polinom *sonraki; 
	} Polinomlar; 
	
	polinom *p1=NULL , *p2=NULL , *p3=NULL , *son1=NULL , *son2=NULL , *son3=NULL , *yeni1=NULL , *yeni2=NULL , *yeni3=NULL;
	
	Polinomlar * Polinom_Topla(Polinomlar * p1, Polinomlar * p2){
		
		polinom *temp2=NULL , *temp3=NULL , *yeni=NULL;
		int kontrol;
		temp3=p3;
		temp2=p2;
		
		while(p2!=NULL){
			kontrol=0;
			p3=temp3;
			while(p3!=NULL){
																	//p3 zaten p1in t�m elemanlar�n� kapsad��� i�in p1 ile burda i�im kalmad�
				if(p3->us==p2->us){									//p2 nin bir eleman� ile p3 teki elemanlar�n us lerini kontrol ettim 
					p3->katsayi += p2->katsayi;						//e�itse katsay�lar� toplad�m
					kontrol=1;
				}
		
				p3=p3->sonraki;
			}
			if(kontrol == 0){										//de�ilse yeni bir kutu olu�turup ekledim
				yeni=(polinom*)malloc(sizeof(polinom));
				
				yeni->us=p2->us;
				yeni->katsayi=p2->katsayi;
				yeni->sonraki=NULL;
				son3->sonraki=yeni;
				son3=yeni;
				
				
			}
			p2=p2->sonraki;
		}
		
		p3=temp3;
		return p3;											//ve geriye p1 ve p2 nin toplam� olan p3 � d�nd�rd�m
	}
	
	Polinomlar * Siralama(Polinomlar * p3){
		
		polinom *sira1=NULL , *sira2=NULL , *temp=NULL;
		
		temp=(polinom*)malloc(sizeof(polinom));
		
		int kontrol=0;
		sira1=p3;
		sira2=p3->sonraki;
		
		while(kontrol==0){
		sira1=p3;
		sira2=p3->sonraki;
		kontrol=0;			
			while(sira2!=NULL){													//polinomlar� uslerine g�re d�zenle sokmak i�in bubble sort uygulad�m
				if(sira1->us < sira2->us){										
					temp->us = sira1->us;												
					temp->katsayi = sira1->katsayi;
				
					sira1->us = sira2->us;
					sira1->katsayi = sira2->katsayi;
				
					sira2->us = temp->us;
					sira2->katsayi = temp->katsayi;
					}
				sira1=sira1->sonraki;
				sira2=sira2->sonraki;
				
				kontrol=1;
			}
		}
		return p3;
	}
	
	void DosyaOkuBListeOlustur(){
		
	FILE *fp1 , *fp2;
	int ks,uss;	

		
	fp1 = fopen("polinom1.txt","r");
	fp2 = fopen("polinom2.txt","r");
		
																		
		while(!feof(fp1)){													
			fscanf(fp1,"%dx%d",&ks,&uss);									//Bu while d�ng�s� i�inde p1 ve p3 ba�l� listelerini ayn� anda olu�turdum
																			//zaten p1 veya p2 direk olarak p3 te bulunaca�� i�in ben de direk p1 ile p3 ayn� anda olu�turdum
																			//daha sonra da p3 kontrol ederek p2 yi toplar�m veya eklerim diye d���nd�m
			if(p1==NULL){													//Burda p1 ve p3 �n ilk kutular�n� olu�turdum			
				p1=(polinom*)malloc(sizeof(polinom));
			
				p1->katsayi=ks;
				p1->us=uss;
				p1->sonraki=NULL;
				son1=p1;
				
				p3=(polinom*)malloc(sizeof(polinom));
								
				p3->katsayi=ks;
				p3->us=uss;
				p3->sonraki=NULL;
				son3=p3;
			}
			else{													 	//Burda da di�er elemanlar� ayr� ayr� p1 ve p3 �n pe�ine ekledim
				yeni1=(polinom*)malloc(sizeof(polinom));
				
				yeni1->katsayi=ks;
				yeni1->us=uss;
				son1->sonraki=yeni1;
				son1=yeni1;
				son1->sonraki=NULL;
				
				yeni3=(polinom*)malloc(sizeof(polinom));
				
				yeni3->katsayi=ks;
				yeni3->us=uss;
				son3->sonraki=yeni3;
				son3=yeni3;
				son3->sonraki=NULL;
			}
			
		}
		fclose(fp1);
		
			while(!feof(fp2)){										//Bu while d�ng�s� yukarda p1 ve p3 i�in yap�lan� sadece p2 i�in yap�yor
				fscanf(fp2,"%dx%d",&ks,&uss);
				if(p2==NULL){										//Burda p2 nin ilk eleman�n� olu�turuyoruz
					p2=(polinom*)malloc(sizeof(polinom));

					p2->katsayi=ks;
					p2->us=uss;
					p2->sonraki=NULL;
					son2=p2;
			}
			else{												// burda da sonraki elemanlar� pe�ine ekliyoruz
				yeni2=(polinom*)malloc(sizeof(polinom));
				
				yeni2->katsayi=ks;
				yeni2->us=uss;
				son2->sonraki=yeni2;
				son2=yeni2;	
				son2->sonraki=NULL;
			}	
		}
		
	}
	
int main(){
		FILE *fp3;
		
		DosyaOkuBListeOlustur();
		
		polinom *temp3=NULL;											//toplarken p3 yer de�i�ti�i i�in ilk adresi kaybetmemek i�in temp3 olu�turdum ve p3 g�stedi�i yeri g�stedim
		temp3=p3;
		
		p3=Polinom_Topla(p3 , p2);
		
		p3=Siralama(p3);
		
		fp3=fopen("polinom3.txt","w");									
		
		while(temp3!=NULL){											//burda da dosyaya ve ekrana yazd�rd�m 
				
			if(temp3->sonraki !=NULL){
				if(temp3->sonraki->katsayi < 0){							//katsayi da ki '-', '+' durumunu ayarl�yor
					fprintf(fp3,"%dx%d",temp3->katsayi,temp3->us);
					printf("%dx%d+",temp3->katsayi,temp3->us);
					printf("\b");
				}
				else{
			fprintf(fp3,"%dx%d+",temp3->katsayi,temp3->us);
			printf("%dx%d+",temp3->katsayi,temp3->us);
				}					
			}
			else if(temp3->sonraki == NULL){
			fprintf(fp3,"%dx%d",temp3->katsayi,temp3->us);
			printf("%dx%d",temp3->katsayi,temp3->us);
			}
			temp3=temp3->sonraki;	
		}	
		fclose(fp3);
		
		getch();
		return 0;
	}
