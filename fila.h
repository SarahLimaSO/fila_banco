
typedef struct fila_No{
    int age;
    struct fila_No *next;
    struct fila_No *previous;
}Node;

typedef struct fila{
    Node *first;
    Node *last;
}Fila;


//FUNCOES DA LISTA (Queue functions)

//Create a new queue(fila)
Fila* create_fila();

//Open the txt file to read the informations inside it
FILE* open_file_read();

//Insert a new node in the end of the queue
void insert_node(Fila *fila, int value);

//Remove the node of the beginning of the queue and returns the age of the removed client(the info of the removed node)
int remove_node(Fila *fila);

//Verify if the queue is empty
int empty_fila(Fila *fila);

//Print the queue
void print_fila(Fila *fila);

//Freeing up the queue
void free_fila(Fila *fila);