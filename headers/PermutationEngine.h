//
// Created by Erik Soekov on 15.09.2016.
//

#ifndef TASK1_1_PERMUTATIONENGINE_H
#define TASK1_1_PERMUTATIONENGINE_H

#include <vector>
#include <algorithm>
#include "Tile.h"

class PermutationEngine {
private:
    std::vector<Tile*> tiles;
    int* order;

    void attachNeighbours();
    void detachNeighbours();

public:

    ~PermutationEngine();
    void addTile(Tile* newTile);
    void resetPermut();
    bool nextPermut();
    std::string printOrder();
    std::string printNeighbours();

};


#endif //TASK1_1_PERMUTATIONENGINE_H
