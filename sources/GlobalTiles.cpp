//
// Created by Erik on 24.09.2016.
//

#include "../headers/GlobalTiles.h"

std::string GlobalTiles::getConf(int index) {

    switch (index){
        case 1:
            return "ryybrb";
        case 2:
            return "byybrr";
        case 3:
            return "yrrbby";
        case 4:
            return "byrbry";
        case 5:
            return "ryyrbb";
        case 6:
            return "yrbybr";
        case 7:
            return "rbbyry";
        case 8:
            return "ybbryr";
        case 9:
            return "rybrby";
        case 10:
            return "byyrbr";
        case 11:
            return "yrrbyb";
        case 12:
            return "brryby";
        case 13:
            return "ybbyrr";
        case 14:
            return "ryybbr";
        case 15:
            return "rggryy";
        case 16:
            return "yggyrr";
        default:
            return "ryybrb";
    }
    return "ryybrb";
}
