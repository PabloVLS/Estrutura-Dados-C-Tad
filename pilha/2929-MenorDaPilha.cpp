#include <stdio.h>
#include <string.h>

struct Node {
    int value;
    int minValue; // Armazena o menor valor até este nó
    Node* next;

    Node(int _value, int _minValue) {
        value = _value;
        minValue = _minValue;
        next = NULL;
    }
};

struct Stack {
    Node* t;

    Stack() {
        t = NULL;
    }

    bool empty() { // O(1)
        return t == NULL;
    }

    void push(int value) { // O(1)
        int minValue;
        if (empty()) {
            minValue = value;
        } else {
            if (value < t->minValue) {
                minValue = value;
            } else {
                minValue = t->minValue;
            }
        }
        Node* n = new Node(value, minValue);
        n->next = t;// t era o topo atual , mas como entrou outro t passa a ser o segundo do topo
        t = n; // e o topo agora e n
    }

    void pop() { // O(1)
        if (empty()) {
            return;
        }
        Node* toDel = t;
        t = t->next;
        delete toDel;
    }

    int top() { // O(1)
        if (empty()) {
            return -1;
        }
        return t->value;
    }

    int min() { // O(1)
        if (empty()) {
            return -1;
        }
        return t->minValue;
    }
};

int main() {
    Stack s;
    int qtd, valor;
    char frase[5];

    scanf("%d", &qtd);
    getchar();

    for (int i = 0; i < qtd; i++) {
        scanf("%s", frase);

        if (strcmp(frase, "PUSH") == 0) {
            scanf("%d", &valor);
            s.push(valor);
        } else if (strcmp(frase, "MIN") == 0) {
            if(s.empty()){
                printf("EMPTY\n");
            }else{
                printf("%d\n", s.min());
            }
        } else if (strcmp(frase, "POP") == 0) {
            if(s.empty()){
                printf("EMPTY\n");
            }else{
                s.pop();
            }
            
        }
    }

    return 0;
}
