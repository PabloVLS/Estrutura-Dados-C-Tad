#include<stdio.h>
#include<string.h>
struct Node{
    String palavra;
    Node* next;
    
    Node(){
        palavra = NULL;
        next = NULL;
    }
    
    Node(String _palavra){
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
  
  void pushBack(String _palavra){
      Node *n = new Node(_palavra);
      if(empty()){
          first = n;
          last= n;
      }
      last->next = n;
      last = n;
  }
  
  void print(String nome,String _palavra){
      Node *aux = first;
      while(aux != NULL){
          if(strcmp(aux->palavra, _palavra)==0 ){
              printf("%s\n",nome);
              printf("%s\n\n",aux->next);
          }
          aux = aux->next;
      }
  }
  
  
};


int main()
{
   List l;
   int qtd,qtd2;
   String idioma,frase,nome;
   scanf("%d",&qtd);
   for (int i=0 i < qtd;i++){
       scanf("%s",idioma);
       scanf("%[^/n]*c",frase);
       l.pushBack(idioma);
       l.pushBack(frase);
   }
   
   scanf("%d",&qtd2);
   for (int i=0 i < qtd2;i++){
       scanf("%s",nome);
       scanf("%s",idioma);
       l.print(nome,idioma);
   }
    return 0;
}