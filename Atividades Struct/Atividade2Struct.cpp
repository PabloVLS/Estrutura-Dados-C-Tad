#include <stdio.h>

struct Entrada{
    int valor;

    void capturar(){
        printf("Digite os numeros:\n");
        for(int i = 0; i < 10; i++) {
            scanf("%d", &valor);
        }printf("\n");
    }
};

struct Grupo{
    int elementos[20];
    int cont = 0;
    Entrada numeros[20];

    void adicionar(){
        if(cont < 20){
            numeros[cont].capturar();
            cont++;
            printf("Grupo criado: %d\n\n", cont);
        }else {
            printf("Nao existem mais espacos para criar grupos.\n\n");
        }
    }

    void obter(){
        if(cont == 0) {
            printf("Nao ha grupos preenchidos.\n\n");
        }else {
            printf("Escolha um grupo para ler:\n");
            for(int i = 0; i < cont; i++) {
                printf("%d - ", i);
            }
            int pos;
            scanf("%d%*c", &pos);
            numeros[pos].capturar();
        }
    }

    void juntar(){
        printf("Juntando dois grupos...\n");
    }

    void interseccao(){
        printf("Fazendo interseção...\n");
    }

    void imprimir(){
        printf("Imprimindo grupos:\n");
        for(int i = 0; i < cont; i++) {
            printf("Grupo %d: %d\n", i, numeros[i].valor);
        }
        printf("\n");
    }
};

struct Menu{
    int operacao;
    Grupo grupo;

    void mostrar(){
        printf("Escolha uma operacao:\n");
        printf("Digite 1 - Criar um grupo.\n");
        printf("Digite 2 - Ler dados de um grupo.\n");
        printf("Digite 3 - Juntar dois grupos.\n");
        printf("Digite 4 - Fazer interseção de dois grupos.\n");
        printf("Digite 5 - Imprimir um grupo.\n");
        printf("Digite 0 - Fechar sistema.\n");
        scanf("%d%*c", &operacao);
    }

    void executar(){
        while(operacao != 0){
            mostrar();
            if(operacao == 1){
                grupo.adicionar();
            }else if(operacao == 2){
                grupo.obter();
            }else if(operacao == 3){
                grupo.juntar();
            }else if(operacao == 4){
                grupo.interseccao();
            }else if(operacao == 5){
                grupo.imprimir();
            }
        }
    }
};

int main(){
    Menu menu;
    menu.operacao = 1;
    menu.executar();
    return 0;
}
