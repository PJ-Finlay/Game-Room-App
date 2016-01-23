#include "checkersgamestate.h"

#include <QChar>
#include <QDebug>
#include <string>

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
    return toReturn;
}

void CheckersGameState::setGameState(QString gameState){
    for(int i = 0; i < 9; i++){ //loop through the gameState string's characters
        board[i % 3][2 - (i / 3)] = gameState.at(i).toLatin1();
    }

    //Figure out which player's turn it is
    int xCount = 0;
    int oCount = 0;
    for(int i = 0; i < 9; i++){ //loop through the gameState string's characters
        if(gameState.at(i).toLatin1() == 'X') xCount++;
        if(gameState.at(i).toLatin1() == 'O') oCount++;
    }
    if(xCount == oCount){
        playerTurn = 1;
    }else{
        playerTurn = 2;
    }

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
    QStringList toReturn;
    for(int i = 0; i < 3; i++){ //Loop through x coordinates of the board
        for(int j = 0; j < 3; j++){//Loop through the y coordinates of the board
            if(board[i][j] == '_'){
                QString xString = QString::number(i);
                QString yString = QString::number(j);
                toReturn.append(xString.append(yString));
            }
        }
    }
    return toReturn;
}

void CheckersGameState::printGameState() const{
    qDebug() << board[0][2] << board[1][2] << board[2][2];
    qDebug() << board[0][1] << board[1][1] << board[2][1];
    qDebug() << board[0][0] << board[1][0] << board[2][0];
}
