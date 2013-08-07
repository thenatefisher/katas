#include "stdio.h"
#include "Node.h"

int main(int argc, char *argv[]) {

  // create nodes
  Node *a = new Node("A");
  Node *b = new Node("B");
  Node *c = new Node("C");

  // create mesh
  a->addEdge(b,3);
  a->addEdge(c,8);
  b->addEdge(c,3);

  //printf("Node Count: %i \n", Node::count());
  //printf("Edge A->C Cost: %i \n", a->getEdgeCost(c));

}
