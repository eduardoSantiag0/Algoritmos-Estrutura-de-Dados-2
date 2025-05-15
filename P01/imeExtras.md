### HeapSort: 
#### Por que a seguinte implementação de peneira não funciona?

    int p = 1, f = 2;
    while (f <= m) {
       if (v[p] < v[f]) {
          troca (v[p], v[f]);
          p = f;
          f = 2*p; }
       else {
          if (f < m && v[p] < v[f+1]) {
             troca (v[p], v[f+1]);
             p = f+1;
             f = 2*p; }
          else break; } }

- Resposta: O código não coloca o valor original na posição correta

#### O seguinte código alternativo da função peneira está correto?

    for (int f = 2; f <= m; f *= 2) {
        if (f < m && v[f] < v[f+1]) 
            ++f;
        
        int p = f/2;
        
        if (v[p] >= v[f]) 
            break;
        troca (v[p], v[f]); 
    }

- Resposta: O problema do código é que, ao incrementar f dentro do if (++f), ele pode ultrapassar o tamanho do vetor e acessar uma posição inválida, como v[f+1]. 

#### Discuta a seguinte variante do código de peneira:

    int x = v[1], f = 2;
    while (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (x >= v[f]) break;
        v[f/2] = v[f]; // O filho se torna pai
        f *= 2; } // Filho desce
    v[f/2] = x;

- Resposta: Ele está correto, ele não faz uso de uma variavel auxiliar com nome de pai mas usa a posição do vetor e a propriedade de altura da arvore binaria para localiza-lo