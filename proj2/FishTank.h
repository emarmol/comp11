/*Name: Erika Marmol
Date: 4/7/14
Purpose: to create an animated fishtank
Discussed ideas with: Emma Coltoff, Jessica Morales. Ambika Jayakumar
 */

// Defines the class FishTank, includes the fish.h file, and
// is not created if the FishTank class has already been created
#ifndef FISHTANK_H
#define FISHTANK_H
#include <string>
#include "Fish.h"
using std::string;

class FishTank
{
public:

    FishTank();
    FishTank(int hgt, int wid);
    void setHeight(int hgt);
    void setWidth(int wid);
    int getHeight();
    int getWidth();
    int getMaxFish();
    int getNumFish();
    bool addFish(Fish f);
    void clearTank();
    void showTank();
    void updateAt(int row, int col, char newChar);
    void simulate(bool singleStep, int fps);

private:

    static const int MAX_FISH =40;
    static const int MAX_HGT = 50;
    static const int MAX_WID=200;
    int tank_hgt;
    int tank_wid;
    int num_fish;
    char Tank[MAX_HGT][MAX_WID];
    Fish Fishes[MAX_FISH];
};

#endif
