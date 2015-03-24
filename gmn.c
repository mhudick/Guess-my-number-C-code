
//Name:  Michael Hudick
//Class: Operating Systems

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int playerOnePasses = 0;
    int playerTwoPasses = 0;
    int playerOnePassesInRow = 0;
    int playerTwoPassesInRow = 0;
    int correct = 0;
    int numberToGuess = rand() % 10 + 1; //generating "random" guess
    int guess;
    int currentPlayer = rand() % 2; //modulo to create bit checking for starting player
    int player = 0;
    int totalPassesOne = 0;
    int totalPassesTwo = 0;
    int onePassesLeft = 3;
    int twoPassesLeft = 3;


    printf("It is time to play Guess My Number!\n");
    printf("Guess a number 1 - 10\n");
    printf("if you enter 0 you will pass your turn\n");
    printf("you cannot pass more than twice in a row nor three times in a game\n");
      do{
        //which player is playing logic
        currentPlayer = currentPlayer % 2;
        if(currentPlayer == 0){
          player = 1;

        }else{
          player = 2;
        }
        printf("Player ");
        printf("%i", player);
        printf(" make your choice!\n");
        // guess retrieval
        scanf("%i", &guess);
        // player 1 logic to disallow too many passes
        if (player == 1){
          if (totalPassesOne == 3 || playerOnePassesInRow == 2){
            printf("you cannot pass anymore.\n");
            printf("please choose your guess again\n");
            while(guess == 0){
              scanf("%i", &guess);
            }
          }
        }
        // player 2 logic to disallow too many passes
        if (player == 2){
          if (totalPassesTwo == 3 || playerTwoPassesInRow == 2){
            printf("you cannot pass anymore.\n");
            printf("please choose your guess again\n");
            while(guess == 0){
              scanf("%i", &guess);
            }
          }
        }


        // logic gate for correct guess, also end condition
        if(guess == numberToGuess){
            correct = 1;
            if (player == 1){
              printf("Player one has won!\n");
            } else{
              printf("Player two has won!\n");
            }
        }
        //check that says the user did not guess right
        if(guess != numberToGuess && guess != 0){
          printf("test\n");
          if (player == 1){
            printf("Player one has guessed wrong\n");
            playerOnePassesInRow = 0; //resetting guesses in a row
            if(guess > numberToGuess){ // to high or too low logic gate
              printf("your guess is to high\n");
            }else{
              printf("your guess is to low\n");
            }

          } else{
            printf("Player two has guessed wrong\n");
            playerTwoPassesInRow = 0; // resetting guesses in a row
            if(guess > numberToGuess){ // too high or too low logic gate
              printf("your guess is to high\n");
            }else{
              printf("your guess is to low\n");
            }
          }
        }

        if(guess == 0){  // checking to see if a user passes
          if(player == 1){ //checking if player is player 1
            printf("Player one has passed\n");
            playerOnePasses++;
            playerOnePassesInRow++;
            totalPassesOne++;
            onePassesLeft--;
            printf("%i", onePassesLeft);
            printf(" passes left\n");
            }
            else{ // if not player 1 operates on player 2
            printf("Player two has passed\n");
            playerTwoPasses++;
            playerTwoPassesInRow++;
            totalPassesTwo++;
            twoPassesLeft--;
            printf("%i", twoPassesLeft); // how many total passes left for player 2
            printf(" passes left\n");
            }
          }
        currentPlayer++; // bit operation to differentiate from each player
      }while (guess != numberToGuess ); // end condition
}
