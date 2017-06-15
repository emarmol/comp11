/*Name: Erika Marmol
Date: 4/7/14
Purpose: to create an animated fishtank
Discussed ideas with: Emma Coltoff, Jessica Morales. Ambika Jayakumar


Defines the class for Fish, includes string, and 
won't be created if already made.*/

#ifndef FISH_H
#define FISH_H
#include <string>

using std::string;
class FishTank;

class Fish
{

public:

    Fish();
    bool readFish();
    string getName();
    void setName(string name);
    void setHSpeed(float new_speed);
    void setVSpeed(float new_speed);
    void setPos(int row, int col);
    int getHeight();
    int getWidth();
    void move(int tankHeight, int tankWidth);
    void draw(FishTank *tank);
    void print(); //for debugging

private:

    static const int MAX_HGT = 30;
    static const int MAX_WID = 60;
    string fish_name;
    float fish_vspeed;
    float fish_hspeed;
    float fish_posx;
    float fish_posy;
    int fish_hgt;
    int fish_wid;
    char fish_map[MAX_HGT][MAX_WID];

};

#endif
