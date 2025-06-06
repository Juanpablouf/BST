#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

Aluno* criarAluno(char nome[], int matricula, float nota) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

Aluno* inserirAluno(Aluno* raiz, char nome[], int matricula, float nota) {
    if (raiz == NULL)
        return criarAluno(nome, matricula, nota);

    if (strcmp(nome, raiz->nome) < 0)
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    else if (strcmp(nome, raiz->nome) > 0)
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    
    return raiz;
}

Aluno* buscarAluno(Aluno* raiz, char nome[]) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0)
        return raiz;

    if (strcmp(nome, raiz->nome) < 0)
        return buscarAluno(raiz->esquerdo, nome);
    else
        return buscarAluno(raiz->direito, nome);
}

int main() {
    Aluno* raiz = NULL;
  
    raiz = inserirAluno(raiz, "Carlos", 1001, 8.0);
    raiz = inserirAluno(raiz, "Ana", 1002, 9.5);
    raiz = inserirAluno(raiz, "Bruno", 1003, 7.5);

    char nomeBusca[50];
    printf("Digite o nome do aluno que deseja buscar: ");
    scanf("%s", nomeBusca);

    Aluno* resultado = buscarAluno(raiz, nomeBusca);
    if (resultado != NULL) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", resultado->nome);
        printf("Matrícula: %d\n", resultado->matricula);
        printf("Nota: %.2f\n", resultado->nota);
    } else {
        printf("Aluno '%s' não encontrado na árvore.\n", nomeBusca);
    }

    return 0;
}
