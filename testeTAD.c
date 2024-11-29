#include <stdio.h>
#include "fila.h"

void clean_buffer(){
    char trash;

    while((trash = getchar()) != '\n' && trash != EOF);
}

int read_input(int* age){
    char trash;
    int valid = 0;

    while(!valid){
        printf("Qual a sua idade?\n");

        if((scanf("%d%c", age, &trash) == 2) && (trash == '\n')){
            valid = 1;
        }
        else{
            clean_buffer();
            printf("Entrada inválida!\n");
        }
    }

    return 1;
}

int main(){
    Fila *fila = create_fila();
    int age;

    printf("--Bem vind@ ao Banco Nsei!\n");

    // while(read_input(&age)){
    //     printf("entrou\n");
    //     insert_node(fila, age);
    // }
    while(scanf("%d", &age) == 1){
        printf("entrou\n");
        insert_node(fila, age);
    }
    
    print_fila(fila);

    //Assist(remove) the customers one by one until the end of the line
    while(!empty_fila(fila)){
        
        printf("Cliente com idade: %d, foi atendido.\n", remove_node(fila));
    }
    
    printf("\nNenhum atendimento pendente :)\n\n");
    free_fila(fila);
}