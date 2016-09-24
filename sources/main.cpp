#include <iostream>
#include "../headers/Tile.h"
#include "../headers/TileConfs.h"
#include "../headers/PermutationEngine.h"


int main() {
    ColorConf * colorConf;
    PermutationEngine engine;
    Tile* tile;

    colorConf = new ColorConf(TANTRIX01, 1);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX02, 2);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX03, 3);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    /*colorConf = new ColorConf(TANTRIX04, 4);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX05, 5);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX06, 6);
    tile = new Tile(colorConf);
    engine.addTile(tile);*/


    std::cout << "Hello, World!" << std::endl;
    engine.resetPermut();
    std::cout<< engine.printOrder() << std::endl;
    std::cout << engine.printNeighbours() << std::endl;
    std::cout << "victory count: " << engine.testPermut() << "\n";

    /*while(engine.nextPermut()) {
        std::cout << engine.printOrder() << std::endl;
        std::cout << engine.printNeighbours() << std::endl;
    }*/

    /*std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;*/
    return 0;
}