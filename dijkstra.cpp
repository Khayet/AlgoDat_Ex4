#include <iostream>
#include <vector>
#include <tuple>
#include <limits> // max()
#include <memory> // shared_ptr

// Not truly infinite of course, because integers are always finite in C++, but larger than any input value
const int INF = std::numeric_limits<int>::max();

struct Node
{
  Node(int c, std::shared_ptr<Node> p, std::vector<std::tuple<int, std::shared_ptr<Node>>> n) :
    cost(c), prev(p), neighbors(n) {}

  Node(int c) : cost(c), prev(std::shared_ptr<Node>()), neighbors({}) {}

  int cost; // The cost to reach the node
  std::shared_ptr<Node> prev; // The node that comes in front of this one in the path
  std::vector<std::tuple<int, std::shared_ptr<Node>>> neighbors; // The nodes that are visitable from this one in one step
};


typedef std::shared_ptr<Node> Node_p;
typedef std::vector<std::tuple<int, std::shared_ptr<Node>>> Arc;


// Returns the cost. Passes back a reference to the winning path in the last argument
int dijkstra(std::vector<Node_p> const& nodes, Node_p first_element, Node_p last_element, std::vector<Node> & path) {
  std::vector<Node_p> not_visited{nodes};
  int sum_cost = 0;

  // int current_node = 0;
  Node_p cur = nodes.front();
  std::vector<Arc> visitable;

  while (!not_visited.empty()) {
    // cur = nodes[current_node];
    visitable.clear();

    for (int i=0; i < not_visited.size(); ++i) {
      for (int j=0; j < cur->neighbors.size(); ++j) {
        auto cur_neighbor = std::get<1>(cur->neighbors[j]);
        if ( not_visited[i] == cur_neighbor ) { // If one of the not visited nodes is in the neighborhood
          visitable.emplace_back(cur->neighbors[j]);
        }
      }
    }

    // Choose next node:
    if (!visitable.empty()) {
      auto visit = visitable.front();
      int smallest_cost = INF;
      int visitable_cost, cost_to_visit;
      Node_p foo;

      for (int i=0; i < visitable.size(); ++i) {
        std::tie(std::ignore, foo) = visitable[i];
        visitable_cost = foo->cost;
        cost_to_visit = (cur->cost + std::get<0>(visitable[i]));

        // Update cost for visitable nodes:
        if (cost_to_visit < visitable_cost) {
          (std::get<1>(visitable[i]))->cost = cost_to_visit;
        }

        // Choose next destination:
        if (cost_to_visit < smallest_cost) {
          visit = visitable[i];
        }
      }
    }

    // Go to next node:
    not_visited.remove(cur);
    sum_cost += std::get<1>(visit)->cost;
    std::get<1>(visit)->prev = cur;
    cur = std::get<1>(visit);
  }

  // Build path by tracing back:
  Node_p t = last_element;
  while (t != first_element()) {
    path.push_front(*t);
    t = t->prev;
  }

  return -1;
}

int main(int argc, char* argv[]) {
  // define graph:
  std::vector<Node_p> graph;

  // a := first node, b := second node, ...
  auto a = std::make_shared<Node>(Node{0, Node_p(), {} });
  auto b = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto c = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto d = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto e = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto f = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto g = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto h = std::make_shared<Node>(Node{INF, Node_p(), {} });
  auto i = std::make_shared<Node>(Node{INF, Node_p(), {} });

  // Fill adjacency lists of nodes:
  (a->neighbors).push_back(std::tuple<int, Node_p>(25, b)); (a->neighbors).push_back(std::tuple<int, Node_p>(15, c));
  (b->neighbors).push_back(std::tuple<int, Node_p>(10, c)); (b->neighbors).push_back(std::tuple<int, Node_p>(30, e));
  (c->neighbors).push_back(std::tuple<int, Node_p>(80, b)); (c->neighbors).push_back(std::tuple<int, Node_p>(30, e));
  (d->neighbors).push_back(std::tuple<int, Node_p>(20, e)); (d->neighbors).push_back(std::tuple<int, Node_p>(10, g));
  (e->neighbors).push_back(std::tuple<int, Node_p>(70, d)); (e->neighbors).push_back(std::tuple<int, Node_p>( 6, g));
  (f->neighbors).push_back(std::tuple<int, Node_p>(30, g)); (f->neighbors).push_back(std::tuple<int, Node_p>(37, h));
  (g->neighbors).push_back(std::tuple<int, Node_p>( 7, i));
  (h->neighbors).push_back(std::tuple<int, Node_p>(69, i));

  graph.push_back( a ); // 1
  graph.push_back( b ); // 2
  graph.push_back( c ); // 3
  graph.push_back( d ); // 4
  graph.push_back( e ); // 5
  graph.push_back( f ); // 6
  graph.push_back( g ); // 7
  graph.push_back( h ); // 8
  graph.push_back( i ); // 9

  std::vector<Node> winning_path;
  std::cout << "cost: " << dijkstra(graph, a, i, winning_path) << std::endl;

  std::cout << "Hello world!" << std::endl;

  return 0;
}