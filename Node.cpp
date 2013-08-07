#include "stdio.h"
#include "Node.h"

/* Init node count */
int Node::NODE_COUNT = 0;

/* Static function to return number of total nodes instantiated */
int Node::count() {
  return NODE_COUNT;
}

/* Destructor */
Node::~Node() { 

  // destroy each edge
  for(int i = 0; i < edgeCount; i++) {
    delete [] outboundEdges[i];
  }

  // destroy edges array
  delete [] outboundEdges;

  // destroy label
  delete [] label;

  // update static node count
  Node::NODE_COUNT--;

}

/* Create a new node */
Node::Node(char *label) {

  // add a label or set default 
  try {
    if (label == 0) throw 0;
    label = label;
  } catch (int i) {
    label = "UNLABELED";
  }

  // update node count
  NODE_COUNT++;

  // init edges count
  edgeCount = 0;

  // init the edges list
  outboundEdges = new Edge*[0];

}

/* Add an edge to a node. If an edge already exists, update the cost 
 * TODO: there can only be one edge per node pair
 */
void Node::addEdge(Node *node, int cost = 0) {
  
  // the new edge
  Edge *e = new Edge();
  
  // add details and handle null ptr 
  try { 
    if (node == 0) throw 0;
    e->cost = cost;
    e->destination = node;
  } catch (int i) {
    printf("Must specify a valid node in edge creation.\n");
  }

  // create new, bigger edges list
  Edge **newEdgesList = new Edge*[edgeCount+1];

  // copy over the old edge list
  for(int i = 0; i < edgeCount; i++) {
    newEdgesList[i] = outboundEdges[i];
  }

  // add the new edge
  newEdgesList[edgeCount++] = e;

  // update edges list with the new one
  delete [] outboundEdges;
  // TODO and items
  outboundEdges = newEdgesList;
}

/* Clear an edge given the destination node */
void Node::removeEdge(Node *node) {

  // create new, smaller edges list
  Edge **newEdgesList = new Edge*[edgeCount-1];

  int newIndex = 0, removed = 0;

  for(int i = 0; i < edgeCount; i++) {

    if (outboundEdges[i]->destination != node) {
      if(newIndex < edgeCount-1) {newEdgesList[newIndex++] = outboundEdges[i];}
    } else { removed = 1; }

  }

  if (removed == 1) {

    // update edges list with the new one
    delete [] outboundEdges;
    // TODO and items
    outboundEdges = newEdgesList;

    // update edge count
    edgeCount--;

  } else {

    // delete new list items and list
    delete [] newEdgesList;
    // TODO and items

  }

}

/* return cost of an edge to specified node */
int Node::getEdgeCost(Node *node) {
  
  int cost = 0;

  for(int i = 0; i < edgeCount; i++) {
    if (outboundEdges[i]->destination == node) {
      cost = outboundEdges[i]->cost;
    }
  }  

  return cost;
}

/* return total number of node outbound edges */
int Node::getEdgeCount() {
  
  return edgeCount;

}
