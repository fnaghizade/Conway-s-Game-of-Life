#include <vector> 
#include <string>
using namespace std; 
class world
{
private:
    int **grid;
    int h;
    int w;
public:
    world(int, int);
    ~world();
    void set(int, int, int);
    void print();
    int get(int, int);
    int countNeighbors(int x, int y);
    int** newWorld();
    void readFromFile(string);
};
