#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MELKOR 1000000
/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
int printMST(int parent[], int Array[8][8]);
void readMatrix();
int minmaliyet(int maliyet[], bool visited[]);
void prims(int Array[8][8]);

int Array[8][8];

void readMatrix(){
    int i = 0;
    FILE *fp = fopen("prims.txt","r");
    while(!feof(fp)){
    	fscanf(fp, "%d %d %d %d %d %d %d %d",&Array[i][0],&Array[i][1],&Array[i][2],&Array[i][3],&Array[i][4],&Array[i][5],&Array[i][6],&Array[i][7]);
        i = i + 1 ;
    }
}
int minmaliyet(int maliyet[], bool visited[]){
    int min = MELKOR;
    int minIndex, i;
    for( i = 0; i < 8; i++){
        if(visited[i] == false && maliyet[i] < min){
            min = maliyet[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void prims(int Array[8][8]){
    int i, j, t;
    int maliyet[8];
    int parent[8];
    bool visited[8];
    for(i = 0; i < 8; i++){
        visited[i] = false;
        maliyet[i] = MELKOR;
    }
    maliyet[0] = 0;
    parent[0] = -1;
    for(j = 0; j < 8; j++){
        int u = minmaliyet(maliyet, visited);
        visited[u] = true;
        for(t = 0; t < 8; t++){
            if(Array[u][t] && visited[t] == false && Array[u][t] < maliyet[t]){
                maliyet[t] = Array[u][t];
                parent[t] = u;
            }
        }
    }
    printMST(parent, Array);
}
int printMST(int parent[], int Array[8][8]){
   int i;
   for (i = 1; i < 8; i++)
      printf("%c - %c    %d \n", parent[i]+65, i+65, Array[i][parent[i]]);
}
int main(){
    readMatrix();
    prims(Array);
}
