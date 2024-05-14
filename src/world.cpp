#include "world.h"
#include <vector> 
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
void world::set(int x, int y, int v) {
    world::grid[x][y] = v;
}

world::world(int w, int h) {
    this->w = w;
    this->h = h;
    this->grid = new int *[h];
    for(int i = 0; i < h; i++) {
        this->grid[i] = new int[w];
    }
}
int world::countNeighbors(int x , int y)
{
    int alive = 0;
    // testing top
    if(x>0 && grid[x-1][y] == 1) alive+=1;
    
    // testing bottom
    if(x+1< h && grid[x+1][y] == 1) alive+=1;
    
    // testing the left
    if(y > 0 && grid[x][y-1] == 1) alive+=1;
    
    // testing the right
    if(y+1 < h && grid[x][y+1] == 1) alive+=1;
    
    // testing top left
    if(x>0 && y>0 && grid[x-1][y-1] == 1) alive+=1;
    
    // testing top right
    if(x>0 && y+1 < w && grid[x-1][y+1] == 1) alive+=1;
    
    // testing bottom left
    if(x+1 < h && y>0 && grid[x+1][y-1]) alive+=1;
    
    // testing bottom right
    if(x+1 < h && y+1 < w && grid[x+1][y+1]) alive+=1;
    return alive;
}
int** world::newWorld() {
    world *nw = new world(h, w);
    for(int x = 0; x < h; x++){
        for(int y = 0; y < w; y++){
                
            if(grid[x][y] == 1 && (countNeighbors(x, y) == 2 || countNeighbors(x, y) == 3))
                {
                    nw->set(x, y, 1);
                }
            else nw->set(x, y, 0);
            
            if(grid[x][y] == 0 && countNeighbors(x, y) == 3) nw->set(x, y, 1);
        }
    }
}

void world::print()
{
    for(int x = 0; x < h; x++){
        for(int y = 0; y < w; y++){
            if(grid[x][y] == true) cout << "0";
            else cout << "_";
            cout << " ";
        }
        cout << "" << endl;
    }
    cout <<"**************************************************" << endl;
}
void world::readFromFile(string filename) {
    string myText;
    ifstream MyReadFile(filename);
    while (getline (MyReadFile, myText)) {
        cout << myText;
    }
}