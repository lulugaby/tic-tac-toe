#include "Functions.h"

void runGame()
{
    bool again;
	again = true;
	
	while (again == true){
		char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
        char types[2] = {'X','O'};
        initBoard(board);
        char p = 'B';

        //while there is "-" in board
        while (checkForDraw(board)== false){
 
            if (p=='X'){
                p = 'O';
            }
            else{
                p = 'X';
            }

            cout << "Enter coordinate for "<<p<<". Input should be X Y\n";
            int x;
            int y;
            cin >> x >> y;
            
            placeAPiece(x,y,p,board);
            displayBoard(board);

            bool w  = checkForWinner(p, board);
            if (w==true){
                cout<< p << " Won\n";
                break;
            }
            
            if (checkForDraw(board)== true and w==false){
            cout << "Draw\n";
            
            }
        }

        cout << "Do you want to play again?\n";
        string a;
        cin>> a;
        if (a == "n" or a =="N"){
            again = false;
        }
        //cin.ignore();

    }
    cout<<"Done"<<endl;
    cout.flush();
}

void initBoard(char board[3][3])
{
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            board[x][y] = '-';
        }
    }
}

void placeAPiece(int x, int y, char piece, char board[3][3])
{
    board[x][y]= piece;
    
    //cout<< board[x][y];
}

bool checkForWinner(char piece, char board[3][3])
{   
    // you have to check that it is the right winner


    // cross
    if (board[0][0] == piece  and board[1][1] == piece and board[2][2] == piece){
        return true;
    }
    if (board[0][2] == piece and board[1][1] == piece and board[2][0] == piece){
        
        return true;
    }

    for (int x = 0; x < 3; x++){

            if (board[x][0] == piece and board[x][1] == piece and board[x][2] == piece){
            return true;
            }
        
    }
    for (int y = 0; y < 3; y++){

            if (board[0][y] == piece and board[1][y] == piece and board[2][y] == piece){
            return true;
            }
        
    } 
    return false;

}

bool checkForDraw(char board[3][3])
{
    /// check if there is blank space on board
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            if (board[x][y] == '-'){
                return false;
            }
        }
    }
    return true;
}


void displayBoard(char board[3][3])
{
    string s;
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){

            //cout <<board[x][y];
            s+=board[x][y];
            if (y!=2){
            //cout << "|";
            s+= "|";
            }
            }
        if (x != 2){
        //cout <<"\n-----\n";
        s+="\n-----\n";
        }
        else{
            //cout<<"\n";
            s+="\n";
        }
    }
    cout <<s;

}