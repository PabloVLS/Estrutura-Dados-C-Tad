#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

struct Node{
    string palavra;
    Node* next;

    Node(){
        palavra = "";
        next = NULL;
    }

    Node(string _palavra){
        palavra = _palavra;
        next = NULL;
    }

};

struct List{
  Node* first;
  Node* last;

  List(){
      first=NULL;
      last=NULL;
  }

  bool empty(){
      return first==0;
  }

  void pushBack(string _palavra){
      Node *n = new Node(_palavra);
      if(empty()){
          first = n;
          last= n;
          return;
      }
      last->next = n;
      last = n;
  }

  void print(string nome,string _palavra){
      Node *aux = first;
      while(aux != NULL){
          if(aux->palavra == _palavra ){
              cout << nome << endl;
                if (aux->next != NULL) {
                    cout << aux->next->palavra << endl << endl;
                }
          }
          aux = aux->next;
      }
  }


};


int main()
{
   List l;
   int qtd,qtd2;
   string idioma,frase,nome;
   cin >> qtd;
   for (int i=0;i < qtd;i++){
       cin >> idioma;
       cin.ignore();
       getline(cin, frase);
       l.pushBack(idioma);
       l.pushBack(frase);
   }

   cin >> qtd2;
   cin.ignore();
   for (int i=0;i < qtd2;i++){
       getline(cin, nome);
       cin >> idioma;
       cin.ignore();
       l.print(nome,idioma);
   }
    return 0;
}
