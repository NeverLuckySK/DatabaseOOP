#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	//��������� ����������
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	cout << "������� ���������� ������: ";
	cin >> n;

	//�������� ������
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ����� ������: ";
		cin >> carnumber.number;

		cout << "������� ������ ��������� (���): ";
		cin >> initial.surname >> initial.name >> initial.patronymic;

		cout << "������� ������ ����� �������: ";
		cin >> clientnumber.numclient;

		cout << "������� ����� ������: ";
		cin >> marccar.mark;

		cout << "������� ������: ";
		cin >> drive.choose;

		//��������� ����� ������ � ������� ������� ������� ������
		d[i].DataEntry(carnumber, initial, clientnumber, marccar, drive);

		cout << "______________________________________\n";
	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//�������� ������ ��� ������
	ifstream reading(fileName);

	if (reading) {
		//��������� ����������
		Carnumber carnumber;
		Initial initial;
		Clientnumber clientnumber;
		MarcCar marccar;
		Drive drive;

		reading >> n;

		//������� ������
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> carnumber.number;

			reading >> initial.surname >> initial.name >> initial.patronymic;

			reading >> clientnumber.numclient;

			reading >> marccar.mark;

			reading >> drive.choose;

			d[i].DataEntry(carnumber, initial, clientnumber, marccar, drive);
		}

		cout << "������ �������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << ":" << endl;

		d[i].Print();
		cout << "_______________________________\n" << endl;
	}
}

void DataChange(Data* d, int n)
{
	//��������� ����������
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--; // ������� ������� ��� ��� �++ �������� � 0

	system("cls");

	//��������, ��� ������� ���������� �������� 
	if (_n >= 0 && _n < n) { //�������� ������, ������� ����� � �����
		cout << "������� ���� ����� ������: ";
		cin >> carnumber.number;

		cout << "������� ��� ���������: ";
		cin >> initial.surname >> initial.name >> initial.patronymic;

		cout << "������� ��������� ����� �������: ";
		cin >> clientnumber.numclient;

		cout << "������� ����� ������: ";
		cin >> marccar.mark;

		cout << "������� ������ ����������: ";
		cin >> drive.choose;

		d[_n].DataEntry(carnumber, initial, clientnumber, marccar, drive);

		system("cls");

		cout << "������ ��������" << endl;
	}
	else
		cout << "����� ����� �� �����!" << endl;

}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//��������, ��� ������� ��������� ��������
	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		--n;
		//�������� ����� ������
		d = new Data[n];

		//���������� ������ ����� �� �������
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ����� �� �����!" << endl;

}

void Copy(Data *d_n, Data *d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];

}

void AddDate(Data* (&d), int& n)
{
	//��������� ����������
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	//��������� ������ ������ 
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	//��������� ������ � ��������� ������
	Copy(buf, d, size);

	//�������� ����� ������
	d = new Data[new_size];

	//���������� ������ 
	Copy(d, buf, size);

	cout << "������� ���� ����� ������: ";
	cin >> carnumber.number;

	cout << "������� ��� ���������: ";
	cin >> initial.surname >> initial.name >> initial.patronymic;

	cout << "������� ����� �������� ���������: ";
	cin >> clientnumber.numclient;

	cout << "������� ����� ������: ";
	cin >> marccar.mark;

	cout << "������� ������ ������: ";
	cin >> drive.choose;

	//���������� ����� ������ � �������� ������� ������ ������
	d[size].DataEntry(carnumber, initial, clientnumber, marccar, drive);
	system("cls");

	cout << "������ ���������!" << endl;

	delete[] buf;
}

void DataSorting(Data* d, int n)
{
	//��������� ����������
	Data buf;
	int numOfSorted = 0;

	//���������� ������ ��������
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//������� �����������
			if (d[i].GetInitial().surname > d[j].GetInitial().surname) {
				buf, d[j];
				d[j], d[i];
				d[i], buf;

				numOfSorted++;
			}
		}
	}

	cout << "������ �������������!\n���������� ����������: " << numOfSorted << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	//�������� ����� ��� ������
	ofstream record(fileName);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetCarnumber().number << endl;
			record << d[i].GetInitial().surname << " " << d[i].GetInitial().name << " " << d[i].GetInitial().patronymic << endl;
			record << d[i].GetClientnumber().numclient << endl;
			record << d[i].GerMarcCar().mark << endl;
			record << d[i].GetDrive().choose << endl;

			if (i < n - 1);
				record << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	cout << "������ ��������� � ����: " << fileName << endl;

	record.close();
}
