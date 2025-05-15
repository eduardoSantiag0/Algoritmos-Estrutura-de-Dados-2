#include <stdio.h>

// gcc -Wall -pedantic -O2 -Wno-unused-result -o casamentoMulticonjuntos casamentoMulticonjuntos.c

//todo ver para grandes instancias

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int calcularNumeroDePares(int vetorX[],int vetorY[], int tamX, int tamY, int somaDasMedianas) {

    int contador = 0;
    int i, j = 0;

    // int meioX = tamX / 2;
    // int meioY = tamY / 2;
    

    // int usadosX[tamX];
    // int usadosY[tamY];

    // for (i = 0; i < tamX; i++) usadosX[i] = 0;
    // for (i = 0; i < tamY; i++) usadosY[i] = 0;


    // for (i = 0; i < tamX; i++) {
    //     for (j = 0; j < tamX; j++) {
    //         if (!usadosX[i] && !usadosY[j] && vetorX[i] + vetorY[j] == somaDasMedianas) {
    //             contador++;
    //             usadosX[i] = 1;
    //             usadosY[j] = 1;
    //             break; 
    //         }
    //     }
    // }
    
    while (i < tamX && j >= 0)
    {
        int soma = vetorX[i] + vetorY[j];
        if (soma == somaDasMedianas) {
            i++;
            j--;
            contador++;
        } else if (soma < somaDasMedianas) {
            i++;
        } else {
            j--;
        }
    }
    

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

    int tamanhoX = 5;
    int conjuntoX[] = { 4, 5, 6, 7, 8};
    int tamanhoY = 4;
    int conjuntoY[] = { 3, 2, 1, 3};
    
    
    // int tamanhoX;
    // int tamanhoY;
    // scanf("%d %d", &tamanhoX, &tamanhoY);
    // int conjuntoX[tamanhoX];
    // int conjuntoY[tamanhoY];
    // for (int i = 0; i < tamanhoX; i++) {
    //     scanf("%d", &conjuntoX[i]);
    // }
    // for (int i = 0; i < tamanhoY; i++) {
    //     scanf("%d", &conjuntoY[i]);
    // }




    // Encontrar mediana entre dois angulos
    int medianaX = encontrarMediana(conjuntoX, tamanhoX);
    int medianaY = encontrarMediana(conjuntoY, tamanhoY);
    // Somar as duas medianas
    int somaDasMedianas = medianaX + medianaY;


    // Imprimir as medianas
    // printf("Mediana do Conjunto X: %d\n", medianaX);
    // printf("Mediana do Conjunto Y: %d\n", medianaY);
    

    // Calcular quantos pares em cada conjunto somam igual a mediana (mX + mY)
    // imprime(conjuntoX, tamanhoX);
    // imprime(conjuntoY, tamanhoY);

    int out = calcularNumeroDePares(conjuntoX, conjuntoY, tamanhoX, tamanhoY, somaDasMedianas);
    
    printf("%d\n", out);

    return 0;
}

// gcc -Wall -pedantic -O2 -Wno-unused-result -o casamentoMulticonjuntos casamentoMulticonjuntos.c; .\casamentoMulticonjuntos