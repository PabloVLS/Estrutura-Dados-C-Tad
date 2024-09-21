/*1. Criar uma struct para armazenar um cliente, contendo os seguintes dados: nome, data de nascimento,
idade e sexo. O sexo � apenas uma letra (M ou F) e a data de nascimento deve ser armazenada
numa struct de data, com 3 inteiros (dia, m�s e ano). A idade deve ser calculada quando a data de nascimento
for lida, e n�o solicitada ao usu�rio. Guarde a data atual numa vari�vel da struct de data e crie uma fun��o para calcular a idade.

Ap�s isso, criar um menu com 2 op��es: cadastrar cliente e listar clientes. Na primeira, um cliente deve ser lido e na segunda exibidos todos os clientes em ordem de cadastro.
Trate para que seu aplicativo armazene no m�ximo 50 clientes ao mesmo tempo.
*/


#include<stdio.h>

struct Nascimento{
    int dia,mes,ano,idade;

     void calcularIdade(){
        // hoje 21/09/2024
        idade = 2024-ano;
        if (9 < mes || (9 == mes && 21 < dia)) {
            idade--;
        }

    }
    void lerDataNascimento(){
        printf("Digite a Data de nascimento (dia/mes/ano): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        calcularIdade();
    }

};

struct Cliente{
    char nome[100];
    int idade;
    char sexo;
    int dia,mes,ano;
    Nascimento dataNasc;

    void ler(){
        printf("Digite o nome do cliente:");
        scanf(" %[^\n]", nome);

        printf("Digite o sexo(M,F):");
        scanf(" %c", &sexo);


        dataNasc.lerDataNascimento();
        idade = dataNasc.idade;
    }





    void imprimir(){
        printf("Nome:%s\n",nome);
        printf("Sexo:%c\n",sexo);
        printf("Data de nascimento: %02d/%02d/%04d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);
        printf("Idade:%d\n\n\n",idade);
    }

};

struct Lista{
    Cliente clientes[50];
    int cont=0;
    void lerCliente(){
        clientes[cont].ler();
        cont++;
    }

    void MostrarTdsCliente(){
        for(int i=0;i<cont; i++){
            clientes[i].imprimir();
        }
    }

};


struct Menu{
    Lista lista;
    void MenuEntrada(){
        int escolha=0;
        int cont=0;
        while(escolha!=3){
            printf("\n1-Cadastrar Cliente\n\n");
            printf("2-Listar Cliente\n\n");
            printf("3-Sair\n\n");
            scanf("%d",&escolha);
            if(escolha==1){
                lista.lerCliente();
            }else if(escolha==2){
                lista.MostrarTdsCliente();
            }
        }
    }


};

int main(){
    Menu menu;
    menu.MenuEntrada();
    return 0;
}
