#include <iostream>
#include <vector>
#include <numeric>
class UnionFind
{

private:
    int n;
    std::vector<int> parents;
    std::vector<int> ranks;

public:
    UnionFind(int n) : n(n)
    {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
        ranks.resize(n);
    }

    void makeSet(int x)
    {
        if (x >= parents.size())
            parents.resize(x);
        parents.at(x) = x;
        ranks.at(x) = 0;
    }
    int find(int x)
    {
        int p = x;
        if(parents[p] != p) parents[p] = find(parents[p]);
        return parents[p];
    }

    void set_union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if(ranks[pa] < ranks[pb]) parents[pa] = pb;
        else if (ranks[pa] < ranks[pb]) parents[pb] = pa;
        else{
            parents[pb] = pa;
            ranks[pa]++;
        }
        
    }
};