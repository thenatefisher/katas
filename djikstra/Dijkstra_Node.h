#ifndef DIJKSTRA_NODE
#define DIJKSTRA_NODE

class Dijkstra_node : public Node  {

  public:
    Dijkstra_node::Dijkstra_node(char *label);

  private:
    Dijkstra_node *tfrom;
    int tcost;
    bool visited;

};

#endif
