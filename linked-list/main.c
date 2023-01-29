#include <stdio.h>
#include <stdlib.h>


typedef struct {
    void * next;
    int data;
} Node;

static Node * head = NULL; 

void  printMenu()
{
    printf("\nOptions:\n");
    printf("----------------------------------\n");
    printf("1. Add a node (append to the front).\n");
    printf("2. Insert a value on a node (with a given value).\n");
    printf("3. Remove nodes with a given data\n");
    printf("4. Print the nodes.\n");
    printf("5. Quit.\n");
    printf("----------------------------------\n");
}

void pushNode(int new_data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("New node on pushNode didnt allocate.");
        exit(EXIT_FAILURE);
    }

    newNode->data = new_data;
    newNode->next = head;
    head = newNode;
}

void freeNodes()
{
    Node * temp = head;
    while (temp != NULL){
        Node * trash = temp;
        temp = temp->next;

        free(trash);
    }

    free(temp);
}

void printNodes()
{
    Node * temp = head;
    while (temp != NULL){
        printf("[%d]->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    free(temp);
}

void removeElement(int element)
{
    Node * current = head->next;
    Node * previous = head;

    if ( head->data == element ){
        Node * temp = head;
        head = head->next;
        free(temp);
    }

    while (current != NULL){
        if (current->data == element){
            current = current->next;
            free(previous->next);
            previous->next = current;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void insertValue(int prev_value, int new_value)
{
    printf("DEBUG\n");
    Node * current = head;

    while (current != NULL){
        if (current->data == prev_value){
            current->data = new_value;
        }
        current = current->next;
    }
    free(current);
}


int main(void)
{
    int run = 1;
    while(run){

        printMenu();
        int option = 0;
        int received_input = scanf("%d", &option);

        if (received_input && option >= 1 && option <= 5){
            switch (option){
                case 1:
                    // TODO: handle int overflow
                    printf("\nInsert the data: ");
                    int new_data = 0;
                    scanf("%d", &new_data);
                    
                    pushNode(new_data);
                    
                    break;
                case 2:
                    printf("Insert the value to look for and the new value (ex: 6,9):");
                    int prev_value, new_value;
                    scanf("%d %d", &prev_value, &new_value);

                    insertValue(prev_value, new_value);
                    break;
                case 3:
                    printf("\nInsert the element to remove: ");
                    int elem = 0;
                    scanf("%d", &elem);

                    removeElement(elem);
                    break;
                case 4:
                    printNodes();
                    break;
                case 5:
                    freeNodes();
                    run = 0;
                    break;
            }
        }
    }
    
    return 0;
}