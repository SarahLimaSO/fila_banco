#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void clean_buffer(){
    char trash;

    while((trash = getchar()) != '\n' && trash != EOF);
}

//Read the input anf verify if it's valid
int read_input(int* age){
    char end;
    int valid, input;
    valid = 0;

    while(!valid){
        printf("Qual a sua idade?\n");

        input = scanf("%d%c", age, &end);

        if(((input == 2) && (end == '\n')) || (input == 1)){
            valid = 1;
        }
        else if(input == EOF){
            printf("-Fim das entradas\n\n");
            break;
        }
        else{
            
            clean_buffer();
            printf("Entrada inválida!\n");
        }
    }
    return input;
}

void sort_fila(Fila *fila){

    //If the queue is empty
    if(fila->first == NULL){ 
        return;
    }
    
    int swap = 1;
   
    while(swap){
        Node *current = fila->first->next;
        swap = 0;

        while(current != NULL){

            Node *prevNo = current->previous;

            if((prevNo != NULL) && (prevNo->age < current->age)){

                //If "prevNo" node is not the first of the queue(fila)
                if(prevNo->previous != NULL){
                    prevNo->previous->next = current;
                }
                else{
                    fila->first = current; //Update the pointer that indicate the beginning of the queue
                }

                //If "current" node is not the last of the queue(fila)
                if(current->next != NULL){
                    current->next->previous = prevNo;
                }
                else{
                    fila->last = prevNo; //Update the pointer that indicate the end of the queue
                }

                prevNo->next =  current->next;
                current->previous = prevNo->previous;

                prevNo->previous = current;
                current->next = prevNo;
                
                swap = 1;
            }
            current = current->next;
        }
    }
}

int main(){
    Fila *fila = create_fila();
    int age;

    printf("--Welcome to Sarah's bank!\n");

    while(read_input(&age) != EOF){
        printf("entrou\n");
        insert_node(fila, age);
    }

    print_fila(fila);
    sort_fila(fila);
    
    print_fila(fila);
    free_fila(fila);

}