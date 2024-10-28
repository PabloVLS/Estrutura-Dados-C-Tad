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
        int menor = 9999999;
        Node* aux = first;
        int k=0, p;
        while(aux!=NULL){
            if(aux->value < menor){
                menor = aux->value;
                p=k;
            }
            aux=aux->next;
            k++;
        }
        printf("Menor valor: %d\n",menor);
        printf("Posicao: %d\n",p);
    }


};



int main(){
    List l;
    int x,qtd;
    scanf("%d",&qtd);
    for(int i = 0 ; i < qtd; i++){
        scanf("%d",&x);
        l.pushBack(x);
    }

    l.imprimir();


    return 0;
}
