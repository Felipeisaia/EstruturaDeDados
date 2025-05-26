#include <iostream>
#include <ctime>
using namespace std;

#include "lista.h"

int main() {
    srand(time(NULL));

    Lista *listaA = NULL;
    Lista *listaB = NULL;

    // cria uma lista(A) com 25 números aleatórios entre 1 e 100
    for (int i = 0; i < 20; i++) {
        listaA = inserir(rand() % 100 + 1, listaA);
    }

    // cria uma lista(B) com 30 números aleatórios entre 1 e 100
    for (int i = 0; i < 30; i++) {
        listaB = inserir(rand() % 100 + 1, listaB);
    }

    cout << "Lista A:\n";
    exibir(listaA);

    cout << "\nLista B:\n";
    exibir(listaB);

    cout << "\nNumeros presentes em ambas listas:\n";
    exibirComuns(listaA, listaB);

    listaA = removerPares(listaA);

    cout << "\nLista A sem os numeros pares:\n";
    exibir(listaA);

    Lista *listaUnida = unirListas(listaA, listaB);

    cout << "\nNumeros presentes na lista unida:\n";
    exibir(listaUnida);

    ordenarLista(listaUnida);

    cout << "\nlista unida e ordenada:\n";
    exibir(listaUnida);

    liberarLista(&listaUnida);

    if (listaUnida == NULL)
        cout << "\nA lista unida esta vazia (a memoria foi liberada).\n";
    else {
        cout << "Erro: lista ainda contém elementos:\n";
        exibir(listaUnida);
    }
    
    return 0;
}
