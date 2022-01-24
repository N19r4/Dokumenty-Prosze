#include <iostream>
#include <fstream> // biblioteka do plikow
#include <ctime> // biblioteka do czasu
#include <random> // biblioteka do losowego generowania
#include <stdlib.h> // biblioteka do polecen systemowych
#include <windows.h> // biblioteka do "sleep"
#include <iomanip> // biblioteka do manipulacji wygladu i out
#include <string>
#include <chrono>
#include <conio.h>
#include "Nag³ówek.h"

using namespace std;

void gotoxy(int x, int y);

// Arrays

string name_array[] = { "Grigorij", "Nikolai", "Marika", "Paul", "Katrina", "Eva", "Dimitr", "Anna", "Francesca", "Alexandr", "Kristof", "Eric", "Vladimir", "Alisa", "Andrei", "Nastya", "Misha", "Mariya", "Peter", "Aleksandra", "Lev", "Kostya", "Boris", "Rodion", "Anatoli", "Efrosin", "Isaak", "Anushka", "Radianka", "Mikhail", "Wilhelmine", "Jochem", "Luther", "Vogel" };
string surname_array[] = { "Kovalev", "Webov", "Gitarov", "Kaczmarov", "Ginter", "Russ", "Schumann", "Guttman", "Mikhaylov", "Morozov", "Vlasov", "Petrov", "Vasiliev", "Lebedev", "Sokolovic", "Kuzumin", "Bogdanovic", "Pushkin", "Sitz", "Fredrich", "Vonnegut", "Eichel", "Sommer", "Roth", "Neumann", "Shulz", "Hofmann", "Waltz" };
string birth_date_array[] = { "23.04.1976", "12.09.1956", "01.05.1982", "11.07.1968", "09.09.1990", "05.07.1976", "23.12.1965", "13.06.1919", "19.08.1945", "04.08.1963", "29.01.1945", "09.11.1943", "01.09.1907", "07.10.1923", "17.03.1972" };
string country_array[] = { "Arstotzka", "Kolechia", "Obristan", "Republia", "Altan", "Morstana", "West Grestin" };
string code_array[] = { "RGRD2-WTGDF-A674F", "DDFF2-RTVV9-89DFD", "RERG1-JYUJT-56G45", "3454F-9D9FG-SDF98", "DF98G-SDUFI-DF98G", "S98UF-SD9FD-0FGIB", "I3HI4-234BJ-23JKK", "GE8U9-REBRR-QWE78", "29HR9-BQ7E8-QNWOE", "9W9EH-EIWEU-QI2UE", "QUY28-08QXC-34HT7", "FN9FW-BMF9G-WJ9E8", "B8374-2I3RN-IEWUW", "Q09IJ-B2383-IN5TI", "B874B-VHW8E-N2O33", "98GJF-23IEN-19OIR", "09DIF-ASUDH-08NO3", "09IVX-WNE8R-2N398", "2N3O4-IJ8FD-3WJNK" };
string weight_array[] = { "64", "56", "90", "37", "58", "41", "98", "34", "94", "86", "65", "62", "75", "68", "49", "79", "62", "61", "70", "78", "53", "51", "48" };
string height_array[] = { "174", "167", "198", "179", "180", "159", "163", "190", "197", "143", "172", "153", "187", "162", "157", "194", "134", "161", "171", "129", "133", "182"};
string passport_types_of_data_array[] = { "name", "surname", "birth_date", "country", "code"};
string id_card_types_of_data_array[] = { "name", "surname", "birth_date", "country", "height", "weight"};

// Structs

/*extern struct DATA
{
	int DayNumber;
	int CoinsNumber;
	bool SaveGame(string file_name)
	{
		ofstream file;

		file.open(file_name);
		if (file.is_open())
		{
			file << CoinsNumber << endl;
			file << DayNumber << endl;

			file.close();
		}
		else
			cout << "Save file not found." << endl;
	}
};*/

