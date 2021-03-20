#include<stdio.h>


int obeb(int x, int y) {
	if (y == 0)
		return x;
return obeb(y, x % y);
}

int okek(int x, int y) {
return x * y / obeb(x, y);
}


int main(){
	
	int sayi;
	printf("okek ");
	printf("%d",okek(5,102));
	printf("\nobeb ");
	printf("%d",obeb(96,48));
	
}


