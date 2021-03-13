#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "RankAndPathCompression.cpp"

struct Edge {
    int u, v;

    Edge(int u, int v, int weight) : u(u), v(v){}
    
};


bool graphcycle(std::vector<Edge> edges, int nodes){
    
    UnionFind uf = UnionFind(nodes);
    bool cycle = false;
    for(auto edge: edges){
        if(uf.find(edge.u) == uf.find(edge.v)){
            cycle = true;
            break;
        }
        uf.set_union(edge.u,edge.v);
    }
    return cycle;

}