extern struct ID_CARD
{
	string name;
	string surname;
	string birth_date;
	string country;
	string height;
	string weight;
	void PrintIdCard()
	{
		int width = 25;
		cout << setfill(' ');
		//cout << setw(19) << "IDENTITY CARD" << endl;
		cout << setw(19) << "DOWOD OSOBISTY" << endl;
		cout << "+" << setfill('-') << setw(width) << "+" << endl;
		cout << "Dystrykt " << country;
		cout << endl;
		cout << "+" << setfill('-') << setw(width) << "+" << endl;
		cout << surname << " " << name;
		cout << endl;
		cout << "-" << setfill('-') << setw(width) << "-" << endl;
		cout << "Ur: " << birth_date;
		cout << endl;
		cout << "Wys: " << height << "cm";
		cout << endl;
		cout << "Wg: " << weight << "kg";
		cout << endl;
		cout << "+" << setfill('-') << setw(width) << "+" << endl;
	};
	void GenerateIdCard()
	{
		height = GenerateData(height_array, _countof(height_array));
		weight = GenerateData(weight_array, _countof(weight_array));
	}
};

extern struct PASSPORT
{
	string name;
	string surname;
	string birth_date;
	string country;
	string code;
	void GeneratePassport()
	{
		name = GenerateData(name_array, _countof(name_array));
		surname = GenerateData(surname_array, _countof(surname_array));
		birth_date = GenerateData(birth_date_array, _countof(birth_date_array));
		country = GenerateData(country_array, _countof(country_array));
		code = GenerateData(code_array, _countof(code_array));
	};
	void PrintPassport()
	{
		int x = 60;
		int y = 10;

		gotoxy(x, y);
		cout << setfill(' ');
		//cout << setw(19) << "ENTRY VISA" << endl;
		gotoxy(x, y + 1);
		cout << setw(19) << "VISA WEJSCIOWA" << endl;
		gotoxy(x, y + 2);
		cout << "+" << setfill('-') << setw(30) << "+" << endl;
		gotoxy(x, y + 3);
		cout << name << ", " << surname;
		gotoxy(x, y + 4);
		//cout << endl;
		cout << "-" << setfill('-') << setw(30) << "-" << endl;
		gotoxy(x, y + 5);
		//cout << endl;
		cout << "Urodzony/a: " << birth_date;
		gotoxy(x, y + 6);
		//cout << endl;
		cout << "Obywatelstwo: " << country;
		gotoxy(x, y + 7);
		//cout << endl;
		cout << code;
		gotoxy(x, y + 8);
		//cout << endl;
		cout << "+" << setfill('-') << setw(30) << "+" << endl;
	};
	
};

string LetterChanger(string text_to_change)
{
	int i = 0;
	char random_letter;
	while (text_to_change[i] != '\0')
	{
		i++;
	}

	int letter_index = GenerateRandomNumber(i);

	if (text_to_change[letter_index] >= 97 && text_to_change[letter_index] <= 122)
		random_letter = GenerateRandomNumber(25)+97;
	else if (text_to_change[letter_index] >= 65 && text_to_change[letter_index] <= 90)
		random_letter = GenerateRandomNumber(25) + 65;
	else if (text_to_change[letter_index] >= 48 && text_to_change[letter_index] <= 57)
		random_letter = GenerateRandomNumber(9) + 48;
	else
		return text_to_change;

	text_to_change[letter_index] = random_letter;
	return text_to_change;
}

// Generator b³êdu dla paszportu
PASSPORT PassportMistakeGenerator(PASSPORT right_passport)
{
	PASSPORT fake_passport = right_passport;
	string mistake = "name";
	mistake = GenerateData(passport_types_of_data_array, _countof(passport_types_of_data_array));

	// U¿ywam "if" poniewa¿ switch nie przyjmuje "stringa"
	if (mistake == "name")
	{
		fake_passport.name = LetterChanger(right_passport.name);
	}
	else if (mistake == "surname")
	{
		fake_passport.surname = LetterChanger(right_passport.surname);
	}
	else if (mistake == "birth_date")
	{
		fake_passport.birth_date = LetterChanger(right_passport.birth_date);
	}
	else if (mistake == "country")
	{
		fake_passport.country = LetterChanger(right_passport.country);
	}
	else if (mistake == "code")
	{
		fake_passport.code = LetterChanger(right_passport.code);
	}
	else
		return right_passport;
	return fake_passport;
}

