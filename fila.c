#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Open the txt file to read the informations inside it
FILE* open_file_read(){

    FILE* file = fopen("clientes.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    return file;
}

//Create a new queue(fila)
Fila* create_fila(){
    Fila *newfila = malloc(sizeof(Fila));

    if(newfila == NULL){
        printf("ERROR(1): Insufficient memory!\n");
        exit(1);
    }

    newfila->first = NULL;
    newfila->last = NULL;

    return newfila;
}

//Insert a new node in the end of the queue
void insert_node(Fila *fila, int value){

    Node *new = malloc(sizeof(Node));

    if(new == NULL){
        printf("ERROR(2): Insufficient memory!\n");
        exit(1);
    }

    new->age = value;
    new->previous = fila->last;
    new->next = NULL;

    //If the queue is not empty
    if(fila->last != NULL){
        fila->last->next = new;
    }

    //If the queue is empty
    else{
        fila->first = new;
    }

    fila->last = new;
}

//Verify if the queue is empty
int empty_fila(Fila *fila){

    int empty = (fila->last == NULL);
    return empty;
}

//Remove the node of the beginning of the queue
int remove_node(Fila *fila){

    if(empty_fila(fila)){
        printf("Fila Vazia :)\n");
        return -1;
    }

    Node* temp = fila->first;
    int age = temp->age;

    //If the element is the first of the queue
    if (temp == fila->first){
        fila->first = temp->next;
    }
    else{
        temp->previous->next = temp->next;
    }

    //If the element is the last of the queue
    if(temp == fila->last){
        fila->last = temp->previous;
    }
    else{
        temp->next->previous = temp->previous;  //make the next element point to the previous element of the queue
    } 

    free(temp);
    return age;
}

//Print the queue
void print_fila(Fila *fila){

    printf("->Atendimentos pendentes: ");
    for(Node *n = fila->first; n != NULL; n = n->next){
        printf("%d ", n->age);
    }
    printf("\n\n");
}

//Freeing up the queue
void free_fila(Fila *fila){
    Node *temp = fila->first;

    while(temp != NULL){
        Node *t = temp->next;

        free(temp);
        temp = t;
    }
}




