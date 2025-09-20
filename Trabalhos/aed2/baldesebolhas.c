#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


long long g_contador_inversoes;

void imprime(int vetor[], int tamanho){
    for(int i = 0; i<tamanho ; i++){
        printf("%d ", vetor[i]);
    }
}

void mergeVetores(int vetor[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1, n2 = fim-meio, i, j;

    int vetor1[n1+1];
    int vetor2[n2+1];
    vetor1[n1] = INT_MAX;
    vetor2[n2] = INT_MAX;

    for(i = 0; i < n1; i++){
        vetor1[i] = vetor[inicio + i];
    }
    for(j = 0; j < n2; j++){
        vetor2[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    for(int k = inicio; k<=fim; k++){
        if(vetor1[i] <= vetor2[j]){
        vetor[k] = vetor1[i];
        i++;
        }else{
        vetor[k] = vetor2[j];
        j++;
            g_contador_inversoes += (n1 - i);
        }
    }
}


void mergeSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        mergeVetores(vetor,inicio,meio,fim);
    }
}

int main(){
    int N;


    while(scanf("%d", &N) == 1 && N != 0){
        

        g_contador_inversoes = 0;

        int *vetor = (int*) malloc(N * sizeof(int));
        for(int i = 0; i < N; i++){
            scanf("%d", &vetor[i]);
        }
        

        mergeSort(vetor, 0, N - 1);
        

        if (g_contador_inversoes % 2 == 0){
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
        
        free(vetor);
    }
    
    return 0;
}
