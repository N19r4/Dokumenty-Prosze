#include <iostream>
#include <fstream> // biblioteka do plikow
#include <ctime> // biblioteka do czasu
#include <random> // biblioteka do losowego generowania
//#include <stdlib.h> // biblioteka do polecen systemowych
#include <windows.h> // biblioteka do "sleep"
#include <iomanip> // biblioteka do manipulacji wygladu i out
#include <string>
//#include <chrono>
#include <conio.h>
#include <locale.h>
#include "Nag??wek.h"

using namespace std;

// Arrays

string name_array[] = { "Grigorij", "Nikolai", "Marika", "Paul", "Katrina", "Eva", "Dimitr", "Anna", "Francesca", "Alexandr", "Kristof", "Eric", "Vladimir", "Alisa", "Andrei", "Nastya", "Misha", "Mariya", "Peter", "Aleksandra", "Lev", "Kostya", "Boris", "Rodion", "Anatoli", "Efrosin", "Isaak", "Anushka", "Radianka", "Mikhail", "Wilhelmine", "Jochem", "Luther", "Vogel" };
string surname_array[] = { "Kovalev", "Webov", "Gitarov", "Kaczmarov", "Ginter", "Russ", "Schumann", "Guttman", "Mikhaylov", "Morozov", "Vlasov", "Petrov", "Vasiliev", "Lebedev", "Sokolovic", "Kuzumin", "Bogdanovic", "Pushkin", "Sitz", "Fredrich", "Vonnegut", "Eichel", "Sommer", "Roth", "Neumann", "Shulz", "Hofmann", "Waltz" };
string birth_date_array[] = { "23.04.1926", "12.09.1939", "01.05.1922", "11.07.1918", "09.09.1910", "05.07.1906", "23.12.1940", "13.06.1919", "19.08.1941", "04.08.1913", "29.01.1935", "09.11.1933", "01.09.1907", "07.10.1923", "17.03.1932", "04.07.1945", "01.01.1943", "05.11.1939", "07.08.1939", "26.04.1940"};
string country_array[] = { "Kavertia", "Derad", "Ugratia", "Kolosia", "Mamaika", "West Mastern", "Paladia", "East Retkorn"};
string code_array[] = { "RGRD2-WTGDF-A674F", "DDFF2-RTVV9-89DFD", "RERG1-JYUJT-56G45", "3454F-9D9FG-SDF98", "DF98G-SDUFI-DF98G", "S98UF-SD9FD-0FGIB", "I3HI4-234BJ-23JKK", "GE8U9-REBRR-QWE78", "29HR9-BQ7E8-QNWOE", "9W9EH-EIWEU-QI2UE", "QUY28-08QXC-34HT7", "FN9FW-BMF9G-WJ9E8", "B8374-2I3RN-IEWUW", "Q09IJ-B2383-IN5TI", "B874B-VHW8E-N2O33", "98GJF-23IEN-19OIR", "09DIF-ASUDH-08NO3", "09IVX-WNE8R-2N398", "2N3O4-IJ8FD-3WJNK" };
string weight_array[] = { "64", "56", "90", "37", "58", "41", "98", "34", "94", "86", "65", "62", "75", "68", "49", "79", "62", "61", "70", "78", "53", "51", "48" };
string height_array[] = { "174", "167", "198", "179", "180", "159", "163", "190", "197", "143", "172", "153", "187", "162", "157", "194", "134", "161", "171", "129", "133", "182"};
string iq_array[] = { "98", "123", "145", "87", "198", "130", "142" };
string expected_profession_array[] = { "mechanik", "naukowiec", "lekarz", "nauczyciel", "budowlaniec", "sekretarz", "sprz?tacz", "piekarz", "sprzedawca", "psycholog", "tkacz", "bard", "ksi?gowy", "bednarz", "grabarz", "policjant", "kowal", "urzednik", "wo?ny", "katecheta" };

string passport_types_of_data_array[] = { "name", "surname", "birth_date", "code", "country" };
string id_card_types_of_data_array[] = { "name", "surname", "birth_date", "country", "height", "weight", "code"};
string brain_test_types_of_data_array[] = { "name", "surname", "iq", "expected_profession"};
string dialogues_array[] = {"Jeste?cie dobrzy.Przepu?cicie mnie?", "I jak tam sie ?yje?Dobrze?", "Wracam do Kavertii.To wspania?y kraj!", "B?agam.Przepu?cie mnie!M?j syn choruje.Musz? si? tam dosta?.", "Macie po?yczy? 5$?", "Prosz?, przepu?cie mnie!", "Nie daj? ju? sobie rady.", "Zlitujcie si? nade mn?!Musz? wej??!", "Niech ?yje Kavertia!", " ", "Wszystko jest poprawnie?", "Czy tam jest tak dobrze?", "B?dzcie dla mnie ?askawi!", "Ja tylko przejazdem.", "Wracam do rodziny."};

