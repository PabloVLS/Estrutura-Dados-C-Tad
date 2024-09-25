#include <stdio.h>
#include <stdbool.h> // Para utilizar o tipo bool

struct Entrada {
    int grupoLendo[10];

    void capturar(int indice) {
        printf("Digite os numeros para o grupo %d:\n", indice + 1);
        for (int i = 0; i < 10; i++) {
            scanf("%d", &grupoLendo[i]);
        }
        printf("\n");
    }
};

struct Grupo {
    int cont;
    Entrada numeros[20];

    Grupo() : cont(0) {}

    void obter(int qtdGrupoVazio){
        if(qtdGrupoVazio == 0){
            printf("Nao ha grupos preenchidos.\n\n");
        }else{
            printf("Escolha um grupo para ler:\n");
            for(int i = 0; i < qtdGrupoVazio; i++) {
                printf("%d - Grupo %d\n", i, i + 1);
            }
            int pos;
            scanf("%d", &pos);
            if(pos >= 0 && pos < qtdGrupoVazio){
                numeros[pos].capturar(pos);
            }else {
                printf("Grupo invalido.\n");
            }
        }
    }

    void juntar(int qtdGrupoVazio){
        if(qtdGrupoVazio < 2){
            printf("Nao ha grupos suficientes para realizar a uniao.\n\n");
        }else{
            printf("Escolha dois grupos para uniao:\n");
            for (int i = 0; i < qtdGrupoVazio; i++) {
                printf("%d - Grupo %d\n", i, i + 1);
            }
            int posicao1, posicao2;
            scanf("%d %d", &posicao1, &posicao2);

            if(posicao1 >= 0 && posicao1 < qtdGrupoVazio && posicao2 >= 0 && posicao2 < qtdGrupoVazio){
                printf("Unindo grupos %d e %d\n", posicao1 + 1, posicao2 + 1);
                for (int i = 0; i < 10; i++){
                    printf("%d ", numeros[posicao1].grupoLendo[i]);
                }
                for(int i = 0; i < 10; i++){
                    printf("%d ", numeros[posicao2].grupoLendo[i]);
                }
                printf("\nGrupos unidos com sucesso.\n");
            }else {
                printf("Grupos invalidos.\n");
            }
        }
    }

    void interseccao(int qtdGrupoVazio){
        if (qtdGrupoVazio < 2){
            printf("Nao ha grupos suficientes para realizar a interseccao.\n\n");
            return;
        }

        printf("Escolha dois grupos para interseccao:\n");
        for(int i = 0; i < qtdGrupoVazio; i++) {
            printf("%d - Grupo %d\n", i, i + 1);
        }
        int posicao1, posicao2;
        scanf("%d %d", &posicao1, &posicao2);

        if(posicao1 >= 0 && posicao1 < qtdGrupoVazio && posicao2 >= 0 && posicao2 < qtdGrupoVazio){
            printf("Fazendo interseção entre grupos %d e %d...\n", posicao1 + 1, posicao2 + 1);
            Entrada resultado;
            int tamanhoResultado = 0;

            for(int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if(numeros[posicao1].grupoLendo[i] == numeros[posicao2].grupoLendo[j]){
                        bool existe = false;
                        for(int k = 0; k < tamanhoResultado; k++){
                            if(resultado.grupoLendo[k] == numeros[posicao1].grupoLendo[i]){
                                existe = true;
                                break;
                            }
                        }
                        if(!existe){
                            resultado.grupoLendo[tamanhoResultado++] = numeros[posicao1].grupoLendo[i];
                        }
                    }
                }
            }
            printf("Interseção resultante:\n");
            for (int i = 0; i < tamanhoResultado; i++) {
                printf("%d ", resultado.grupoLendo[i]);
            }
            printf("\n");
        } else {
            printf("Grupos invalidos.\n");
        }
    }

    void imprimir(){
        printf("Imprimindo grupos:\n");
        for (int i = 0; i < cont; i++){
            printf("Grupo %d: ", i + 1);
            for (int j = 0; j < 10; j++){
                printf("%d ", numeros[i].grupoLendo[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

int main(){
    Grupo grupo;
    int operacao = 1;
    int qtdGrupoVazio = 0;

    while(operacao != 0){
        printf("Escolha uma operacao:\n");
        printf("Digite 1 - Criar um grupo vazio.\n");
        printf("Digite 2 - Ler dados de um grupo.\n");
        printf("Digite 3 - Juntar dois grupos.\n");
        printf("Digite 4 - Fazer interseção de dois grupos.\n");
        printf("Digite 5 - Imprimir um grupo.\n");
        printf("Digite 0 - Fechar sistema.\n");
        scanf("%d", &operacao);

        if(operacao == 1){
            if (qtdGrupoVazio < 20){
                grupo.numeros[qtdGrupoVazio] = Entrada();
                qtdGrupoVazio++;
                grupo.cont++;
                printf("Grupo vazio criado.\n");
            }else {
                printf("Limite de grupos atingido.\n");
            }
        }else if (operacao == 2){
            grupo.obter(qtdGrupoVazio);
        }else if (operacao == 3){
            grupo.juntar(qtdGrupoVazio);
        }else if (operacao == 4){
            grupo.interseccao(qtdGrupoVazio);
        }else if (operacao == 5){
            grupo.imprimir();
        }else if (operacao == 0){
            printf("Fechando o sistema...\n");
        }else {
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}
