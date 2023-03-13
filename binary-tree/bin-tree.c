#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define MAX_CAP 1023

typedef struct Node Node;

struct Node {
    int data;
    Node* left;
    Node* right;
};

typedef struct{ 
    Node* root;
    uint32_t counter;
} Binary_tree;

Binary_tree* new_Bt(){
//    Binary_tree* new_bt = malloc(sizeof(Binary_tree));
    Binary_tree new_bt;

    new_bt.counter = 0;
    new_bt.root = NULL;
    
    Binary_tree* bt_ptr = &new_bt;
    return bt_ptr;
}

Node* create_node(int data){
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int push_Bt(int value, Binary_tree *bt){
    if (bt->counter < MAX_CAP){
        perror("full capacity reached");
        return 0;
    }

    Node * QUERY_POOL[MAX_CAP];
    size_t tail;
    size_t current;

    Node * new_node = create_node(value); 

    bt->counter++;

    if (bt->counter == 1){
        
        bt->root = new_node;
        return 1;
    }

    QUERY_POOL[0] = bt->root;
    current = 0;
    tail = 0;

    Node *temp; 
    while(1){
        temp = QUERY_POOL[current];

        if (temp->left == NULL){
            temp->left = new_node;
            return 1;
        } else {
            ++tail;
            QUERY_POOL[tail] = temp->left;
        }


        if (temp->right == NULL){
            temp->right = new_node;
            return 1;
        } else {
            ++tail;
            QUERY_POOL[tail] = temp->right;
        }
        
        ++current;
    }
    
}

int main(void){
    
    Binary_tree* bt = new_Bt();
    
    push_Bt(3, bt);
    printf("\nroot; %d\n", (bt->root)->data);
    return 0;
}
