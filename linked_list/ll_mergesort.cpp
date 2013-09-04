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
    
    // do something with list head
    
    LL<int> *n = head;
    printf("%i ", n->data);
    while(n->head != NULL) {

        n = n->head;
        printf("%i ", n->data);
        
    }
    printf("\n");

}






