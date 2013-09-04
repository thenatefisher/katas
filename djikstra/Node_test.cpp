#include "gtest/gtest.h"
#include "Node.h"

TEST(Node, count) {

  // create nodes
  Node *a = new Node("A");
  EXPECT_EQ(Node::count(), 1);
  
  Node *b = new Node("B");
  EXPECT_EQ(Node::count(), 2);
  
  Node *c = new Node("C");
  EXPECT_EQ(Node::count(), 3);

}

TEST(Node, getEdgeDest) {

  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b,3);
  Node* dest = a->getEdgeDest(0);
  EXPECT_EQ(dest, b);

}

TEST(Node, getEdgeCost) {

  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b,3);

  EXPECT_EQ(a->getEdgeCost(b), 3);

}

TEST(Node, getEdgeCount) {
  
  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCount());

  b->addEdge(a, 1);
  EXPECT_EQ(1, b->getEdgeCount());

}

TEST(Node, noDuplicateEdges) {
  
  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCount());
  
  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCount()) << "Duplicate edges are being added";

}

TEST(Node, reAddingEdgeUpdatesCost) {
  
  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCost(b));
  
  a->addEdge(b, 2);
  EXPECT_EQ(2, a->getEdgeCost(b)) << "Edge cost should be updated";

}

TEST(Node, addEdge) {

  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b, 1);

  EXPECT_EQ(1, a->getEdgeCount());

}

TEST(Node, removeEdge) {

  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b, 1);

  EXPECT_EQ(1, a->getEdgeCount());

  a->removeEdge(b);

  EXPECT_EQ(0, a->getEdgeCount());

}

TEST(Node, setLabel) {

  Node *a = new Node("A");

  a->setLabel("NEWLABEL");

  EXPECT_EQ(a->getLabel(), "NEWLABEL");

}

TEST(Node, getLabel) {

  Node *a = new Node("A");

  EXPECT_EQ(a->getLabel(), "A");

}

