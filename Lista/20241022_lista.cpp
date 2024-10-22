#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() { // O(1)
        value = 0;
        next = NULL;
    }

    Node(int _value) { // O(1)
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* first;
    Node* last;
    int c;

    List() { // O(1)
        first = NULL;
        last = NULL;
        c = 0;
    }


    bool empty() { // O(1)
        return first == NULL;
    }

    void pushFront(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void pushBack(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void print() { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
    }

    /*
    int size() { // O(n)
        int c = 0;
        Node* aux = first;
        while (aux != NULL) {
            c++;
            aux = aux->next;
        }
        return c;
    }
    */

    int size() { // O(1)
        return c;
    }

    void popFront() { // O(1)
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
        c--;
    }

    void popBack() { // O(n)
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = last;
        Node* aux = first;
        while (aux->next != last) {
            aux = aux->next;
        }
        last = aux;
        last->next = NULL;
        delete(toDel);
        c--;
    }

    void insert(int value, int pos) { //O(n)
        if (pos <= 0) {
            pushFront(value);
            return;
        }
        if (pos >= c) {
            pushBack(value);
            return;
        }
        Node* aux = first;
        for (int i = 0; i < pos; i++, aux = aux->next);
        Node* n = new Node(value);
        n->next = aux->next;
        aux->next = n;
        c++;
    }

    void remove(int value) { // O(n)
        if (empty()) return;

        Node *aux = first;
        Node *prev = NULL;
        for (int i = 0; i < c; i++) {
            if (aux->value == value) {
                if (prev == NULL) {
                    popFront();
                } else {
                    prev->next = aux->next;
                    delete(aux);
                    c--;
                    aux = prev;
                }
            }
            prev = aux;
            aux = aux->next;
        }
    }

    void removeByPos(int pos) { // O(n)
        if (pos <= 0) {
            popFront();
            return;
        }
        if (pos >= c) {
            popBack();
            return;
        }
        Node* aux = first;
        for (int i = 0; i < pos - 1; i++, aux = aux->next);
        Node* toDel = aux->next;
        aux->next = toDel->next;
        delete(toDel);
        c--;
    }

};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);

    l.popBack();

    l.print();

    return 0;
}
