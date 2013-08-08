#include "stdio.h"
#include "gtest/gtest.h"
#include "Node.h"
#include "vector.h"

// fwd declare prototype
int dijkstra(Node *origin, Node *dest, Node **path);

// run dijkstra test
TEST(Dijkstra, dijkstra) {

  // create nodes
  Node *a = new Node("A");  
  Node *b = new Node("B");  
  Node *c = new Node("C");
  Node *d = new Node("D");
  Node *e = new Node("E");
  Node *f = new Node("F");

  // create mesh
  a->addEdge(b,2);
  a->addEdge(c,5);
  b->addEdge(e,1);
  c->addEdge(d,3);
  c->addEdge(e,1);
  e->addEdge(d,1);
  e->addEdge(f,6);
  d->addEdge(f,1);

  // create pointer for the calculated shortest path
  Node **path;

  // run the algo
  int cost = dijkstra(a, f, path);

  // did we get the correct cost?
  EXPECT_EQ(cost, 5);

}


/* augemnting the node class a bit for the algorithm */
struct dNode {
    Node *node;
    Node *tfrom;
    int tcost;
    bool visited;
  };
  

/* Dijkstra's Algorithm
 *
 *  Given an origina and dest, find the cheapest
 *  route from origin to dest (if it exists). The route will be 
 *  entered in the specified path location and the total cost via
 *  this route returned. 
 *
 */ 
int dijkstra(Node *origin, Node *dest, Node **path) {

  std::vector<dNode> nodeList;

  // convert origin and dest to dNode types
  sNode dn_origin, dn_dest;
  dn_origin.node = origin;
  dn_dest.node = dest;

  // 1 init nodeList with origin
  nodeList.push_back(dn_origin);

  // 2 find node in nodeList with cheapest tcost, set as current node 
  dNode cnode;
  for (vector<dNode>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
      if (!cnode) {
        cnode = node;
      } else if () {
        //
      } else if (cnode->tcost > node->tcost) {
        cnode = node;
      }
  }


    // stop if cnode == dest

  // 3 iterate over all cnode outbound edge nodes

    // calculate tentative cost to each node

    // check if node is in nodeList

      // if yes, update tcost/tfrom of dNode if this tcost is lower

      // if no, create dNode and add to observedList

  // 4 mark cnode as visited, go to step 2


  // output results
  int cost_to_dest;
  return cost_to_dest;

}
