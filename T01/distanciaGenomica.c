#include <stdio.h>

// gcc -Wall -pedantic -O2 -Wno-unused-result -o distanciaGenomica distanciaGenomica.c; .\distanciaGenomica

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void trocarPosicao()
{

}

int numeroDeTrocas(int individuo1[], int individuo2[], int numeroDeGenes)
{

    int numeroDeTrocas = 0;
    int i, j;

    for (i=0;i<numeroDeGenes;i++) {
        int atual = individuo1[i];
        int posicaDoAtual = i;

        for (j=0;i<numeroDeGenes;j++) {
            
        }
    }

    return numeroDeTrocas;

}

int main (void)
{

    int numeroDeGenes = 5;

    int individuo1[] = { 0, 1, 2, 3, 4 };
    int individuo2[] = { 1, 4, 3, 2, 0 };

    //todo OBJETIVO: todo o menor numero de inversoes de genes necessário 
    //todo para transformar o genoma do indivıduo 2 no genoma do individuo 1.

    int out = numeroDeTrocas(individuo1, individuo2, numeroDeGenes);

    printf("%d\n", out);

    return 0;
}

// gcc -Wall -pedantic -O2 -Wno-unused-result -o distanciaGenomica distanciaGenomica.c; .\distanciaGenomica