extern struct GAME_DATA
{
	int CoinsNumber;
	int DayNumber;
	
	void SaveGame(string file_name)
	{
		ofstream file;

		file.open(file_name);
		if (file.is_open())
		{
			file << CoinsNumber << endl;
			file << DayNumber << endl;

			file.close();
		}
		else
		{
			cout << "Save file not found." << endl;
		}
	}
	void LoadGame(string file_name)
	{
		string data[2];
		int i = 0;

		ifstream file;
		file.open(file_name);
		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, data[i]);
				i++;
			}
			file.close();
		}
		else
			cout << "Error." << endl;
	}
};

// Variables

int DayNumber{};
int CoinsNumber{};

/*int TextCenter(string text[])
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD max_size = GetLargestConsoleWindowSize(screen);

	COORD pos;
	pos.X = (max_size.X - sizeof(text)) / 2;
	pos.Y = max_size.Y / 2;
	SetConsoleCursorPosition(screen, pos);

	LPDWORD written;
	WriteConsole(screen, text, sizeof(text), written, 0);

	return 0;
}*/

// Functions

// Inicjalizacja gry
void InitializeGame()
{
	CoinsNumber = 60;
	DayNumber = 1;
}
// Generator liczb losowych od 1 do zadanej liczby
int GenerateRandomNumber(int max)
{
	int range = max;
	srand(time(nullptr));
	int num = rand() % range + 1;

	return num;
}
// Generator danych osobowych petenta
string GenerateData(string array[], int max_range)
{
	--max_range;
	string data = array[GenerateRandomNumber(max_range)];
	return data;
}
// G³ówna czêœæ - wybór dnia
int GoToWork(int DayNumber)
{
	DayChoose(DayNumber);

	system("pause");
	ShowMenu();

	return 0;
}
// Funkcja wypisuj¹ca z pliku jak na maszynie
void WriteFromFileByIndex(int index, string file_name)
{
	gotoxy(40, 5);

	string text;
	char z{};

	ifstream file;
	file.open(file_name);
	if (file.is_open())
	{
		while (!file.eof())
		{
			file.get(z);
			if ((z - '0') == index)
			{
				getline(file, text);
				Typewriter(text);
				break;
			}
		}
		file.close();
	}
	else
		cout << "Error." << endl;
}
void hidecursor() 
{ 
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   
	CONSOLE_CURSOR_INFO info;   
	info.dwSize = 100;   
	info.bVisible = FALSE;   
	SetConsoleCursorInfo(consoleHandle, &info); 
}

