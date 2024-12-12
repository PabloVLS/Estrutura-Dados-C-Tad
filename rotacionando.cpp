#include <stdio.h>

struct Node {
    int valor;
    Node *prox;
};

struct Queue {
    Node *cabeca, *cauda;
    int n;

    Queue() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserir(int v) { // O(1)
        Node *novo = new Node();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                Node *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete aux;
            } else {
                Node *aux = cabeca;
                cabeca = cabeca->prox;
                delete aux;
            }
            n--;
        }
    }

    int frente() {
        if (vazia()) {
            return -1;
        }
        return cabeca->valor;
    }

    void imprimir() {
        Node *aux = cabeca;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

    void inserirFinal(int v) {
        Node *novo = new Node();
        novo->valor = v;
        novo->prox = NULL;
        if (!vazia()) {
            cauda->prox = novo;
            cauda = novo;
        } else {
            cabeca = novo;
            cauda = novo;
        }
        n++;
    }
};

int main() {

    Queue baralhoA;
    Queue baralhoB;

    int qtdCartas, carta, i, qtdOperacoes = 0;

    scanf("%d", &qtdCartas);

    for (i = 0; i < qtdCartas; i++) {
        scanf("%d", &carta);
        baralhoA.inserir(carta);
    }

    for (i = 0; i < qtdCartas; i++) {
        scanf("%d", &carta);
        baralhoB.inserir(carta);
    }

    while (!baralhoA.vazia() && !baralhoB.vazia()) {
        if (baralhoA.frente() == baralhoB.frente()) {
            baralhoA.remover();
            baralhoB.remover();
            qtdOperacoes++;
        } else {
            int cartaA = baralhoA.frente();
            baralhoA.remover();
            baralhoA.inserirFinal(cartaA);
            qtdOperacoes++;
        }
    }

    printf("%d\n", qtdOperacoes);

    return 0;
}
