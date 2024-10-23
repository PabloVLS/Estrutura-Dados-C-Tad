#include <stdio.h>

struct Node{
  long long value;
  Node* next;
 
  Node() { 
        value = 0;
        next = NULL;
  }
  
  Node(long long _value){
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
        return first==NULL;
    }
    
    void pushFront(long long value){
        Node* n = new Node(value);
        if(empty()){
            first = n;
            last = n;
            return;
        }
        n->next=first;
        first=n;
        
    }
    
    void imprimir(){
        Node* aux2 = first;
        while(aux2!=last){
            printf("%lld ",aux2->value);
            aux2 = aux2->next;
        }
        printf("%lld\n",aux2->value);
        
    }
    
    
};


int main()
{
    List l;
    int i=0,x;
    long long aux=1,valor=1,valor1;
    scanf("%d",&x);
    if (x >= 1) l.pushFront(1);
    if (x >= 2) l.pushFront(1);


    for (int i = 2; i < x; i++) {
        long long valor1 = valor + aux;
        l.pushFront(valor1);
        aux = valor;
        valor = valor1;
    }

    l.imprimir();
    return 0;
}