// Jak graæ?
void ShowHowToPlay()
{
	system("CLS");
	int option;
	cout << "Dziekujemy za granie w \"Dokumenty, prosze!\"." << endl << endl;

	cout << "   ___   __   __ __   __    ___ " << endl;
	cout << "  | _,\\ /__\\ |  V  | /__\\  / _/ " << endl;
	cout << "  | v_/| \\/ || \\_/ || \\/ || \\__ " << endl;
	cout << "  |_|   \\__/ |_| |_| \\__/  \\__/ " << endl;

	cout << endl << "W grze wcielisz sie w inspektora imigracyjnego sprawdzajacego dokumenty na granicy Twojego kraju - Kavertii.";
	cout << endl << endl;
	cout << "Podstawowa mechanika jest tu wybieranie, ktora z informacji zawartych w dokumentach petentow jest niezgodna z innymi papierami tegoz petenta lub z obecnym prawem. Na poczatku kazdego dnia zostaniesz zapoznany z nowym przepisem, ktorego nalezy przestrzegac.\nAby podac, w ktorym miejscu wedlug Ciebie znajduje sie blad, wystarczy wpisac nazwe informacji z niezgodnoscia, na przyklad: imie, data urodzenia, waga.Jesli nie widzisz zadnego bledu, po prostu wpisz: brak.\n\nNastepnie, bedziesz musial zadecydowac, czy przepuscisz danego petenta, czy nie w zaleznoci od Twoich wyborow moralnych.\nPamietaj! Jesli przepuscisz osobe, ktorej dokumenty byly niezgodne lub nie przepuscisz osoby, ktora zadbala o poprawnosc papierow - stracisz czesc swojej wyplaty.";

	cout << endl << endl;
	cout << "Aby zglosic, w ktorym miejscu jest blad wystarczy wpisac nazwe typu danej informacji np. imie, data urodzenia, kraj pochodzenia itd.";

	cout << "\n\n" << "Powodzenia!";
	color(3);
	cout << endl << endl << "< Back" << endl;
	color(7);
	system("pause");
	ShowMenu();
}
// Ekran stworzenia nowej gry lub za³adowania istniej¹cej
void PlayGame()
{
	system("CLS");
	//Tu trzeba sprawdzic czy istnieje plik zapisu
	//if(plik istnieje) {poka¿ opcjê kontynuuj grê}
	//else {poka¿ tylko opcjê "nowa gra"}
	int menu_y = 13;
	int Set[] = { 7,7,7 }; // DEFAULT COLORS
	int main_color = 7;
	int hover_color = 3;
	int menu_width = 45;

	int counter = 1;
	char key;

	for (int i = 0;;)
	{
		gotoxy(24, menu_y);
		color(Set[0]);
		cout << setw(menu_width - 2) << "NOWA GRA";

		gotoxy(24, menu_y+1);
		color(Set[1]);
		cout << setw(menu_width) << "WCZYTAJ GRE";

		key = _getch();

		if (key == 72 && counter == 2)
			counter--;
		if (key == 80 && counter == 1)
			counter++;
		if (key == '\r')
		{
			color(7);
			if (counter == 1)
				NewGame();
			if (counter == 2)
				DayChoose(1);
		}

		Set[0] = 7;
		Set[1] = 7;

		if (counter == 1)
			Set[0] = hover_color;
		if (counter == 2)
			Set[1] = hover_color;
	}
}
// Funkcja prosz¹ca o podanie b³êdu
/*bool WhereIsTheMistake(string mistake_type, PASSPORT right_passport, PASSPORT wrong_passport, ID_CARD right_id_card, ID_CARD wrong_id_card)
{

}*/
// Nowa gra
//------------------------------------
void NewGame()
{
	InitializeGame();
	system("CLS");
	Typewriter("Witajcie obywatelu!Zostala wam przydzielona bardzo wazna funkcja inspektora emigracyjnego.Macie za zadanie sprawdzac dokumenty kazdego petenta.Pilnujcie przepisow!Sprawujcie sie dobrze.\n\n");
	system("CLS");
	
	GoToWork(DayNumber);
}
//------------------------------------

