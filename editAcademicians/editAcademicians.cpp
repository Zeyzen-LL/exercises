#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct akademisyen {  
		int sicilNo; 
		char ad[100]; 
		char soyAd[100]; 
		int unvanID; 
		int unvanYili; 
		struct akademisyen *sonraki; 
} Akademisyenler;
	akademisyen *son=NULL ,*ilk=NULL ,*yeni=NULL; 



	void DosyaOkuBListeOlustur(){
		FILE *fp1;
		int sicilno ,unvanid ,unvanyili;
		char adi[100];
		char soyadi[100];
		
		fp1 = fopen("akademisyenler.txt","r");
		akademisyen *temp=NULL ,*temp1=NULL; 
		while(!feof(fp1)){	
														
			yeni=(akademisyen*)malloc(sizeof(akademisyen));
			fscanf(fp1,"%d %s %s %d %d",&sicilno ,adi ,soyadi ,&unvanid ,&unvanyili); 									
			
			strcpy(yeni->ad,adi);
			strcpy(yeni->soyAd,soyadi);
			yeni->sicilNo=sicilno;
			yeni->unvanID=unvanid;
			yeni->unvanYili=unvanyili;
			yeni->sonraki=NULL;																	
																			
			if(ilk==NULL){																
				ilk=yeni;
				son=yeni;	
			}
			else if(son==ilk){
				if(son->unvanID > yeni->unvanID){
					yeni->sonraki=ilk;
					ilk=yeni;
				}
				else if(son->unvanID < yeni->unvanID){
					son->sonraki=yeni;
					son=yeni;
				}
				else if(son->unvanID == yeni->unvanID && son->unvanYili < yeni->unvanYili){
					son->sonraki=yeni;
					son=yeni;
				}
				else if(son->unvanID == yeni->unvanID && son->unvanYili > yeni->unvanYili){
					yeni->sonraki=ilk;
					ilk=yeni;
				}
			}
			else if(ilk->unvanID > yeni->unvanID){
				yeni->sonraki=ilk;
				ilk=yeni;	
			}
			else if(son->unvanID < yeni->unvanID){
				son->sonraki=yeni;
				son=yeni;
				}
			else if(son->unvanID == yeni->unvanID && son->unvanYili < yeni->unvanYili){
				son->sonraki=yeni;
				son=yeni;
			}
			else{
				temp=ilk;
				temp1=ilk->sonraki;
				while(temp1!=NULL){
					if(temp->unvanID < yeni->unvanID && temp1->unvanID > yeni->unvanID){
						yeni->sonraki=temp->sonraki;
						temp->sonraki=yeni;
					}
					else if(temp1->unvanID == yeni->unvanID && temp1->unvanYili < yeni->unvanYili){
						yeni->sonraki=temp1->sonraki;
						temp1->sonraki=yeni;
					}
					else if(temp1->unvanID == yeni->unvanID && temp1->unvanYili > yeni->unvanYili){
						yeni->sonraki=temp->sonraki;
						temp->sonraki=yeni;
					}
					temp=temp->sonraki;
					temp1=temp1->sonraki;
				}
			}		
		}
		fclose(fp1);
	}
	
	void Listeleme(){
		akademisyen *temp=NULL;
		temp=ilk;
		while(temp != NULL){
			if(temp->unvanID==1){
			printf("%d Prof. Dr. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==2){
			printf("%d Doc. Dr. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==3){
			printf("%d Dr. Ogr. Uyesi %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==4){
			printf("%d Ars. Gor. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			temp=temp->sonraki;
		}
	}
	
	void Silme(){
		int sicilno;
		akademisyen *temp=NULL ,*temp1=NULL;
		akademisyen *silinecek=NULL;
		int kontrol=0;
		printf("Silmek istenilen gorevlinin sicil numarasi :");
		scanf("%d",&sicilno);
		temp=ilk;
			if(ilk->sicilNo == sicilno){
				silinecek=ilk;
				ilk=ilk->sonraki;
				kontrol=1;
			}
			else if(son->sicilNo == sicilno){
				while(temp->sonraki->sonraki!=NULL){
					temp=temp->sonraki;
				}
				silinecek=son;
				son=temp;
				son->sonraki=NULL;
				kontrol=1;
			}
			else{
				temp=ilk;
				temp1=ilk->sonraki;
				while(temp!=NULL){
						if(temp1->sicilNo == sicilno){
						silinecek=temp1;
						temp->sonraki=temp1->sonraki;
						kontrol=1;
					}
				temp=temp->sonraki;
				temp1=temp1->sonraki;
			}
		}
		if(kontrol==0){
			printf("Uygun kayit bulunamamistir....");
		}
		else{
		printf("%d %s %s %d %d",silinecek->sicilNo ,silinecek->ad ,silinecek->soyAd ,silinecek->unvanID ,silinecek->unvanYili); 	
		free(silinecek);	
		}
		
	}

	void Ekleme(){
		int sicilno ,unvanid ,unvanyili;
		char adi[100];
		char soyadi[100];
		akademisyen *temp=NULL ,*temp1=NULL;
		
		yeni=(akademisyen*)malloc(sizeof(akademisyen));									
			
		printf("Sicil no: ");
		scanf("%d", &sicilno);
		printf("Ad: ");
		scanf("%s", adi);
		printf("Soyad: ");
		scanf("%s", soyadi);
		printf("Unvad id: ");
		scanf("%d", &unvanid);
		printf("Unvan yili: ");
		scanf("%d", &unvanyili);
		
		strcpy(yeni->ad,adi);
		strcpy(yeni->soyAd,soyadi);
		yeni->unvanID=unvanid;
		yeni->unvanYili=unvanyili;
		yeni->sicilNo=sicilno;
		yeni->sonraki=NULL;
		
		if(ilk->unvanID > yeni->unvanID){
			yeni->sonraki=ilk;
			ilk=yeni;
		}
		else if(ilk->unvanID == yeni->unvanID && ilk->unvanYili > yeni->unvanYili){
			yeni->sonraki=ilk;
			ilk=yeni;
		}
		else if(son->unvanID < yeni->unvanID){
			son->sonraki=yeni;
			son=yeni;
		}
		else if(son->unvanID == yeni->unvanID && son->unvanYili < yeni->unvanYili){
			son->sonraki=yeni;
			son=yeni;
		}
		else{
			temp=ilk;
			temp1=ilk->sonraki;
			while(temp1!=NULL){
				if(temp->unvanID < yeni->unvanID && temp1->unvanID > yeni->unvanID){
					yeni->sonraki=temp->sonraki;
					temp->sonraki=yeni;
				}
				else if(temp1->unvanID == yeni->unvanID && temp1->unvanYili < yeni->unvanYili){
					yeni->sonraki=temp1->sonraki;
					temp1->sonraki=yeni;
				}
				else if(temp1->unvanID == yeni->unvanID && temp1->unvanYili > yeni->unvanYili){
					yeni->sonraki=temp->sonraki;
					temp->sonraki=yeni;
				}
				temp=temp->sonraki;
				temp1=temp1->sonraki;
			}
		}		
	}


	void Gorevlendirme(){
		int kisisayisi,sayac=0;
		akademisyen *temp=NULL;
		
		printf("Gorevlendirilecek kisi sayisi:");
		scanf("%d",&kisisayisi);
		temp=ilk;
		while(temp!=NULL){
			sayac++;
			temp=temp->sonraki;
		}
		int a,j,i;
		temp=ilk;
		for(i=1;i<=kisisayisi;i++){
			temp=ilk;
			for(j=0;j<sayac-1;j++){
				temp=temp->sonraki;
			}
			if(temp->unvanID==1){
			printf("%d Prof. Dr. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==2){
			printf("%d Doc. Dr. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==3){
			printf("%d Dr. Ogr. Uyesi %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			else if(temp->unvanID==4){
			printf("%d Ars. Gor. %s %s \n",temp->sicilNo ,temp->ad ,temp->soyAd );
			}
			sayac--;
	
		}
	}

	int main(){
		int secim;
		DosyaOkuBListeOlustur();
		
		while(1){
			printf("1.Listeleme...\n2.Gorevlendirme...\n3.Ekleme...\n4.Silme...\n0.Exit...\n");
			scanf("%d",&secim);
			
			switch(secim){
				case 1 : Listeleme();break;
				case 2 : Gorevlendirme();break;
				case 3 : Ekleme();break;
				case 4 : Silme();break;
				case 0 : exit(1);break;
				default : printf("Gecerli bir numara girmediniz...");break;
			}
			printf("\n\n");
			
		}
	return 0;
		
	}


