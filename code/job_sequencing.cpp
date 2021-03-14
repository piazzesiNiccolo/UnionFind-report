#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "RankAndPathCompression.cpp"

struct Job
{
    std::string id;
    int profit, deadline;
    Job(std::string id, int profit, int deadline) : 
    id(id), profit(profit), deadline(deadline) {}
};

std::vector<Job> jobSequencing(std::vector<Job> jobs)
{
    std::sort(jobs.begin(), jobs.end(), 
            [](Job j1, Job j2) { return j1.profit > j2.profit; });
    
    int maxD = std::max_element(jobs.begin(), jobs.end(), 
            [](Job j1) { return j1.deadline; })->deadline;
    
    std::vector<Job> sol;
    UnionFind uf(maxD + 1);
    for (Job j : jobs)
    {
        int slot = uf.find(j.deadline);
        if (slot > 0)
        {
            uf.set_union(slot - 1, slot);
            sol.push_back(j);
        }
    }

    return sol;
}