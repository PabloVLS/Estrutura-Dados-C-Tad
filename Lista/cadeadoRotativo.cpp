#include <iostream>

struct Node{
  Node* next;
  Node* prev;
  int value;

  Node(){
      value =0;
      next=NULL;
  }

  Node(int _value) {
        value = _value;
        next = NULL;
  }

};

struct List{
    Node* first;
    Node* mid;
    Node* last;
    int c,soma;

    List(){
        first = NULL;
        last = NULL;
        c=0;
        soma=0;
    }

    bool empty(){
        return first == NULL;
    }

    void pushBack(int value){
        Node *n = new Node(value);

        if(empty()){
            first = n;
            last=n;
            n->next = first; // O próximo do novo nó aponta para ele mesmo
            n->prev = last; // O anterior do novo nó aponta para ele mesmo
            return;
        }
        n->prev = last; // O ponteiro anterior do novo nó aponta para o último nó
        last->next = n; // O próximo do último nó aponta para o novo nó
        last = n; // Atualiza o último nó para o novo nó
    
        // Para manter a circularidade, é necessário fazer com que o próximo do último nó
        // aponte para o primeiro nó e o anterior do primeiro nó aponte para o último nó.
        last->next = first; // O próximo do último nó aponta para o primeiro nó
        first->prev = last; // O anterior do primeiro nó aponta para o último nó
    }
    
    void verificar(int valor){
        c++;
        int cont=0, cont1=0;
        Node *aux = first;
        Node *prev = last;
        while(aux->value != valor){
            aux = aux->next;
            cont++;
        }
        first->value=cont;
        
        while(prev->value != valor){
            prev = prev->next;
            cont1++;
        }
        
        last->value=cont1;
        if(cont < cont1){
            soma=soma+cont;
        }else{
            soma=soma+cont1;
        }
    }
    int getSoma() { // Método para retornar a soma
        return soma;
    }


    void print(){
        Node* aux = first;
        while(aux != NULL){
            printf("%d ",aux->value);
            aux = aux->next;
        }

    }

  
};


int main()
{
    int qtd,num3,num2,num1;
    double numero;
    List l;
    for(int i=0 ; i< 10;i++){
        l.pushBack(i);
    }
    scanf("%d",&num1);
    l.verificar(num1);
    scanf("%d",&num2);
    l.verificar(num2);
    scanf("%d",&num3);
    l.verificar(num3);

    printf("%d\n", l.getSoma());
    return 0;
}