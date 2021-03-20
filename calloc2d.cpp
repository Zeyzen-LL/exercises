#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **dizi=NULL;
	dizi=(int**)calloc(10,sizeof(int*));
	
	
	for(int i=0;i<10;i++)
	{
		dizi[i]=(int *)calloc(10, sizeof(int));
	} 
	
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			printf("%d ", dizi[i][j]);
		}
		printf("\n");
	}
	
}
