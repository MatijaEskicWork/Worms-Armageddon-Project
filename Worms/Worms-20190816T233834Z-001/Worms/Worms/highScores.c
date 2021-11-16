#include <stdio.h>
#include "highScores.h"
#include <string.h>
#include <stdlib.h>
/*!	\file highScores.c
*	\brief Contains all function used for handling highscores
*/

const char *hs_file_name = "Worms8px.ico.png";


const char *icon_path = "Worms16px.ico.png";

const char id_char[SIZE_OF_ID_CHR] = "$";

/*!	\brief Function used for encypting name and score before storing them in file
*	\param structure player containt it's name and score
*	\param encrypted name
*	\param encrypted score
*/
void Encrypt(HighScore Player, char *en_name, char *en_score)
{
	strcpy(en_name, Player.name);
	char *a = en_name;
	int ia = *a;
	while (*a != '\0')
	{
		ia = *a;
		ia = ~ia;
		*a = ia;
		a++;
	}
	sprintf(en_score, "%d", Player.score);
	a = en_score;
	ia = *a;
	while (*a != '\0')
	{
		ia = *a;
		ia = ~ia;
		*a = ia;
		a++;
	}

}

/*!	\brief Function used for decrypting player name and score after reading it from file and before printing on screen
*	\param decrypted name
*	\param decrypted score
*	\param structure player containing decrypted name and score
*/
void Decrypt(char *dec_name, char *dec_score, HighScore *Player)
{
	char *a = dec_name;
	int ia, score;
	while (*a != '\0')
	{
		ia = *a;
		ia = ~ia;
		*a = ia;
		a++;
	}
	strcpy(Player->name, dec_name);
	a = dec_score;
	while (*a != '\0')
	{
		ia = *a;
		ia = ~ia;
		*a = ia;
		a++;
	}
	score = atoi(dec_score);
	Player->score = score;
}

/*!	\brief Checking if file is okay
*	\param path
*/
int Original(char *path)
{
	int counter = 0;
	char id_char_pom[SIZE_OF_ID_CHR], header[LEN_OF_HEADER], s1[MAX_LEN_OF_NAME], s2[MAX_LEN_OF_SCORE];  //s1 i s2 su nebitni stringovi, dodati kao zamena za fseek()
	FILE *file = fopen(path, "rb");

	fread(header, sizeof(header), 1, file);

	for (int i = 0; i < MAX_NUM_OF_HS; i++)
	{
		fread(s1, sizeof(s1), 1, file);
		fread(s2, sizeof(s2), 1, file);
		fread(id_char_pom, sizeof(id_char_pom), 1, file);
		if (strcmp(id_char_pom,id_char)==0)
			counter++;
	}
	
	fclose(file);
	return counter == MAX_NUM_OF_HS ? 1 : 0;
}

/*!	\brief Function used for creating highscores file
*/
void CreateHighScoresFile()
{
	int bool_file_exists = FileExists(hs_file_name);
	if (!bool_file_exists || !Original(hs_file_name))
	{
		char en_name[MAX_LEN_OF_NAME], en_score[MAX_LEN_OF_SCORE], header[LEN_OF_HEADER];
		FILE *hs_file = fopen(hs_file_name, "wb");
		FILE *icon = fopen(icon_path, "rb");
		HighScore generate_player;
		int gen_score = -1;
		const char gen_name[MAX_LEN_OF_NAME] = "NoName";

		fread(header, sizeof(header), 1, icon);
		fwrite(header, sizeof(header), 1, hs_file);
		fclose(icon);

		strcpy(generate_player.name, gen_name);
		generate_player.score = gen_score;
		Encrypt(generate_player, en_name, en_score);

		for (int i = 0; i < MAX_NUM_OF_HS; i++) // Upisi u datoteku istog igraca MAX_NUM_OF_HS puta
		{
			fwrite(en_name, sizeof(en_name), 1, hs_file);
			fwrite(en_score, sizeof(en_score), 1, hs_file);
			fwrite(id_char, sizeof(id_char), 1, hs_file);
		}
		fclose(hs_file);
	}
}

/*!	\brief Function used to check if file exists
*	\param file name
*/
int FileExists(const char *file_name)
{
	FILE *f;
	if (f = fopen(file_name, "rb"))
	{
		fclose(f);
		return 1;
	}
	return 0;
}

/*!	\brief Function used for reading highscore list from file
*/
HighScoreList ReadHighScores()
{
	HighScoreList A;
	HighScore Player;
	FILE *hs_file = fopen(hs_file_name, "rb");
	char header[LEN_OF_HEADER], name[MAX_LEN_OF_NAME], score[MAX_LEN_OF_SCORE];
	char id_char_pom[SIZE_OF_ID_CHR];

	fread(header, sizeof(header), 1, hs_file);

	for (int i = 0;i < MAX_NUM_OF_HS;i++)
	{
		fread(name, sizeof(name), 1, hs_file);
		fread(score, sizeof(score), 1, hs_file);
		fread(id_char_pom, sizeof(id_char_pom), 1, hs_file);
		Decrypt(name, score, &Player);
		A.list[i] = Player;
	}
	fclose(hs_file);
	return A;
}

/*!	\brief Function used to write encrypted names and scores into file
*	\param list of players
*/
void WriteToHSFile(HighScoreList Players)
{
	char name[MAX_LEN_OF_NAME], score[MAX_LEN_OF_SCORE];
	char header[LEN_OF_HEADER];
	FILE *hs_file = fopen(hs_file_name, "wb");
	FILE *icon = fopen(icon_path, "rb");
	fread(header, sizeof(header), 1, icon);
	fwrite(header, sizeof(header), 1, hs_file);
	for (int i = 0; i < MAX_NUM_OF_HS; i++)
	{
		Encrypt(Players.list[i], name, score);
		fwrite(name, sizeof(name), 1, hs_file);
		fwrite(score, sizeof(score), 1, hs_file);
		fwrite(id_char, sizeof(id_char), 1, hs_file);
	}
	fclose(hs_file);
	fclose(icon);
	return;
}

/*!	\brief Function used for updating highscores file after every game
*	\param name
*	\param score
*/
void UpdateHighScores(char *name, int score)  //Glavna funckija
{
	CreateHighScoresFile();

	HighScore player;
	int changed = 0;
	strcpy(player.name, name);
	player.score = score;

	HighScoreList OldPlayers = ReadHighScores();

	for (int i = 0;i < MAX_NUM_OF_HS;i++)
	{
		if (OldPlayers.list[i].score <= player.score)
		{
			changed = 1;
			for (int j = MAX_NUM_OF_HS - 1; j - 1 >=i ; j--)
			{
				OldPlayers.list[j] = OldPlayers.list[j - 1];
			}
			OldPlayers.list[i] = player;
			break;
		}
	}
	if(changed)
		WriteToHSFile(OldPlayers);
}

