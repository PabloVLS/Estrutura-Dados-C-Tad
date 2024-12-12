#include<string.h>
#include<stdio.h>
#include <ctype.h>

struct Node {

    char value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct Stack{

    Node* t;

    Stack() {
        t = NULL;
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
            return;
        }
        Node* toDel = t;
        t = t->next;
        delete(toDel);
    }

    void top() { // O(1)
        if (empty()) {
            printf("Empty\n");
        }
        printf("%c",t->value);
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

    void enqueue(char value) {
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
            first = NULL;
            last = NULL;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
    }

    void front() {
        if (empty()) {
            printf("Empty queue\n");
        }
        printf("%c",first->value);
    }

};

int main(){
    Stack s;
    Queue q;
    char letra;
    char palavra[100];
    while(scanf("%[^\n]%*c",palavra) != EOF){
        for(int i=0; i < strlen(palavra);i++){
            letra = toupper(palavra[i]);
            if(letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U'){
                s.push(letra);
            }else{
                q.enqueue(letra);
            }
        }
        for(int j=0; j < strlen(palavra); j++){
                 letra = toupper(palavra[j]);
                 if(letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U'){
                    s.top();
                    s.pop();
                }else{
                    q.front();
                    q.dequeue();
                }
        }
        printf("\n");


    }


    return 0;
}
