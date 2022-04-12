#include "Ranking.h"
#include <stdlib.h>
#include <time.h>
extern int play5X5Puzzle();
extern int play5x5Puzzle();
void main()
{
	srand((unsigned int)time(NULL));
	loadRanking("ranking.txt");
	int rank = play5X5Puzzle();
	printRanking();
	
	play5X5Puzzle();
	play5x5Puzzle();
	for (int i = 0; i < 5; i++)
		addRanking(rand() % 500, rand() % 1000 * 0.1);
	storeRanking("ranking.txt");
}