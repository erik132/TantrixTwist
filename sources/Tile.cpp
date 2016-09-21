//
// Created by Erik Soekov on 15.09.2016.
//

#include "../headers/Tile.h"

int Tile::countNr = 0;

Tile::Tile(ColorConf * colorConf1){
    Tile::countNr++;
    id = countNr;
    colorConf = colorConf1;
    resetNeighbours();
}

Tile::~Tile() {
    delete colorConf;
}

void Tile::resetNeighbours() {
    int i;
    for(i=0; i<TILE_SIDES; i++){
        neighbours[i] = NULL;
    }
}

std::string Tile::printNeighbours() {
    std::stringstream ss;
    int i;
    for(i=0; i<TILE_SIDES; i++){
        if(neighbours[i] == NULL){
            ss << "NULL ";
        }else{
            ss << neighbours[i]->getid() << " ";
        }
    }

    return ss.str();
}

int Tile::getid(){
    return id;
}

void Tile::setid(int newid){
    id = newid;
}

void Tile::setNeighbour(Tile* neighbour, int index){
    neighbours[index] = neighbour;
}

Tile* Tile::getNeighbour(int index){
    return neighbours[index];
}

std::string Tile::getSignature() {
    std::stringstream ss;
    ss << colorConf->getPieceNr();
    std::string signature(colorConf->getColors());
    signature = signature + " " + ss.str();
    return signature;
}

void Tile::rotateRight() {
    colorConf->rotateRight();
}