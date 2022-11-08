#pragma once

#include <iostream> // Библиотека для потока ввода и вывода
#include <fstream> // Библиотека для потока и работы с файлама
#include <string> // Библиотека для работы со строками
#include <Windows.h> // Библиотека для работы с нужными функциями system

using namespace std;

/*
	Данных:
	1. Номер машины
	2. Данные клиента (ФИО)
	3. Личный номер
	4. Марка машины
	5. Привод
*/

//Структура номер машины
struct  Carnumber {
	string number;
};

//Структура данных клиента (ФИО)
struct Initial {
	string surname,
		name,
		patronymic;
};

//Структура номера клиента
struct Clientnumber {
	string numclient;
};

//Структура марки машины
struct MarcCar {
	string mark;
};

//Структура Привода
struct Drive {
	string choose;
};

//Прототип класса
class Data 
{
	//Закрытая часть класса (Поля класса)
private:
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	//Открытая часть класса
public:
	//Обязательные методы класса
	Data();//конструктор по умолчанию. Создаёт пустой объект
	Data(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_);//конструктор с параметрами. Создаёт объект с параметрами
	~Data();// Действие удаляет объект

	//не обязательные методы (нужны нам для выполнения задания)
	void Print(); //вывод данных в консоль
	void DataEntry(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_);//ввод данных
	// вывод данных (полей) из класса
	Carnumber GetCarnumber() { return carnumber; }; // Пример: Тип вывода Название метода(что туда должно приходить[в данном случае ничего]) {выход}
	Initial GetInitial() { return initial; };
	Clientnumber GetClientnumber() { return clientnumber; };
	MarcCar GerMarcCar() { return marccar; };
	Drive GetDrive() { return drive; };

	//перегрузка оператора =
	Data& operator = (Data d_o); //ссылка на класс оператор = должен прийти один параметр
};
