#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_PLAYERS 5 // Maximum number of players
#define MAX_BOARD_SIZE 100
// Function to roll a die
int rollDie() {
    return rand() % 6 + 1;
}

// Function to play a turn
int playTurn(int player, int currentPosition) {
    printf("\nPlayer %d, it's your turn. Press enter to roll the die...", player);
    getchar(); // Wait for the user to press enter
    int dice = rollDie();
    printf("You rolled a %d.\n", dice);
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

    return currentPosition;
}

// Function to check if a player has won
int hasPlayerWon(int position) {
    return position >= 100;
}

int main() {
    srand(time(NULL)); // Seed for random numbers

    int numPlayers, boardSize;

    // Get number of players
    do {
        printf("Enter the number of players (2 or more): ");
        scanf("%d", &numPlayers);
        getchar(); // Consume newline character
    } while (numPlayers < 2);

    // Get board size
    do {
        printf("Enter the board size (minimum 10): ");
        scanf("%d", &boardSize);
        getchar(); // Consume newline character
    } while (boardSize < 10);

    int* playerPositions = (int*)malloc(numPlayers * sizeof(int));

    // Initialize player positions to zero
    for (int i = 0; i < numPlayers; ++i) {
        playerPositions[i] = 0;
    }

    printf("\nWelcome to Snake and Ladder Game!\n");

    while (1) {
        for (int i = 0; i < numPlayers; ++i) {
            playerPositions[i] = playTurn(i + 1, playerPositions[i]);
            if (hasPlayerWon(playerPositions[i])) {
                printf("Player %d wins!\n", i + 1);
                free(playerPositions);
                return 0;
            }
        }
    }

    free(playerPositions);
    return 0;
}