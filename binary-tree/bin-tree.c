#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void* childs[2]; 
} Node;

int main(void){
    Node * n = (Node*)malloc(sizeof(Node));
    n.data = 1;
    return 0;
}