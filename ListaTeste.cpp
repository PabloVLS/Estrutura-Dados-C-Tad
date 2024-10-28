#include <iostream>

struct Node{
  Node* next;
  double value;

  Node(){
      value =0.0;
      next=NULL;
  }

  Node(double _value) {
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

    void pushBack(double value){
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
            printf("%.0lf ",aux->value);
            aux = aux->next;
        }

    }

    void mediana(double value){
        if(c==1){
            printf("%.2lf\n",value);
            return;
        }
        Node* aux = first;
        Node* prev = NULL;
        int a=0;
        double j;
        if(c%2==0){
            while(aux!=NULL && a<c/2){
                prev = aux;
                aux = aux->next;
                a++;
            }
            j=(aux->value + prev->value)/2;
            printf(" %.2lf\n",j);
        }else{
            while(aux!=NULL && a<c/2){
                aux = aux->next;
                a++;
            }
            printf(" %.2lf\n",aux->value);

        }
    }
};


int main()
{
    int qtd;
    double numero;
    List l;
    scanf("%d",&qtd);
    for(int i =0 ; i< qtd;i++){
        scanf("%lf",&numero);
        l.pushBack(numero);
        l.print();
        l.mediana(numero);
    }

    return 0;
}
