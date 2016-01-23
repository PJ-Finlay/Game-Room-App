#include "checkersgamestate.h"

#include <QChar>
#include <QDebug>
#include <string>
#include <iostream>

CheckersGameState::CheckersGameState() : GameState()
{
    playerTurn = 1;
}

void CheckersGameState::initializeGame(){
    for(int i = 0; i < 8; i++){ //Loop through x coordinates of the board
        for(int j = 0; j < 8; j++){//Loop through the y coordinates of the board
            this->board[i][j] = '_';
        }
    }
    playerTurn = 1;
}

QString CheckersGameState::getGameState() const{
    QString toReturn;
    for(int y = 7; y >= 0; y--){
        for(int x = 0; x < 8; x++){
            toReturn.append(board[x][y]);
        }
    }
    toReturn.append(QString::number(playerTurn));
    return toReturn;
}

void CheckersGameState::setGameState(QString gameState){
    for(int i = 0; i < 64; i++){ //loop through the gameState string's characters
        board[i % 8][7 - (i / 8)] = gameState.at(i).toLatin1();
    }
    playerTurn = gameState.right(1).toInt();

}

void CheckersGameState::updateGameState(QString move){
    //Parse String
    int x = move.mid(0,1).toInt();
    int y = move.mid(1,1).toInt();

    //Find the right piece to play
    char pieceToPlace;
    if(playerTurn == 1){
        pieceToPlace = 'X';
    }else{
        pieceToPlace = 'O';
    }

    //Place that piece
    board[x][y] = pieceToPlace;

    //Increment the turn
    this->incrementTurn();
}

/**
 * @todo Not as efficient as it could be
 */
int CheckersGameState::findWinners() const{
    //This finds winners by testing the 8 possible win conditions, then testing for a tie

    //Test the eight winning combinations

    char winningChar = '_';
    //Horizontal Rows
    for(int i = 0; i < 3; i++){ //Loop through each row
        char first = board[0][i];
        if(board[1][i] == first && board[2][i] == first && first != '_'){
            winningChar = first;
        }
    }
    //Vertical Columns
    for(int i = 0; i < 3; i++){ //Loop through each column
        char first = board[i][0];
        if(board[i][1] == first && board[i][2] == first && first != '_'){
            winningChar = first;
        }
    }
    //Diag
    char middleChar = board[1][1];
    if(board[0][2] == middleChar && board[2][0] == middleChar && middleChar != '_'){
        winningChar = middleChar;
    }
    if(board[0][0] == middleChar && board[2][2] == middleChar && middleChar != '_'){
        winningChar = middleChar;
    }



    if(winningChar == 'X'){
        return 1;
    }else if(winningChar == 'O'){
        return 2;
    }


    //Test for a tie
    bool blankSquareFound = false;
    for(int i = 0; i < 3; i++){ //Loop through x coordinates of the board
        for(int j = 0; j < 3; j++){//Loop through the y coordinates of the board
            if(board[i][j] == '_'){
                blankSquareFound = true;
            }
        }
    }
    if(!blankSquareFound){
        return 0;
    }

    //Game Continues
    return -1;
}

QList<int> CheckersGameState::getValidNumberOfPlayers() const
{
    QList<int> toReturn;
    toReturn.append(2);
    return toReturn;

}

void CheckersGameState::incrementTurn()
{
    //Alternate the player turns
    if(playerTurn == 1){
        playerTurn = 2;
    }else{
        playerTurn = 1;
    }
}

void CheckersGameState::deincrementTurn()
{
    //Since there are only two possible turn states deincrementTurn is the same as incrementTurn
    incrementTurn();
}

int CheckersGameState::getTurn() const
{
    return playerTurn;
}

QStringList CheckersGameState::findValidMoves() const
{
    char regTurn = 'b';
    char kingTurn = 'B';
    if(playerTurn == 2){
        regTurn = 'r';
        kingTurn = 'R';
    }

    QStringList toReturn;
    for(int y = 7; y >=0; y--){
        for(int x = 0; x < 8; x++){
            if(board[x][y] != '_' && (board[x][y] == regTurn || board[x][y] == kingTurn)){
                toReturn += validMovesForPiece(x,y);
            }
        }
    }
    return toReturn;
}

QStringList CheckersGameState::validMovesForPiece(int x, int y) const
{
    QStringList toReturn;

    int direction = 1;
    if(board[x][y] == 'r' || board[x][y] == 'R'){
        direction = -1;
    }


    //This uses short circuit evaluation to prevent out of bounds errors
    //For all pieces
    if(x > 0 && y+direction>=0 && y+direction<=7 && board[x-1][y+1*direction] == '_'){ //Checks up/left
        toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-1) + QString::number(y+1*direction));
    }
    if(x < 7 && y+direction>=0 && y+direction<=7 && board[x+1][y+1*direction] == '_'){ //Checks up/right
        toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+1) + QString::number(y+1*direction));
    }
    //Jumps
    if(x > 0 && y+direction*2>=0 && y+direction*2<=7 && board[x-2][y+2] == '_'){ //Checks up/left for jump
        if(QString(board[x][y]).toLower().compare(QString(board[x-1][y+1*direction])) != 0 && board[x-1][y+1*direction] != '_')
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-2) + QString::number(y+2*direction));
    }
    if(x < 7 &&  y+direction*2>=0 && y+direction*2<=7  && board[x+2][y+2] == '_'){ //Checks up/right for jump
        if(QString(board[x][y]).toLower().compare(QString(board[x+1][y+1*direction])) != 0 && board[x+1][y+1*direction] != '_')
        toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+2) + QString::number(y+2*direction));
    }

    //For kings
    if(board[x][y] == 'R' || board[x][y] == 'B'){ //If the piece is a king
        if(x > 0 && y-direction>=0 && y-direction<=7 && board[x-1][y-1*direction] == '_'){ //Checks back/left
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-1) + QString::number(y-1*direction));
        }
        if(x < 7 && y-direction>=0 && y-direction<=7  && board[x+1][y-1*direction] == '_'){ //Checks back/right
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+1) + QString::number(y-1*direction));
        }
        //Jumps
        if(x > 0 && y-direction*2>=0 && y-direction*2<=7  && board[x-2][y-2] == '_'){ //Checks back/left for jump
            if(QString(board[x][y]).toLower().compare(QString(board[x-1][y-1*direction])) != 0 && board[x-1][y-1*direction] != '_')
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-2) + QString::number(y-2*direction));
        }
        if(x < 7 &&y-direction*2>=0 && y-direction*2<=7  && board[x+2][y-2] == '_'){ //Checks back/right for jump
            if(QString(board[x][y]).toLower().compare(QString(board[x+1][y-1*direction])) != 0 && board[x+1][y-1*direction] != '_')
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+2) + QString::number(y-2*direction));
        }
    }

    return toReturn;
}

void CheckersGameState::printGameState() const{

    for(int y = 7; y >=0; y--){
        QString line;
        for(int x = 0; x < 8; x++){
            line.append(board[x][y]);
            line.append(" ");
        }
        std::cout << line.toStdString() << std::endl;
    }
}
