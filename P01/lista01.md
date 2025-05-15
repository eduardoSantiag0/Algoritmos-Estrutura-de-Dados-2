### 1 - [8.1.1] - Escreva uma função que decida se um vetor v[0..n-1] está em ordem  crescente. Depois, critique o código a seguir. 
 

    int verifica (int v[], int n) { 
        int i, anterior = v[0], sim = 1; 
        for (i = 1; i < n && sim; i++) { 
            if (anterior > v[i]) sim = 0; 
            anterior = v[i]; } 
        return sim;  
    }


**RESPOSTA:** 
    
    int ehCrescente(int v[], int n) 
    {
        int i;

        for (i = 1; i< n; i++) {
            if (v[i-1] > v[i]) return 0;
        }
        return 1;

    }
 
### 2 - [8.2.8, 8.3.3] - Modifique as seguintes funções de ordenação para que elas  permutem os elementos de um vetor v[0..n-1] de modo que eles fiquem em ordem  decrescente. 
 
a) insertionSort 

    void insertionsort (int n, int v[])
    {
    for (int j = 1; j < n; ++j) {
        int x = v[j];
        int i;
        for (i = j-1; i >= 0 && v[i] < x; --i)  // && v[i] < x
            v[i+1] = v[i];
        v[i+1] = x;
    }
    }

b) selectionSort 

    void selectionsort (int n, int v[])
    {
    for (int i = 0; i < n-1; ++i) {
        int max = i;
        for (int j = i+1; j < n; ++j)
            if (v[j] > v[max])  max = j; // v[j] > v[max]
        int x = v[i]; v[i] = v[max]; v[max] = x;
    }
    }

c) bubbleSort 

    void bubbleSort(int *vetor, int tamanho) {
        int atual=0;
        int proximo=0;;
        int auxiliar=0;

        for (atual=1; atual < tamanho; atual++) {

            for (proximo=0; proximo < tamanho-1; proximo++) {

                if (vetor[proximo] < vetor[proximo+1]) { // Faz a troca caso não seja o que eu quero
                    auxiliar = vetor[proximo];
                    vetor[proximo] = vetor[proximo+1];
                    vetor[proximo+1] = auxiliar;
                }
            }
        }
    }
 
### 3 - [10.5.1] - [Ordem Decrescente] Escreva uma versão do algoritmo heapSort que rearranja um vetor v[0 .. n - 1] de modo que ele fique em ordem decrescente. 

    void constroiHeap (int m, int v[])
    {
    for (int k = 1; k < m; ++k) {                   
        // v[1..k] é um heap
        int f = k+1;
        while (f > 1 && v[f/2] < v[f]) {  // 5
            troca (v[f/2], v[f]);          // 6
            f /= 2;                        // 7
        }
    }
    }

    static void peneira (int m, int v[]) 
    {
        int f = 2;
        while (f <= m) {
            if (f < m && v[f] < v[f+1]) ++f;
            // f é o filho mais valioso de f/2
            if (v[f/2] >= v[f]) break;
            troca (v[f/2], v[f]);
            f *= 2;
        }
    }

    void heapsort (int n, int v[]) 
    {
        constroiHeap (n, v);
        for (int m = n; m >= 2; --m) {
            troca (v[1], v[m]);
            peneira (m-1, v);
        }
    }

 
### 4 - [10.5.2] - [Ordenação de Strings] Escreva uma versão do algoritmo heapSort que coloque um vetor de strings em ordem lexicográfica (“ordem alfabética”). 
Veja https://www.ime.usp.br/~pf/algoritmos/aulas/string.html. 

 
### 5 - [10.1.1] - Mostre que todo vetor decrescente é um max-heap. Mostre que a  recíproca não é verdadeira. 

Resposta: Uma das propriedades do heap é que os pais são sempre maiores que os filhos. O mesmo é verdade para um vetor. No entanto, o heap não garante que o filho direito seja maior que o esquerdo, não garantindo assim que um max-heap é um vetor decrescente
 
### 6 - [10.1.3] - Escreva uma função que decida se um vetor v[0 .. m - 1] é ou não um  max-heap.
Resposta: FEITO EM AULA
