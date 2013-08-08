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

TEST(Node, getEdgeCost) {

  Node *a = new Node("A");
  Node *b = new Node("B");

  a->addEdge(b,3);

  EXPECT_EQ(a->getEdgeCost(b), 3);

}

TEST(Node, getEdgeCount) {
  
  Node *a = new Node("A");
  Node *b = new Node("B");
  Node *c = new Node("C");

  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCount());
  
  a->addEdge(b, 1);
  EXPECT_EQ(1, a->getEdgeCount()) << "Duplicate edges are being added";
  
  a->addEdge(c, 1);
  EXPECT_EQ(2, a->getEdgeCount());

}

TEST(Node, addEdge) {}

TEST(Node, removeEdge) {}