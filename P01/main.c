#include <stdio.h>
#include <stdlib.h>

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void troca(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
//* MERGESORT
void intercala(int p, int q, int r, int v[]) {
    int i = p;

    while (i < q && q < r) {
        if (v[i] < v[q]) {
            // Elemento da segunda metade é maior, precisa vir antes
            int temp = v[q];
            int k;

            // Move todos os elementos entre i e q-1 uma posição à direita
            for (k = q; k > i; --k)
                v[k] = v[k - 1];

            v[i] = temp;

            // Atualiza os índices
            ++q;
            ++i;
        } else {
            ++i;
        }
    }
}

void mergeSortDecrescente(int p, int r, int v[]) {
    if (p < r - 1) { // Garante que haja dois ou mais elementos
        int q = (p + r) / 2;
        mergeSortDecrescente(p, q, v);
        mergeSortDecrescente(q, r, v);
        intercala(p, q, r, v);
    }
}

int ehCrescente(int v[], int n) 
{
    int i;

    for (i = 1; i< n; i++) {
        if (v[i-1] > v[i]) return 0;
    }

    printf("Eh Crescente\n");
    return 1;

}


//* QUICKSORT
int separa (int v[], int p, int r) {
   int c = v[r]; // pivô
   int t; // temporario 
   int j = p; // guarda a posição do corte
   for (int k = p;  k < r; ++k) // k -> Percorre o array e o j guarda a posição do corte
      if (v[k] <= c) { // se o elemento atual for menor ou igual ao pivô
         t = v[j], v[j] = v[k], v[k] = t;
         ++j;  // Avança o corte
      } 
    
   // Coloca o pivô em sua posição correta no vetor (entre os menores e maiores)
    t = v[j];
    v[j] = v[r];
    v[r] = t;

    return j; // Final do pivo (onde houve o corte)
}

int separaMeu (int v[], int p, int r) {

    int pivo = v[r]; 
    int jWalk = p;
    int iPosicaoCorte = p;
    int temp;

    while (jWalk < r) // J não chegou no final do ponteiro
    {
        if (v[jWalk] < pivo ) {
            temp = v[iPosicaoCorte]; 
            v[iPosicaoCorte] = v[jWalk]; 
            v[jWalk] = temp;
            iPosicaoCorte++;
        }
        
        jWalk++;
    }

    //* Colocar pivo na posicao do corte
    temp = v[iPosicaoCorte];
    v[iPosicaoCorte] = v[r];
    v[r] = temp;

    return iPosicaoCorte;    

}

int separaErrado (int v[], int p, int r) {
   int i = p, j = r;
   int q = (p + r)/2;
   do {
      while (v[i] < v[q]) ++i;
      while (v[j] > v[q]) --j;
      if (i <= j) {
         int t = v[i]; v[i] = v[j]; v[j] = t;
         ++i, --j; }
   } while (i <= j);
   return i; 
}

void quickSort (int v[], int p, int r) { 
    int j;                            // 1 
    if (p < r) {                    // 2 
        j = separaMeu (v, p, r);     // 3 
        quickSort (v, p, j-1);    // 4 
        quickSort (v, j+1, r);    // 5 
    } 
}

//* HEAPSORT
// void constroiHeap (int m, int v[])
// {
// for (int k = 1; k < m; ++k) {                   
//     // v[1..k] é um heap
//     int f = k+1;
//     while (f > 1 && v[f/2] < v[f]) {  // 5
//         troca (v[f/2], v[f]);          // 6
//         f /= 2;                        // 7
//     }
// }
// }

// void peneira (int m, int v[]) 
// {
//     int f = 2;
//     while (f <= m) {
//         if (f < m && v[f] < v[f+1]) ++f;
//         // f é o filho mais valioso de f/2
//         if (v[f/2] >= v[f]) break;
//         troca (v[f/2], v[f]);
//         f *= 2;
//     }
// }

// void heapsort (int n, int v[]) 
// {
//     constroiHeap (n, v);
//     imprime(v, n);
//     for (int m = n; m >= 2; --m) {
//         troca (&v[1], &v[m]);
//         peneira (m-1, v);
//     }
// }


void countingSort( int v[], int n, int tamIntervalo) 
{
    //* 1) Inicia o ocorrePred com 0.
    //* 2) Marca o numero de ocorrencias de cada valor no ocorrePred. 
        // usa o valor do numero como posição do ocorrePred
    //* 3) Atualiza o ocorrePred baseado nos predecessores 
        // frequencia acumulada
    //* 4) Coloca os elementos em posições ordenadas no vetor aux
    //* 5) Copia do aux para o original


    // Vetor que guarda as frequencias de um elemento X
    // int* ocorre = malloc ( tamIntervalo * sizeof( int ));

    // Vetor que guarda as frequencias de [0..X-1]
    int* ocorrePred = malloc ( (tamIntervalo+1) * sizeof( int )); 

    // Vetor que armazena os elementos na ordem correta e mantem a estabilidade do algoritmo
    int* aux = malloc ( n * sizeof( int )); 
    
    int i, valor;

    //* Iniciando ocorrePred com com 0.
    for(valor = 0; valor <= tamIntervalo; valor++)
        ocorrePred[valor] = 0;
    
    //* Função: Marca o numero de ocorrencias
    //* usa o valor do numero como posição do ocorrePred
    for(i = 0; i < n; i++) {
        valor = v[i];
        ocorrePred[valor+1] += 1;
    }

    // Varre o vetor atualizando baseado nos predecessores
    for (valor = 1; valor <= tamIntervalo; valor++)
        ocorrePred[valor] += ocorrePred[valor - 1];

    
    for ( i = 0 ; i < n ; ++ i ) {
        valor = v[i];
        int numeroAntecessoresDeValorNoVetorOcorrePred = ocorrePred[valor]; // Simboliza o local em que ele deve ser colocado
        aux[numeroAntecessoresDeValorNoVetorOcorrePred] = v[i];
        ocorrePred[valor]++; // Atualiza caso haja mais de um elemento
    } 

    //* aux está em ordem crescente
    for (i = 0; i < n; ++i ) v[i] = aux[i]; 

    free(ocorrePred);
    free(aux);

}

void selectionSort(int v[], int n )
{
    int i,j;
    for (i = 0; i < n-1; i++) {
        int minPosicao = i; // Guarda a posição para trocar depois
        for (j = i+1; j <= n; j++) {
            if (v[j] < v[minPosicao]) 
                minPosicao = j;
        }

        printf("%d\n", v[minPosicao]);

        int x = v[i]; v[i] = v[minPosicao]; v[minPosicao] = x;

    }
}

int main (void)
{
    int v[] = {1, 5, 10, 3, 2, 8};

    // mergeSortDecrescente(0, 5, v);
    // quickSort(v, 0, 5);
    // countingSort(v, 6, 10);
    selectionSort(v, 6);
    imprime(v, 6);

    return 0;
}