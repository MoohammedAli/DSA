#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <cassert>
#define DEBUG false
#define ll long long
#define OJ_DEBUG
using namespace std;



class Graph {
private:
  int V;
  vector<vector<int> > adj;

public:
  Graph(int v){
    V = v;
    adj.resize(V);
  }
  void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void printAdjacenyList(){
    for(int i=0;i<V;i++){
      cout << i << " -> ";
      for(int j : adj[i]){
        cout << j << " ";
      }
      cout << endl;
    }
  }
};

int main(){
   Graph g(5); // 5 vertices (0 to 4)

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjacenyList();

    return 0;
}
