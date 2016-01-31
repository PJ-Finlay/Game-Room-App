#include "heartsgamestate.h"

#include <QDebug>

HeartsGameState::HeartsGameState() : TrickBasedGameState()
{
    playerTurn = 1;
}

void HeartsGameState::initializeGame(){
    clearGameState();
}

void HeartsGameState::updateGameState(QString move){
    int mode = getMode();
    if(mode == 0){ //Passing Mode
        addToMoveRecord(move);
        QList<QList<QString>> hands = getPlayerHands();
        int from = getTurn();
        int to = findPlayerToPassTo(from);
        QList<QString> fromHand = hands.at(from -1);
        QList<QString> toHand = hands.at(to - 1);
        QList<QString> passedCards = move.split("|");
        for(int i = 0; i < passedCards.size(); i++){
            QString card = passedCards.at(i);
            fromHand.removeAt(fromHand.indexOf(card));
            toHand.append(card);
        }
        hands.replace(from,fromHand);
        hands.replace(to,toHand);
    }
}

int HeartsGameState::findWinners() const{
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

QList<int> HeartsGameState::getValidNumberOfPlayers() const
{
    QList<int> toReturn;
    toReturn.append(4);
    return toReturn;

}

void HeartsGameState::incrementTurn()
{
    //Alternate the player turns
    if(playerTurn == 1){
        playerTurn = 2;
    }else{
        playerTurn = 1;
    }
}

void HeartsGameState::deincrementTurn()
{
    //Since there are only two possible turn states deincrementTurn is the same as incrementTurn
    incrementTurn();
}

int HeartsGameState::getTurn() const
{
    return playerTurn;
}

QStringList HeartsGameState::findValidMoves() const
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

void HeartsGameState::printGameState() const{
    //TrickBasedGameState::printGameState();

}

int HeartsGameState::findPlayerToPassTo(int player)
{
    QString passingMode = getOtherInfo();
    if(passingMode.compare("R") == 0){
        if(player > 1) return player - 1;
        return 4;
    }
    if(passingMode.compare("L") == 0){
        if(player < 4) return player + 1;
        return 1;
    }
    if(passingMode.compare("A") == 0){
        if(player == 1) return 3;
        if(player == 2) return 4;
        if(player == 3) return 1;
        if(player == 4) return 2;
    }
    return player;
}
