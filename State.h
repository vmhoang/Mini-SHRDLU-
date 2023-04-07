#ifndef State_H_
#define State_H_

const int BOARDSIZE = 3;
const int numberofblocks = 6;

class State{
    private:
    std::stack<int> list1;
    std::stack<int> list2;
    std::stack<int> list3;
    std::stack<int> grid[BOARDSIZE] = {list1, list2, list3};

public:

    State(){
       
    }
    void createtable();
    bool checkstack(int x); // true if full, false if not full
    void printtable();
    void tableinput();
};

void State::createtable(){
    // initialize the program and create a 3x3 array. Fill the array with random number from 0 to 6
    {
        int count = 1 ;
        int randnum;
        while (count <= 6){
            randnum = rand()%3 ; // init random number from 0 to 2
            // cout << randnum << endl;
            if (!checkstack(randnum)){ 
                grid[randnum].push(count);
                count++;
            }
            
        }
        // cout << "size" << endl;
        // cout << grid[0].size() << endl;
        // cout << grid[1].size() << endl;
        // cout << grid[2].size() << endl;
    }
}
bool State::checkstack(int x){
    if (grid[x].size()== BOARDSIZE){
        return true;
    }
    return false;
}
// Printing the 2D array
void State::printtable(){
    // std::cout << endl;
    // std::cout << "Initital State" << std::endl;
    // for (int i = 0; i < BOARDSIZE; i++)
    // {
    //     for (int j = 0; j < BOARDSIZE; j++)
    //     {
    //         std::cout << "|" << grid[BOARDSIZE - i - 1][j] << "|";
    //     }
    //     std::cout << endl;
    // }
    // copy and paste the the grid with gridcopy
    std::stack<int> gridcopy[BOARDSIZE];
    for (int i = 0; i < BOARDSIZE; i++){
        gridcopy[i] = grid[i];
    }
    // printing the stack in a stack for mat
    // stack1 | stack 2| stack 3|
    int count = 0;
    while (count < BOARDSIZE)
    {
        for (int i = 0; i < BOARDSIZE; i++)
        {
            if(!gridcopy[i].empty()){
                std::cout << gridcopy[i].top() << " | ";
                gridcopy[i].pop();
            }
            else{
                std::cout << "  | ";
            }
        }
        count++;
        cout << endl;
    }
    
}

void State::tableinput(){
    // std::cout << "Input a goal in a format: " << std::endl;
    // std::cout << "Block (1-6): ";
    // std::cin >> i_block;
    // std::cout << std::endl;
    // std::cout << "Row (0-2 bottom up): ";
    // std::cin >> i_row;
    // std::cout << std::endl;
    // std::cout << "column (0 - 2 left- right) ";
    // std::cin >> i_col;
    // std::cout << std::endl;
}
#endif 