#include <iostream>
#include <time.h>
#include "../headers/Tile.h"
#include "../headers/TileConfs.h"
#include "../headers/PermutationEngine.h"


int main() {
    ColorConf * colorConf;
    PermutationEngine engine;
    Tile* tile;
    time_t timer;
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

    //level 5
    colorConf = new ColorConf(TANTRIX11, 11);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX12, 12);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX13, 13);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX14, 14);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    colorConf = new ColorConf(TANTRIX15, 15);
    tile = new Tile(colorConf);
    engine.addTile(tile);

    timer = time(NULL);
    engine.resetPermut();
    std::cout<< engine.printOrder() << std::endl;
    std::cout << engine.printNeighbours() << std::endl;
    std::cout << "victory count: " << engine.testPermut() << "\n";

     do{

        vicotryCount = engine.testPermut();
        if(vicotryCount != 0){
            /*std::cout << engine.printOrder() << std::endl;
            std::cout << engine.printNeighbours() << std::endl;
            std::cout << "victory count: " << vicotryCount << "\n";*/
            totalWins = totalWins + vicotryCount;
        }
        if(totalWins >  208123123){

            break;
        }
    }while(engine.nextPermut());
    std::cout<<"total wins " << totalWins << std::endl;
    std::cout<<"ran " << time(NULL) - timer << " seconds"<< std::endl;
    return 0;
}