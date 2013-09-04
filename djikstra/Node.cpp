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

  // TODO destroy each edge
  // destroy edges array
  delete [] outboundEdges;

  // destroy label
  delete [] label;

  // update static node count
  Node::NODE_COUNT--;

}

/* Create a new node */
Node::Node(char *setlabel) {
  
  // add a label or set default 
  try {
    if (setlabel == 0) throw 0;
    label = setlabel;
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

/* private helper method to find if a given
 * node is already in an outbound edge
 */
bool Node::isNodeInEdgeList(Node *node) {
  
  if (node == 0) {
    // TODO throw exception
  }
  
  bool inList = false; 

  for(int i = 0; i < edgeCount; i++) {
    if (outboundEdges[i]->destination == node) {
      inList = true;
    } 
  }

  return inList;
  
}

/* Add an edge to a node. If an edge already exists, update the cost 
 * there can only be one edge per node pair
 */
void Node::addEdge(Node *node, int cost = 0) {
  
  if (node == 0) {
    // TODO throw exception
  }

  // determine if node already exists as an edge
  if (!isNodeInEdgeList(node)) {

    // the new edge
    Edge *e = new Edge();
    
    // add details and handle null ptr 
    e->cost = cost;
    e->destination = node;

    // create new, bigger edges list
    Edge **newEdgesList = new Edge*[edgeCount+1];

    // copy over the old edge list
    for(int i = 0; i < edgeCount; i++) {
      newEdgesList[i] = outboundEdges[i];
    }

    // add the new edge
    newEdgesList[edgeCount++] = e;

    // update edges list with the new one
    // TODO destroy each edge
    delete [] outboundEdges;
    outboundEdges = newEdgesList;

  } else {

    // if node was already in list, just update its cost
    for(int i = 0; i < edgeCount; i++) {
      if (outboundEdges[i]->destination == node) {
        outboundEdges[i]->cost = cost;
      }
    }

  }

}

/* Clear an edge given the destination node */
void Node::removeEdge(Node *node) {

  if (node == 0 || !isNodeInEdgeList(node)) {
    // TODO throw exception
  }

  // create new, smaller edges list
  Edge **newEdgesList = new Edge*[edgeCount-1];

  int newIndex = 0, removed = 0;

  for(int i = 0; i < edgeCount; i++) {

    if (outboundEdges[i]->destination != node) {
      if(newIndex < edgeCount-1) {
        newEdgesList[newIndex++] = outboundEdges[i];
      }
    } else { removed = 1; }

  }

  if (removed == 1) {

    // update edges list with the new one
    // TODO destroy each edge
    delete [] outboundEdges;
    outboundEdges = newEdgesList;

    // update edge count
    edgeCount--;

  } else {

    // delete new list items and list
    // TODO destroy each edge
    delete [] newEdgesList;

  }

}

/* return cost of an edge to specified node */
int Node::getEdgeCost(Node *node) {
  
  if (node == 0 || !isNodeInEdgeList(node)) {
    // TODO throw exception
  }

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

/* set label of a node */
void Node::setLabel(char *setlabel) {

  if (setlabel == 0) {
    // TODO throw exception
  }

  // add a label or set default 
  label = setlabel;

}

/* return node label */
char* Node::getLabel() {

  return label;

}

/* pretty print the node and its properties */
void Node::print() {

  printf("%i Edge(s) from node %s\n", edgeCount, label);
  for(int i = 0; i < edgeCount; i++) {
    printf("  ---- (cost: %i) ---> %s\n", 
      outboundEdges[i]->cost, 
      outboundEdges[i]->destination->getLabel());
  }

}

/* get destination node at edge i */
Node* Node::getEdgeDest(int i) {
  return outboundEdges[i]->destination;
}
