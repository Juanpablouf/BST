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

void somarNotas(Aluno* raiz, float* soma, int* cont) {
    if (raiz != NULL) {
        *soma += raiz->nota;
        (*cont)++;
        somarNotas(raiz->esquerdo, soma, cont);
        somarNotas(raiz->direito, soma, cont);
    }
}

float calcularMedia(Aluno* raiz) {
    float soma = 0;
    int cont = 0;
    somarNotas(raiz, &soma, &cont);
    return (cont == 0) ? 0 : soma / cont;
}

int main() {
    Aluno* raiz = NULL;

    raiz = inserirAluno(raiz, "Carlos", 1001, 8.0);
    raiz = inserirAluno(raiz, "Ana", 1002, 9.5);
    raiz = inserirAluno(raiz, "Bruno", 1003, 7.5);
    raiz = inserirAluno(raiz, "Daniela", 1004, 10.0);

    float media = calcularMedia(raiz);
    printf("Média das notas dos alunos: %.2f\n", media);

    return 0;
}
