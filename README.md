# Cannibals-and-Missionaries
Solves the problem of getting cannibals and missionaries across a river

You have 3 missionaries and 3 cannibals on the side of a river. They want to cross to the other side. There is one boat that can
hold 2 people at a time. If the cannibals ever out-number the missionaries, then they'll eat them and you lose. 
Get all 6 people to the other side safely to win.

The way it is solved is by pushing the GameStates onto a queue, which is just a vector of GameStates in the program. A GameState is just a possible scenario of where the Cannibals and Missionaries can be: on the East or West shore, and which side of the shore the boat's on. Then 5 new GameStates test the 5 possibilities of change (Move 2 C, 1 C, 1C1M, 1M, xor 2M) and check if it would create a losing game. If it isn't a losing game, it pushes that GameState to the back of the queue, which means the most simple (least amount of moves) solution will be found first, because it is a first in first out queue. 
