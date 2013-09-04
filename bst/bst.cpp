#include <stdio.h>
#include "bst.h"

template<class T>
nBST<T>::nBST() {
    root = NULL; 
}

template<class T>
void nBST<T>::insert(T inputData) {

    if (root == NULL) {
    
        root = new Node<T>();
        root->data = inputData;
    
    } else {
    
        bool inserted = false;
        
        Node<T>* cursor = root;
        Node<T>* inputNode = new Node<T>;
        inputNode->data = inputData;
        inputNode->left = NULL;
        inputNode->right = NULL;
        
        while(!inserted) {
            if (inputNode->data < cursor->data) {
                
                if (cursor->left != NULL) {
                    // move cursor left
                    cursor = cursor->left;
                } else {
                    // insert and finish
                    cursor->left = inputNode;
                    inserted = true;
                }
                
            } else {
                if (cursor->right != NULL) {
                    // move cursor right
                    cursor = cursor->right;
                } else {
                    // insert and finish
                    cursor->right = inputNode;
                    inserted = true;
                }
            }
        }
    
    }

}

template<class T>
void nBST<T>::print() {

    printf("INORDER: \t");
    printInOrder(root);
    printf("\n");
    
    printf("PREORDER: \t");
    printPreOrder(root);
    printf("\n");
    
}

template<class T>
void nBST<T>::printInOrder(Node<T>* r) {
    
    if (r != NULL) {
    
        // left
        printInOrder(r->left);
        
        // root
        printf("%i ", r->data);
        
        // right
        printInOrder(r->right);
        
    }

}

template<class T>
void nBST<T>::printPreOrder(Node<T>* r) {
    
    if (r != NULL) {
    
        // root
        printf("%i ", r->data);
        
        // left
        printPreOrder(r->left);
                
        // right
        printPreOrder(r->right);
        
    }

}

template<class T>
void nBST<T>::remove(T itemValueToRemove) {
    
    // handle root == target
    
    // else walk rest of tree
    rremove(itemValueToRemove, root);
    
}

template<class T>
void nBST<T>::rremove(T targetValue, Node<T>* p) {

    if (p != NULL) {
    
        // look at children
        Node<T>* target = NULL;
        if (p->right->data == targetValue) {
            target = p->right;
        } else if (p->left->data == targetValue) {
            target = p->left;
        }
        
        if (target != NULL) {
        
            // 1) remove target if it is a leaf
            if (target->right == NULL && target->left == NULL) {
                // clear pointer from parent
                if (p->left == target) {
                    p->left = NULL;
                } else {
                    p->right = NULL;
                }
                // delete object
                delete [] target;
            }
        
            // 2)
            
            // 3)
        
        } else {
        
            // left
            rremove(targetValue, p->left);
                    
            // right
            rremove(targetValue, p->right);
            
        }
        
    }
    
}

int main() {

    nBST<int> mytree;
    
    mytree.insert(10);
    mytree.insert(5);
    mytree.insert(15);
    mytree.insert(0);
    mytree.insert(20);
    mytree.insert(16);
    mytree.insert(25);
    
    mytree.print();
    
    int target = 20;
    mytree.remove(target);
    printf("- REMOVED %i -\n", target);
    
    mytree.print();

}
