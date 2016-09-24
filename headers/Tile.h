//
// Created by Erik Soekov on 15.09.2016.
//

#ifndef TASK1_1_TILE_H
#define TASK1_1_TILE_H

#include <iostream>
#include <sstream>
#include <string>
#include "ColorConf.h"
#include "TileConfs.h"



class Tile {
private:
    static int countNr;
    int id;
    Tile* neighbours[TILE_SIDES];
    ColorConf * colorConf;

public:


    Tile(ColorConf * colorConf1);
    ~Tile();
    friend std::ostream &operator<<( std::ostream &output, Tile &t){
        output << t.getid() << " " << t.getSignature();
        return output;
    }
    int getid();
    void setid(int newid);
    void setNeighbour(Tile* neighbour, int index);
    Tile* getNeighbour(int index);
    std::string getSignature();
    void rotateRight();
    void resetNeighbours();
    std::string printNeighbours();
    bool alignTo0();
    bool checkColors();

    char getNeighbourColor(int neighbourSide);


};


#endif //TASK1_1_TILE_H
