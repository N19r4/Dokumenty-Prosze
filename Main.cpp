// Dokumenty, proszê!.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

// NAMING
// struct names - uppercase characters and "_"
// variable names - small characters and "_"
// function names - small and one/two uppercase characters

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include <locale.h>
#include "Nag³ówek.h"

using namespace std;

//string passport_data_array[] = { *name_array, *surname_array, *birth_date_array, *country_date_array, *code_array };

// Program g³ówny
int main()
{
	setlocale(LC_CTYPE, "Polish");
	bool played = PlaySound(TEXT("SoundTrackTwo.wav"), NULL, SND_LOOP | SND_ASYNC);
	ShowMenu();
	system("pause");
}