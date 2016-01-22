#include <iostream>
#include <list>
#include <tuple>
#include <limits> // INF
#include <memory> // shared_ptr

const int INF = std::numeric_limits<int>::infinity();

struct Node
{
  int cost;
  std::shared_ptr<Node> prev;

  // We store arcs as pair of a weight and a pointer to the next (head) node instead of as a pair of nodes
  typedef std::tuple<int, std::shared_ptr<Node>> arc;

  std::list<arc> neighbors;
};


// Returns the cost. Passes back a reference to the winning path in the last parameter
int dijkstra(const std::list<Node>& vertices, std::shared_ptr<std::list<Node>> path) {

  auto new_path = std::make_shared<std::list<Node>>;
  return -1;
}

int main(int argc, char* argv[]) {
  std::cout << "Hello world!" << std::endl;
  Node ver{0, nullptr, {}};

  return 0;
}