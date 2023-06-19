#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define MAX_CAP 1023

typedef int bt_type; 

typedef struct Node Node;

struct Node {
    bt_type data;
    Node* left;
    Node* right;
};


void pre_order(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    pre_order( root->left );
    pre_order( root->right );
} 

void in_order(Node* root) {
    if( root == NULL ) return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void insert_left(Node* root, bt_type new_data) {
    if( root == NULL ) return;

    if ( root->left == NULL ){
        Node new_node = { new_data, NULL, NULL };
        root->left = &new_node; 
    } 
    else if ( root->right == NULL) {
        Node new_node = { new_data, NULL, NULL };
        root->right = &new_node;
    }

}

int main(void){

    Node left_node = {69, NULL, NULL}; 
    Node right_node = {1, NULL, NULL}; 
    
    Node root = {420, &left_node, &right_node};
    
    in_order(&root);
    return 0;
}
