#include <iostream>
#include <vector>
using namespace std;

const int mxN = 1100;
vector<int> adj[mxN];     // adj[i] is the list of neigbors of i
bool seen[mxN];           // seen[i] = true if my DFS has seen vertex i
int parent[mxN];           // parent[i] is the parent of node i in my DFS tree

void dfs(int v){
  seen[v] = 1;
  cout << v << " ";
  for(int i : adj[v]){
    if(!seen[i]){
      parent[i] = v;
      dfs(i);
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
}