// Funkcja wypisuj¹ca tekst jak na maszynie
void Typewriter(string text, int which_line)
{
	int line_index = 1;
	int i = 0;
	gotoxy(24, 10 + which_line);
	
	while (text[i] != '\0')
	{
		Sleep(50);
		
		cout << text[i];
		//Beep(777, 20);

		if (text[i] == '.' || text[i] == '!')
		{
			gotoxy(24, 10 + line_index);
			line_index++;
		}
		i++;
	}
	//cout << text;
	
	Sleep(500);
};
// Funkcja zmieniaj¹ca kolor tekstu
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Funkcja pokazuj¹ca menu g³ówne
void ShowMenu()
{
	system("CLS");

	bool played = PlaySound(TEXT("SoundTrack.wav"), NULL, SND_ASYNC | SND_LOOP);

	hidecursor();

	int starting_point_x = 20;
	int starting_point_y = 5;

	//cout << setfill(' ') << setw(25);
	gotoxy(starting_point_x, starting_point_y);
	cout << "   __    __   _  __ _  _  __ __  ___  __  _  _____ __   __   ___  ___   __    __  ___  ___  _  " << endl;
	gotoxy(starting_point_x, starting_point_y+1);
	cout << "  | _\\  /__\\ | |/ /| || ||  V  || __||  \\| ||_   _|\\ `v' /  | _,\\| _ \\ /__\\ /' _/|_  || __|/ \\ " << endl;
	gotoxy(starting_point_x, starting_point_y+2);
	cout << "  | v || \\/ ||   < | \\/ || \\_/ || _| | | ' |  | |   `. .'_, | v_/| v /| \\/ |`._`. / / | _| \\_/ " << endl;
	gotoxy(starting_point_x, starting_point_y+3);
	cout << "  |__/  \\__/ |_|\\_\\ \\__/ |_| |_||___||_|\\__|  |_|    !_![_/ |_|  |_|_\\ \\__/ |___/|___||___|(_) " << endl;
	gotoxy(starting_point_x, starting_point_y+4);
	cout << "                                                                                        |/      " << endl;

	int Set[] = { 7,7,7 }; // DEFAULT COLORS
	int main_color = 7;
	int hover_color = 3;
	int menu_width = 45;

	int counter = 1;
	char key;

	int menu_y = 13;

	for (int i = 0;;)
	{
		gotoxy(24, menu_y);
		color(Set[0]);
		cout << setw(menu_width-1) << "GRAJ";

		gotoxy(24, menu_y+1);
		color(Set[1]);
		cout << setw(menu_width) << "POMOC";

		gotoxy(24, menu_y+2);
		color(Set[2]);
		cout << setw(menu_width) << "WYJDZ";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 3))
			counter--;
		if (key == 80 && (counter >= 1 && counter <= 2))
			counter++;
		if (key == '\r')
		{
			if (counter == 1)
				PlayGame();
			if (counter == 2)		
				ShowHowToPlay();
			if (counter == 3)
			{
				color(main_color);
				cout << endl;
				exit(0);
			}
		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;

		if (counter == 1)
			Set[0] = hover_color;
		if (counter == 2)
			Set[1] = hover_color;
		if (counter == 3)
			Set[2] = hover_color;
	}
}

bool CheckMistake(int choice, PASSPORT fake_passport, PASSPORT right_passport)
{
	switch (choice)
	{
	case 1:
		if (fake_passport.name == right_passport.name)
			return false;
		break;
	case 2:
		if (fake_passport.surname == right_passport.surname)
			return false;
		break;
	case 3:
		if (fake_passport.birth_date == right_passport.birth_date)
			return false;
		break;
	case 4:
		if (fake_passport.country == right_passport.country)
			return false;
		break;
	case 5:
		if (fake_passport.code == right_passport.code)
			return false;
		break;
	}
	return true;
}

// Funkcja pokazuj¹ca menu g³ówne
int ShowMenuForChoosingMistake(PASSPORT fake_passport, PASSPORT right_passport)
{
	int choice;
	int salary = 0;

	// Zrobiæ menu które wypisuje siê z tablicy!!!
	cout << "1. imie\n";
	cout << "2. nazwisko\n";
	cout << "3. data urodzenia\n";
	cout << "4. kraj\n";
	cout << "5. kod\n";
	cout << "6. Brak niezgodnosci\n";

	bool mistake_is_here = false;

	do
	{
		cout << "Wybierz opcje: ";
		cin >> choice;
		if (choice >= 1 && choice <= 6)
		{
			if (choice == 6)
			{
				cout << "W paszporcie nie ma zadnego bledu\n";
				mistake_is_here = true;
			}
			else
			{
				mistake_is_here = CheckMistake(choice, fake_passport, right_passport);
				if (mistake_is_here)
					cout << "\nWykryto nezgodnosc\n";
				else
					cout << "\nNie wykryto nezgodnosci\n";
			}
		}
		else
			cout << "\nPodaj poprawna wartosc!\n";

	} while (!mistake_is_here);

	if (choice == 6 && (fake_passport.name != right_passport.name || fake_passport.surname != right_passport.surname || fake_passport.birth_date != right_passport.birth_date || fake_passport.country != right_passport.country || fake_passport.code != right_passport.code))
	{
		system("CLS");
		Typewriter("Upomnienie. Dane petenta byly niezgodne. -5$");
		salary -= 5;
	}
	else
	{
		system("CLS");
		Typewriter("Poprawnie. +10$.");
		salary += 10;
	}
	cout << endl;
	return salary;
}

