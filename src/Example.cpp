#include <iostream> 
#include <vector> 
using namespace std; 


int countNeighbors(vector<vector<bool>> &grid, int x , int y)
{
    int alive = 0;
    // testing top
    if(x>0 && grid[x-1][y] == 1) alive+=1;
    
    // testing bottom
    if(x+1<grid.size() && grid[x+1][y] == 1) alive+=1;
    
    // testing the left
    if(y>0 && grid[x][y-1] == 1) alive+=1;
    
    // testing the right
    if(y+1 < grid[0].size() && grid[x][y+1] == 1) alive+=1;
    
    // testing top left
    if(x>0 && y>0 && grid[x-1][y-1] == 1) alive+=1;
    
    // testing top right
    if(x>0 && y+1 < grid[0].size() && grid[x-1][y+1] == 1) alive+=1;
    
    // testing bottom left
    if(x+1 < grid.size() && y>0 && grid[x+1][y-1]) alive+=1;
    
    // testing bottom right
    if(x+1 < grid.size() && y+1 < grid[0].size() && grid[x+1][y+1]) alive+=1;
    return alive;
}


vector<vector<bool>> newGrid(vector<vector<bool>> &grid)
{
    vector<vector<bool>> a = grid;
    for(int x = 0; x < grid.size(); x++){
        for(int y = 0; y < grid[0].size(); y++){
                
            if(grid[x][y] == 1 && (countNeighbors(grid, x, y) == 2 || countNeighbors(grid, x, y) == 3))
                {
                    a[x][y]=true;
                }
            else a[x][y]=false;
            
            if(grid[x][y] == 0 && countNeighbors(grid, x, y) == 3) a[x][y]=true;
        }
    }
    
    return a;
}


void print(vector<vector<bool>> &grid)
{
    for(int x = 0; x < grid.size(); x++){
        for(int y = 0; y < grid[0].size(); y++){
            if(grid[x][y] == true) cout << "0";
            else cout << "_";
            cout << " ";
        }
        cout << "" << endl;
    }
    cout <<"**************************************************" << endl;
}



int main() 

{ 
    vector<vector<bool>> a = {{false, true, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, true, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {true, true, true, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
                                        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}};


    vector<vector<bool>> new_grid = newGrid(a);
    for(int i=0; i<10; i++){

        print(new_grid);
        
        new_grid = newGrid(new_grid);
    }

    return 0; 
}