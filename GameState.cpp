#include "GameState.h"

GameState::GameState(){
  boatStartSide = true;
  for (int i = 0; i < 3; i++){
    startShore.push_back(Person(true));
  }
  for (int i = 0; i < 3; i++){
    startShore.push_back(Person(false));
  }
}

bool GameState::isLosing(){
  int cannibals = 0;
  int missionaries = 0;
  for (int i = 0; i < startShore.size(); i++){
    if (startShore[i].isMissionary)
      missionaries++;
    else
      cannibals++;
  }
  if (cannibals > missionaries && missionaries > 0)
    return true;

  cannibals = 0;
  missionaries = 0;
  for (int i = 0; i < endShore.size(); i++){
    if (endShore[i].isMissionary)
      missionaries++;
    else
      cannibals++;
  }
  if (cannibals > missionaries && missionaries > 0)
    return true;

  return false;

}

bool GameState::won(){
  if (endShore.size() == 6)
    return true;
  return false;
}

void GameState::swapBoat(){
  boatStartSide = !boatStartSide;
}

bool GameState::leaveBoat(){
  for (int i = boat.size() - 1; i >= 0; i--){
    if (boatStartSide){
      startShore.push_back(boat[i]);
      boat.pop_back();
    }
    else{
      endShore.push_back(boat[i]);
      boat.pop_back();
    }
  }
  return isLosing();
}

void GameState::manBoat(int people){
  if (people == MAN_ONE_CANNIBAL){
    if (boatStartSide){
      for (int i = 0; i < startShore.size(); i++){
        if (startShore[i].isMissionary == false){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          return;
        }
      }
    }
    else {
      for (int i = 0; i < endShore.size(); i++){
        if (endShore[i].isMissionary == false){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          return;
        }
      }
    }
  }
  else if (people == MAN_TWO_CANNIBALS){
    int count = 2;
    if (boatStartSide){
      for (int i = 0; i < startShore.size(); i++){
        if (startShore[i].isMissionary == false){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          i--;
          if (--count == 0)
            return;
        }
      }
    }
    else {
      for (int i = 0; i < endShore.size(); i++){
        if (endShore[i].isMissionary == false){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          i--;
          if (--count == 0)
            return;
        }
      }
    }
  }
  else if (people == MAN_ONE_AND_ONE){
    int countM = 1, countC = 1;
    if (boatStartSide){
      for (int i = 0; i < startShore.size(); i++){
        if (startShore[i].isMissionary == false && countC > 0){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          countC--;
          i--;
        }
        else if (startShore[i].isMissionary && countM > 0){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          countM--;
          i--;
        }
      }
    }
    else {
      for (int i = 0; i < endShore.size(); i++){
        if (endShore[i].isMissionary == false && countC > 0){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          countC--;
          i--;
        }
        else if (endShore[i].isMissionary && countM > 0){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          countM--;
          i--;
        }
      }
    }
  }
  else if (people == MAN_ONE_MISSIONARY){
    if (boatStartSide){
      for (int i = 0; i < startShore.size(); i++){
        if (startShore[i].isMissionary){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          return;
        }
      }
    }
    else {
      for (int i = 0; i < endShore.size(); i++){
        if (endShore[i].isMissionary){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          return;
        }
      }
    }
  }
  else if (people == MAN_TWO_MISSIONARIES){
    int count = 2;
    if (boatStartSide){
      for (int i = 0; i < startShore.size(); i++){
        if (startShore[i].isMissionary){
          boat.push_back(startShore[i]);
          startShore.erase(startShore.begin() + i);
          i--;
          if (--count == 0)
            return;
        }
      }
    }
    else {
      for (int i = 0; i < endShore.size(); i++){
        if (endShore[i].isMissionary){
          boat.push_back(endShore[i]);
          endShore.erase(endShore.begin() + i);
          i--;
          if (--count == 0)
            return;
        }
      }
    }
  }
}

bool GameState::canMove(int people){
  if (boatStartSide){
    if (people == -2){
      if (countC(startShore) < 2)
        return false;
    }
    if (people == -1){
      if (countC(startShore) < 1)
        return false;
    }
    if (people == 0){
      if (countC(startShore) < 1 || countM(startShore) < 1)
        return false;
    }
    if (people == 1){
      if (countM(startShore) < 1)
        return false;
    }
    if (people == 2){
      if (countM(startShore) < 2)
        return false;
    }
  }
  else {
    if (people == -2){
      if (countC(endShore) < 2)
        return false;
    }
    if (people == -1){
      if (countC(endShore) < 1)
        return false;
    }
    if (people == 0){
      if (countC(endShore) < 1 || countM(endShore) < 1)
        return false;
    }
    if (people == 1){
      if (countM(endShore) < 1)
        return false;
    }
    if (people == 2){
      if (countM(endShore) < 2)
        return false;
    }
  }
}

bool GameState::makeMove(int peopleToMove){
  if (!canMove(peopleToMove))
    return true;
  manBoat(peopleToMove);
  swapBoat();
  return leaveBoat();
}

int GameState::countC(std::vector<Person> p){
  int counter = 0;
  for (int i = 0; i < p.size(); i++){
    if (p[i].isMissionary == false)
      counter++;
  }
  return counter;
}

int GameState::countM(std::vector<Person> p){
  int counter = 0;
  for (int i = 0; i < p.size(); i++){
    if (p[i].isMissionary)
      counter++;
  }
  return counter;
}