#include <stdio.h>
#include <vector>
#include <math.h>
#include <sys/time.h>

using namespace std;

template<class D>
class LL {
    public: 
        LL* head;
        D data;
};


LL<int>* reverse(LL<int>* l);

int main() {

    srand(time(NULL));
    LL<int> *head;
    int p;

    for(int l = 0; l < 12; l++) {

        p = rand() % 1000 + 1;
        
        LL<int> *node = new LL<int>();
        node->data = l;
        node->head = head;
        head = node;

    }
    
    head = reverse(head);
    
    LL<int> *n = head;
    printf("%i ", n->data);
    while(n->head != NULL) {

        n = n->head;
        printf("%i ", n->data);
        
    }
    printf("\n");

}

LL<int>* reverse(LL<int>* listHead) {
    
    if (listHead == NULL) return NULL;

    LL<int>* a; 
    LL<int>* b; 
    LL<int>* c;

    a = listHead;
    b = a->head;
    a->head = NULL;
    c = b->head;
    b->head = a;
    
    while (c != NULL) {

        a = b;
        b = c;
        c = c->head;
        
        b->head = a;
 
    }
    
    return b;

}





