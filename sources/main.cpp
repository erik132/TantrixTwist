#include <iostream>
#include "../headers/Tile.h"
#include "../headers/TileConfs.h"
#include "../headers/PermutationEngine.h"


int main() {
    ColorConf * colorConf;
    PermutationEngine engine;
    Tile* tile;
    int vicotryCount;
    int totalWins = 0;

    colorConf = new ColorConf(TANTRIX01, 1);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    //level 2
    colorConf = new ColorConf(TANTRIX02, 2);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX03, 3);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    //level 3
    colorConf = new ColorConf(TANTRIX04, 4);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX05, 5);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX06, 6);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    //level 4
    colorConf = new ColorConf(TANTRIX07, 7);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX08, 8);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX09, 9);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX10, 10);
    tile = new Tile(colorConf);
    engine.addTile(tile);


    engine.resetPermut();
    /*std::cout<< engine.printOrder() << std::endl;
    std::cout << engine.printNeighbours() << std::endl;
    std::cout << "victory count: " << engine.testPermut() << "\n";*/

     do{

        vicotryCount = engine.testPermut();
        if(vicotryCount != 0){
            std::cout << engine.printOrder() << std::endl;
            std::cout << engine.printNeighbours() << std::endl;
            std::cout << "victory count: " << vicotryCount << "\n";
            totalWins = totalWins + vicotryCount;
        }
        if(totalWins > 10){

            break;
        }
    }while(engine.nextPermut());
    std::cout<<"total wins " << totalWins;
    return 0;
}