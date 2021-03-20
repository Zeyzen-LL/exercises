#include<stdio.h>

int main(){
	
	int matris[5][5] = {{1,0,1,1,0},
						{1,0,0,0,1},
						{1,1,1,1,1},
						{1,0,1,0,0},
						{0,1,0,1,1}
						};
	
	int cikis[5]={0, 0, 0, 0, 0};
	int giris[5]={0, 0, 0, 0, 0};
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(matris[i][j]==1){
				cikis[i]++;
				giris[j]++;
			}
		}
	}
	for(int i = 0; i < 5; i++){
		printf("%d. indexin cikis %d \tgiris %d\n",i, cikis[i], giris[i]);
	}
	
}

