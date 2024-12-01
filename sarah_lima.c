#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Clears the keyboard buffer
void clean_buffer(){
    char trash;

    while((trash = getchar()) != '\n' && trash != EOF);
}

//Sorts the queue elements in descending order
void sort_fila(Fila *fila){

    //If the queue is empty
    if(fila->first == NULL){ 
        return;
    }
    
    int swap = 1;
   
   //While there is an exchange of elements the loop continues
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
    
                swap = 1; //Signals that a change has occurred
            }
            current = current->next;
        }
    }
}

int main(){
    FILE* fileTxt = open_file_read(); //Open the file "clientes.txt" in reading mode

    Fila *fila = create_fila();
    int age;

    printf("* $ **Bem vind@ ao banco Bradesco!** $ *\n\n");

    //Reading the informations in the file "clientes.txt"
     while((fscanf(fileTxt, "%d", &age)) != EOF){
        insert_node(fila, age); //Insert the information into the list
    }

    print_fila(fila); //Prints the original queue(fila) accordimg with the info in the file "clientes.txt"
    sort_fila(fila); //Sorts the queue elements in descending order
    

    //Assist(remove) the customers(nodes) one by one until the end of the line
    while(!empty_fila(fila)){
        
        printf("Cliente com idade: %d, foi atendido.\n", remove_node(fila));
    }
    
    printf("\nNenhum atendimento pendente :)\n\n");
    free_fila(fila); //Freeing up the queue
    fclose(fileTxt); //Close the txt file

}