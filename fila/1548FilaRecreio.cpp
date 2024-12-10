#include<stdio.h>

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
            first = NULL;
            last = NULL;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
    }

    int front() {
        if (empty()) {
            printf("Empty queue\n");
            return -1;
        }
        return first->value;
    }

    void print(){
        Node* current = first;
        while(current!= NULL){
            printf("%d ",current->value);
            current = current->next;
        }
    }

};


struct PriorityQueue {

    Node* first;

    PriorityQueue() {
        first = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        Node* n = new Node(value);

        if (empty() || n->value > first->value) {
            n->next = first;
            first = n;
            return;
        }

        Node* current = first;
        while (current->next != nullptr && current->next->value >= n->value) {
            current = current->next;
        }

        n->next = current->next;
        current->next = n;
    }

    void dequeue() {
        if (empty()) return;

        Node* toDel = first;
        first = first->next;
        delete toDel;
    }

    int front() {
        if (empty()) {
            printf("Empty queue\n");
            return -1;
        }
        return first->value;
    }

    void print(){
        Node* current = first;
        while(current!= NULL){
            printf("%d ",current->value);
            current = current->next;
        }
    }

};

int main() {

    PriorityQueue p;
    Queue q;
    int n,qtd,valor;
    scanf("%d",&n);
    for(int j=0; j<n;j++){
        scanf("%d",&qtd);
        int cont=0;
        for(int i=0; i <qtd;i++){
            scanf("%d",&valor);
            q.enqueue(valor);
            p.enqueue(valor);
        }
        for(int i=0; i <qtd;i++){
            if(p.front() == q.front()){
                cont++;
                p.dequeue();
                q.dequeue();
            }else{
                p.dequeue();
                q.dequeue();
            }
        }
        printf("%d\n",cont);
    }




    return 0;
}
