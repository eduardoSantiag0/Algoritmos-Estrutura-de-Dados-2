
Seguem alguns exercícios relacionados com ordenação. 
 
### 1 - A seguinte solução do problema da intercalação está correta?  Quais os 
invariantes do while?  (Observe que a função faz a intercalação in loco, ou seja, sem 
usar vetor auxiliar.) Qual o consumo de tempo? 
 
    int i, k, x; 
    i = p;  
    while (i < q && q < r) { 
        if (v[i] >= v[q]) { 
            x = v[q]; 
            for (k = q - 1; k >= i; --k)  
                v[k+1] = v[k]; 
            v[i] = x; 
            ++q; } 
        ++i; } 

**RESPOSTA:** 

O código está correto: O código está correto sim, ele divide o vetor ao meio e adiciona movendo os elementos à direita. Ele só funciona se as duas metades estiverem ordenadas

Invariantes do while: 
- i seja menor do que q
- q seja menor do que r
- após cada iteração,todas as posições em v[i] sejam menores do que as posições em v[q]
- v[i..q-1] e v[q..r-1] estejam ordenadas

Qual o consumo de tempo: O(n^2)

### 2 - Considere a seguinte implementação do mergeSort. 
 
    void mergeSort (int p, int r, int v[]) { 
        if (p < r-1) {    // 1 
            int q = (p + r)/2;  // 2 
            mergeSort (p, q, v);  // 3 
            mergeSort (q, r, v);  // 4 
            intercala (p, q, r, v);  // 5 
        } 
    } 
 
a) O que acontece se trocarmos (p < r-1) por (p < r) na linha // 1? A função termina? 
Por que? 

R: A função iria terminar, porém faria uma chama a mais para o vetor com apenas um elemento. O r-1 garante que tenham pelo menos, dois elementos dentro do vetor.
 
b) O que acontece se trocarmos (p + r)/2 por (p + r - 1)/2 na linha // 2? Os 
subproblemas sempre diminuem? Por que?

R: A arvore de recursão seria mais alta, ou seja, haveriam mais chamadas, porque não pegaria exatamente a metade do vetor, então seria necessário mais divisões até chegar no intercala.
 
c) O que acontece se trocarmos (p + r)/2 por (p + r + 1)/2 na linha // 2? Os 
subproblemas sempre diminuem? Por que?

R: O mesmo aconteceria, haveriam mais chamadas e os subproblemas iriam aumentar

### 3 - Escreva uma versão recursiva do algoritmo mergeSort que rearranje um vetor v[p..r-1] em ordem decrescente. Será preciso reescrever o algoritmo da intercalação. 

    int i, k, x; 
    i = p;  
    while (i < q && q < r) { 
        if (v[i] <= v[q]) { 
            x = v[q]; 
            for (k = q - 1; k >= i; --k)  
                v[k+1] = v[k]; 
            v[i] = x; 
            ++q; } 
        ++i; }
 
### 4* - Digamos que um vetor v[p..r] está separado se existe j em p..r tal que v[p..j-1] 
<= v[j] < v[j+1..r]. Escreva um algoritmo que decida se v[p..r] está separado. Em 
caso afirmativo, o seu algoritmo deve devolver o valor de j. 
 
### 5 - Critique a seguinte variante da função separa. Quais os invariantes? 
 
    int separa (int v[], int p, int r) { 
        int c = v[p]; // Pivot 
        int i = p+1; 
        int j = r; 
        int t; 
        
        while (i <= j) { 
            if (v[i] <= c) // Tudo certo, continue
                ++i; // Mova o i para a direita
            
            else { 
                t = v[i], v[i] = v[j], v[j] = t; // Troca
                --j;  // Mova o j para a esquerda
            } 
        }

        // j é a posição final do pivot

        v[p] = v[j]; // Coloca o elemento do meio na posição inicial
        v[j] = c; // Coloca o valor do pivô na posição correta
        
        return j; // Retorna onde foi dividido o vetor
    } 
 

Resposta: O indice i não se movimenta corretamente pois está dentro de um if

- Invariantes: 
- v[p...j-1] <= c 
- c < v[j+1...r]

### 6 - Considere a seguinte implementação do quickSort. 
 
void quicksort (int v[], int p, int r) { 
    int j;                            // 1 
    if (p < r) {                    // 2 
        j = separa (v, p, r);     // 3 
        quicksort (v, p, j-1);    // 4 
        quicksort (v, j+1, r);    // 5 
    } } 
 
a) Que acontece se trocarmos p < r por p != r na linha 2? A função termina? Por 
que? 

Resposta: A condição p < r garante que ainda há mais de um elemento para ordenar, enquanto p != r pode permitir chamadas com subvetores inválidos.
 
b) Que acontece se trocarmos j-1 por j na linha 4? Os subproblemas sempre 
diminuem? Por que? 

Resposta: Ele irá incluir um elemento já ordenado na próxima chamada. Os subproblemas não irão diminuir, só ficarão maiores do que deveria. Além disso, podem causar looping infinito, devido à incluir um item já ordenado


c) Que acontece se trocarmos j+1 por j na linha 5? Os subproblemas sempre 
diminuem? Por que?

Resposta: O mesmo acontece da resposta acima