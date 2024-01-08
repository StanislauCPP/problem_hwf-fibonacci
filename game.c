#include <stdio.h>
#include <stdlib.h>

#include "MatchesFibonacciGame.h"

void userTurn(unsigned* subMatches)
{
    unsigned parScanf;

    parScanf = scanf("%d", subMatches);
    if (parScanf != 1 || !(*subMatches))
    {
        printf("Incorrected input!!!\n");
        abort();
    }
}

void play()
{
    unsigned matches, subMatches = 0, possible;
    char playerNum = 0;

    unsigned* nSFibNum;

    srand(time(NULL));
    matches = rand() % 20;

    nSFibNum = getNSFibNum(matches);
    printf("Start amount of mathes %d\n", matches);
    possible = matches - 1;

    while (matches)
    {
        playerNum = !playerNum;

        printf("Player %d: ", playerNum);
        if (!playerNum)
        {
            userTurn(&subMatches);

            while ((subMatches > (possible)))
            {
                printf("Substracted mathes > last amount Substracted mathes(%d)\n", possible);
                printf("Player %d: ", playerNum);
                userTurn(&subMatches);
            }
        }
        else
        {
            subMatches = next_turn(matches, possible, nSFibNum);
            printf("%d\n", subMatches);
        }

        matches -= subMatches;
        possible = subMatches * 2;
        printf("Matches remained %d\n", matches);
    }
    free(nSFibNum);

    printf("Player %d won!!!\n", playerNum);
}

int main()
{
    play();

    return 0;
}
