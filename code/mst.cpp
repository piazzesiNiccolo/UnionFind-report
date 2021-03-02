#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "RankAndPathCompression.cpp"

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight){}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

void mst(std::vector<Edge>& edges, int nodes){
    UnionFind uf = UnionFind(nodes);
    std::sort(edges.begin(), edges.end());
    int cost = 0;
    std::vector<Edge> mst;
    for(Edge e: edges){
        if(uf.find(e.u) != uf.find(e.v)){
            cost += e.weight;
            mst.push_back(e);
            if(mst.size() == nodes - 1) break; // the mst must not have more than n-1 edges
            uf.set_union(e.u,e.v);
        }
    }
    std::cout << "\n\nThe minimum spanning tree is:\n\n";
    for(Edge e: mst) std::cout << e.u << " -- " << e.v << " with weight: " << e.weight << std::endl;
    std::cout << "total cost: " << cost << std::endl;
}
int main(){
    int n,m;
    std::cin >> n;
    
    std::cin >> m;
    std::vector<Edge> edges;
    edges.reserve(m);
    while (m--)
    {
        int u,v,w;
        std::cin >> u >> v >> w;
        edges.emplace_back(u,v,w);
    }
    mst(edges, n);

}
