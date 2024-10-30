#include <stdio.h>
#include <string.h>

struct Node {
    char estacao1[25];
    Node* next;

    Node() { // O(1)
        strcpy(estacao1, "");
        next = NULL;
    }

    Node(char _estacao1[]) { // O(1)
        strcpy(estacao1, _estacao1);
        next = NULL;
    }
};

struct List {
    Node* first;
    Node* last;
    int c;
    int cont;
    int cont1;

    List() { // O(1)
        first = NULL;
        last = NULL;
        c = 0;
        cont = 0;
        cont1 = 0;
    }

    bool empty() { // O(1)
        return first == NULL;
    }

    void pushBack(char estacao1[]) { // O(1)
        Node *n = new Node(estacao1);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void rotacionar(char estacao1[]) {
        Node *aux = first;
        while (aux != NULL) {
            if (strcmp(aux->estacao1, estacao1) == 0) {
                return;
            }
            cont++;
            aux = aux->next;
        }
    }

    void rotacionar2(char estacao2[]) {
        Node *aux = first;
        while (aux != NULL) {
            if (strcmp(aux->estacao1, estacao2) == 0) {
                return;
            }
            cont1++;
            aux = aux->next;
        }
    }

    void verificar() {
        if (cont > cont1) {
            printf("ESQUERDA %d\n", cont - cont1);
        } else {
            printf("DIREITA %d\n", cont1 - cont);
        }
    }

    void print() { // O(n)
        Node* aux = first;
        while (aux != NULL) {
            printf("%s -> ", aux->estacao1);
            aux = aux->next;
        }
        printf("NULL\n");
    }

    int size() { // O(1)
        return c;
    }
};

int main() {
    List l;
    char estacao1[25];
    char estacao2[25];

    l.pushBack("PALMEIRAS BARRA FUNDA");
    l.pushBack("MARECHAL DEODORO");
    l.pushBack("SANTA CECILIA");
    l.pushBack("REPUBLICA");
    l.pushBack("ANHANGABAU");
    l.pushBack("SE");
    l.pushBack("PEDRO II");
    l.pushBack("BRAS");
    l.pushBack("BRESSER MOOCA");
    l.pushBack("BELEM");
    l.pushBack("TATUAPE");
    l.pushBack("CARRAO");
    l.pushBack("PENHA");
    l.pushBack("VILA MATILDE");
    l.pushBack("GUILHERMINA ESPERANCA");
    l.pushBack("PATRIARCA");
    l.pushBack("ARTUR ALVIM");
    l.pushBack("CORINTHIANS ITAQUERA");

    scanf(" %[^\n]", estacao1);
    scanf(" %[^\n]", estacao2);

    l.rotacionar(estacao1);
    l.rotacionar2(estacao2);
    l.verificar();

    
    return 0;
}
