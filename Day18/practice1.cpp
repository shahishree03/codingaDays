#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5 // Maximum number of players
#define MAX_BOARD_SIZE 100

// Function to roll a die
int rollDie() {
    return rand() % 6 + 1;
}

// Function for computer's turn using BFS
int computerTurn(int currentPosition, int snakesAndLadders[]) {
    // (Same as before...)
}

// Function to move the player on the snake and ladder board
int movePlayer(int currentPlayer, int roll, int snakesAndLadders[]) {
    int newPosition = currentPlayer + roll;

    int newSquare = newPosition + snakesAndLadders[newPosition];

    if (newSquare > MAX_BOARD_SIZE) {
        return currentPlayer; // Player cannot move beyond the maximum board size
    }

    return newSquare;
}

// Function to print the snake and ladder board
void printBoard(int players[], int numPlayers, int snakesAndLadders[]) {
    printf("\nSnake and Ladder Game Board:\n");

    for (int i = MAX_BOARD_SIZE; i >= 1; --i) {
        int position = i;
        int playerAtPosition = 0;

        // Check if any player is at the current position
        for (int j = 0; j < numPlayers; ++j) {
            if (players[j] == position) {
                playerAtPosition = j + 1; // Player number is 1-based
                break;
            }
        }

        if (playerAtPosition != 0) {
            printf("[P%d]", playerAtPosition);
        } else {
            printf("[%2d] ", position);
        }

        if (position % 10 == 1) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random numbers

    int numPlayers, boardSize, isComputer;

    // Get number of players
    do {
        printf("Enter the number of players (1 for computer vs human, 2-5 for human vs human): ");
        scanf("%d", &numPlayers);
        getchar(); // Consume newline character
    } while (numPlayers < 1 || numPlayers > MAX_PLAYERS);

    // Get board size
    do {
        printf("Enter the board size (minimum 10, maximum 100): ");
        scanf("%d", &boardSize);
        getchar(); // Consume newline character
    } while (boardSize < 10 || boardSize > MAX_BOARD_SIZE);

    // Determine if the player is playing against the computer
    isComputer = (numPlayers == 1);

    int players[MAX_PLAYERS] = {0}; // Array to store the positions of players

    // Define snake and ladder positions
    int snakesAndLadders[MAX_BOARD_SIZE + 1];

    for (int i = 0; i <= MAX_BOARD_SIZE; i++) {
        snakesAndLadders[i] = 0;
    }

    // Positive weights represent a ladder, and negative weights represent a snake.
    snakesAndLadders[6] = 40;
    snakesAndLadders[23] = -10;
    snakesAndLadders[45] = -7;
    snakesAndLadders[61] = -18;
    snakesAndLadders[65] = -8;
    snakesAndLadders[77] = 5;
    snakesAndLadders[98] = -10;

    printf("\nWelcome to Snake and Ladder Game!\n");

    while (1) {
        for (int i = 0; i < numPlayers; ++i) {
            printf("\nPlayer %d, press Enter to roll the die...", i + 1);
            getchar(); // Wait for the player to press Enter

            int roll = rollDie();
            printf("Player %d rolled a %d.\n", i + 1, roll);

            players[i] = movePlayer(players[i], roll, snakesAndLadders);
            printf("Player %d is now at square %d.\n", i + 1, players[i]);

            printBoard(players, numPlayers, snakesAndLadders);

            if (players[i] == MAX_BOARD_SIZE) {
                printf("Player %d wins!\n", i + 1);
                return 0;
            }
        }

        if (numPlayers == 1 && isComputer) {
            // Computer's turn
            int moves = computerTurn(players[numPlayers - 1], snakesAndLadders);
            printf("Computer decided to move %d steps.\n", moves);

            players[numPlayers - 1] = movePlayer(players[numPlayers - 1], moves, snakesAndLadders);
            printf("Computer is now at square %d.\n", players[numPlayers - 1]);

            printBoard(players, numPlayers, snakesAndLadders);

            if (players[numPlayers - 1] == MAX_BOARD_SIZE) {
                printf("Computer wins!\n");
                return 0;
            }
        }
    }

    return 0;
}