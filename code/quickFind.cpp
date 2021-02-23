
#include <vector>
#include<numeric>
class QuickFind
{

private:
    int n;
    std::vector<int> parents;

public:
    QuickFind(int n) : n(n)
    {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
    }

    void makeSet(int x)
    {
        if (x >= parents.size())
            parents.resize(x);
        parents.at(x) = x
    }
    int find(int x)
    {
        return parents[x];
    }

    void set_union(int a, int b)
    {
        for (auto i : parents)
        {
            if (i == b)
                i = a;
        }
    }
};
