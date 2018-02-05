# traverse-game

## Installation and Building
To get the unit tests to run you must pull with recursive
```bash
$ git clone --recursive https://github.com/davidraleigh/traverse-game.git
```

Requires cmake
```bash
cmake .
make
```

To run the example just execute the program in your terminal:
```bash
./traverse_game
```

To run the unit tests you'll need to have python installed and you'll need to have made the git clone recursive call from above. Then call the tests with the following command:
```bash
./traverse/traverse-tests/traverse_test
```

## Details of programming challenge:

[Knight Board]
The knight board can be represented in x,y coordinates.  The upper left positionis (0,0) and the bottom right is (7,7).  Assume there is a single knight chess piece on the board that can move according to chess rules.  Sample S[tart] and E[nd] points are shown below:

```bash
    . . . . . . . .
    . . . . . . . .
    . S . . . . . .
    . . . . . . . .
    . . . . . E . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
```

Level 1: Write a function that accepts a sequence of moves and reports whether the sequence contains only valid knight moves.  It should also optionally print the state of the knight board to the terminal as shown above after each move.  The current position should be marked with a 'K'.

Level 2: Compute a valid sequence of moves from a given start point to a given end point.

Level 3: Compute a valid sequence of moves from a given start point to a given end point in the fewest number of moves.

Level 4: Now repeat the Level 3 task for this 32x32 board.  Also, modify your validator from Level 1 to check your solutions.  This board has the following additional rules:
1) W[ater] squares count as two moves when a piece lands there
2) R[ock] squares cannot be used
3) B[arrier] squares cannot be used AND cannot lie in the path
4) T[eleport] squares instantly move you from one T to the other in the same move
5) L[ava] squares count as five moves when a piece lands there

```bash
    . . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . .
    . . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . .
    . . . . . . . . B . . . L L L . . . L L L . . . . . . . . . . .
    . . . . . . . . B . . . L L L . . L L L . . . R R . . . . . . .
    . . . . . . . . B . . . L L L L L L L L . . . R R . . . . . . .
    . . . . . . . . B . . . L L L L L L . . . . . . . . . . . . . .
    . . . . . . . . B . . . . . . . . . . . . R R . . . . . . . . .
    . . . . . . . . B B . . . . . . . . . . . R R . . . . . . . . .
    . . . . . . . . W B B . . . . . . . . . . . . . . . . . . . . .
    . . . R R . . . W W B B B B B B B B B B . . . . . . . . . . . .
    . . . R R . . . W W . . . . . . . . . B . . . . . . . . . . . .
    . . . . . . . . W W . . . . . . . . . B . . . . . . T . . . . .
    . . . W W W W W W W . . . . . . . . . B . . . . . . . . . . . .
    . . . W W W W W W W . . . . . . . . . B . . R R . . . . . . . .
    . . . W W . . . . . . . . . . B B B B B . . R R . W W W W W W W
    . . . W W . . . . . . . . . . B . . . . . . . . . W . . . . . .
    W W W W . . . . . . . . . . . B . . . W W W W W W W . . . . . .
    . . . W W W W W W W . . . . . B . . . . . . . . . . . . B B B B
    . . . W W W W W W W . . . . . B B B . . . . . . . . . . B . . .
    . . . W W W W W W W . . . . . . . B W W W W W W B B B B B . . .
    . . . W W W W W W W . . . . . . . B W W W W W W B . . . . . . .
    . . . . . . . . . . . B B B . . . . . . . . . . B B . . . . . .
    . . . . . R R . . . . B . . . . . . . . . . . . . B . . . . . .
    . . . . . R R . . . . B . . . . . . . . . . . . . B . T . . . .
    . . . . . . . . . . . B . . . . . R R . . . . . . B . . . . . .
    . . . . . . . . . . . B . . . . . R R . . . . . . . . . . . . .
    . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
    . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
```




Demo output for starting at (0, 31) and finishing at (31, 0). Each turn in the sequence of the path is demonstrated by the corresponding number. In the below exampl you can see the use of the teleport at the 6th turn:

```bash
1. [I]nput board
2. [P]re-made board
3. [E]mpty board

E[X]it

Select a start position row:0

Select a start position column:31

Select an end position row:31

Select an end position column:0


Completed board:

The character inputs are '.', 'o' or 'O' for empty positions. They cost 1 movement per position.
The character inputs are 'l' or 'L' for lava positions. They cost 5 movements per position.
The character inputs are 'b' or 'B' for barrier positions. Impassable.
The character inputs are 'r' or 'R' for rock positions. Impassable
The character inputs are 'w' or 'W' for water positions. They cost 3 movements per position.
The character inputs are 't' or 'T' for teleport positions. Only two teleport positions per map.

. . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . 0    0
. . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . .    1
. . . . . . . . B . . . L L L . . . L L L . . . . . . . . . 1 .    2
. . . . . . . . B . . . L L L . . L L L . . . R R . . . 2 . . .    3
. . . . . . . . B . . . L L L L L L L L . . . R R . . . . . . .    4
. . . . . . . . B . . . L L L L L L . . . . . . . . . 3 . . . .    5
. . . . . . . . B . . . . . . . . . . . . R R . . . . . . . . .    6
. . . . . . . . B B . . . . . . . . . . . R R . . . 4 . . . . .    7
. . . . . . . . W B B . . . . . . . . . . . . . . . . . . . . .    8
. . . R R . . . W W B B B B B B B B B B . . . . . 5 . . . . . .    9
. . . R R . . . W W . . . . . . . . . B . . . . . . . . . . . .    10
. . . . . . . . W W . . . . . . . . . B . . . . . . 6 . . . . .    11
. . . W W W W W W W . . . . . . . . . B . . . . . . . . . . . .    12
. . . W W W W W W W . . . . . . . . . B . . R R . . . . . . . .    13
. . . W W . . . . . . . . . . B B B B B . . R R . W W W W W W W    14
. . . W W . . . . . . . . . . B . . . . . . . . . W . . . . . .    15
W W W W . . . . . . . . . . . B . . . W W W W W W W . . . . . .    16
. . . W W W W W W W . . . . . B . . . . . . . . . . . . B B B B    17
. . . W W W W W W W . . . . . B B B . . . . . . . . . . B . . .    18
. . . W W W W W W W . . . . . . . B W W W W W W B B B B B . . .    19
. . . W W W W W W W . . . . . . . B W W W W W W B . . . . . . .    20
. . . . . . . . . . . B B B . . . . . . . . . . B B . . . . . .    21
. . . . . R R . . . . B . . . . . . . . . . . . . B . . . . . .    22
. . . . . R R . . . . B . . . . . . . . . . . . . B . 6 . . . .    23
. . . . . . . . . . . B . . . . . R R . . . . . . B . . . . . .    24
. . . . . . . . . . . B . . . . . R R . . . . . . . 7 . . . . .    25
. . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .    26
. . . . . . . . . . . B . . . . . . . . . . R R . 8 . . . . . .    27
. . . . . . . . . . . . . . . . . . . . . . . 9 . . . . . . . .    28
. . . . . 18. . . . . . . . . . . . . . . 10. . . . . . . . . .    29
. . 20. . . . 17. . . 15. . . 13. . . 11. . . . . . . . . . . .    30
21. . . 19. . . . 16. . . 14. . . 12. . . . . . . . . . . . . .    31


0 1 2 3 4 5 6 7 8 9 10111213141516171819202122232425262728293031

```


