#define _CRT_SECURE_NO_WARNINGS

#include "MatchesFibonacciGame.h"

unsigned getNumSize(int total)
{
    unsigned fFib = 1, sFib = 1, numFib = 1, numSize = 0;

    if (total == 1)
        return 1;

    while (total >= numFib)
    {
        numFib = fFib + sFib;
        fFib = sFib;
        sFib = numFib;
        ++numSize;
    }

    return numSize;
}

unsigned getLowestDigit(unsigned numSize, unsigned* nSFibNum, unsigned residue)
{
    int i, futureResidue;
    char settedDigitFlag = 0;

    unsigned lowestDigit = 1;

    for (i = (numSize - 1); i >= 0; --i)
    {
        futureResidue = residue - nSFibNum[i];
        if (!residue || futureResidue < 0)
            settedDigitFlag = 0;
        else
        {
            if (settedDigitFlag)
                settedDigitFlag = 0;
            else
            {
                lowestDigit = nSFibNum[i];
                residue = residue - nSFibNum[i];
                settedDigitFlag = 1;
            }
        }
    }

    return lowestDigit;
}

int next_turn(int total, int possible, unsigned* nSFibNum)
{
    unsigned numSize = 0, lowestDigit;

    if (possible >= total)
        return total;
    else
    {
        numSize = getNumSize(total);
        lowestDigit = getLowestDigit(numSize, nSFibNum, total);
    }

    if (possible < lowestDigit)
        return 1;

    return lowestDigit;
}

unsigned* getNSFibNum(int total)
{
    unsigned* nSFibNum = NULL;
    unsigned fFib = 1, sFib = 1, numFib = 1;
    int numSize = 0;

    numSize = getNumSize(total);

    nSFibNum = calloc(numSize, sizeof(unsigned));

    fFib = 1, sFib = 1, numFib = 1;
    nSFibNum[0] = numFib;

    for (int i = 1; i < numSize; ++i)
    {
        numFib = fFib + sFib;
        nSFibNum[i] = numFib;
        fFib = sFib;
        sFib = numFib;
    }

    return nSFibNum;
}

