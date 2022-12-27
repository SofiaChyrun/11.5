// ChyrunSofialab11.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_11_5.cpp
// < Чирун Софія >
// Лабораторна робота № 11.5
// Структури, об’єднання та бінарні файли 
// Варіант 18

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Student { KN, IT, ME, FI, TN };
enum Teacher { PR, AP, AS };
enum Persona { ST, TR };
string studentStr[] = { "Комп’ют. науки", "Інформатика", "Матем. та екон", "Фізика та інф.", "Трудове навч." };
string teacherStr[] = { "Професор", "Доцент", "Асистент" };
string personStr[] = { "Студент", "Викладач" };
struct Specialist
{
	Student student;
	Persona persona;
	string prizv;
	union A
	{
		int stypd;
		Teacher teacher;
	} x;
	union B
	{
		double srbal;
		double zarplt;
	} y; 
};

void Create(Specialist* p, const int N);
void Print(Specialist* p, const int N);
int NDocent(Specialist* p, const int N, int stud);
double MinSerbal(Specialist* p, const int N);
int MinStypd(Specialist* p, const int N);
int Suma(Specialist* p, const int N, int stud);
int NN(int s);
void CreateBIN(char* fname, Specialist* p, const int N) 
{
	ofstream fout(fname, ios::binary);
	string s; 
	fout << "===========================================================================" << endl;
	fout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
	fout << "---------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		fout << endl << "|" << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << studentStr[p[i].student] << " "
			<< "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
		switch (p[i].persona)
		{
		   case ST:
			  fout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
			  fout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
			  break;
		   case TR:
			  fout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
			  fout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
			  break;
		}
	}
	fout << "\n===========================================================================" << endl;
	fout << endl;
	fout << endl;
}

void PrintBIN(char* fname) 
{
	ifstream fin(fname, ios::binary); 
	char c;
	while (fin.read((char*)&c, sizeof(c))) 
	{
		cout << c; 
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	int N, st, nt, student, fond;
	double sb;
	cout << "Введіть N: "; cin >> N;
	Specialist* p = new Specialist[N];
	Create(p, N);
	Print(p, N);
	cout << endl << "Мінімaльний середній бал: " << MinSerbal(p, N) << endl;
	sb=MinSerbal(p, N);
	cout << "===========================================================================" << endl;
	cout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
	cout << "---------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		if (sb== p[i].y.srbal) {
		   cout << endl << "|" << setw(2) << right << i + 1 << " "
				<< "| " << setw(13) << left << studentStr[p[i].student] << " "
				<< "| " << setw(9) << left << p[i].prizv
				<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
			switch (p[i].persona)
			{
			   case ST:
				  cout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
				  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
				  break;
			   case TR:
				  cout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
				  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
				  break;
			}
		}
	}
	cout << "\n===========================================================================" << endl;
	cout << endl;
	cout << endl << "Мінімaльна стипендія: " << MinSerbal(p, N) << endl;
	st=MinStypd(p, N);
	cout << "===========================================================================" << endl;
	cout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
	cout << "---------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		if (st == p[i].x.stypd) {
		   cout << endl << "|" << setw(2) << right << i + 1 << " "
				<< "| " << setw(13) << left << studentStr[p[i].student] << " "
				<< "| " << setw(9) << left << p[i].prizv
				<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
			switch (p[i].persona)
			{
			   case ST:
				  cout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
				  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
				  break;
			   case TR:
				  cout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
				  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
				  break;
			}
		}
	}
	cout << "\n===========================================================================" << endl;
	cout << endl;
	cout << "кількість викладачів - доцентів на заданому факультеті" << endl;
	cout << " Факультет (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
	cin >> student;
	nt= NDocent(p, N, student);
	cout<<"Кількість = " << nt << endl;
	if (nt > 0) 
	{
		cout << "===========================================================================" << endl;
		cout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
		cout << "---------------------------------------------------------------------------";
		for (int i = 0; i < N; i++)
		{
			if (p[i].x.teacher == AP && p[i].student == (Student)student) {
			   cout << endl << "|" << setw(2) << right << i + 1 << " "
					<< "| " << setw(13) << left << studentStr[p[i].student] << " "
					<< "| " << setw(9) << left << p[i].prizv
					<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
				switch (p[i].persona)
				{
				   case ST:
					  cout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
					  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
					  break;
				   case TR:
					  cout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
					  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
					  break;
				}
			}
		}
		cout << "\n===========================================================================" << endl;
		cout << endl;
	}
	else cout << "Доцентів в списку немає!" << endl;
	cout << "сумарний фонд стипендії і зарплати на заданому факультеті" << endl;
	cout << " Факультет (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
	cin >> fond;
	nt = Suma(p, N, fond);
	cout << "Кількість = " << nt << endl;
	if (nt > 0) 
	{
        cout << "===========================================================================" << endl;
		cout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
		cout << "---------------------------------------------------------------------------";
		for (int i = 0; i < N; i++)
		{
			if (p[i].x.teacher == AP && p[i].student == (Student)student) {
			   cout << endl << "|" << setw(2) << right << i + 1 << " "
					<< "| " << setw(13) << left << studentStr[p[i].student] << " "
					<< "| " << setw(9) << left << p[i].prizv
					<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
				switch (p[i].persona)
				{
				   case ST:
					  cout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
					  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
					  break;
				   case TR:
					  cout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
					  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
					  break;
				}
			}
		}
		cout << "\n===========================================================================" << endl;
		cout << endl;
	}
	else cout << "Доцентів в списку немає!" << endl;
	char fname[100]; 
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname, p, N); 
	cout << "\nВивід результату з файлу 1: " << endl;
	PrintBIN(fname); 
	return 0;
}

