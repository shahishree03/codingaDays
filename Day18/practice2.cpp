#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_PLAYERS 10
#define BOARD_MIN_SIZE 10
#define MAX_DICE_VALUE 6
#define SNAKES_COUNT 10
#define LADDERS_COUNT 9
// Function to roll a die
int rollDie() {
    return rand() % 6 + 1;
}

// Function for computer's turn
int computerTurn(int currentPosition, int boardSize) {
    int targetPosition = boardSize * boardSize;
    int remainingDistance = targetPosition - currentPosition;

    // Simple strategy: Computer tries to move to the last cell as quickly as possible
    int maxMove = remainingDistance > 6 ? 6 : remainingDistance;
    int dice = rand() % maxMove + 1;

    return dice;
}

int numPlayers;  // Add this line to declare numPlayers

int playTurn(int player, int currentPosition, int boardSize, int isComputer, int *playerPositions){
    // ... (unchanged)
 printf("\nPlayer %c, it's your turn. Press enter to roll the die...", isComputer ? '1' : ('P' + player - 1));
    getchar(); // Wait for the user to press enter

    int dice;
    if (isComputer) {
        dice = computerTurn(currentPosition, boardSize);
        printf("%c rolled a %d.\n", isComputer ? 'C' : ('P' + player - 1), dice);
    } else {
        dice = rollDie();
        printf("You rolled a %d.\n", dice);
    }
currentPosition += dice;

    // Define snake and ladder positions
    int snakes[][2] = {{16, 6}, {47, 26}, {49, 11}, {56, 53}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78}};
    int ladders[][2] = {{1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91}, {80, 100}};

    // Check for snakes
    for (int i = 0; i < sizeof(snakes) / sizeof(snakes[0]); ++i) {
        if (currentPosition == snakes[i][0]) {
            printf("Oops! Snake at position %d. You go back to position %d.\n", currentPosition, snakes[i][1]);
            currentPosition = snakes[i][1];
        }
    }

    // Check for ladders
    for (int i = 0; i < sizeof(ladders) / sizeof(ladders[0]); ++i) {
        if (currentPosition == ladders[i][0]) {
            printf("Yay! Ladder at position %d. You climb to position %d.\n", currentPosition, ladders[i][1]);
            currentPosition = ladders[i][1];
        }
    }

    printf("You are now at position %d.\n", currentPosition);
    printf("Current Board:\n");
    for (int i = boardSize; i >= 1; --i) {
        for (int j = 1; j <= boardSize; ++j) {
            int position = (i - 1) * boardSize + j;

            // Print player positions
            char symbol = ' ';
            for (int p = 0; p < numPlayers; ++p) {
                if (playerPositions[p] == position) {
                    symbol = isComputer && p == 0 ? '1' : ('P' + p);
                    break;
                }
            }

            printf("[%2c] ", symbol);
        }
        printf("\n");
    }
    printf("\n");

    return currentPosition;
}

// Function to check if a player has won
int hasPlayerWon(int position, int boardSize) {
    return position >= boardSize * boardSize;
}

int main() {
    srand(time(NULL)); // Seed for random numbers

    int boardSize, isComputer;
    int *playerPositions;  // Move this declaration here

    // Get number of players
    do {
        printf("Enter the number of players (1 for computer vs human, 2 or more for human vs human): ");
        scanf("%d", &numPlayers);
        getchar(); // Consume newline character
    } while (numPlayers < 1);

    // Get board size
    do {
        printf("Enter the board size (minimum 10): ");
        scanf("%d", &boardSize);
        getchar(); // Consume newline character
    } while (boardSize < 10);

    playerPositions = (int *)malloc(numPlayers * sizeof(int));  // Allocate memory for playerPositions

    // Initialize player positions to zero
    for (int i = 0; i < numPlayers; ++i) {
        playerPositions[i] = 0;
    }

    printf("\nWelcome to Snake and Ladder Game!\n");

    while (1) {
        for (int i = 0; i < numPlayers; ++i) {
            playerPositions[i] = playTurn(i + 1, playerPositions[i], boardSize, (i == 0 && numPlayers == 1), playerPositions);
            if (hasPlayerWon(playerPositions[i], boardSize)) {
                if (numPlayers == 1 && i == 0) {
                    printf("Computer wins!\n");
                } else {
                    printf("Player %d wins!\n", i + 1);
                }
                free(playerPositions);
                return 0;
            }
        }
    }

    free(playerPositions);
    return 0;
}