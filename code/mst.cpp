struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight){}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

std::vector<Edge> mst(std::vector<Edge>& edges, int nodes){
    UnionFind uf = UnionFind(nodes);
    std::sort(edges.begin(), edges.end());
    std::vector<Edge> mst;
    for(Edge e: edges){
        if(uf.find(e.u) != uf.find(e.v)){
            mst.push_back(e);
            // the mst has n-1 edges
            if(mst.size() == nodes - 1) break; 
           
            uf.set_union(e.u,e.v);
        }
    }
    return mst;
}

