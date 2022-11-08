#include "Data.h"

Data::Data() // создание пустого объекта
{
	carnumber.number = "";

	initial.surname = "";
	initial.name = "";
	initial.patronymic = "";

	clientnumber.numclient = "";

	marccar.mark = "";

	drive.choose = "";
}

Data::Data(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_) //задача параметров
{
	carnumber.number = carnumber_.number;

	initial.surname = initial_.surname;
	initial.name = initial_.name;
	initial.patronymic = initial_.patronymic;

	clientnumber.numclient = clientnumber_.numclient;

	marccar.mark = marccar_.mark;

	drive.choose = drive_.choose;
}

Data::~Data() // диструктор
{
}

void Data::Print()
{
	cout << "Гост номер машины: " << carnumber.number << endl;
	cout << "ФИО владельца: " << initial.name << " " << initial.patronymic << " " << initial.surname << endl;
	cout << "Номер телефона клиента: " << clientnumber.numclient << endl;
	cout << "Марка машины клиента: " << marccar.mark << endl;
	cout << "Привад атомобиля: " << drive.choose << endl;
}

void Data::DataEntry(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_)
{
	carnumber.number = carnumber_.number;

	initial.surname = initial_.surname;
	initial.name = initial_.name;
	initial.patronymic = initial_.patronymic;

	clientnumber.numclient = clientnumber_.numclient;

	marccar.mark = marccar_.mark;

	drive.choose = drive_.choose;
}

Data& Data::operator=(Data d_o)
{
	this->carnumber.number = d_o.carnumber.number;

	this->initial.surname = d_o.initial.surname;
	this->initial.name = d_o.initial.name;
	this->initial.patronymic = d_o.initial.patronymic;

	this->clientnumber.numclient = d_o.clientnumber.numclient;

	this->marccar.mark = d_o.marccar.mark;

	this->drive.choose = d_o.drive.choose;

	return *this;
}