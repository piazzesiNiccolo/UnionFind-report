#include<iostream>
#include <vector>
#include <functional>
#include "RankAndPathCompression.cpp"


void lca(std::vector<std::vector<int>> &tree,std::vector<std::vector<int>> &queries){
    std::vector<int> ancestor(tree.size());
    std::vector<bool> visited(tree.size(),false);
    UnionFind uf(tree.size());
    std::function<void(int)> dfs = [&](int v){
        visited[v] = true;
        ancestor[v] = v;
        for(int u : tree[v]){
            if (!visited[u])
            {
                dfs(u);
                uf.set_union(v, u);
                ancestor[uf.find(v)] = v;
            }
            
        }
        for (int q : queries[v])
        {
            if(visited[q]){
                std::cout << "lca of "
                 << v << " and " << " q " << " is " 
                << ancestor[uf.find(q)] << std::endl;
            }
        }
        
    };
    dfs(0);
}
