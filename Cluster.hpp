#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include <vector>

class Cluster {
    public:
    std::vector<int> new_cluster;
    std::vector<int> prev_additions;
    std::vector<int> new_additions;
    int new_pSpin_cluster;

    double avg_size;
    double avg_flipped_size;
};

#endif