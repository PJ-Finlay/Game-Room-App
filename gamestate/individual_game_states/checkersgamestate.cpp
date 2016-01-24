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
    for(int y = 7; y >= 0; y--){
        for(int x = 0; x < 8; x++){
            if(y > 4 && (x % 2 == 0 + y % 2) % 2 == 1){ //Top of the board
                   board[x][y] = 'r';
            }else if(y < 3 && (x % 2 == 0 + y % 2) % 2 == 1){ //Bottom of the board
                board[x][y] = 'b';
            }else{
                board[x][y] = '_';
            }
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
    int startX = move.midRef(0,1).toInt();
    int startY = move.midRef(1,1).toInt();
    int endX = move.midRef(2,1).toInt();
    int endY = move.midRef(3,1).toInt();
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '_';

    incrementTurn();

    //If a piece was captured
    if(abs(startX - endX) > 1){
        board[(startX+endX)/2][(startY+endY)/2] = '_'; //remove the jumped piece
        if(validCaptureMoves(endX,endY).size() > 0) incrementTurn();//deincrement the turn  because the player gets to go again
    }

    //If a piece reaches the end make it a king
    if(endY == 0 || endY == 7){
        if(board[endX][endY] == 'b') board[endX][endY] = 'B';
        if(board[endX][endY] == 'r') board[endX][endY] = 'R';
    }
}


int CheckersGameState::findWinners() const{
    bool player1CanMove = false;
    bool player2CanMove = false;
    for(int y = 7; y >=0; y--){
        for(int x = 0; x < 8; x++){
            if(board[x][y] == 'b' || board[x][y] == 'B'){
                if(validMovesForPiece(x,y).size() > 0) player1CanMove = true;
            }
            if(board[x][y] == 'r' || board[x][y] == 'R'){
                if(validMovesForPiece(x,y).size() > 0) player2CanMove = true;
            }
        }
    }
    if(player1CanMove && player2CanMove) return -1;
    if(!player1CanMove && !player2CanMove) return 0;
    if(!player1CanMove && player2CanMove) return 2;
    if(player1CanMove && !player2CanMove) return 1;
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

    //For kings
    if(board[x][y] == 'R' || board[x][y] == 'B'){ //If the piece is a king
        if(x > 0 && y-direction>=0 && y-direction<=7 && board[x-1][y-1*direction] == '_'){ //Checks back/left
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-1) + QString::number(y-1*direction));
        }
        if(x < 7 && y-direction>=0 && y-direction<=7  && board[x+1][y-1*direction] == '_'){ //Checks back/right
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+1) + QString::number(y-1*direction));
        }
    }


    toReturn.append(validCaptureMoves(x,y));

    return toReturn;
}

QStringList CheckersGameState::validCaptureMoves(int x, int y) const //Seperated so it can be used to determine if their is a potential double jump
{
    QStringList toReturn;

    int direction = 1;
    if(board[x][y] == 'r' || board[x][y] == 'R'){
        direction = -1;
    }
    //Jumps
    if(x > 0 && y+direction*2>=0 && y+direction*2<=7 && board[x-2][y+2*direction] == '_'){ //Checks up/left for jump
        if(QString(board[x][y]).toLower().compare(QString(board[x-1][y+1*direction])) != 0 && board[x-1][y+1*direction] != '_')
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-2) + QString::number(y+2*direction));
    }
    if(x < 7 &&  y+direction*2>=0 && y+direction*2<=7  && board[x+2][y+2*direction] == '_'){ //Checks up/right for jump
        if(QString(board[x][y]).toLower().compare(QString(board[x+1][y+1*direction])) != 0 && board[x+1][y+1*direction] != '_')
        toReturn.append(QString::number(x) + QString::number(y) + QString::number(x+2) + QString::number(y+2*direction));
    }
    //For kings
    if(board[x][y] == 'R' || board[x][y] == 'B'){ //If the piece is a king
        //Jumps
        if(x > 0 && y-direction*2>=0 && y-direction*2<=7  && board[x-2][y-2*direction] == '_'){ //Checks back/left for jump
            if(QString(board[x][y]).toLower().compare(QString(board[x-1][y-1*direction])) != 0 && board[x-1][y-1*direction] != '_')
            toReturn.append(QString::number(x) + QString::number(y) + QString::number(x-2) + QString::number(y-2*direction));
        }
        if(x < 7 &&y-direction*2>=0 && y-direction*2<=7  && board[x+2][y-2*direction] == '_'){ //Checks back/right for jump
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

double CheckersGameState::competitivePosition(int player) const
{
    int playerCount = 0;
    int playerKingCount = 0;
    int otherCount = 0;
    int otherKingCount = 0;

    char playerMan;
    char playerKing;
    char otherMan;
    char otherKing;
    if(player == 1){
        playerMan = 'b';
        playerKing = 'B';
        otherMan = 'r';
        otherKing = 'R';
    }else{
        playerMan = 'r';
        playerKing = 'R';
        otherMan = 'b';
        otherKing = 'B';
    }


    for(int y = 7; y >=0; y--){
        for(int x = 0; x < 8; x++){
            char position = board[x][y];
            if(position == playerMan) playerCount++;
            if(position == playerKing) playerKingCount++;
            if(position == otherMan) otherCount++;
            if(position == otherKing) otherKingCount++;

        }
    }

    int playerSum = playerCount + (playerKingCount * 12);
    int otherSum = otherCount + (otherKingCount * 12);
    int difference = playerSum - otherSum;
    double dblDiff = (double) difference;

    return dblDiff / 144;
}
