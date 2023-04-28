#include <iostream> 
#include <string> 
#include <fstream>
#include <windows.h> //для записи на русском в файле

using namespace std;

struct sotrudnicFirmi
{
	string FIO;
	int time_za_month;
	int pochasovoy_tarif;
	int zarplata;
};

string FIO(string str)
{
	string name, fname, lname;
	cin >> fname >> name >> lname;
	str = fname + " " + name + " " + lname;
	return str;
};

int var1(int mas[], int kol_sotr, string masstr[])
{
	sotrudnicFirmi sotrudniki[10];
	int kol_vo, kolv = 0;
	string str, fio;

	ofstream sozd_file;
	ofstream delete_file;
	fstream firma;
	sozd_file.open("Firma.txt", ofstream::app);
	firma.open("Firma.txt", fstream::in | fstream::out);

	cout << "\n\nВведите кол-во сотрудников фирмы: ";
	cin >> kol_vo;
	kol_sotr = kol_vo;

	if (!firma.is_open())
	{
		cout << "Ошибка открытия файла!!!" << endl;
	}
	else
	{
		for (int i = 0; i < kol_vo; i++)
		{
			cout << "ФИО сотрудника фирмы: ";
			SetConsoleCP(1251);					//для записи на русском в файле
			sotrudniki[i].FIO = FIO(fio);
			masstr[i] = sotrudniki[i].FIO;
			firma << "ФИО сотрудника фирмы: ";
			firma << sotrudniki[i].FIO << "\n";
			SetConsoleCP(866);					//для перевода обратно на английском, но в файле всё на русском

			cout << "Количество проработанных часов за месяц: ";
			cin >> sotrudniki[i].time_za_month;
			mas[i] = sotrudniki[i].time_za_month;
			firma << "Количество проработанных часов за месяц: ";
			firma << sotrudniki[i].time_za_month << "\n";

			cout << "Почасовой тариф: ";
			cin >> sotrudniki[i].pochasovoy_tarif;
			firma << "Почасовой тариф: ";
			firma << sotrudniki[i].pochasovoy_tarif << "\n";

			sotrudniki[i].zarplata = sotrudniki[i].time_za_month * sotrudniki[i].pochasovoy_tarif;

			firma << "Зарплата: ";
			firma << sotrudniki[i].zarplata << "\n";

			firma << "\n\n";
			cout << "\n\n";
		}
	}
	return kol_sotr;
}

void var2()
{
	sotrudnicFirmi sotrudniki[10];
	int kol_vo, variant;
	string str, fio;

	ofstream sozd_file;
	ofstream delete_file;
	fstream firma;

	sozd_file.open("Firma.txt", ofstream::app);
	firma.open("Firma.txt", fstream::in | fstream::out);
	if (!firma.is_open())
	{
		cout << "Ошибка открытия файла!!!" << endl;
	}
	else
	{
		cout << "Считывание из файла!!!" << endl << endl;
		while (!firma.eof())
		{
			str = "";
			getline(firma, str);
			cout << str << endl;
		}
	}
}

void var3(int a[], int n)
{
	int min = a[0], x, imin, max = 0;

	for (int j = 0; j < n; j++)
	{
		if (max < a[j])
		{
			max = a[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == min)
			{
				imin = j;
			}
		}
		x = a[i];
		a[i] = min;
		a[imin] = x;
		min = max;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
		cout << " ";
	}
}

void var4(int mas[], int kol_vo, string str[])
{
	sotrudnicFirmi sotrudniki[10];

	cout << "Ищем 156 методом полного перебора" << endl << endl;
	for (int i = 0; i < kol_vo; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < kol_vo; i++)
	{
		if (mas[i] == 156)
		{
			cout << "Сотрудник фирмы: " << str[i] << endl;
			cout << "Искомый элемент находится на позиции: " << i + 1 << endl;
		}
	}

}

void var5(int mas[], int kol_vo, string str[])
{
	cout << "Ищем 156 методом двоичного поиска" << endl << endl;
	int sred;
	sred = kol_vo / 2;

	for (int i = 0; i < kol_vo; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";
	if (156 > mas[sred])
	{
		for (int i = sred; i < kol_vo; i++)
		{
			if (mas[i] == 156)
			{
				cout << "Искомый элемент находится на позиции: " << i + 1 << endl;
			}
		}
	}
	else
	{
		for (int i = sred; i > 0; i--)
		{
			if (mas[i] == 156)
			{
				cout << "Искомый элемент находится на позиции: " << i + 1 << endl;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	sotrudnicFirmi sotrudniki[10];
	int variant;
	string str, fio;

	cout << "1-запись в файл" << endl;
	cout << "2-считывание из файла" << endl;
	cout << "3-сортировка по min" << endl;
	cout << "4-поиск элемента методом полного перебора" << endl;
	cout << "5-поиск элемента методом двоичного поиска" << endl;
	cout << "6-очистить запись в файле" << endl;
	cout << "0-выйти" << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "Выберите вариант: ";
	cin >> variant;
	cout << "_____________________________________________________________________________" << endl;
	system("cls");
	while (variant != 0)
	{
		ofstream sozd_file;
		ofstream delete_file;
		fstream firma;
		sozd_file.open("Firma.txt", ofstream::app);
		firma.open("Firma.txt", fstream::in | fstream::out);

		int* mas = new int[10];
		string masstr[10];
		int kol_vo = 0;

		if (variant == 1)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			kol_vo = var1(mas, kol_vo, masstr);

			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
			firma.close();
		}
		if (variant == 2)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			var2();

			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
			firma.close();
		}
		if (variant == 3)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			var3(mas, kol_vo);

			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
		}
		if (variant == 4)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			var4(mas, kol_vo, masstr);

			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
		}
		if (variant == 5)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			var5(mas, kol_vo, masstr);

			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
		}
		if (variant == 6)
		{
			cout << "1-запись в файл" << endl;
			cout << "2-считывание из файла" << endl;
			cout << "3-сортировка по min" << endl;
			cout << "4-поиск элемента методом полного перебора" << endl;
			cout << "5-поиск элемента методом двоичного поиска" << endl;
			cout << "6-очистить запись в файле" << endl;
			cout << "0-выйти" << endl;
			cout << "\n";

			delete_file.open("Firma.txt");
			firma.close();

			cout << "Файл очищен!!!" << endl;
			cout << "\n";
			cout << "_____________________________________________________________________________" << endl;
			cout << "Выберите вариант: ";
			cin >> variant;
			cout << "_____________________________________________________________________________" << endl;
			system("cls");
		}
	}
	return 0;
}