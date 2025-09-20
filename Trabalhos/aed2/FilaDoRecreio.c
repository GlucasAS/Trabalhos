#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int cont = 0;


void imprime(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
	printf("\n");
    }
}


void mergeVetores(int vetor[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int i, j;

    int vetor1[n1+1], vetor2[n2+1];

    vetor1[n1] = INT_MIN; 
    vetor2[n2] = INT_MIN;

    
    for(i = 0; i < n1; i++){
        vetor1[i] = vetor[inicio + i];
    }
    for(j = 0; j < n2; j++){
        vetor2[j] = vetor[meio + 1 + j];
    }

    i = 0; j = 0;
    for(int k = inicio; k <= fim; k++){
        if(vetor1[i] >= vetor2[j]){ 
            vetor[k] = vetor1[i]; 
            i++;
        } else {
            vetor[k] = vetor2[j];
            j++;
        }
    }
}


void mergeSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        mergeVetores(vetor, inicio, meio, fim);
    }
}

int main(){
    int a,b,c, cont = 0;
    scanf("%d", &a);
    int *retornos = malloc(a*sizeof(int));

    for(int i = 0; i < a; i++){
   	scanf("%d", &b);
	int *notas = malloc(b*sizeof(int));
	int *pos_original = malloc(b*sizeof(int));
	for(int j=0; j<b; j++){
		scanf("%d", &c);
		notas[j] = c;
		pos_original[j] = c;
	}
	mergeSort(notas, 0, b-1);
	for(int k=0; k<b; k++){
		if(notas[k] == pos_original[k]){
			cont++;
		}
	}
	retornos[i] = cont;
	cont =0;
	free(notas);
	free(pos_original);
    }

    imprime(retornos,a);
    free(retornos);


    return 0;
}
