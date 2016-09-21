//
// Created by Erik Soekov on 15.09.2016.
//


#include "../headers/ColorConf.h"

ColorConf::ColorConf(std::string newColors, int pieceNr) {
    this->pieceNr = pieceNr;
    colors = newColors;
    rotation = 0;
}

int ColorConf::getPieceNr() {
    return pieceNr;
}

std::string ColorConf::getColors() {
    return colors;
}

void ColorConf::rotateRight() {
    char tempchar;
    int i;

    tempchar = colors[TILE_SIDES - 1];
    for(i=TILE_SIDES - 1; i > 0; i--){
        colors[i] = colors[i -1];
    }
    colors[0] = tempchar;
    rotation++;
    if(rotation == TILE_SIDES){
        rotation = 0;
    }

}

