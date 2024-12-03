#include <stdio.h>

struct Node {
    int value;
    Node* next;

    Node() {
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct Queue {
    Node* first;
    Node* last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void dequeue() {
        if (empty()) return;
        if (first == last) {
            delete(first);
            first = last = NULL;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
    }

    int front() {
        if (empty()) {
            return -1;
        }
        if(first->value != last->value){
            printf("%d ",first->value);
        }else{
            printf("%d\n",first->value);
        }
        
        return first->value;
    }

    void popBack() {
        if (empty()) return;
        if (first == last) {
            delete(last);
            first = last = NULL;
            return;
        }
        Node* aux = first;
        while (aux->next != last) {
            aux = aux->next;
        }
        delete(last);
        last = aux;
        last->next = NULL;
    }

    void removeByPos(int valor) {
        if (empty()) return;
        if (first->value == valor) {
            Node* toDel = first;
            first = first->next;
            delete(toDel);
            if (first == NULL) last = NULL;
            return;
        }

        Node* aux = first;
        while (aux->next && aux->next->value != valor) {
            aux = aux->next;
        }

        if (aux->next) {
            Node* toDel = aux->next;
            aux->next = toDel->next;
            if (toDel == last) last = aux;
            delete(toDel);
        }
    }
};

int main() {
    Queue q;
    int qtd, qtd1, valor;
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        scanf("%d", &valor);
        q.enqueue(valor);
    }

    scanf("%d", &qtd1);
    for (int i = 0; i < qtd1; i++) {
        scanf("%d", &valor);
        q.removeByPos(valor);
    }

    while (!q.empty()) {
        q.front();
        q.dequeue();
    }
    return 0;
}
