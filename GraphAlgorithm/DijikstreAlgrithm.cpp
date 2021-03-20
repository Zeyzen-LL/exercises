#include <stdio.h>
#include <limits.h>
#define V 8 // Graftaki d���m say�s�n� V global de�i�keni ile ifade edece�iz.

int minDistance(int dist[], bool visited[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    	if (visited[v] == false && dist[v] <= min)
        	min = dist[v], min_index = v;
    return min_index;
}  

int printDist(int dist[], int n){
	char dizi[8][20] = {"KONYA", "ESKISEHIR", "SIVAS", "NIGDE", "MERSIN", "KAYSERI", "ANTALYA", "DENIZLI"} ;
   	printf("Dugumlerin ana kaynaga olan uzakligi\n");
   	for (int i = 0; i < V; i++)
    	printf("%s--%s  mesafe %d\n", dizi[0], dizi[i], dist[i]);
}
// Dijkstra algoritmas�n�n temel fonksiyonu
// A��rl�kl� graf yap�m�z� graph[V][V] dizisinde tutuyoruz
// int src ise ba�lang�� noktam�z.
void dijkstra(int graph[V][V], int src){
	int dist[V];     //Ba�lang�� d���m�nden bir ba�ka d���me olan uzakl��� burada tutaca��z.
	bool visited[V];
	 
	for (int i = 0; i < V; i++)
	    dist[i] = INT_MAX, visited[i] = false;
		dist[src] = 0;
	 // T�m d���mlere olan uzakl���n (kaynaktan) bulunaca�� d�ng�ye giri� yap�yoruz.
	for (int count = 0; count < V-1; count++){
	   // Hen�z ziyaret edilmemi�, en az maliyetli d���m� u de�i�kenine aktar�yoruz.
	   int u = minDistance(dist, visited);
	   visited[u] = true;
	    // Mevcut d���mden di�er kom�u d���mleri tarayan d�ng�m�z
	    for (int v = 0; v < V; v++)
	    	if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
	        	dist[v] = dist[u] + graph[u][v];
	}
	printDist(dist, V);
}
   
int main(){ 
	//KONYA 1, ESKISEH�R 2, SIVAS 3, NIGDE 4, MERSIN 5, 
	//KAYSERI 6, ANTALYA 7 , DENIZLI 8
    int graph[V][V] = {{0, 20, 0, 0, 80, 0, 90, 0},
 	                	{0, 0, 10, 0, 0, 0, 0, 0},
    	                {0, 0, 0, 10, 40, 0, 0, 0},
        	            {0, 0, 50, 0, 10, 20, 0, 0},
            	        {0, 0, 0, 10, 0, 0, 20, 0},
                	    {0, 0, 0, 0, 0, 0, 0, 0},
                        {20, 0, 0, 0, 0, 0, 0, 0},
                        {0, 50, 0, 0, 0, 0, 30, 0}};
    dijkstra(graph, 0);
   
    return 0;
}
