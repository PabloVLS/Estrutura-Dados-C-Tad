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
    Node* mid;

    List() { // O(1)
        first = NULL;
        last = NULL;
        c = 0;
        mid=NULL;
    }


    bool empty() { // O(1)
        return first == NULL;
    }



    void pushBack(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            mid=n;
            return;
        }
        last->next = n;
        last = n;
        if(c%2!=0){
            mid=mid->next;
        }
    }

    void print() {
        Node* aux = first;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
    }



    int size() { // O(1)
        return c;
    }


    void calcula(){
        print();
        if(c%2==0){
            double val=(mid->value + mid->next->value)/2.0;
            printf("%.2lf\n",val);
            return;
        }else{
            printf("%.2lf\n",double(mid->value));

        }
    }

};

int main() {

    List l;

    int qtd;

    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){
        int num;
        scanf("%d",&num);
        l.pushBack(num);
        l.calcula();
    }

    return 0;
}
