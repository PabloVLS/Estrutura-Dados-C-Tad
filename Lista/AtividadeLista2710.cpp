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


    /*int size() { // O(n)
        int c = 0;
        Node* aux = first;
        while (aux != NULL) {
            c++;
            aux = aux->next;
        }
        return c;
    }*/


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
        c--;//nao se esqueça de sempre incrementar e decrementar
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
        c++;//nao se esqueça de sempre incrementar e decrementar
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

    void removeByQtd(int n){
        int a=c;
        if(n>c){
            for(int i=0;i<a;i++){
                popBack();
            }
           /* first=NULL;
            last=NULL;*/
        }else{
            for(int i=0;i<n;i++){
                popBack();
            }
        }
    }

    void remove2Elemento(){
        if(c<=1){
            return;
        }else{
            Node* aux = first->next;//aux = 10
            first->next = aux->next;// proximo do primeiro que e 10 vai receber o proximo do segundo que e 5
            delete(aux); // deleta o 10
            c--;
        }
    }

    void colocarCnoFinal(){
        pushBack(c);

    }

    void inserirListaAteN(int n){
        for(int i =1; i<=n;i++){
            pushBack(i);

        }
    }

    void inserirPenultimoPos(int element){
        if(c<=1){
            return;
        }else{
            Node* penult = first;
            Node* elemento =new Node(element);
            while(penult->next!=last){//rodou ate a penultima posição
                penult = penult->next;
            }
            penult->next = elemento;
            elemento->next= last;//promixo do elemento vai receber o ultimo
            c++;
        }
    }

};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);
    l.remove2Elemento();
    l.inserirPenultimoPos(33);
    l.inserirPenultimoPos(34);
    l.colocarCnoFinal();
    l.removeByQtd(10);
   // l.print();
    l.inserirListaAteN(56);
   // l.print();
    l.removeByQtd(57);
    l.colocarCnoFinal();
    l.print();

    return 0;
}
