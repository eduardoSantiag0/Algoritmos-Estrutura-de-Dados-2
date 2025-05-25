#include <stdio.h>
#include <stdlib.h>

//todo Usar posicaoUltimoVoto como desempate

typedef struct aux 
{
    int valor;
    int numeroDeVotos;
    int posicaoUltimoVoto;
} Candidato;


void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void imprimeCandidatos(Candidato v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Candidato %d: %d votos\n", v[i].valor, v[i].numeroDeVotos);
    printf("\n");
}

void countingSortDesempate(Candidato candidatos[], int quantidadeCandidatos) {
    if (quantidadeCandidatos <= 0) return;

    // 1. Achar maior posicaoUltimoVoto para definir tamanho do vetor de contagem
    int maxPos = 0;
    for (int i = 0; i < quantidadeCandidatos; i++) {
        if (candidatos[i].posicaoUltimoVoto > maxPos)
            maxPos = candidatos[i].posicaoUltimoVoto;
    }
    int i;
    for (i = 0; i < quantidadeCandidatos; i++) {
        if (candidatos[i].posicaoUltimoVoto > maxPos)
            maxPos = candidatos[i].posicaoUltimoVoto;
    }

    // 2. Conta quantos candidatos tem cada posicaoUltimoVoto
    int* contagem = (int*)calloc(maxPos + 1, sizeof(int));
    for (i = 0; i < quantidadeCandidatos; i++)
        contagem[candidatos[i].posicaoUltimoVoto]++;

    // 3. Soma acumulada reversa para ordenar decrescente
    for (i = maxPos - 1; i >= 0; i--)
        contagem[i] += contagem[i + 1];
    

    // 4. Aloca vetor auxiliar para ordenação estável
    Candidato* ordenados = (Candidato*)malloc(quantidadeCandidatos * sizeof(Candidato));
    // 5. Preenche vetor ordenado, do fim para o começo para manter estabilidade
    for (i = quantidadeCandidatos - 1; i >= 0; i--) {
        int votos = candidatos[i].posicaoUltimoVoto;
        int posicao = --contagem[votos];
        ordenados[posicao] = candidatos[i];
    }

    // 6. Copia resultado para vetor original
    for (i = 0; i < quantidadeCandidatos; i++)
        candidatos[i] = ordenados[i];


    free(contagem);
    free(ordenados);

}

void countSortCandidatos(Candidato candidatos[], int quantidadeCandidatos) {
    if (quantidadeCandidatos <= 0)
        return;

    int i;
    int maxVotos = 0;

    for (i = 0; i < quantidadeCandidatos; i++) {
        if (candidatos[i].numeroDeVotos > maxVotos)
            maxVotos = candidatos[i].numeroDeVotos;
    }

    int* contagem = (int*)calloc(maxVotos + 1, sizeof(int));
    for (i = 0; i < quantidadeCandidatos; i++)
        contagem[candidatos[i].numeroDeVotos]++;

    for (i = maxVotos - 1; i >= 0; i--)
        contagem[i] += contagem[i + 1];

    Candidato* ordenados = (Candidato*)malloc(quantidadeCandidatos * sizeof(Candidato));
    for (i = quantidadeCandidatos - 1; i >= 0; i--) {
        int votos = candidatos[i].numeroDeVotos;
        int posicao = --contagem[votos];
        ordenados[posicao] = candidatos[i];
    }

    for (i = 0; i < quantidadeCandidatos; i++)
        candidatos[i] = ordenados[i];


    // Desempate (insertion sort estável para quem tem mesmos votos)
    // for (i = 1; i < quantidadeCandidatos; i++) {
    //     Candidato atual = candidatos[i];
    //     int j = i - 1;
    //     while (j >= 0 &&
    //            candidatos[j].numeroDeVotos == atual.numeroDeVotos &&
    //            candidatos[j].posicaoUltimoVoto > atual.posicaoUltimoVoto) {
    //         candidatos[j + 1] = candidatos[j];
    //         j--;
    //     }
    //     candidatos[j + 1] = atual;
    // }
    
    
    free(contagem);
    free(ordenados);
}



void contarVotos (int votacao[], int totalVotos, int cadeirasDisputadas)
{

    int vistos[totalVotos];
    int i, j;
    int indexVistos = 0;


    //* Loop pelos valores unicos
    for (i = 0; i < totalVotos; i++ ) {
        int atual = votacao[i];
        int jaVisto = 0;
        
        for (j = 0; j < indexVistos; j++ ) {
            if (vistos[j] == atual) {
                jaVisto = 1;
                break;
            }
        }
        if (!jaVisto) {
            vistos[indexVistos] = atual;
            indexVistos++;
        }
    }    

    Candidato candidatos[indexVistos];
    // imprime(vistos, indexVistos);

    //* Cria os candidatos
    for (i = 0; i < indexVistos; i++ ) {
        candidatos[i].valor = vistos[i];
        candidatos[i].numeroDeVotos = 0;
        candidatos[i].posicaoUltimoVoto = 0;
    }

    //* Atualiza os valores dos candidatos
    for (i = 0; i < totalVotos; i++ ) {
        for (j = 0; j < indexVistos; j++ ) {
            if (votacao[i] == candidatos[j].valor) {
                candidatos[j].numeroDeVotos++;
                candidatos[j].posicaoUltimoVoto = i;
                break;
            }
        }
    }


    //* Ordena os candidatos 
    countingSortDesempate(candidatos, indexVistos);

    countSortCandidatos(candidatos, indexVistos);


    // imprimeCandidatos(candidatos, indexVistos);

    // //* Imprime os cadeirasDisputados primeiros
    for (i = 0; i < cadeirasDisputadas; i++) {
        printf("%d: %d\n", candidatos[i].valor, candidatos[i].numeroDeVotos);
    }


}



int main (void)
{

    // int totalVotos = 6;
    // int cadeirasDisputadas = 2;
    // int votacao[] = { 1, 3, 5, 7, 3, 1};
    
    int totalVotos, cadeirasDisputadas;
    scanf("%d %d", &totalVotos, &cadeirasDisputadas);
    int votacao[totalVotos];

    int i;
    for (i = 0; i < totalVotos; i++) 
        scanf("%d", &votacao[i]);

    
    contarVotos(votacao, totalVotos, cadeirasDisputadas);


    return 0;
}

// gcc -Wall -pedantic -O2 -Wno-unused-result -o eleicaoLegislativa eleicaoLegislativa.c;  .\eleicaoLegislativa
