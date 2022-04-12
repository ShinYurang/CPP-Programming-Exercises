#include <cstdio>

struct PlayInfo {
	char	name[200];	
	int	nMove;		
	double	tElapsed;	
};
extern void loadRanking(char* filename);
extern void storeRanking(char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);