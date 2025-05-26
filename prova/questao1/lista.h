#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Lista;

// função para inserir um novo elemento no inicio de uma lista
Lista *inserir(int valor, Lista *lista) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

// função para imprimir todos os elementos da lista
void exibir(Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << "\t";
    }
    cout 
    << endl;
}

// função para localizar um valor na lista
bool localizar(int valor, Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        if (p->dado == valor)
            return true;
    }
    return false;
}

//               questão 1:
// função exibir números presentes em ambas listas
void exibirComuns(Lista *a, Lista *b) {
    Lista *p;
    for (p = a; p; p = p->prox) {
        if (localizar(p->dado, b)) {
            cout << p->dado << "\t";
        }
    }
    cout << endl;
}

//               questão 2:
// função para remover números pares da lista
Lista *removerPares(Lista *lista) {
    Lista *p = lista, *anterior = NULL;

    while (p != NULL) {
        if (p->dado % 2 == 0) {
            Lista *remover = p;
            if (p == lista) {
                lista = p->prox;
                p = lista;
            } else {
                anterior->prox = p->prox;
                p = p->prox;
            }
            free(remover);
        } else {
            anterior = p;
            p = p->prox;
        }
    }

    return lista;
}

//               questão 3:
// função para unir duas listas
Lista *unirListas(Lista *a, Lista *b) {
    if (!a) return b; // se a estiver vazia, ele vai retornar b
    if (!b) return a; // se b estiver vazia, ele vai retornar a
    Lista *p = a;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = b; // ultimo no de A aponta para início de B
    return a; //vai retornar o ponteiro para o inicio da lista unida
}

//               questão 4:
// função para ordenar a lista em ordem crescente
void ordenarLista(Lista *lista) {
    if (!lista) return;
    bool trocou;
    do {
        trocou = false;
        Lista *p = lista;
        while (p->prox != NULL) {
            if (p->dado > p->prox->dado) {
                int temp = p->dado;
                p->dado = p->prox->dado; 
                p->prox->dado = temp;
                trocou = true; 
            }
            p = p->prox; 
        }
    } while (trocou); // repete até nao precisar mais trocar nada
}

//               questão 5:
// função para liberar a memória alocada para a lista
void liberarLista(Lista **lista) {
    Lista *atual = *lista;
    Lista *proxNo;

    while (atual != NULL) {
        proxNo = atual->prox;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL; // ponteiro externo também é zerado
}


