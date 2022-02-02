#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <locale.h>

using namespace std;

// Auxiliary functions

int TextCenter(string text[]);
int GenerateRandomNumber(int max);
string GenerateData(string array[], int max_range);
void Typewriter(string text, int which_line = 0);
void color(int color);
void gotoxy(int x, int y);
bool SaveGame(string file_name);
void WriteFromFileByIndex(int index, string file_name);
//void SayNext();
//string LetterChanger(string);

// Game functions

void DayChoose(int day_number);
void ShowMenu2();
void ShowMenu();
void ShowHowToPlay();
void InitializeGame();
void PlayGame();
void NewGame();
//void ContinueGame();
//bool CheckMistake(int, PASSPORT, PASSPORT);
//void ShowMenuForChoosingMistake(PASSPORT fake_passport, PASSPORT passport);

