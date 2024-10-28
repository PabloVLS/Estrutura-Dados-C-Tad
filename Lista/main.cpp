#include <iostream>

struct Node{
  Node* next;
  int value;
  
  Node(){
      value =0;
      next=NULL;
  }
  
  Node(int _value) { // O(1)
        value = _value;
        next = NULL;
  }
    
};

struct List{
    Node* first;
    Node* last;
    int c;
    
    List(){
        first = NULL;
        last = NULL;
        c=0;
    }
    
    bool empty(){
        return first == NULL;
    }
    
    void pushBack(int value){
        Node *n = new Node(value);
        c++;
        if(empty()){
            first = n;
            last=n;
            return;
        }
        last->next = n;
        last = n;
        
    }
    
    void print(){
        Node* aux = first;
        while(aux != NULL){
            printf("%d ",first->value);
            aux = aux->next;
        }
    }
    
    void mediana(double value){
        if(c==1){
            printf("%.2lf",value);
        }else{
            Node* aux = first;
            Node* prev = NULL;
            int a=0;
            double j;
            if(c%2==0){
                while(aux!=NULL && a<c/2){
                    aux = aux->next;
                    prev = aux->next;
                    a++;
                }
                int o=prev->value;
                j=(aux->value + o)/2;
                printf(" %.2lf\n",j);
            }else{
                while(aux!=NULL && a<c){
                    aux = aux->next;
                    a++;
                }
                
                printf(" %.2lf\n",aux->value);
            }
        }
    }
};


int main()
{
    int qtd, numero;
    List l;
    scanf("%d",&qtd);
    for(int i =0 ; i< qtd;i++){
        scanf("%d",&numero);
        l.pushBack(numero);
    }

    return 0;
}