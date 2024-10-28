#include<stdio.h>

struct Node{
    int value;
    Node* next;

    Node(){
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};


struct List{
    Node* first;
    Node* last;

    List(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first == NULL;
    }

    void pushBack(int value) {
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }


    void imprimir(){
        Node* aux = first;
        int k=0;
        while(aux!=NULL){
            printf("X[%d""] = %d\n",k,aux->value);
            aux=aux->next;
            k++;
        }
    }


};



int main(){
    List l;
    int x;

    for(int i = 0 ; i < 10; i++){
        scanf("%d",&x);
        if(x<=0){
            x=1;
        }
        l.pushBack(x);
    }

    l.imprimir();


    return 0;
}
