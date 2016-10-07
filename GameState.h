#include "Person.h"
#include <vector>
#include <sstream>

const int MAN_ONE_AND_ONE = 0;
const int MAN_ONE_MISSIONARY = 1;
const int MAN_TWO_MISSIONARIES = 2;
const int MAN_ONE_CANNIBAL = -1;
const int MAN_TWO_CANNIBALS = -2;

class GameState{
public:

  std::vector<Person> startShore;
  std::vector<Person> endShore;
  std::vector<Person> boat;
  bool boatStartSide;
  std::string moves;

  GameState();

  bool isLosing();

  bool won();

  void swapBoat();

  bool leaveBoat();

  void manBoat(int people);

  bool makeMove(int peopleToMove);

  int countC(std::vector<Person> p);
  int countM(std::vector<Person> p);

  bool canMove(int people);

};