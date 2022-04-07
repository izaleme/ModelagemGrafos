#include <stdio.h>
#include <stdlib.h>

//Teremos duas funções: heapSort e createHeap
void heapSort (int *vet, int n){
	int i, aux;
	
	//Criando o heap a partir dos elementos (dados)
	for (i=(n-1)/2; i>=0; i--){
		createHeap(vet, i, n-1);	//O createHeap vai estruturar os elementos no formato da árvore	
	}
	
	for (i=n-1; i>=1; i--){
		//Pegando o maior elemento no topo da árvore e colocando na posição i (última posição do vetor)
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		createHeap(vet, 0, i -1); //Reconstrói o heap
	}

	void createHeap(int *vet, int i, int f){
		int aux = vet[i]; //Posição "pai"
		int j = i*2+1; //Primeiro "filho"
		
		while (j<=f){ //Se o filho for menor ou igual o final do vetor
			if (j<f){ //Se o filho for menor que o final do vetor
				if(vet[j] < vet[j+1]){ //Verifica qual é o maior dentre os filhos
					j = j + 1; //Filho maior
				}
			}
			
			if (aux < vet[j]){ //Verifica se o pai é menor que o filho. Se for correto, ele não está na posição correta da Heap.
				vet[i] = vet[j];
				i = j; //O j se torna o pai
				j = 2*i+1; ///Calcula o primeiro filho do j e repete o processo.
			} else {
				j = f + 1;
			}
		}
		vet[i] = aux; //Antigo pai ocupa o lugar do último filho analisado. 
	}
	
}