const char* passport_types_of_data_array_PL[] = {"imi?", "nazwisko", "rok", "kraj", "kod"};
const char* passport_and_id_types_of_data_array_PL[] = { "imi?", "nazwisko", "rok", "kraj", "kod", "waga", "wzrost"};
const char* passport_id_and_brain_test_types_of_data_array_PL[] = { "imi?", "nazwisko", "rok", "kraj", "kod", "waga", "wzrost", "IQ", "zaw?d"};

// Functions

void gotoxy(int x, int y);

// Structs

extern struct BRAIN_TEST
{
	string name;
	string surname;
	string iq;
	string expected_profession;
	void PrintBrainTest()
	{
		int x = 98;
		int y = 20;
		int width = 20;

		gotoxy(x, y);
		cout << setfill(' ');
		gotoxy(x, y+1);
		cout << setw(15) << "BADANIA LEKARSKIE";
		gotoxy(x, y+2);
		cout << "<" << setfill('-') << setw(width) << ">";
		gotoxy(x, y + 3);
		cout << iq << " IQ";
		gotoxy(x, y+4);
		cout << name << " " << surname;
		gotoxy(x, y+5);
		cout << "-" << setfill('-') << setw(width) << "-";
		gotoxy(x, y+6);
		cout << "Przewidywany zaw?d:";
		gotoxy(x, y+7);
		cout << expected_profession;
		gotoxy(x, y+8);
		cout << "<" << setfill('-') << setw(width) << ">";
	}
	void GenerateBrainTest()
	{
		iq = GenerateData(iq_array, _countof(iq_array));
		expected_profession = GenerateData(expected_profession_array, _countof(expected_profession_array));
	}
};
extern struct ID_CARD
{
	string name;
	string surname;
	string birth_date;
	string country;
	string height;
	string weight;
	string code;
	void PrintIdCard()
	{
		int x = 95;
		int y = 8;
		int width = 25;

		gotoxy(x, y);
		cout << setfill(' ');
		gotoxy(x, y + 1);
		cout << setw(19) << "DOW?D OSOBISTY";
		gotoxy(x, y + 2);
		cout << "+" << setfill('-') << setw(width) << "+";
		gotoxy(x, y + 3);
		cout << code;
		gotoxy(x, y + 4);
		cout << "+" << setfill('-') << setw(width) << "+";
		gotoxy(x, y + 5);
		cout << name << " " << surname;
		gotoxy(x, y + 6);
		cout << "-" << setfill('-') << setw(width) << "-";
		gotoxy(x, y + 7);
		cout << "Ur: " << birth_date;
		gotoxy(x, y + 8);
		cout << "Ob: " << country;
		gotoxy(x, y + 9);
		cout << "Wys: " << height << "cm";
		gotoxy(x, y + 10);
		cout << "Wg: " << weight << "kg";
		gotoxy(x, y + 11);
		cout << "+" << setfill('-') << setw(width) << "+";
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
		int y = 8;
		int width = 30;

		gotoxy(x, y);
		cout << setfill(' ');
		gotoxy(x, y + 1);
		cout << setw(22) << "VIZA WEJ?CIOWA";
		gotoxy(x, y + 2);
		cout << "+" << setfill('-') << setw(width) << "+";
		gotoxy(x, y + 3);
		cout << surname << ", " << name;
		gotoxy(x, y + 4);
		cout << "-" << setfill('-') << setw(width) << "-";
		gotoxy(x, y + 5);
		cout << "Urodzony/a: " << birth_date;
		gotoxy(x, y + 6);
		cout << "Obywatelstwo: " << country;
		gotoxy(x, y + 7);
		cout << code;
		gotoxy(x, y + 8);
		cout << "+" << setfill('-') << setw(width) << "+";
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
bool IsAgeOK(string date1, string date2, int min_age, int max_age)
{
	int age1 = stoi(date1);
	int age2 = stoi(date2.substr(8));

	if (age1 - age2 > 0)
	{
		if ((age1 - age2 >= min_age) && (age1 - age2 <= max_age))
			return true;
		else
			return false;
	}
	else
	{
		if ((age2 - age1 >= min_age) && (age2 - age1 <= max_age))
			return true;
		else
			return false;
	}

}
bool IsBmiOK(string data, int min, int max)
{
	if (stoi(data) >= min && stoi(data) <= max)
		return true;
	else
		return false;
}

// Generator b??du dla paszportu
PASSPORT PassportMistakeGenerator(PASSPORT right_passport)
{
	PASSPORT fake_passport = right_passport;
	string mistake = "name";
	mistake = GenerateData(passport_types_of_data_array, _countof(passport_types_of_data_array));

	// U?ywam "if" poniewa? switch nie przyjmuje "stringa"
	if (mistake == "name")
		fake_passport.name = LetterChanger(right_passport.name);
	else if (mistake == "surname")
		fake_passport.surname = LetterChanger(right_passport.surname);
	else if (mistake == "birth_date")
		fake_passport.birth_date = GenerateData(birth_date_array, _countof(birth_date_array));
	else if (mistake == "country")
		fake_passport.country = GenerateData(country_array, _countof(country_array));
	else if (mistake == "code")
		fake_passport.code = LetterChanger(right_passport.code);
	else
		return right_passport;
	return fake_passport;
}
ID_CARD IdCardMistakeGenerator(ID_CARD right_id_card)
{
	ID_CARD fake_id_card = right_id_card;
	string mistake = "name";
	mistake = GenerateData(id_card_types_of_data_array, _countof(id_card_types_of_data_array));

	// U?ywam "if" poniewa? switch nie przyjmuje "stringa"
	if (mistake == "name")
		fake_id_card.name = LetterChanger(right_id_card.name);
	else if (mistake == "surname")
		fake_id_card.surname = LetterChanger(right_id_card.surname);
	else if (mistake == "birth_date")
		fake_id_card.birth_date = GenerateData(birth_date_array, _countof(birth_date_array));
	else if (mistake == "country")
		fake_id_card.country = GenerateData(country_array, _countof(country_array));
	//else if (mistake == "height")
		//fake_id_card.height = GenerateData(height_array, _countof(height_array));
	//else if (mistake == "weight")
		//fake_id_card.weight = GenerateData(weight_array, _countof(weight_array));
	else if (mistake == "code")
		fake_id_card.code = LetterChanger(right_id_card.code);
	else
		return right_id_card;
	return fake_id_card;
}
BRAIN_TEST BrainTestMistakeGenerator(BRAIN_TEST right_brain_test)
{
	BRAIN_TEST fake_brain_test = right_brain_test;
	string mistake = "name";
	mistake = GenerateData(brain_test_types_of_data_array, _countof(brain_test_types_of_data_array));
	if (mistake == "name")
		fake_brain_test.name = LetterChanger(right_brain_test.name);
	else if (mistake == "surname")
		fake_brain_test.surname = LetterChanger(right_brain_test.surname);
	//else if (mistake == "iq")
		//fake_brain_test.iq = LetterChanger(right_brain_test.iq);
	//else if (mistake == "expected_profession")
		//fake_brain_test.expected_profession = GenerateData(expected_profession_array, _countof(expected_profession_array));
	else
		return right_brain_test;
	return fake_brain_test;
}
// Variables

int DayNumber{};
int CoinsNumber{};
int NeutralEndingPoints{};
int BadEndingPoints{};
int GoodEndingPoints{};

string LetterChanger(string text_to_change);
void InitializeGame();
int GenerateRandomNumber(int max);
string GenerateData(string array[], int max_range);
void WriteFromFileByIndex(int index, string file_name);
void hidecursor();
void ShowHowToPlay();
void PlayGame();
void NewGame();
void Typewriter(string text, int which_line);
void GenerateDialogue(int which_line);
void color(int color);
void ShowMenu();
void Ending(int ending_index);
bool CheckIfMistakeIsHere(int choice, PASSPORT fake_passport, ID_CARD fake_id_card);
bool LetIn();
int ShowMenuForChoosingMistake(PASSPORT fake_passport, ID_CARD fake_id_card);
int SelectMistake(int counter, int how_many_data);
void SayNext();
void DayChoose(int day_number);

// Inicjalizacja gry
void InitializeGame()
{
	CoinsNumber = 30;
	DayNumber = 2;
	NeutralEndingPoints = 0;
	BadEndingPoints = 0;
	GoodEndingPoints = 0;
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
// Funkcja wypisuj?ca z pliku jak na maszynie
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
// Funkcja ukrywaj?ca kursor
void hidecursor() 
{ 
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   
	CONSOLE_CURSOR_INFO info;   
	info.dwSize = 100;   
	info.bVisible = FALSE;   
	SetConsoleCursorInfo(consoleHandle, &info); 
}
// Funkcja pokazuj?ca jak gra??
void ShowHowToPlay()
{
	system("CLS");
	int option;
	cout << "Dziekuj? za granie w \"Dokumenty, prosz?!\"." << endl << endl;

	cout << "   ___   __   __ __   __    ___ " << endl;
	cout << "  | _,\\ /__\\ |  V  | /__\\  / _/ " << endl;
	cout << "  | v_/| \\/ || \\_/ || \\/ || \\__ " << endl;
	cout << "  |_|   \\__/ |_| |_| \\__/  \\__/ " << endl;

	cout << endl << "W grze wcielisz si? w inspektora imigracyjnego sprawdzaj?cego dokumenty na granicy Twojego kraju - Kavertii.";
	cout << endl << endl;
	cout << "Podstawow? mechanik? jest tu wybieranie, kt?ra z informacji zawartych w dokumentach petent?w \njest niezgodna z innymi papierami tego? petenta lub z obecnym prawem. \nNa pocz?tku ka?dego dnia zostaniesz zapoznany z nowym przepisem, kt?rego nale?y przestrzega?.\n\nB?dziesz musia? zadecydowa?, czy przepu?cisz danego petenta czy nie, \nw zale?no?ci od Twoich wybor?w moralnych.\nPami?taj! Je?li przepu?cisz osob?, kt?rej dokumenty by?y niezgodne \nlub nie przepu?cisz osoby, kt?ra zadba?a o poprawno?? papier?w - stracisz cz??? swojej wyp?aty.\nDbaj o swoj? rodzin?!";

	cout << endl << endl;
	cout << "Gra zapisuje si? automatycznie na pocz?tku ka?dego dnia pracy.";

	cout << "\n\n" << "Powodzenia!";
	color(3);
	cout << endl << endl << "< POWR?T" << endl;
	color(7);
	char key{};
	for (int i = 0;;)
	{
		key = _getch();
		if (key == 75)
			ShowMenu();
	}
}
// Ekran stworzenia nowej gry lub za?adowania istniej?cej
void PlayGame()
{
	system("CLS");

	int menu_y = 13;
	int Set[] = { 3,7,7 }; // DEFAULT COLORS
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
		cout << setw(menu_width + 1) << "KONTYNUUJ GR?";

		gotoxy(24, menu_y+3);
		color(Set[2]);
		cout << setw(menu_width + 1) << "POWR?T DO MENU";

		key = _getch();

		if (key == 72 && counter > 1 && counter <= 3)
			counter--;
		if (key == 80 && counter >= 1 && counter < 3)
			counter++;
		if (key == '\r')
		{
			color(7);
			if (counter == 1)
				NewGame();
			if (counter == 2)
			{
				string data[5]{};
				int i = 0;
				fstream file;
				file.open("data.txt", ios::in);
				if (file.is_open())
				{
					while (!file.eof())
					{
						getline(file, data[i]);
						i++;
					}
				}
				else
					cout << "Error.";

				DayNumber = stoi(data[0]);
				CoinsNumber = stoi(data[1]);
				NeutralEndingPoints = stoi(data[2]);
				GoodEndingPoints = stoi(data[3]);
				BadEndingPoints = stoi(data[4]);
				DayChoose(DayNumber);
			}
			if (counter == 3)
				ShowMenu();
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
// Funkcja pokazuj?ca tekst na pocz?tku gry
void NewGame()
{
	InitializeGame();
	system("CLS");
	Typewriter("Witajcie obywatelu!Zosta?a Wam przydzielona funkcja inspektora imigracyjnego.Macie za zadanie sprawdza? dokumenty ka?dego petenta przekraczaj?cego granic?.Rozkaz to pilnowa? przepis?w!Sprawujcie si? dobrze.NIECH ?YJE KAVERTIA!");
	Sleep(1000);
	system("CLS");
	
	DayChoose(DayNumber);
}
// Funkcja wypisuj?ca tekst jak na maszynie
void Typewriter(string text, int which_line)
{
	int line_index = 1;
	int i = 0;
	gotoxy(24, 10 + which_line);
	
	while (text[i] != '\0')
	{
		Sleep(40);
		
		cout << text[i];
		//Beep(777, 20);

		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			gotoxy(24, 10 + which_line + line_index);
			line_index++;
		}
		i++;
	}
	//cout << text;
	
	Sleep(500);
};
// Funkcja generuj?ca losowo dialog
void GenerateDialogue(int which_line)
{
	Typewriter(GenerateData(dialogues_array, _countof(dialogues_array)), 4+which_line);
}
// Funkcja zmieniaj?ca kolor tekstu
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Funkcja ustawiaj?ca kursor w x i y
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Funkcja pokazuj?ca menu g??wne
void ShowMenu()
{
	system("CLS");

	hidecursor();
	cout << setfill(' ');

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

	int Set[] = { 3,7,7 }; // DEFAULT COLORS
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
		cout << setw(menu_width) << "WYJD?";

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
// Funkcja wybieraj?ca ending
void Ending(int ending_index)
{
	system("CLS");

	switch (ending_index)
	{
	case 0:
		Typewriter("Twoja rodzina i Ty - umieracie.Czasy by?y ci??kie.Nie starcza?o Wam na dom i po?ywienie.Ka?dy z Was zaczyna? chorowa? z powodu panuj?cego w domu zimna.W chwili swojej ?mierci my?la?e? o swojej pracy - wykona?e? j? dobrze, mimo ?e nie dawa?a Ci wielu zysk?w.Teraz wszyscy b?dziecie szcz??liwi.Razem.");
		break;
	case 1:
		Typewriter("Wykonywa?e? swoj? prac? skrupulatnie i zgodnie z prawem.Nikt nie mo?e Ci zarzuci? nieuczciwo?ci.Wiesz, ?e post?powa?e? dobrze.Twoja rodzina i Ty ?yjecie godnie.Nie musisz si? ju? wi?cej martwi?.");
		break;
	case 2:
		Typewriter("Byle? surowym inspektorem.W?szy?es podst?p w ka?dym okazanym Ci dokumencie.Nie mog?e? odpu?ci? sobie wci?ni?cia przycisku ODMOWA.Wiesz, ?e wype?ni?e? swoje obowi?zki a? za dobrze.Siedzisz teraz sam w pustym domu i jeste? z siebie dumny.");
		break;
	case 3:
		Typewriter("Wiedzia?e?, ?e praca na granicy sprawi Ci wiele przykro?ci. Tyle smutnych twarzy b?agaj?cych Ci? o wci?ni?cie przycisku UZNANO. Mia?e? serce, ?eby wpuszcza? tych biednych ludzi, nawet za cen? swojego ?ycia. Mo?e i nie ?yjesz teraz w ci?g?ym dostatku, ale wiesz, ?e spe?ni?e? swoj? misje. Wiesz, ze uratowa?e? wielu ludzi i dzi?kujesz Bogu za to, ?e da? Ci tak? szans?.");
		break;
	default:
		ShowMenu();
		break;
	}
	color(7);
	Sleep(3000);
	system("CLS");
	Typewriter("Gra stworzona przez King? Grabarczyk.");
	system("CLS");
	Typewriter("Dzi?kuj? za gr?.");
	InitializeGame();
	ShowMenu();
}
bool CheckIfMistakeInAllDocuments(PASSPORT fake_passport, ID_CARD fake_id_card)
{
	if ((fake_passport.name == fake_id_card.name) && (fake_passport.surname == fake_id_card.surname) && (fake_passport.birth_date == fake_id_card.birth_date) && (fake_passport.country == fake_id_card.country) && (fake_passport.code == fake_id_card.code))
		return false;
	else
		return true;
}
// Funkcja sprawdzaj?ca czy gracz poda? dobry b??d
// Zwraca false jesli bledu nie ma, zwraca true jesli blad jest
bool CheckIfMistakeIsHere(int choice, PASSPORT fake_passport, ID_CARD fake_id_card)
{
	switch (choice)
	{
	case 1:
		if (fake_passport.name == fake_id_card.name)
			return false;
		break;
	case 2:
		if (fake_passport.surname == fake_id_card.surname)
			return false;
		break;
	case 3:
		if ((DayNumber == 3 || DayNumber == 4) && (!(IsAgeOK("56", fake_passport.birth_date, 18, 100)) || !(IsAgeOK("56", fake_id_card.birth_date, 18, 100))))
			return true;
		if (fake_passport.birth_date == fake_id_card.birth_date)
			return false;
		break;
	case 4:
	{
		if ((DayNumber == 1) && fake_passport.country != "Kavertia")
			return true;
		if (fake_passport.country == fake_id_card.country)
			return false;
		break;
	}
	case 5:
		if (fake_passport.code == fake_id_card.code)
			return false;
		break;
	case 6:
		if ((DayNumber == 4) && !(IsBmiOK(fake_id_card.weight, 0, 80)))
			return true;
		else
			return false;
		break;
	case 7:
		if ((DayNumber == 4) && !(IsBmiOK(fake_id_card.height, 140, 200)))
			return true;
		else
			return false;
		break;
	default:
		return false;
	}
	return true;
}
// Funcja pokazuj?ca dwa przyciski - ODMOWA i UZNANO
bool LetIn()
{
	system("CLS");

	int Set[] = { 7,7 }; // DEFAULT COLORS
	int menu_width = 45;

	int counter = 1;
	char key;

	int menu_y = 13;

	for (int i = 0;;)
	{
		gotoxy(50, 10);
		color(Set[0]);
		cout << "::::::::::";
		gotoxy(50, 11);
		cout << ": ODMOWA :";
		gotoxy(50, 12);
		cout << "::::::::::";

		gotoxy(65, 10);
		color(Set[1]);
		cout << "::::::::::";
		gotoxy(65, 11);
		cout << ": UZNANO :";
		gotoxy(65, 12);
		cout << "::::::::::";

		key = _getch();

		if (key == 75 && (counter == 2))
			counter--;
		if (key == 77 && (counter == 1))
			counter++;
		if (key == '\r')
		{
			//Beep(500, 500);
			Beep(120, 150);
			color(7);
			system("CLS");
			if (counter == 1)
				return false;
			if (counter == 2)
				return true;
		}

		Set[0] = 7;
		Set[1] = 7;

		if (counter == 1)
			Set[0] = 4;
		if (counter == 2)
			Set[1] = 2;
	}
}
// Funkcje odpowiedzi na b??d
int DocumentsIncorrectReminder(int salary)
{
	Typewriter("Upomnienie.Dane petenta by?y niezgodne.-5$");
	salary -= 5;
	GoodEndingPoints++;
	return salary;
}
int DocumentsCorrectReminder(int salary)
{
	Typewriter("Upomnienie.Dane petenta by?y zgodne.-5$");
	salary -= 5;
	BadEndingPoints++;
	return salary;
}
int NoReminder(int salary)
{
	Typewriter("Poprawnie.+5$.");
	salary += 5;
	NeutralEndingPoints++;
	return salary;
}
// Funkcja pokazuj?ca czy gracz wybra? dobry b??d
int ShowMenuForChoosingMistake(PASSPORT fake_passport, ID_CARD fake_id_card)
{
	int choice = 1;
	int salary = 0;

	int how_many_data{};
	if (DayNumber == 1)
		how_many_data = _countof(passport_types_of_data_array_PL);
	if (DayNumber >= 2 && DayNumber <= 5)
		how_many_data = _countof(passport_and_id_types_of_data_array_PL);

	bool mistake_is_here = false;

	do
	{
		choice = SelectMistake(choice, how_many_data+1);
		gotoxy(60, 21);
		cout << "                                     ";
		cout << "\r";
			
		if (choice == how_many_data+1)
		{
			gotoxy(60, 21);
			cout << "W dokumentach nie ma b??du.";
			Sleep(1000);
			mistake_is_here = true;
		}
		else
		{
			mistake_is_here = CheckIfMistakeIsHere(choice, fake_passport, fake_id_card);
			gotoxy(60, 21);
			if (mistake_is_here)
			{
				Beep(600, 200);
				cout << "Wykryto niezgodno??.";
				gotoxy(60, 23);
				Typewriter("> Te dane si? nie zgadzaj?.", 9);
			}
			else
			{
				Beep(120, 50);
				cout << "Nie wykryto niezgodno?ci.";
			}
		}
	} while (!mistake_is_here);
	
	system("CLS");
	switch (DayNumber)
	{
	case 1:
		if (LetIn())
		{
			if ((CheckIfMistakeIsHere(4, fake_passport, fake_id_card)))
				salary = DocumentsIncorrectReminder(salary);
			else
				salary = NoReminder(salary);
		}
		else
		{
			if ((CheckIfMistakeIsHere(4, fake_passport, fake_id_card)))
				salary = NoReminder(salary);
			else
				salary = DocumentsCorrectReminder(salary);
		}
		break;
	case 2:
		if (LetIn())
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card))
				salary = DocumentsIncorrectReminder(salary);
			else
				salary = NoReminder(salary);
		}
		else
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card))
				salary = NoReminder(salary);
			else
				salary = DocumentsCorrectReminder(salary);
		}
		break;
	case 3:
		if (LetIn())
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card) || (CheckIfMistakeIsHere(3, fake_passport, fake_id_card)))
				salary = DocumentsIncorrectReminder(salary);
			else
				salary = NoReminder(salary);
		}
		else
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card) || (CheckIfMistakeIsHere(3, fake_passport, fake_id_card)))
				salary = NoReminder(salary);
			else
				salary = DocumentsCorrectReminder(salary);
		}
		break;
	case 4:
		if (LetIn())
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card) || (CheckIfMistakeIsHere(3, fake_passport, fake_id_card)) || (CheckIfMistakeIsHere(6, fake_passport, fake_id_card)) || (CheckIfMistakeIsHere(7, fake_passport, fake_id_card)))
				salary = DocumentsIncorrectReminder(salary);
			else
				salary = NoReminder(salary);
		}
		else
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card) || (CheckIfMistakeIsHere(3, fake_passport, fake_id_card)) || (CheckIfMistakeIsHere(6, fake_passport, fake_id_card)) || (CheckIfMistakeIsHere(7, fake_passport, fake_id_card)))
				salary = NoReminder(salary);
			else
				salary = DocumentsCorrectReminder(salary);
		}
		break;
	case 5:
		if (LetIn())
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card))
				salary = DocumentsIncorrectReminder(salary);
			else
				salary = NoReminder(salary);
		}
		else
		{
			if (CheckIfMistakeInAllDocuments(fake_passport, fake_id_card))
				salary = NoReminder(salary);
			else
				salary = DocumentsCorrectReminder(salary);
		}
		break;
	default:
		cout << "Error.";
	}
	Sleep(500);
	cout << endl;
	return salary;
}
// Funckcja daj?ca mo?liwo?? przeskakiwania mi?dzy elementami dokument?w
int SelectMistake(int counter, int how_many_data)
{
	char key;

	color(112);
	gotoxy(60, 20);
	cout << "                  ";
	cout << "\r";
	gotoxy(60, 20);
	cout << "imi?";

	for (int i = 0;;)
	{
		color(112);

		key = _getch();

		if (key == 72 && (counter > 1))
			counter--;
		if (key == 80 && (counter < how_many_data))
			counter++;
		if (key == '\r')
		{
			color(7);
			return counter;
		}

		gotoxy(60, 20);
		cout << "                  ";
		cout << "\r";
		gotoxy(60, 20);

		for (int c = 1; c < how_many_data; c++)
		{
			if (counter == c)
			{
				if(DayNumber == 1)
					cout << passport_types_of_data_array_PL[c - 1];
				if (DayNumber >= 2 && DayNumber <= 5)
					cout << passport_and_id_types_of_data_array_PL[c - 1];
			}
		}
		if (counter == how_many_data)
			cout << "Brak";
	}
}
// Funkcja wypisuj?ca na ekranie "nast?pny"
void SayNext()
{
	system("CLS");
	Typewriter("> Nast?pny!");
	system("CLS");
}
// G??wna gra - ka?dy dzie? ma inny przepis prawny
void DayChoose(int day_number)
{
	char key;
	int salary = 0;
	system("CLS");

	ofstream file("data.txt");
	file << DayNumber << endl << CoinsNumber << endl << NeutralEndingPoints << endl << GoodEndingPoints << endl << BadEndingPoints;
	file.close();

	//--------------------JAKIE DZI? NEWSY?----------------------//
	Typewriter(" MAGAZYN CODZIENNY   ", -2);
	cout << DayNumber << ". lutego 1956 roku";
	setlocale(LC_CTYPE, "UTF-8");
	WriteFromFileByIndex(DayNumber, "DayNews.txt");
	setlocale(LC_CTYPE, "Polish");
	Sleep(1000);
	system("CLS");

	//------------------JAKIE DZI? PRZEPISY?--------------------//
	Typewriter(" DZIE? ", -2);
	cout << DayNumber;
	setlocale(LC_CTYPE, "UTF-8");
	WriteFromFileByIndex(DayNumber, "DayRules.txt");
	setlocale(LC_CTYPE, "Polish");
	Sleep(1000);
	system("CLS");
	//--------------------ROZPOCZECIE DNIA----------------------//
	//----------------------------------------------------------//
	Typewriter("> Rozpocznij dzie?.\n");
	do 
	{
	key = _getch();
	} while (key != '\r');

	double seconds_since_start = 0;
	auto time_start = time(0);
	//------------------WYB?R NUMERU DNIA-----------------------//
	switch (day_number)
	{
		//-------DZIE? 1-------//
		case 1:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosz?.");
				Typewriter("Ju? daj?.", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country, " ", " ", passport.code };
				id_card.GenerateIdCard();
				GenerateDialogue(-2);
				passport.PrintPassport();

				salary += ShowMenuForChoosingMistake(passport, id_card);
				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 60);
			break;
		}
		//-------DZIE? 2-------//
		case 2:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosz?.");
				Typewriter("Tutaj s?.", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				Typewriter("> Imi? i nazwisko.", 2);
				Typewriter(passport.name + " " + passport.surname, 3);
				GenerateDialogue(0);

				ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country, " ", " ", passport.code };
				id_card.GenerateIdCard();
				PASSPORT fake_passport;
				ID_CARD fake_id_card;

				switch (GenerateRandomNumber(3))
				{
					// Paszport jest niezgodny
					case 1:
						fake_passport = PassportMistakeGenerator(passport);
						fake_passport.PrintPassport();
						id_card.PrintIdCard();
						salary += ShowMenuForChoosingMistake(fake_passport, id_card);
						break;
					// Dow?d jest niezgodny
					case 2:
						fake_id_card = IdCardMistakeGenerator(id_card);
						fake_id_card.PrintIdCard();
						passport.PrintPassport();
						salary += ShowMenuForChoosingMistake(passport, fake_id_card);
						break;
					default:
						passport.PrintPassport();
						id_card.PrintIdCard();
						salary += ShowMenuForChoosingMistake(passport,id_card);
						break;
				}
				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 120);
			break;
		}
		//-------DZIE? 3-------//
		case 3:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosz?.");
				Typewriter("Oto m?j paszport i dow?d.", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				Typewriter("> Imi? i nazwisko.", 2);
				Typewriter(passport.name + " " + passport.surname, 3);
				GenerateDialogue(0);

				ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country, " ", " ", passport.code };
				id_card.GenerateIdCard();
				PASSPORT fake_passport;
				ID_CARD fake_id_card;

				switch (GenerateRandomNumber(3))
				{
					// Paszport jest niezgodny
				case 1:
					fake_passport = PassportMistakeGenerator(passport);
					fake_passport.PrintPassport();
					id_card.PrintIdCard();
					salary += ShowMenuForChoosingMistake(fake_passport, id_card);
					break;
					// Dow?d jest niezgodny
				case 2:
					fake_id_card = IdCardMistakeGenerator(id_card);
					fake_id_card.PrintIdCard();
					passport.PrintPassport();
					salary += ShowMenuForChoosingMistake(passport, fake_id_card);
					break;
				default:
					passport.PrintPassport();
					id_card.PrintIdCard();
					salary += ShowMenuForChoosingMistake(passport, id_card);
					break;
				}
				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 160);
			break;
		}
		//-------DZIE? 4-------//
		case 4:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosz?.");
				Typewriter("Prosz?.", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				Typewriter("> Imi? i nazwisko.", 2);
				Typewriter(passport.name + " " + passport.surname, 3);
				GenerateDialogue(0);

				ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country, " ", " ", passport.code };
				id_card.GenerateIdCard();
				PASSPORT fake_passport;
				ID_CARD fake_id_card;

				switch (GenerateRandomNumber(3))
				{
					// Paszport jest niezgodny
				case 1:
					fake_passport = PassportMistakeGenerator(passport);
					fake_passport.PrintPassport();
					id_card.PrintIdCard();
					salary += ShowMenuForChoosingMistake(fake_passport, id_card);
					break;
					// Dow?d jest niezgodny
				case 2:
					fake_id_card = IdCardMistakeGenerator(id_card);
					fake_id_card.PrintIdCard();
					passport.PrintPassport();
					salary += ShowMenuForChoosingMistake(passport, fake_id_card);
					break;
				default:
					passport.PrintPassport();
					id_card.PrintIdCard();
					salary += ShowMenuForChoosingMistake(passport, id_card);
					break;
				}
				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 300);
			break;
		}
		//-------DZIE? 5-------//
		case 5:
		{
			do
			{
				SayNext();
				Typewriter("> Dokumenty, prosz?.");
				Typewriter("Czego jeszcze chcecie?", 1);
				PASSPORT passport;
				passport.GeneratePassport();
				Typewriter("> Imi? i nazwisko.", 2);
				Typewriter(passport.name + " " + passport.surname, 3);
				GenerateDialogue(0);

				ID_CARD id_card = { passport.name, passport.surname, passport.birth_date, passport.country, " ", " ", passport.code };
				id_card.GenerateIdCard();

				BRAIN_TEST brain_test = { passport.name, passport.surname };
				brain_test.GenerateBrainTest();

				PASSPORT fake_passport;
				ID_CARD fake_id_card;
				BRAIN_TEST fake_brain_test;

				switch (GenerateRandomNumber(4))
				{
					// Paszport jest niezgodny
				case 1:
					fake_passport = PassportMistakeGenerator(passport);
					fake_passport.PrintPassport();
					id_card.PrintIdCard();
					brain_test.PrintBrainTest();
					salary += ShowMenuForChoosingMistake(fake_passport, id_card);
					break;
					// Dow?d jest niezgodny
				case 2:
					fake_id_card = IdCardMistakeGenerator(id_card);
					fake_id_card.PrintIdCard();
					passport.PrintPassport();
					brain_test.PrintBrainTest();
					salary += ShowMenuForChoosingMistake(passport, fake_id_card);
					break;
					//case 3:
						//fake_brain_test = BrainTestMistakeGenerator(brain_test);
						//id_card.PrintIdCard();
						//passport.PrintPassport();
						//fake_brain_test.PrintBrainTest();
						//salary += ShowMenuForChoosingMistake(passport, fake_id_card);
						//break;
				default:
					passport.PrintPassport();
					id_card.PrintIdCard();
					brain_test.PrintBrainTest();
					salary += ShowMenuForChoosingMistake(passport, id_card);
					break;
				}
				seconds_since_start = difftime(time(0), time_start);

			} while (seconds_since_start < 320);
			break;
		}
		default:
		{
			ShowMenu();
			break;
		}
	}
	//------------------------KONIEC DNIA-----------------------//
	//----------------------------------------------------------//
	system("CLS");
	Sleep(500);
	Typewriter("Koniec dnia!");
	//--------------------PODSUMOWANIE DNIA--------------------//
	color(112);
	Typewriter("Oszcz?dno?ci          ", 4);
	cout << "+" << CoinsNumber << "$";
	Typewriter("Zarobi?e?             ", 6);
	cout << "+" << salary << "$";
	Typewriter("Ogrzewanie            ", 8);
	cout << "-10$";
	Typewriter("Czynsz                ", 10);
	cout << "-15$";
	Typewriter("?ywno??               ", 12);
	cout << "-10$";
	CoinsNumber = CoinsNumber + salary - 35;
	Typewriter("Razem                 ", 14);
	cout << CoinsNumber << "$";
	Typewriter("Rodzina               ", 16);
	if (CoinsNumber > 70)
		cout << "Dobrze";
	else if (CoinsNumber >= 20 && CoinsNumber <= 70)
		cout << "OK";
	else if (CoinsNumber < 20 && CoinsNumber > 0)
		cout << "?le";
	else if (CoinsNumber <= 0)
	{
		cout << "Nie ?yje";
		Sleep(1000);
		color(7);
		Ending(0);
	}
	color(7);
	//-------------------------------------------------------//
	file.open("data.txt");
	file << (DayNumber+1) << endl << CoinsNumber << endl << NeutralEndingPoints << endl << GoodEndingPoints << endl << BadEndingPoints;
	file.close();

	Typewriter("Kontynuuj >", 18);
	Typewriter("< Wr?? do menu", 19);
	for (int i = 0;;)
	{
		key = _getch();
		if (key == 77)
		{
			//-------DZIE? 6-------//
			if ((DayNumber + 1) == 6)
			{
				color(112);
				if ((GoodEndingPoints > NeutralEndingPoints) && (GoodEndingPoints > BadEndingPoints))
					Ending(3);
				else if ((BadEndingPoints > GoodEndingPoints) && (BadEndingPoints > NeutralEndingPoints))
					Ending(2);
				else
					Ending(1);
			}
			DayNumber++;
			DayChoose(DayNumber);
		}
		else if (key == 75)
		ShowMenu();
	}
}