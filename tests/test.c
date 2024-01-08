#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../MatchesFibonacciGame.h"

int main()
{
	unsigned matches, possible = 0, turn = 0;
	unsigned* nSFibNum;
	int parScanf, checkPar;

	parScanf = scanf("%u %u %d", &matches, &possible, &checkPar);
	if(parScanf != 3)
	{
		printf("Error! Unexpected input data of test\n");
		abort();
	}	
	
	nSFibNum = getNSFibNum(matches);
	
	assert(checkPar == next_turn(matches, possible, nSFibNum));

	free(nSFibNum);

	printf("Test passed\n\n");

	return 0;
}
