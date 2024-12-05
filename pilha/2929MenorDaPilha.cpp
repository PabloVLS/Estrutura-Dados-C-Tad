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
    Node* first;
    int menorzinho=1000000000;

    Stack() {
        first = NULL;
        t = NULL;
    }

    bool empty() { // O(1)
        return t == NULL;
    }

    void push(int value) { // O(1)

        Node* n = new Node(value);
        if (empty()) {
            first = n;
            t = n;
            return;
        }
        while(n!=NULL){
            if(n->value > ){
                menorzinho=n->value;
            }
            n = n->next;
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
            return -1;
        }
        return t->value;
    }
    /*// pesquisar oque e min
    void menor(){

        printf("ENTROU\N");
        Node* n = first;

        printf("%d\n",menorzinho);
    }*/

};

int main(){

    Stack s;
    int qtd,valor;
    char frase[10];
    for(int i=0; i < qtd;i++){
        scanf("%[^\n]%*c",frase);
        if(frase=="PUSH"){
            scanf("%d",&valor);
            s.push(valor);
        }else if(frase=="MIN"){
            s.menor();
        }else if(frase=="POP"){
            s.pop();
        }
    }



}
