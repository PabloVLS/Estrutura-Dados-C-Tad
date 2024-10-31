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
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void print(int lido) { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        while (aux != NULL) {
            if(lido > 0){
                lido = lido-aux->value;
                c++;
            }else{
                break;
            }
          aux = aux->next;
        }
        if(aux == NULL && lido>0){
            c=0;
        }
         printf("%d",c);
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









};

int main() {
    int qtd,paginas,lido;
    List l;
    scanf("%d",&qtd);
    for(int i=0;i < qtd;i++){
       scanf("%d",&paginas);
       l.pushBack(paginas);
    }
    scanf("%d",&lido);
    l.print(lido);

    return 0;
}
