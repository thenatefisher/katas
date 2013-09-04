#include "stdio.h"
#include "gtest/gtest.h"
#include "Node.h"
#include <vector>

// fwd declare prototype
int dijkstra(Dijkstra_node *origin, Dijkstra_node *dest, std::vector<Dijkstra_node*> &path);

// run dijkstra test
TEST(Dijkstra, dijkstra) {

  // create nodes
  Dijkstra_node *a = new Dijkstra_node("A");  
  Dijkstra_node *b = new Dijkstra_node("B");  
  Dijkstra_node *c = new Dijkstra_node("C");
  Dijkstra_node *d = new Dijkstra_node("D");
  Dijkstra_node *e = new Dijkstra_node("E");
  Dijkstra_node *f = new Dijkstra_node("F");

  // create mesh
  a->addEdge(b,2);
  a->addEdge(c,1);
  b->addEdge(e,1);
  c->addEdge(d,3);
  c->addEdge(e,1);
  e->addEdge(d,1);
  e->addEdge(f,6);
  d->addEdge(f,1);

  // create pointer for the calculated shortest path
  std::vector<Dijkstra_node*> path;

  // run the algo
  int cost = dijkstra(a, f, path);

  // did we get the correct cost?
  EXPECT_EQ(cost, 4);

  // did we get correct path?
  EXPECT_EQ(path.at(0)->getLabel(), "A");
  EXPECT_EQ(path.at(1)->getLabel(), "C");
  EXPECT_EQ(path.at(2)->getLabel(), "E");
  EXPECT_EQ(path.at(3)->getLabel(), "D");
  EXPECT_EQ(path.at(4)->getLabel(), "F");

}


/* Dijkstra's Algorithm
 *
 *  Given an origina and dest, find the cheapest
 *  route from origin to dest (if it exists). The route will be 
 *  entered in the specified path location and the total cost via
 *  this route returned. 
 *
 */ 
int dijkstra(Dijkstra_node *origin, Dijkstra_node *dest, std::vector<Dijkstra_node*> &path) {

  std::vector<Dijkstra_node*> nodeList;

  // convert origin and dest to dNode types
  Dijkstra_node *dn_origin, *dn_dest;

  // 1 init nodeList with origin
  dn_origin          = new Dijkstra_node();
  dn_origin->node    = origin;
  dn_origin->tcost   = 0;
  dn_origin->tfrom   = NULL;
  dn_origin->visited = false;  
  nodeList.push_back(dn_origin);

  // set search limit
  int search_count = 0, search_limit = 50;

  // keep looking for the destination
  while(search_count < search_limit) {
    
    // inc search count
    ++search_count;
    
    // 2 find node in nodeList with cheapest tcost which has not been visited, set as current node  
    Dijkstra_node *current_node = NULL;
    for (std::vector<dNode*>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
      if (!(*node)->visited && (current_node == NULL || current_node->tcost > (*node)->tcost)) {
        current_node = *node;
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
      dNode *tdestDNode = NULL;
      for (std::vector<dNode*>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
        // check if node is in nodeList, set tdestDNode
        if ((*node)->node == tdest) { tdestDNode = *node; }
      }

      // if yes, update tcost/tfrom of dNode if this tcost is lower
      if (tdestDNode != NULL) {
        
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
  dNode *cnode = dn_dest;
  do {

    // add the current node to path
    path.insert(path.begin(), cnode->node);

    for(std::vector<dNode*>::iterator node = nodeList.begin(); node != nodeList.end(); ++node) {
      if (cnode->tfrom == (*node)->node) {
        cnode = *node;
        break;
      }
    }
  
  } while(cnode->tfrom != NULL);

  // add the origin
  path.insert(path.begin(), cnode->node);

  return dn_dest->tcost;

}
