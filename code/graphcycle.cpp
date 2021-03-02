#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "RankAndPathCompression.cpp"


int main(){
    int n,m;
    std::cin >> n;
    UnionFind uf = UnionFind(n);
    std::cin >> m;
    
    std::vector<std::pair<int,int>> edges;
    edges.reserve(m);
    while (m--)
    {
        int u,v;
        std::cin >> u >> v;
        edges.emplace_back(u,v);
    }
    bool cycle = false;
    for(auto edge: edges){
        if(uf.find(edge.first) == uf.find(edge.second)){
            cycle = true;
            break;
        }
        uf.set_union(edge.first,edge.second);
    }
    std::string sol = cycle ? "cycle detected" : "cycle not detected";
    std::cout << sol << std::endl;

}