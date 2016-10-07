#include "GameState.h"
#include <iostream>
#include <string>

int main(){
  std::vector<GameState> q;
  q.push_back(GameState());

  GameState lastMove;

  while (q.size() != 0){
    GameState curr = q.front();
    q.erase(q.begin());
    if (curr.won()){
      std::cout << curr.moves;
      break;
    }
    GameState move1, move2, move3, move4, move5;
    move1 = curr;
    move2 = curr;
    move3 = curr;
    move4 = curr;
    move5 = curr;
    if (move1.moves.length() >= 3){
      if (move1.moves[move1.moves.length() - 3] != '0'){
        if (!move1.makeMove(MAN_ONE_AND_ONE)){
          move1.moves.append("0, ");
          q.push_back(move1);
        }
      }
    }
    else{
      if (!move1.makeMove(MAN_ONE_AND_ONE)){
        move1.moves.append("0, ");
        q.push_back(move1);
      }
    }
    if (move2.moves.length() >= 3){
      if (move2.moves[move2.moves.length() - 3] != '3'){
        if (!move2.makeMove(MAN_ONE_CANNIBAL)){
          move2.moves.append("3, ");
          q.push_back(move2);
        }
      }
    }
    else{
      if (!move2.makeMove(MAN_ONE_CANNIBAL)){
        move2.moves.append("3, ");
        q.push_back(move2);
      }
    }
    if (move3.moves.length() >= 3){
      if (move3.moves[move3.moves.length() - 3] != '4'){
        if (!move3.makeMove(MAN_TWO_CANNIBALS)){
          move3.moves.append("4, ");
          q.push_back(move3);
        }
      }
    }
    else{
      if (!move3.makeMove(MAN_TWO_CANNIBALS)){
        move3.moves.append("4, ");
        q.push_back(move3);
      }
    }
    if (move1.moves.length() >= 3){
      if (move1.moves[move1.moves.length() - 3] != '1'){
        if (!move4.makeMove(MAN_ONE_MISSIONARY)){
          move4.moves.append("1, ");
          q.push_back(move4);
        }
      }
    }
    else{
      if (!move4.makeMove(MAN_ONE_MISSIONARY)){
        move4.moves.append("1, ");
        q.push_back(move4);
      }
    }
    if (move1.moves.length() >= 3){
      if (move1.moves[move1.moves.length() - 3] != '2'){
        if (!move5.makeMove(MAN_TWO_MISSIONARIES)){
          move5.moves.append("2, ");
          q.push_back(move5);
        }
      }
    }
    else{
      if (!move5.makeMove(MAN_TWO_MISSIONARIES)){
        move5.moves.append("2, ");
        q.push_back(move5);
      }
    }
  }
  return 0;
}