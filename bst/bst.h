#ifndef nBST_H_
#define nBST_H_

using namespace std;

template<class D>
struct Node {
    D data;
    Node* left;
    Node* right;
};

template<class T>
class nBST {
    
    public: 
        nBST();
        void insert(T);
        void printInOrder();
        void remove(T);
        void rremove(T, Node<T>*);
        void nBST<T>::print();
    
    private: 
        Node<T>* root;
        void nBST<T>::printInOrder(Node<T>* r);
        void nBST<T>::printPreOrder(Node<T>* r);
        
};

#endif


