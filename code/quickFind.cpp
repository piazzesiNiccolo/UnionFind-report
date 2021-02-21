
#include <vector>
class QuickFind
{

private:
    int n;
    std::vector<int> elements;

public:
    QuickFind(int n) : n(n)
    {
        elements.resize(n);
    }

    void makeSet(int x)
    {
        if (x >= elements.size())
            elements.resize(x);
        elements.at(x) = x
    }
    int find(int x)
    {
        return elements[x];
    }

    void set_union(int a, int b)
    {
        for (auto i : elements)
        {
            if (i == b)
                i = a;
        }
    }
};
