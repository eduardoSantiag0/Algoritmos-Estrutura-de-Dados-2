#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -pedantic -O2 -Wno-unused-result -o distanciaGenomica distanciaGenomica.c; .\distanciaGenomica

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int v[], int n )
{
    int i,j;
    for (i = 0; i < n-1; i++) {
        int minPosicao = i; 
        for (j = i+1; j <= n; j++) {
            if (v[j] < v[minPosicao]) 
                minPosicao = j;
        }

        printf("%d\n", v[minPosicao]);

        int x = v[i]; v[i] = v[minPosicao]; v[minPosicao] = x;

    }
}

int numeroDeTrocas(int individuo1[], int individuo2[], int numeroDeGenes)
{

    int numeroDeTrocas = 0;
    int i, j;

    for (i = 0; i < numeroDeGenes; i++) {

        int posDeY = -1;
        //* Procura a posição de Y
        for (j = i; i < numeroDeGenes; j++) {
            if (individuo2[j] == individuo1[i]) {
                posDeY = j;
                break;
            }
        }


        //! Refatorar

        // Distancia de posDeY e i = numero de Trocas 

        while (posDeY > i)
        {
            troca(&individuo2[posDeY], &individuo2[posDeY - 1] );
            numeroDeTrocas++;
            posDeY--;
        }
    }

    return numeroDeTrocas;

}

int numeroDeTrocas2(int individuo1[], int individuo2[], int numeroDeGenes)
{
    int numeroDeTrocas = 0;
    
    int posicaoAtual[numeroDeGenes];


    for (int i = 0; i < numeroDeGenes; i++) {
        posicaoAtual[individuo2[i]] = i;
    }

    for (int i = 0; i < numeroDeGenes; i++) {
        int val = individuo1[i];
        int pos = posicaoAtual[val];


        while (pos > i) {
            int valAnterior = individuo2[pos - 1];


            individuo2[pos] = valAnterior;
            individuo2[pos - 1] = val;

            
            posicaoAtual[val] = pos - 1;
            posicaoAtual[valAnterior] = pos;

            pos--;
            numeroDeTrocas++;
        }
    }

    return numeroDeTrocas;
}


long long mesclarEContar(int seq[], int temp[], int inicio, int meio, int fim) {
    int i = inicio;

    int j = meio;
    int k = inicio;


    long long numeroDeInversoes = 0;

    while (i <= meio - 1 && j <= fim) {
        if (seq[i] <= seq[j]) {
            temp[k++] = seq[i++];
        } else {
            temp[k++] = seq[j++];
            numeroDeInversoes += (meio - i);  
        }
    }

    while (i <= meio - 1) 
    
        temp[k++] = seq[i++];

    while (j <= fim) 
        
        temp[k++] = seq[j++];

    for (i = inicio; i <= fim; i++) 
        
        seq[i] = temp[i];
    

    return numeroDeInversoes;
}

long long mergeSortRecursivo(int sequencia[], int temporario[], int inicio, int fim) {
    long long numeroDeInversoes = 0;
    
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        numeroDeInversoes += mergeSortRecursivo(sequencia, temporario, inicio, meio);


        numeroDeInversoes += mergeSortRecursivo(sequencia, temporario, meio + 1, fim);

        numeroDeInversoes += mesclarEContar(sequencia, temporario, inicio, meio + 1, fim);
    }


    return numeroDeInversoes;
}


long long contarInversoesComMergeSort(int sequencia[], int tamanho) {
    int* vetorTemporario = (int*) malloc(sizeof(int) * tamanho);
    long long numeroDeInversoes = mergeSortRecursivo(sequencia, vetorTemporario, 0, tamanho - 1);
    free(vetorTemporario);
    return numeroDeInversoes;
}


int main (void)
{

    // int numeroDeGenes = 5;
    // int individuo2[] = { 0, 1, 2, 3, 4};
    // int individuo1[] = { 4 ,3 ,2, 1, 0};
    
    int numeroDeGenes;
    scanf("%d", &numeroDeGenes);

    int individuo1[numeroDeGenes];
    int individuo2[numeroDeGenes];
    int i;
    for (i = 0; i < numeroDeGenes; i++) scanf("%d", &individuo1[i]);
    for (i = 0; i < numeroDeGenes; i++) scanf("%d", &individuo2[i]);

    //todo OBJETIVO: todo o menor numero de inversoes de genes necessário.
    //todo para transformar o genoma do indivıduo 2 no genoma do individuo 1.


    // Mapeia a posição de cada gene no genoma do primeiro indivíduo
    int posicaoDoGeneNoIndividuo1[numeroDeGenes];
    for (int i = 0; i < numeroDeGenes; i++) {
        int gene = individuo1[i];
        posicaoDoGeneNoIndividuo1[gene] = i;
    }

    // Cria um vetor com as posições dos genes do indivíduo 2 de acordo com o indivíduo 1
    int ordemTransformada[numeroDeGenes];
    for (int i = 0; i < numeroDeGenes; i++) {
        int gene = individuo2[i];
        ordemTransformada[i] = posicaoDoGeneNoIndividuo1[gene];
    }

    // int out = numeroDeTrocas(individuo1, individuo2, numeroDeGenes);
    long long out = contarInversoesComMergeSort(ordemTransformada, numeroDeGenes);

    // printf("%d\n", out);
    printf("%lld\n", out);

    return 0;
}

// gcc -Wall -pedantic -O2 -Wno-unused-result -o distanciaGenomica distanciaGenomica.c; .\distanciaGenomica
