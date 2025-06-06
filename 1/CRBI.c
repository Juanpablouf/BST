#include <stdio.h>
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
