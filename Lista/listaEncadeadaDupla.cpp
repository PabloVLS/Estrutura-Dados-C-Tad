#include <iostream>

struct Node{
  Node* next;
  Node* prev;
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
    Node* mid;
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
            mid=n;
            print();
            printf("%.2lf\n", value);
            return;
        }
        n->prev = last;
        last->next = n;
        last = n;
        
        
        
        if(c%2==0){
            mid = mid->next;
        }
        print();
        
         if (c % 2 == 0) {
            //printf("mid %.2lf\n  mid prev %.2lf\n",mid->value , mid->prev->value);
            double media = (mid->value + mid->prev->value) / 2; // exemplo: quanto o mid aponta pro 40 o proximo de prev era o last=30
            printf(" %.2lf\n", media);
        } else {
            printf(" %.2lf\n", mid->value);
        }
    }

    void print(){
        Node* aux = first;
        while(aux != NULL){
            printf("%.0lf ",aux->value);
            aux = aux->next;
        }

    }

   /* void mediana(double value){
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
    }*/
};


int main()
{
    int qtd;
    double numero;
    List l;
    scanf("%d",&qtd);
    for(int i=0 ; i< qtd;i++){
        scanf("%lf",&numero);
        l.pushBack(numero);
    }

    return 0;
}