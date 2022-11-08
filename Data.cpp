#include "Data.h"

Data::Data() // �������� ������� �������
{
	carnumber.number = "";

	initial.surname = "";
	initial.name = "";
	initial.patronymic = "";

	clientnumber.numclient = "";

	marccar.mark = "";

	drive.choose = "";
}

Data::Data(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_) //������ ����������
{
	carnumber.number = carnumber_.number;

	initial.surname = initial_.surname;
	initial.name = initial_.name;
	initial.patronymic = initial_.patronymic;

	clientnumber.numclient = clientnumber_.numclient;

	marccar.mark = marccar_.mark;

	drive.choose = drive_.choose;
}

Data::~Data() // ����������
{
}

void Data::Print()
{
	cout << "���� ����� ������: " << carnumber.number << endl;
	cout << "��� ���������: " << initial.name << " " << initial.patronymic << " " << initial.surname << endl;
	cout << "����� �������� �������: " << clientnumber.numclient << endl;
	cout << "����� ������ �������: " << marccar.mark << endl;
	cout << "������ ���������: " << drive.choose << endl;
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