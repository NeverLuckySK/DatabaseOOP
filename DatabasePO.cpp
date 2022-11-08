#include "Functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберите действаие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Удаление данных" << endl
		<< "(5) Добавление данных" << endl
		<< "(6) Сортировка данных" << endl
		<< "(7) Сохранение данных" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main() {
	//руссификация консоли ввода/вывода
	SetConsoleCP(1251); //Установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //Установка кодовой страницы win-cp 1251 в поток вывода 

	Menu();

	//инициализация данных
	int _actions; //Дополнительная переменная для того, чтобы могли выбрать определённое действие непосредственно в действии
	string fileName;

	int _size = 0; //колличетсво данных
	//массив данных 
	Data* d = new Data[_size];

	while (_stateMenu != 0) // Выход из программы
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls"); //очистка консоли

			cout << "Ввод вручную или из файла?: ";
			cin >> _actions;

			system("cls"); //очистка консоли

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, _size);
			}
			else {
				//ввод вручную
				/*
				//Вслучае ввода название файла с данными
				cout << "Введите название файлла: ";
				cin >> fileName;// Input.txt

				ReadingData(d, _size, fileName);
				*/

				ReadingData(d, _size, "Input.txt");
			}

			system("pause");//задержка консоли
			system("cls");//очитка консоли
			Menu();
			break; // Выход из switch
			////////////////////////////////////////////////////
		case 2:
			system("cls");//очистка консоли

			if (_size != 0) 
				Print(d, _size);
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			////////////////////////////////////////////////////
		case 3:
			system("cls"); //очистка консоли

			if (_size != 0) {
				DataChange(d, _size);
			}
			else
				cout << "Данные пусты" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			////////////////////////////////////////////////////
		case 4:
			system("cls"); //очистка консолей

			if (_size != 0) {
				DeleteData(d, _size);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			///////////////////////////////////////////////////
		case 5:
			system("cls"); // очистка консоли

			if (_size != 0) 
				AddDate(d, _size);
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			///////////////////////////////////////////////////
		case 6:
			system("cls");// Очистка консоли

			if (_size != 0) {
				DataSorting(d, _size);

			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			//////////////////////////////////////////////////
		case 7:
			system("cls");// Очистка консоли

			cout << "Введите название файла: ";
			cin >> fileName;

			if (_size != 0) {
				/*
				cout << "Введите название файла: ";
				cin >> fileName; //Out.txt
				
				SaveData(d, _size, fileName);
				*/

				SavingData(d, _size, fileName);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			////////////////////////////////////////////////
		default:
			cout << "Неверно введён номер действия!" << endl;
			system("pause"); //Задержка консоли
			system("cls"); //очистка консоли
			Menu();
			break;
		}
	}

	system("cls");
	cout << "Работа завершена!" << endl;
	system("pause");
}