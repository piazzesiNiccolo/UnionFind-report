#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
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
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void set_union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (ranks[a] < ranks[b])
                std::swap(a, b);
            parents[b] = a;
            if (ranks[a] == ranks[b])
                ranks[a]++;
        }
    }
};