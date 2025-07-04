# 🎮Simple Tic-Tac-Toe Game In C

A basic command-line implementation of the classic Tic-Tac-Toe game written in C . This version supports two players taking turns as X and O.


## 📌Features
- 3x3 grid interface
- Input validation for position selection
- Detection of win conditions (rows, columns, diagonals)
- Draw detection if the board fills without a winner
- Player alternation (X starts first, then O)


##🕹️ Gameplay Instructions
- The game will display an empty 3x3 grid with positions numbered from 1 to 9.
- Players take turns entering a number corresponding to the cell they want to mark.
- Player X always goes first.
- The game checks after each move whether there is a winner or a draw.
- If someone wins, the game ends and the winner is announced.
Example Grid Layout:
```
 1 | 2 | 3 
 ------------
 4 | 5 | 6 
 ------------
 7 | 8 | 9
```

📁 Files Included
tictactoe.c – Main source code containing game logic.
TicTacToe.h – Header file with constants/macros and function declarations.

