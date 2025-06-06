#include <stdio.h>Add commentMore actions
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int dado) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = dado;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, dado);
    } else if (dado > raiz->dado) {
        raiz->direito = inserir(raiz->direito, dado);
    }
    return raiz;
}

No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz;
    }
    if (dado < raiz->dado) {
        return buscar(raiz->esquerdo, dado);
    } else {
        return buscar(raiz->direito, dado);
    }
}

void remover(No* raiz) {
    if (raiz != NULL) {
        remover(raiz->esquerdo);
        remover(raiz->direito);
        free(raiz);
    }
}

void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        inOrdem(raiz->direito);
    }
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int altEsq = altura(raiz->esquerdo);
    int altDir = altura(raiz->direito);
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

int profundidade(No* raiz, int dado, int nivel) {
    if (raiz == NULL) {
        return -1; 
    }
    if (raiz->dado == dado) {
        return nivel;
    }
    if (dado < raiz->dado) {
        return profundidade(raiz->esquerdo, dado, nivel + 1);
    } else {
        return profundidade(raiz->direito, dado, nivel + 1);
    }
}

int main() {
    No* raiz = NULL;

    int elementos[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, elementos[i]);
    }

    int buscarValores[] = {40, 90};
    for (int i = 0; i < 2; i++) {
        No* resultado = buscar(raiz, buscarValores[i]);
        if (resultado != NULL) {
            printf("Encontrado: %d\n", resultado->dado);
        } else {
            printf("Valor %d nao encontrado.\n", buscarValores[i]);
        }
    }
    for (int i = 0; i < 2; i++) {
    int valor = buscarValores[i];
    int prof = profundidade(raiz, valor, 0);
    if (prof != -1) {
        printf("Profundidade de %d: %d\n", valor, prof);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor);
    }
}
    printf("Percurso in-ordem: ");
    inOrdem(raiz);
    printf("\n");

    printf("Percurso pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Percurso pos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", altura(raiz));
  
    remover(raiz);

    return 0;
}
