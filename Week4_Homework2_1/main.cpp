#include "Ranking.h"
#include <stdlib.h>
#include <time.h>
extern int play3X3Puzzle();
extern int play3x3Puzzle();
void main()
{
	srand((unsigned int)time(NULL));
	loadRanking("ranking.txt");
	int rank = play3X3Puzzle();
	printRanking();
	
	play3X3Puzzle();
	play3x3Puzzle();
	for (int i = 0; i < 5; i++)
		addRanking(rand() % 500, rand() % 1000 * 0.1);
	storeRanking("ranking.txt");
}