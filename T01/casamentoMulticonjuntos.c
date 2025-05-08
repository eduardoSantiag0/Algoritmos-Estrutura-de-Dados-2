#include <stdio.h>

// gcc -Wall -pedantic -O2 -Wno-unused-result -o casamentoMulticonjuntos casamentoMulticonjuntos.c

// ./instancias_Casamento_entre_Multiconjuntos < teste01.in > saida.txt
// diff saida.txt teste01.sol

int calcularNumeroDePares(int* vetorX[],int* vetorY[], int tamX, int tamY, int somaDasMedianas) {

    int contador = 0;

    // Pegar do meio para trás de um conjunto e olhar o do meio para frente no outro

    int i, j;
    for (i=0; i < tamX ;i++) {
        for (j=0; j < tamY; j++) {
            if (*vetorX[i] + *vetorY[j] == somaDasMedianas) {
                contador++;
            }
        }
    }

    // Cuidado para não repetir o elemento 

    return contador;

}

void insertionSort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

int encontrarMediana(int vetor[], int tam) {

    insertionSort(vetor, tam);
    // selectionSort, insertionSort, quickSort, mergeSort

    // Se for par, deixar um elemento a menos
    if (tam % 2 == 0) return vetor[(tam/2)-1];
    // Se for impar, é o valor que define ao meio
    else return vetor[tam/2];

}

int main (void)
{

    // Primeira linha é a &numeroDeConjuntos1 &numeroDeConjuntos2    
    int tamanhoX = 3;
    int tamanhoY = 4;
    
    // Inserir primeiro conjunto
    int conjuntoX[] = { 1, 2, 3};
    // Inserir segundo conjunto
    int conjuntoY[] = { 1, 2, 3, 4};


    // Encontrar mediana entre dois angulos
    int medianaX = encontrarMediana(conjuntoX, tamanhoX);
    int medianaY = encontrarMediana(conjuntoY, tamanhoY);
    // Somar as duas medianas
    int somaDasMedianas = medianaX + medianaY;


    // Imprimir as medianas
    printf("Mediana do Conjunto X: %d\n", medianaX);
    printf("Mediana do Conjunto Y: %d\n", medianaY);
    

    // Calcular quantos pares em cada conjunto somam igual a mediana (mX + mY)

    int out = calcularNumeroDePares(conjuntoX, conjuntoY, tamanhoX, tamanhoY, somaDasMedianas);
    
    printf("%d", out);


    return 0;
}