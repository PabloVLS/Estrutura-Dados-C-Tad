#include<stdio.h>

struct Node {

    char value;
    Node* next;

    Node() {
        value = '\0';
        next = NULL;
    }

    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct Stack{

    Node* t;
    int cont;
    Stack() {
        t = NULL;
        cont=0;
    }

    bool empty() { // O(1)
        return t == NULL;
    }

    void push(char value) { // O(1)
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
            cont++;
            return;
        }
        cont++;
        Node* toDel = t;
        t = t->next;
        delete(toDel);
    }

    /*int top() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return t->value;
    }*/

};


int main(){
    Stack s;

    int qtd;
    char frase[1010];
    while(scanf(" %[^\n]", frase) != EOF){
        int p=0;
        for (int j = 0; frase[j] != '\0' && frase[j] != '\n'; j++) {
            if(frase[j] == '(') {
                s.push(frase[j]);
            }else if (frase[j] == ')') {
                if(s.empty()){
                    p=1;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty() || p==1){
            printf("incorrect\n");
        }else if(s.empty()){
            printf("correct\n");
        }

        while (!s.empty()) {
                s.pop();
        }
    }
}




