
/*Para comandos 1 x, adiciona o valor x a todas as estruturas.
Para comandos 2 x, verifica se a estrutura pode retornar o valor esperado:
Pilha: O topo deve ser igual a x.
Fila: O início deve ser igual a x.
Fila de Prioridade: O maior elemento deve ser igual a x.*/
#include<stdio.h>

struct Node {

    int value;
    int priority;
    Node* next;

    Node() {
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        priority = 0;
        next = NULL;
    }

    Node(int _value, int _priority) {
        value = _value;
        priority = _priority;
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

};

struct PriorityQueue {

    Node* first;

    PriorityQueue() {
        first = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value, int priority) {
        Node* n = new Node(value, priority);

        // Inserir na posição correta baseada na prioridade (maior prioridade vem primeiro)
        if (empty() || n->priority > first->priority) {
            n->next = first;
            first = n;
            return;
        }

        // Percorrer para encontrar a posição correta
        Node* current = first;
        while (current->next != NULL && current->next->priority >= n->priority) {
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

    int frontPriority() {
        if (empty()) {
            printf("Empty queue\n");
            return -1;
        }
        return first->priority;
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

int main() {

    Queue q;
    Stack s;
    PriorityQueue p;

    int qtd,tipo,x;
    while(scanf("%d",&qtd) != EOF){
        bool queue1= true, stack1=true, priority1=true;
        for(int i=0; i < qtd;i++){
            scanf("%d %d",&tipo, &x);

            if(tipo==1){
                q.enqueue(x);
            }else if(tipo==2){
                if(x == q.front()){
                    q.dequeue();
                }else{
                    queue1 = false;
                }
            }

            if(tipo==1){
                p.enqueue(x,x);
            }else if(tipo==2){
                if(x == p.front()){
                    p.dequeue();
                }else{
                    priority1 = false;
                }
            }


            if(tipo==1){
               s.push(x);
            }else if(tipo==2){
                if(x==s.top()){
                    s.pop();
                }else{
                    stack1=false;
                }
            }


        }

        if (queue1 && !stack1 && !priority1) {
            printf("queue\n");
        } else if (!queue1 && stack1 && !priority1) {
            printf("stack\n");
        } else if (!queue1 && !stack1 && priority1) {
            printf("priority queue\n");
        } else if (queue1 + stack1 + priority1 > 1) {
            printf("not sure\n");
        } else {
            printf("impossible\n");
        }
        while (!q.empty()) q.dequeue();
        while (!s.empty()) s.pop();
        while (!p.empty()) p.dequeue();
    }


    return 0;
}
