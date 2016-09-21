//
// Created by Erik Soekov on 15.09.2016.
//

#ifndef TASK1_1_COLORCONF_H
#define TASK1_1_COLORCONF_H

#include <string>
#include "TileConfs.h"


class ColorConf {
private:
    std::string colors;
    int pieceNr;
    int rotation;

public:
    ColorConf(std::string newColors, int pieceNr);
    int getPieceNr();

    std::string getColors();
    void rotateRight();

};


#endif //TASK1_1_COLORCONF_H
