#include <stdio.h>
#include <stdlib.h>

// Lenght maximo da lista
#define MAX 256

// Structs
struct LISTA {
    int length;
    char content[MAX];
};
typedef struct LISTA list;

// Funcoes;
list* criarLista (); // Cria uma lista com tamanho maximo == MAX;
int unshift (list *, char ); // Adiciona ao inicio
int shift (list *); // Remove do inicio
int push(list *, char); // Funcao adicionar no fim da lista
int pop (list *); // remove o ultimo elemento
int showAll(list *); // Mostrar o conteudo da lista
int insert(list *, int, char); // Adiciona em um index especifico
int remover(list *, int); // Remove em um index especifico

// Iniciar
int main()
{
    list *newList = criarLista();
    showAll(newList);
    return 1;
}

//// Funcoes e suas logicas
list* criarLista () {
    list *li = (list*) malloc(sizeof(list));
    if (li == NULL) {
        return 0;
    };

    li->length = 0;
    return li;
};

int push(list *lista, char letter) {
    if (lista->length == MAX) return 0;
    insert(lista, lista->length, letter);
    return 1;

};

int showAll(list *lista) {
    printf("===================\n");
    for (int index = 0; index < lista->length; index++) {
        printf("%c", lista->content[index]);
    };
    printf("\n===================\n");
    return 1;
};

int shift (list *lista) {
    remover(lista, 0);
    return 1;
};

int unshift (list *lista, char letter) {
    if (lista->length == MAX) return 0;
    insert(lista, 0, letter);
    return 1;
};

int insert(list *lista, int index, char letter) {
    if (lista->length == MAX) return 0;
    if (index > lista->length) index = lista->length;

    int lastIndex = lista->length - 1;
    for (lastIndex; lastIndex >= index; lastIndex--) {
        lista->content[lastIndex+1] = lista->content[lastIndex];
    };

    lista->content[index] = letter;
    lista->length++;

    return 1;
};

int remover (list *lista, int index) {
    int lastIndex = lista->length - 1;
    int pos = index;
    lista->content[index] = '\0';
    for (pos; pos <= lastIndex; pos++) {
        lista->content[pos] = lista->content[pos + 1];
    };

    lista->length--;
    return 1;
};

int pop (list *lista) {
    remover(lista, lista->length - 1);
};
