#include <stdio.h>
#include "fila.h"

int main(){
    Fila *fila = create_fila();
    int age;

    printf("--Bem vind@ ao Banco Nsei!\n");

    while(scanf("%d%*c", &age) == 1){
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