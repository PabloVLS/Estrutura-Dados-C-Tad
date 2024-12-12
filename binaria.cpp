#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
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
        Node* n = new Node(value);
        if (empty()) {
            t = n;
            return;
        }
        n->next = t;
        t = n;
    }

    void pop() { // O(1)
        if (empty()) {
            return;
        }
        if (t->next == NULL) {
            delete(t);
            t = NULL;
            return;
        }
        Node* toDel = t;
        t = t->next;
        delete(toDel);
    }

    int top() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return t->value;
    }

};

int main(){

    Stack s;
    int qtd, valor,aux=0;

    scanf("%d",&qtd);
    for(int i=0; i < qtd; i++){
        scanf("%d",&valor);
        while(valor > 0){
            aux = valor %2;
            valor = valor / 2;
            s.push(aux);
        }
        while(!s.empty()){
            printf("%d",s.top());
            s.pop();
        }
        printf("\n");
    }

    return 0;
}
