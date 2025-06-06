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

    remover(raiz);

    return 0;
}
