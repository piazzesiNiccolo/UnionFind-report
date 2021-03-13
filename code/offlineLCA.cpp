#include <iostream>
#include <vector>
#include <functional>
#include "RankAndPathCompression.cpp"

struct Lca
{
    int u, v, ancestor;
    Lca(int u, int v, int ancestor) : u(u), v(v), ancestor(ancestor) {}
};
std::vector<Lca> lca(std::vector<std::vector<int>> &tree, 
                    std::vector<std::vector<int>> &queries)
{
    std::vector<int> ancestor(tree.size());
    std::vector<bool> visited(tree.size(), false);
    std::vector<Lca> lca;
    UnionFind uf(tree.size());
    std::function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        ancestor[v] = v;
        for (int u : tree[v])
        {
            if (!visited[u])
            {
                dfs(u);
                uf.set_union(v, u);
                ancestor[uf.find(v)] = v;
            }
        }
        for (int q : queries[v])
        {
            if (visited[q])
            {
                lca.emplace_back(v, q, uf.find(q));
            }
        }
    };
    dfs(0);
    return lca;
}
