#include <iostream>
#include <vector>
#include <tuple>
#include <limits> // INF
#include <memory> // shared_ptr

const int INF = std::numeric_limits<int>::infinity();

struct Node
{
  int cost;
  std::shared_ptr<Node> prev;
  std::vector<std::tuple<int, std::shared_ptr<Node>>> neighbors;
};

typedef std::shared_ptr<Node> Node_p;

std::tuple<int, Node_p> make_neighbor(int dist, Node neighbor) {
  return std::tuple<int, Node_p>(dist, std::make_shared<Node>(neighbor));
}

// Takes graph as argument and fills it with nodes
void fill_graph(std::vector<Node> & graph) {
  // a := first node, b := second node, ...

  Node a{0, Node_p(), {}};
  graph.push_back( a ); // 1

  Node b{INF, Node_p(), {}};
  graph.push_back( b ); // 2

  Node c{INF, Node_p(), {}};
  graph.push_back( c ); // 3

  Node d{INF, Node_p(), {}};
  graph.push_back( d ); // 4

  Node e{INF, Node_p(), {}};
  graph.push_back( e ); // 5

  Node f{INF, Node_p(), {}};
  graph.push_back( f ); // 6

  Node g{INF, Node_p(), {}};
  graph.push_back( g ); // 7

  Node h{INF, Node_p(), {}};
  graph.push_back( h ); // 8

  Node i{INF, Node_p(), {}};
  graph.push_back( i ); // 9

  // Fill adjacency lists of nodes:
  a.neighbors = {make_neighbor(25, b), make_neighbor(15, c)};
  b.neighbors = {make_neighbor(10, c), make_neighbor(30, e)};
  c.neighbors = {make_neighbor(80, b), make_neighbor(30, e)};
  d.neighbors = {make_neighbor(20, e), make_neighbor(10, g)};
  e.neighbors = {make_neighbor(70, d), make_neighbor( 6, g)};
  f.neighbors = {make_neighbor(30, g), make_neighbor(37, h)};
  g.neighbors = {make_neighbor( 7, i)};
  h.neighbors = {make_neighbor(69, i)};

}

// Returns the cost. Passes back a reference to the winning path in the last argument
int dijkstra(std::vector<Node> const& nodes, std::vector<Node> & path) {

  return -1;
}

int main(int argc, char* argv[]) {
  // define graph:
  std::vector<Node> graph;
  fill_graph(graph);


  std::cout << "Hello world!" << std::endl;

  return 0;
}