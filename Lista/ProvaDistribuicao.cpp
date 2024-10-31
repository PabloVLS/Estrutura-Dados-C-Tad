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
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }




    int size() { // O(1)
        return c;
    }






};

int main() {

    List l;
    int qtd,k;
    scanf("%d",&qtd);
    k=qtd*2;
    int vetor[k];
    int vetor1[k];
    for(int i=0; i < qtd; i++){
        scanf("%d",&vetor[i]);
    }
    for(int j=0; j < qtd; j++){
        scanf("%d",&vetor1[j]);
    }
    for(int i=0; i < qtd; i++){

        l.pushBack(vetor[i]);
        l.pushBack(vetor1[i]);
    }
    l.print();
    return 0;
}
