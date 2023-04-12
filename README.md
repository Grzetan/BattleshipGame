Ship class:                                                           4
n_blocks = how many blocks it takes                                   3
alive = is alive?                                                     2
origin = coordinates of tail                         1 2 3 4  or 1 or 1 or 4 3 2 1
direction = orientation of the ship                              2
placed = is placed on board?                                     3
hits = vector of hits to this ship                               4  

Board class:
width,
height,
ships = vector of ships on board
hits = array of hits

game class:
Board of player one
Board of player two

save to file
load from file