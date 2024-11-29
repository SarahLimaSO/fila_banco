#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void clean_buffer(){
    char trash;

    while((trash = getchar()) != '\n' && trash != EOF);
}

// int read_input(int* age){

//     printf("Qual a sua idade?\n");

//     if(scanf("%d%*c", age) == 1){
//         return 1;
//     }
    
//     clean_buffer();
//     printf("Entrada inválida!\n");
    
//     return 0;
// }

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

    while((scanf("%d%*c", &age) == 1)){
        insert_node(fila, age);
    }
    print_fila(fila);
    sort_fila(fila);
    
    print_fila(fila);
    free_fila(fila);

}