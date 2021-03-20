#include<stdio.h>


int okek(int x, int y){
	if(x%y == 0)
		return x;
	return x*okek(y,x%y)/(x%y);	
}


int main(){
	int x,y;
	x=102;
	y=5;
	
	printf("%d",okek(x,y));
	
	return 0;
	
}