void Create(Specialist* p, const int N)
{
	int student, persona, teacher; 
	for (int i = 0; i < N; i++)
	{
		cout << "Інформація № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 
		cout << " Факультет (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> student;
		p[i].student = (Student)student;
		cout << " Прізвище: "; 
		cin >> p[i].prizv;
		cout << " Персона (0 - Студент, 1 - Викладач): ";
		cin >> persona;
		p[i].persona = (Persona)persona;
		switch (p[i].persona)
		{
		   case ST:
			  cout << " Стипендія: "; cin >> p[i].x.stypd;
			  cout << " Середній бал: "; cin >> p[i].y.srbal;
			  break;
		   case TR:
			  cout << " Посада (0 - Професор, 1 - Доцент, 2 - Асистент): ";
			  cin >> teacher;
			  p[i].x.teacher = (Teacher)teacher;
			  cout << " Зарплата: "; cin >> p[i].y.zarplt;
			  break;
		}
		cout << endl;
	}
}

double MinSerbal(Specialist* p, const int N)
{
	double s = 1000;
	for (int i = 0; i < N; i++)
	{
		if (p[i].y.srbal < s)
		   s = p[i].y.srbal;
	}
	return s;
}

int MinStypd(Specialist* p, const int N) {
	int s = 1000;
	for (int i = 0; i < N; i++)
	{
		if (p[i].x.stypd < s)
		   s = p[i].x.stypd;
	}
	return s;
}

int NDocent(Specialist* p, const int N, int stud) {
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].x.teacher == AP && p[i].student == (Student)stud)
		   s=NN(s);
	}
	return s;
}

int NN(int s)
{
	s += 1;
	return s;
}

int Suma(Specialist* p, const int N, int stud) {
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].student == (Student)stud)
		   switch (p[i].persona)
		   {
			  case ST:
				 s += p[i].x.stypd ;
				 break;
			  case TR:
				 s += p[i].y.zarplt ;
				 break;
		   }
	}
	return s;
}

void Print(Specialist* p, const int N)
{
	cout << "===========================================================================" << endl;
	cout << "| № |   Факультет   | Прізвище |   Студ/Викл | Стип/Посад |  Сербал/Зарпл |" << endl;
	cout << "---------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		cout << endl << "|" << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << studentStr[p[i].student] << " "
			<< "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(11) << left << personStr[p[i].persona] << " ";
		switch (p[i].persona)
		{
		   case ST:
			  cout << "| " << setw(10) << setprecision(2) << fixed << right << p[i].x.stypd << " ";
			  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.srbal << " |";
			  break;
		   case TR:
			  cout << "| " << setw(10) << left << teacherStr[p[i].x.teacher] << " ";
			  cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].y.zarplt << " |";
			  break;
		}
	}
	cout << "\n===========================================================================" << endl;
	cout << endl;
}
