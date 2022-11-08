#pragma once

#include <iostream> // ���������� ��� ������ ����� � ������
#include <fstream> // ���������� ��� ������ � ������ � �������
#include <string> // ���������� ��� ������ �� ��������
#include <Windows.h> // ���������� ��� ������ � ������� ��������� system

using namespace std;

/*
	������:
	1. ����� ������
	2. ������ ������� (���)
	3. ������ �����
	4. ����� ������
	5. ������
*/

//��������� ����� ������
struct  Carnumber {
	string number;
};

//��������� ������ ������� (���)
struct Initial {
	string surname,
		name,
		patronymic;
};

//��������� ������ �������
struct Clientnumber {
	string numclient;
};

//��������� ����� ������
struct MarcCar {
	string mark;
};

//��������� �������
struct Drive {
	string choose;
};

//�������� ������
class Data 
{
	//�������� ����� ������ (���� ������)
private:
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	//�������� ����� ������
public:
	//������������ ������ ������
	Data();//����������� �� ���������. ������ ������ ������
	Data(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_);//����������� � �����������. ������ ������ � �����������
	~Data();// �������� ������� ������

	//�� ������������ ������ (����� ��� ��� ���������� �������)
	void Print(); //����� ������ � �������
	void DataEntry(Carnumber carnumber_, Initial initial_, Clientnumber clientnumber_, MarcCar marccar_, Drive drive_);//���� ������
	// ����� ������ (�����) �� ������
	Carnumber GetCarnumber() { return carnumber; }; // ������: ��� ������ �������� ������(��� ���� ������ ���������[� ������ ������ ������]) {�����}
	Initial GetInitial() { return initial; };
	Clientnumber GetClientnumber() { return clientnumber; };
	MarcCar GerMarcCar() { return marccar; };
	Drive GetDrive() { return drive; };

	//���������� ��������� =
	Data& operator = (Data d_o); //������ �� ����� �������� = ������ ������ ���� ��������
};
