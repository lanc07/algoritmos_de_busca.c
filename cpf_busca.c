#include <stdio.h>
#include <string.h>
 
int busca_linear_cpf(const char* cpfs[], int n, const char* alvo){
    for (int i = 0; i < n; i++){
        if (strcmp(cpfs[i], alvo) == 0)
        return i;
    }
    return -1;
}
 
int busca_binaria_cpf(const char* cpfs[], int n, const char* alvo){
    int ini = 0, fim = n -1;
    while (ini <= fim){
        int meio = ini + (fim - ini) / 2;
        int cmp = strcmp(cpfs[meio], alvo);
        if (cmp == 0) return meio;
        if (cmp < 0) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main(){
    const char* cpfs_ordenados[] = {
         "12345678909", "14785236900", "14785236900", "30817462003", "62543891020", "9765432100"
    };

    const char* cpfs_nao_ordenados[] = {
        "12345678909", "98765432100", "11122233344", "55566677788", "00011122233", "62543291020", "14785236900"

    };

    int n = 7;
    char alvo[20];
    printf("Digite o CPF para busca (somente números): ");
    scanf("%19s", alvo);

    int idx_linear = busca_linear_cpf(cpfs_nao_ordenados, n, alvo);
    if (idx_linear == -1){
        printf("[Linear] CPF %s nao encontrado (vetor NAO ordenado).\n", alvo);
    } else {
         printf("[Linear] CPF %s encontrado no indice %d (vetor NAO ordenado).\n", alvo, idx_linear);
    }

    int idx_bin = busca_binaria_cpf(cpfs_ordenados, n, alvo);
    if (idx_bin == -1) {
        printf("[Binaria] CPF %s nao encontrado (vetor ORDENADO).\n", alvo);
    } else {
        printf("[Binaria] CPF %s encontrado no indice %d (vetor ORDENADO).\n", alvo, idx_bin);
    }

    return 0;
}