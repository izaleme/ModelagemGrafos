#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

//Cabeçalho 

int main () 
{
  
void menorCaminho_Grafo (Grafo * gr, int ini, 
int *ant, float *dist);
  
system ("pause");
   
return 0; }

///////////////////////////////////////////////////////////////////////////////////

void menorCaminho_Grafo (Grafo * gr, int ini, int *ant, float *dist)
{

  int i, cont, NV, ind, *visitado, u;
  cont = NV = gr->nro_vertices;
   
  visitado = (int *) malloc (NV * sizeof (int));
  for (i = 0; i < NV; i++)
    {
      ant[i] = -1;
      dist[i] = -1;
      visitado[i] = 0;
	}  
    dist[ini] = 0;
      while (cont > 0)
	{

	  u = procMenorDist (dist, visitado, NV);
	  if (u == -1)
	    break;

	  visitado[u] = 1;
	  cont--;
	}

      free (visitado);
///////////////////////////////////////////////////////////////////////////////////

//NV = Numero de vertices

int procMenorDist (float *dist, int *visitado, int NV)
{
int i, menor = -1, primeiro = 1;
for (i = 0; i < NV; i++)
    {  
if (dist[i] >= 0 && visitado[i] == 0)
	{	  
if (primeiro)
	    {	      
menor = i;	      
primeiro = 0;    
}
	else
	    {
	      
if (dist[menor] > dist[i])		
menor = i;	    
}
}   
}
return menor;
}
///////////////////////////////////////////////////////////////////////////////////

for (i = 0; i < gr->grau[u]; i++) //Para cada vertice sozinho
  {
    ind = gr->arestas[u][j];
    if (dist[ind] < 0)
      {
	dist[ind] = dist[u] + 1;
	//ou peso da aresta 
	//dist [ind] = dist [u] + gr -> pesos [u] [i];
	ant[ind] = u;
      }
    else
      {

	if (dist[ind] > dist[u] + 1)
	  {
	    //if (dist[ind] > dist [u] + 1) {// ou peso da aresta
	    dist[ind] = dist[u] + 1;
	    //ou peso da aresta
	    // dist [ind] = dist[u] + gr -> pesos [u][i];
	    ant[ind] = u;

	  }
      }
  }
/////////////////////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main ()
{
   
int FIB_digrafo = 1;
Grafo * gr = cria_Grafo (4, 4, 0);
insereAresta (gr, 0, 1, FIB_digrafo, 0);
insereAresta (gr, 1, 3, FIB_digrafo, 0);
insereAresta (gr, 1, 2, FIB_digrafo, 0); 
insereAresta (gr, 2, 4, FIB_digrafo, 0); 
insereAresta (gr, 3, 0, FIB_digrafo, 0); 
insereAresta (gr, 3, 4, FIB_digrafo, 0); 

int ant[5];
float dist[5]; 
menorCaminho_Grafo (gr, 0, ant, dist);
 
liberar_Grafo (gr); 
system ("pause"); 
 
return 0; 
}
  


