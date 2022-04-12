#include "Ranking.h"
#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];	
static int nMVP = NUM_MVP;	

static void initRanking() {
	PlayInfo noname = { "C++good", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}

void loadRanking(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
}
void storeRanking(char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) return;
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);
}

void printRanking() {
	for (int i = 0; i < nMVP; i++)
		printf("  [rank:%2d]  %4d  %-16s %5.1f\n", i + 1, MVP[i].nMove,
			MVP[i].name, MVP[i].tElapsed);
}
int addRanking(int nMove, double tElap) {
	if (nMove < MVP[nMVP - 1].nMove) {
		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf(" Rank:%d. Enter your name : ", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}