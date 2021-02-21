#include <iostream>
#include <vector>
class QuickUnion
{

private:
    int n;
    std::vector<int> parents;

public:
    QuickUnion(int n) : n(n)
    {
        parents.resize(n);
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