#ifndef NODE
#define NODE

class Node {

  struct Edge {
    Node *destination;
    int cost; 
  };

  // track total node count
  static int NODE_COUNT; 
 
  // number of edges
  int edgeCount; 

  // list of node outbound edge pointers
  Edge **outboundEdges;

  // name of the node
  char *label;

  public: 
    Node(char *l);
    ~Node();
    void print();
    void addEdge(Node *n, int);
    void removeEdge(Node *n);
    int getEdgeCost(Node *n);
    int getEdgeCount();
    void setLabel(char *l);
    char* getLabel();
    static int count();

  private:
    Node();
    bool isNodeInEdgeList(Node *n);

};

#endif
