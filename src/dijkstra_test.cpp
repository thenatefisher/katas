#include "stdio.h"
#include "gtest/gtest.h"
#include "Node.h"
#include <vector>

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

  std::vector<dNode*> nodeList;

  // convert origin and dest to dNode types
  dNode *dn_origin, *dn_dest;

  // 1 init nodeList with origin
  dn_origin          = new dNode();
  dn_origin->node    = origin;
  dn_origin->tcost   = 0;
  dn_origin->visited = false;  
  nodeList.push_back(dn_origin);

  // set search limit
  int search_count = 0, search_limit = 1000;

  // keep looking for the destination
  while(search_count < search_limit) {
    
    // inc search count
    ++search_count;
    
    // 2 find node in nodeList with cheapest tcost which has not been visited, set as current node  
    // TODO handle unset cost
    dNode *current_node;
    for (std::vector<dNode*>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
      if (!node->visited && (!current_node->node || current_node->tcost > node->tcost)) {
          current_node = &*node;
      }
    }

    // stop if current_node == dest
    if (current_node->node == dest) { 
      dn_dest = current_node;
      break; 
    }

    // 3 iterate over all current_node outbound edge nodes
    for (int i = 0; i < current_node->node->getEdgeCount(); i++) {

      // calculate tentative cost to each node
      if (!current_node->node->getEdgeDest(i)) { 
        // TODO throw exception 
        break;
      }

      // get destination info
      Node *tdest = current_node->node->getEdgeDest(i);
      int tcost = current_node->tcost + current_node->node->getEdgeCost(tdest);

      // check if node is in nodeList
      dNode *tdestDNode;
      for (std::vector<dNode>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
        // check if node is in nodeList, set tdestDNode
        if (node->node == tdest) { tdestDNode = &*node; }
      }

      // if yes, update tcost/tfrom of dNode if this tcost is lower
      if (tdestDNode) {

        if (tcost < tdestDNode->tcost) {
          tdestDNode->tcost = tcost;
          tdestDNode->tfrom = current_node->node;
        }

      } else {

        // if no, create dNode 
        tdestDNode          = new dNode();
        tdestDNode->node    = tdest;
        tdestDNode->tfrom   = current_node->node;
        tdestDNode->tcost   = tcost;
        tdestDNode->visited = false;

        // ...and add to nodeList
        nodeList.push_back(tdestDNode);

      }
        
    }

    // 4 mark current_node as visited, go to step 2
    current_node->visited = true;   

  }

  // output results
  return dn_dest->tcost;

}
