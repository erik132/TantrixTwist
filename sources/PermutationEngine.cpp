//
// Created by Erik Soekov on 15.09.2016.
//

#include "../headers/PermutationEngine.h"

void PermutationEngine::addTile(Tile *newTile) {
    tiles.push_back(newTile);
}

void PermutationEngine::resetPermut() {
    int i;
    int orderSize = tiles.size();

    detachNeighbours();
    delete[] order;
    order = new int[orderSize];
    for(i=0; i<orderSize; i++){
        order[i] = i;
    }
    std::sort(order, order + orderSize);
    attachNeighbours();
}

bool PermutationEngine::nextPermut() {
    int orderSize =  tiles.size();
    bool result;

    detachNeighbours();
    result = std::next_permutation(order, order + orderSize);
    if(result){
        attachNeighbours();
    }
    return  result;
}

PermutationEngine::~PermutationEngine() {
    int tilescount = tiles.size(), i;

    delete[] order;
    for( i=0; i< tilescount; i++){
        delete tiles[i];
    }
    tiles.clear();
}

std::string PermutationEngine::printNeighbours() {
    std::stringstream ss;
    int i, tileCount = tiles.size();
    for(i=0; i<tileCount; i++){
        ss << tiles[order[i]]->getid() << " neighbours: " << tiles[order[i]]->printNeighbours() << "\n";
    }
    return ss.str();
}

void PermutationEngine::attachNeighbours() {
    int* prevLine = NULL;
    int* thisLine = NULL;
    int* nextLine = NULL;
    int prevCount = 0, thisCount = 0, nextCount = 0;
    int i, totalTiles = tiles.size();
    int currentTiles = 1;
    Tile* thisTile;

    thisLine = order;
    thisCount = 1;
    nextLine = thisLine + thisCount;
    nextCount = thisCount + 1;

    do {

        for (i = 0; i < thisCount; i++) {
            thisTile = tiles[thisLine[i]];

            if (prevLine != NULL) {
                if (i > 0) {
                    thisTile->setNeighbour(tiles[prevLine[i - 1]], 5);
                }
                if (i < (thisCount - 1)) {
                    thisTile->setNeighbour(tiles[prevLine[i]], 0);
                }
            }

            if (i > 0) {
                thisTile->setNeighbour(tiles[thisLine[i - 1]], 4);
            }
            if (i < (thisCount - 1)) {
                thisTile->setNeighbour(tiles[thisLine[i + 1]], 1);
            }

            if (nextLine != NULL) {
                thisTile->setNeighbour(tiles[nextLine[i]], 3);
                thisTile->setNeighbour(tiles[nextLine[i + 1]], 2);
            }
        }
        prevLine = thisLine;
        prevCount = thisCount;
        thisLine = nextLine;
        thisCount = nextCount;
        nextLine = thisLine + thisCount;
        nextCount = thisCount + 1;

        currentTiles = currentTiles + thisCount;
        if(currentTiles == totalTiles){
            nextLine = NULL;
        }
        //std::cout << "passed loop " << currentTiles << std::endl;
    }while( currentTiles <= totalTiles);

}

void PermutationEngine::detachNeighbours() {
    int tileCount = tiles.size();
    int i;

    for(i=0; i<tileCount; i++){
        tiles[i]->resetNeighbours();
    }
}

std::string PermutationEngine::printOrder() {
    std::stringstream ss;
    int orderCount = tiles.size();
    int i;

    for(i=0; i<orderCount; i++){
        ss << tiles[order[i]]->getid() << " ";
    }

    return ss.str();
}

int PermutationEngine::testPermut() {
    int el1Truns, i;
    int tileCount = tiles.size();
    int victoryCount = 0;

    for(el1Truns = 0; el1Truns < TILE_SIDES; el1Truns++){
        tiles[order[0]]->rotateRight();
        testRec(1,&victoryCount);
    }

    return victoryCount;
}

void PermutationEngine::testRec(int index, int *victoryCount) {
    Tile* tile = tiles[order[index]];
    int i;

    for(i=0; i<2; i++) {
        tile->alignTo0();
        if (tile->checkColors()) {
            if (index != (tiles.size() - 1)) {
                testRec(index + 1, victoryCount);
            }else{
                *victoryCount = *victoryCount + 1;
                std::cout << printTileState() << std::endl;
            }
        }
    }
}

std::string PermutationEngine::printTileState() {
    std::stringstream ss;
    int i, tileCount = tiles.size();
    for(i=0; i<tileCount; i++) {
        ss << tiles[order[i]]->getSignature() << "\n";
    }

    return ss.str();
}
