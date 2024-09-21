/*Uma loja precisa controlar a folha de pagamento de seus funcionários.
Os atributos de um funcionário são nome, cargo, salário base, benefícios e descontos.
Criar uma struct para a loja e cadastrar uma lista de no máximo 10 funcionários
com os campos acima e depois mostre os dados de cada um deles, com o salário liquido de
cada um. O cálculo do salário líquido é: salário base + benefícios – descontos.
Criar operações também para exibir a média salarial da loja e exibir quem recebe o maior salário.
*/
#include <stdio.h>
#include <string.h>


struct Funcionario{
    char nome[100];
    char cargo[100];
    double salario,desconto,beneficio;
    double salarioLiquid,maiorSalario,salarioTodos;
    char salaMaior[100];
    int cont=0;

    void ler(){
        printf("Nome Funcionario:");
        scanf(" %[^\n]", nome);
        printf("Cargo:");
        scanf(" %[^\n]", cargo);
        printf("Salario:");
        scanf(" %lf",&salario);
        printf("Desconto:");
        scanf(" %lf",&desconto);
        printf("Beneficios:");
        scanf(" %lf", &beneficio);

        calculoSalario();

    }

    void calculoSalario(){
        salarioLiquid = salario+beneficio-desconto;
        salarioTodos += salarioLiquid;
        cont++;
        if(salarioLiquid > maiorSalario){
            maiorSalario = salarioLiquid;
            strcpy(salaMaior,nome);
        }
    }
    void imprimir() {
        printf("\nNome Funcionario: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario: %.2lf\n", salario);
        printf("Desconto: %.2lf\n", desconto);
        printf("Beneficios: %.2lf\n", beneficio);
        printf("Salario Liquido: %.2lf\n", salarioLiquid);
    }



};

struct Loja{
    Funcionario funcionario[10];
    int cont=0;
    double salarioTodosFunc,salarioMaiorFuncioanrio;
    char nomeMaiorSalario[50];

    void Cadastrarfuncionarios(){
        funcionario[cont].ler();
        salarioTodosFunc += funcionario[cont].salarioLiquid;
        if(funcionario[cont].salarioLiquid > salarioMaiorFuncioanrio){
            salarioMaiorFuncioanrio = funcionario[cont].salarioLiquid;
            strcpy(nomeMaiorSalario, funcionario[cont].salaMaior);
        }
        cont++;
    }

    void mostraFuncionarios(){
        for(int i =0; i < cont ; i++){
            funcionario[i].imprimir();
        }

    }

    void mediaSalarioLoja(){
        double media =salarioTodosFunc / cont;
        printf("\nA media salarial da loja é:%.2lf\n",media);

    }

    void maiorSalario(){
         printf("\nO funcionario %s tem o maior salario da loja: R$ %.2lf\n", nomeMaiorSalario, salarioMaiorFuncioanrio);

    }


};


int main(){
    Loja loja;
    int opcao = 5;
    while(opcao!=0){
        printf("\n1 - Cadastrar Funcionario\n");
        printf("2 - Mostrar Funcionarios\n");
        printf("3 - Mostrar Media Salarial\n");
        printf("4 - Exibir Funcionario com Maior Salario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao==1){
            loja.Cadastrarfuncionarios();
        }else if(opcao==2){
            loja.mostraFuncionarios();
        }else if(opcao==3){
            loja.mediaSalarioLoja();
        }else if(opcao==4){
            loja.maiorSalario();
        }else if(opcao==0){
            return 0;
        }
    }
    return 0;
}
