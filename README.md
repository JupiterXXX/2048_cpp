# 2048_cpp
Game 2048 (C++)
Compose of Input(), Judge() , Print(), Num_generator(), Process(int direction) functions

int Input():
detect inputs(up down left right) from the keyboard and return as direction

int Judge():
judge the game state, continue or win or lose and return 

void Print():
print numbers and game board in the cmd window

void Num_generator():
generator new numbers (2 or 4)in the game board

void Process(int direction):
get direction from Input() function
Move numbers following the direction to the aimed position in the game board
