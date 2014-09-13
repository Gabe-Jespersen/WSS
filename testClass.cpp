#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class puzzle 
{
    /////
    //counted from top left as an array of strings
    /////
    short width;
    short height;
    vector <vector <char> > board;
    public:
        char pos(short,short);
        void init(short,short,vector <vector <char> >);
};

char puzzle::pos(short x, short y)
{
    if(x-1>width||y-1>height)
    {
        cout << "Error, invalid position \(" << x << "," << y << "\)" << endl;
        exit(1);
    }
    return((board.at(y-1)).at(x-1));
}

void puzzle::init(short toWidth, short toHeight, vector <vector <char> > toSet)
{
    width = toWidth;
    height = toHeight;
    board = toSet;
    return;
}

bool isConstantSize(vector <vector <char> > toCheck)
{
    int isLength = toCheck.at(0).size();
    for(int i = 1; i < toCheck.size(); i++) //checking from 1 because already
                                            //checked 0, see: previous line
    {
        if(toCheck.at(i).size() != isLength)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    vector <vector <char> > board = {{ 't', 'e', 's'},
                                     { 't', 'i', 'n'},
                                     { 'g', 'i', 'n'}};
    if(!isConstantSize(board))
    {
        cout << "Board should be of constant size\n";
        exit(1);
    }
    puzzle curPuzzle;
    curPuzzle.init(board.at(0).size(),board.size(),board);
    return 0;
}
