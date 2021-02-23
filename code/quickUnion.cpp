#include <iostream>
#include <vector>
#include <numeric>
class QuickUnion
{

private:
    int n;
    std::vector<int> parents;

public:
    QuickUnion(int n) : n(n)
    {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
    }

    void makeSet(int x)
    {
        if (x >= parents.size())
            parents.resize(x);
        parents.at(x) = x;
    }
    int find(int x)
    {
        int p = x;
        while (parents[p] != p)
        {
            p = parents[p];
        }
        return p;
    }

    void set_union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        parents[pb] = pa;
    }
};