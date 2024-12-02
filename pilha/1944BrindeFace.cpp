/*A lógica do problema se baseia na verificação de padrões em uma sequência de letras 
em um painel. O painel é inicialmente preenchido com "F A C E", e o objetivo é verificar 
se a sequência de letras inserida por cada visitante forma o inverso das últimas 4 letras do painel. 
Caso forme, o visitante recebe um brinde, e as 4 últimas letras são removidas do painel. 
Se o painel esvaziar completamente, "F A C E" é automaticamente adicionado.*/
#include <stdio.h>

// Estrutura que representa um nó da pilha
struct Node {
    char value;   // Valor armazenado no nó
    Node* next;   // Ponteiro para o próximo nó

    // Construtor padrão
    Node() {
        value = 0;
        next = NULL;
    }

    // Construtor que inicializa o nó com um valor
    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

// Estrutura que representa a pilha usando nós encadeados
struct Stack {
    Node* t;   // Ponteiro para o nó no topo da pilha

    // Construtor padrão que inicializa a pilha como vazia
    Stack() {
        t = NULL;
    }

    // Verifica se a pilha está vazia
    bool empty() { // Complexidade: O(1)
        return t == NULL;
    }

    // Adiciona um valor ao topo da pilha
    void push(char value) { // Complexidade: O(1)
        Node* n = new Node(value); // Cria um novo nó
        n->next = t;               // Liga o novo nó ao topo atual
        t = n;                     // Atualiza o topo para o novo nó
    }

    // Remove o valor do topo da pilha
    void pop() { // Complexidade: O(1)
        if (empty()) return;       // Se a pilha estiver vazia, não faz nada
        Node* toDel = t;           // Salva o nó do topo para deletar
        t = t->next;               // Atualiza o topo para o próximo nó
        delete toDel;              // Remove o nó anterior da memória
    }

    // Retorna o valor do topo da pilha sem removê-lo
    char top() { // Complexidade: O(1)
        if (empty()) return '\0';  // Retorna '\0' se a pilha estiver vazia
        return t->value;           // Retorna o valor do topo
    }
};

// Função principal
int main() {
    Stack s;            // Instancia uma pilha
    char a, b, c, d;    // Letras recebidas do participante
    char E, C, A, F;    // Letras removidas do topo da pilha
    int qtd, cont = 0;  // Quantidade de visitantes e contador de brindes

    scanf("%d", &qtd);  // Lê o número de visitantes
    getchar();          // Remove o '\n' deixado no buffer após a entrada

    for (int i = 0; i < qtd; i++) {
        // Se a pilha está vazia, insere as letras padrão 'FACE'
        if (s.empty()) {
            s.push('F');
            s.push('A');
            s.push('C');
            s.push('E');
        }

        // Lê as 4 letras inseridas pelo participante
        scanf("%c %c %c %c", &a, &b, &c, &d);
        getchar(); // Limpa o '\n' do buffer após a leitura

        // Remove as 4 letras do topo da pilha
        E = s.top(); s.pop();
        C = s.top(); s.pop();
        A = s.top(); s.pop();
        F = s.top(); s.pop();

        // Verifica se as letras do participante formam o contrário das removidas
        if (a == E && b == C && c == A && d == F) {
            cont++; // Incrementa o contador de brindes
        } else {
            // Caso contrário, reinsere as letras removidas na pilha
            s.push(F); s.push(A); s.push(C); s.push(E);
            // E adiciona as letras do participante no topo da pilha
            s.push(a); s.push(b); s.push(c); s.push(d);
        }
    }

    // Exibe o número total de brindes distribuídos
    printf("%d\n", cont);
    return 0;
}
