/*Fa�a um programa que seja capaz de armazenar informa��es sobre livros de uma biblioteca.
Seu programa deve ter um TAD para representar o livro, contendo t�tulo, autor e n�mero de p�ginas.
Al�m disso, seu TAD deve ter duas opera��es: ler e imprimir.Seu programa tamb�m deve ter um TAD para
representar toda a biblioteca, contendo um vetor de livros e a quantidade de livros j� armazenados
nessa TAD. O m�ximo de livros na TAD biblioteca ser� 10. Seu TAD deve ter uma opera��o capaz de ler um novo livro, uma opera��o para
imprimir todos os livros da biblioteca e outra opera��o capaz de imprimir o livro que cont�m o maior n�mero de p�ginas de toda a biblioteca.*/
#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int pagina;
};

void lerLivro(struct Livro *livro) {
    printf("\nDigite o titulo do livro: ");
    scanf(" %[^\n]", livro->titulo);
    printf("\nDigite o autor do livro: ");
    scanf(" %[^\n]", livro->autor);
    printf("\nQuantas paginas tem o livro: ");
    scanf(" %d", &livro->pagina);
}

void imprimirLivro(struct Livro livro) {
    printf("\nInformacoes do Livro:\n");
    printf("T�tulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("N�mero de P�ginas: %d\n", livro.pagina);
}

struct Lista {
    struct Livro livro[10];
    int cont;
    int maior;
    char nomeMaior[50];
};

void listaCadastro(struct Lista *lista) {
    lerLivro(&lista->livro[lista->cont]);
    if (lista->livro[lista->cont].pagina > lista->maior) {
        lista->maior = lista->livro[lista->cont].pagina;
        strcpy(lista->nomeMaior, lista->livro[lista->cont].autor);
    }
    lista->cont++;
}

void listaLivros(struct Lista lista) {
    for (int i = 0; i < lista.cont; i++) {
        imprimirLivro(lista.livro[i]);
    }
}

void maiorLivro(struct Lista lista) {
    printf("O livro com mais p�ginas � de %s, com %d p�ginas.\n", lista.nomeMaior, lista.maior);
}

struct Menu {
    int opcao;
    struct Lista lista;
};

void mostrarMenu(struct Menu *menu) {
    menu->opcao = 0;
    menu->lista.cont = 0;
    menu->lista.maior = 0;
    strcpy(menu->lista.nomeMaior, "");

    while (menu->opcao != 4) {
        printf("\nMenu:\n");
        printf("1. Cadastrar livro\n");
        printf("2. Imprimir os livros\n");
        printf("3. Maior livro\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &menu->opcao);

        if (menu->opcao == 1) {
            listaCadastro(&menu->lista);
        } else if (menu->opcao == 2) {
            listaLivros(menu->lista);
        } else if (menu->opcao == 3) {
            maiorLivro(menu->lista);
        } else if (menu->opcao == 4) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }
}

int main() {
    struct Menu menu;
    mostrarMenu(&menu);
    return 0;
}
