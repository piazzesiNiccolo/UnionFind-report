#include <iostream>
#include <vector>
template<typename T> class UnionFInd{

private:
    std::vector<T> elements;

public:

    void makeSet(T x){
        elements.push_back(x);
    }

    T find( T x){
        return elements[x];
    }

    void union(T a, T b){
        elemnts[b] = a;
    }
};
int main(int argc, char const *argv[])
{
    std::cout << "hello" << std::endl;
    return 0;
}
