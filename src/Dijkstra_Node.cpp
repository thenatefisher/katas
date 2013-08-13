#include "stdio.h"
#include "Dijkstra_node.h"

Dijkstra_node::Dijkstra_node(char *label) {
  tcost = 0;
  visited = false;
  super(label);
}