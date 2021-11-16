#ifndef _HIGH_SCORES_H_
#define _HIGH_SCORES_H_


#define MAX_NUM_OF_HS 5


#define LEN_OF_HEADER 10
#define MAX_LEN_OF_NAME 20
#define MAX_LEN_OF_SCORE 6
#define SIZE_OF_ID_CHR 2
/*!	\file highScores.h
*	\brief Contains structures and functions definitons used to manage highscores
*/


/*!	\brief structure used to handle name and score of player
*	\param name
*	\param score
*/
typedef struct
{
	char name[MAX_LEN_OF_NAME];
	int score;
} HighScore;

/*!	\brief structure used to handle list of highscores
*	\param list of highscores
*/
typedef struct {
	HighScore list[MAX_NUM_OF_HS];
} HighScoreList;

void Encrypt(HighScore, char*, char*);

void Decrypt(char*, char*, HighScore*);

int Original(char*);

void CreateHighScoresFile();

int FileExists(const char *);

HighScoreList ReadHighScores();

void WriteToHSFile(HighScoreList Players);

void UpdateHighScores(char*, int);

#endif

