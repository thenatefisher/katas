#include "stdio.h"
#include "Node.h"

// int argc, char *argv[]
int main() {

  // create nodes
  Node *a = new Node("A");
  Node *b = new Node("B");

  // create mesh
  a->addEdge(b,3);

}