int TestingFunction()
{
	int main_color = 0;
	int hover_color = 7;
	int menu_width = 45;

	int counter = 1;
	char key;

	for (int i = 0;;)
	{
		//gotoxy(100, 5);

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 3))
			counter--;
		if (key == 80 && (counter >= 1 && counter <= 2))
			counter++;
		if (key == '\r')
		{
			if (counter == 1)
			{
				cout << "\n";
				cout << "                   ";
				cout << "\rSprawdz imie.";
			}
			if (counter == 2)
			{
				cout << "\n";
				cout << "                   ";
				cout << "\rSprawdz nazwisko.";
			}
			if (counter == 3)
			{
				cout << "\n";
				cout << "                   ";
				cout << "\rSprawdz wiek.";
			}
		}

		cout << "\r";
		cout << "                  ";
		cout << "\r";

		if (counter == 1)
			cout << "Imie";
		if (counter == 2)
			cout << "Nazwisko";
		if (counter == 3)
			cout << "Wiek";
	}
}

void SayNext()
{
	system("CLS");
	Typewriter("> Nastepny\n\n");
	system("CLS");
}

void DayChoose(int day_number)
{
	char key;
	int salary = 0;
	system("CLS");

	//gotoxy(55, 3);
	//cout << "TYGODNIK CODZIENNY" << endl;
	Typewriter(" MAGAZYN CODZIENNY", -2);
	WriteFromFileByIndex(DayNumber, "DayNews.txt");
	system("CLS");

	//gotoxy(50, 3);
	//cout << "Dzien " << DayNumber << endl;
	Typewriter(" DZIEN ", -2);
	cout << DayNumber;
	WriteFromFileByIndex(DayNumber, "DayRules.txt");
	system("CLS");

	Typewriter("> Rozpocznij dzien.\n");
	do 
	{
		key = _getch();

	} while (key != '\r');

		double seconds_since_start = 0;
		auto time_start = time(0);

		switch (day_number)
		{
		case 1:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosze.");
				Typewriter("Oto one.", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				Typewriter("> Imie i nazwisko.", 2);
				Typewriter(passport.name + " " + passport.surname, 3);
				cout << endl << endl;	
				
				//ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country };
				//id_card.GenerateIdCard();
				
				cout << endl << endl;
				PASSPORT fake_passport;
				fake_passport = PassportMistakeGenerator(passport);
				fake_passport.PrintPassport();

				//salary += ShowMenuForChoosingMistake(fake_passport, passport);
				
				TestingFunction();
				//cout << endl << endl;
				//id_card.PrintIdCard();
				system("pause");

				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 60);
			break;
		}
		case 2:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosze.");
				cout << endl << endl;
				PASSPORT passport;
				passport.GeneratePassport();
				passport.PrintPassport();
				cout << endl << endl;
				system("pause");

				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 10);
			break;
		}
		default:
		{
			ShowMenu();
			break;
		}
		}
		cout << endl;
		system("CLS");
		gotoxy(40, 5);
		cout << "Koniec dnia!\n\n";
		gotoxy(40, 7);
		cout << "Zarobiles " << salary << "$";
		cout << endl << endl;
		CoinsNumber += salary;

		DayNumber++;

		system("pause");
		cout << endl;
		DayChoose(DayNumber);
}