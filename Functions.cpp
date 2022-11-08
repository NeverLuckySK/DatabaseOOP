#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	//временные переменные
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	cout << "Введите количество данных: ";
	cin >> n;

	//выделите память
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите номер машины: ";
		cin >> carnumber.number;

		cout << "Введите данные владельца (ФИО): ";
		cin >> initial.surname >> initial.name >> initial.patronymic;

		cout << "Введите личный номер клиента: ";
		cin >> clientnumber.numclient;

		cout << "Введите марку машины: ";
		cin >> marccar.mark;

		cout << "Введите привад: ";
		cin >> drive.choose;

		//добовляем новые данные в элемент массива объекта класса
		d[i].DataEntry(carnumber, initial, clientnumber, marccar, drive);

		cout << "______________________________________\n";
	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//создание потока для чтения
	ifstream reading(fileName);

	if (reading) {
		//временные переменные
		Carnumber carnumber;
		Initial initial;
		Clientnumber clientnumber;
		MarcCar marccar;
		Drive drive;

		reading >> n;

		//выделим память
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> carnumber.number;

			reading >> initial.surname >> initial.name >> initial.patronymic;

			reading >> clientnumber.numclient;

			reading >> marccar.mark;

			reading >> drive.choose;

			d[i].DataEntry(carnumber, initial, clientnumber, marccar, drive);
		}

		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << ":" << endl;

		d[i].Print();
		cout << "_______________________________\n" << endl;
	}
}

void DataChange(Data* d, int n)
{
	//временные переменные
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--; // Убираем единицу так как с++ начинает с 0

	system("cls");

	//проверка, что введено правильное значение 
	if (_n >= 0 && _n < n) { //Проверка номера, который ввели с клавы
		cout << "Введите гост номер машины: ";
		cin >> carnumber.number;

		cout << "Введите ФИО владельца: ";
		cin >> initial.surname >> initial.name >> initial.patronymic;

		cout << "Введите мобильный номер клиента: ";
		cin >> clientnumber.numclient;

		cout << "Введите марку машины: ";
		cin >> marccar.mark;

		cout << "Введите привад транспорта: ";
		cin >> drive.choose;

		d[_n].DataEntry(carnumber, initial, clientnumber, marccar, drive);

		system("cls");

		cout << "Данные изменены" << endl;
	}
	else
		cout << "Номер введён не верно!" << endl;

}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//проверка, что введите правильно значение
	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		--n;
		//выделяем новую память
		d = new Data[n];

		//запоминаем данные кроме не нужного
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введён не верно!" << endl;

}

void Copy(Data *d_n, Data *d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];

}

void AddDate(Data* (&d), int& n)
{
	//временные переменные
	Carnumber carnumber;
	Initial initial;
	Clientnumber clientnumber;
	MarcCar marccar;
	Drive drive;

	//временные массив данных 
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	//сохраняем данные в временный массив
	Copy(buf, d, size);

	//выделяем новую память
	d = new Data[new_size];

	//возвращаем данные 
	Copy(d, buf, size);

	cout << "Введите гост номер машины: ";
	cin >> carnumber.number;

	cout << "Введите ФИО владельца: ";
	cin >> initial.surname >> initial.name >> initial.patronymic;

	cout << "Введите номер телефона владельца: ";
	cin >> clientnumber.numclient;

	cout << "Введите марку машины: ";
	cin >> marccar.mark;

	cout << "Введите привад машины: ";
	cin >> drive.choose;

	//добавление новых данных в элементе массива объект класса
	d[size].DataEntry(carnumber, initial, clientnumber, marccar, drive);
	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[] buf;
}

void DataSorting(Data* d, int n)
{
	//временная переменная
	Data buf;
	int numOfSorted = 0;

	//сортировка метода пузырька
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//условие сортироваки
			if (d[i].GetInitial().surname > d[j].GetInitial().surname) {
				buf, d[j];
				d[j], d[i];
				d[i], buf;

				numOfSorted++;
			}
		}
	}

	cout << "Данные отсортированы!\nКоличество сортировок: " << numOfSorted << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	//создаётся поток для записи
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
		cout << "Ошибка открытия файла!" << endl;

	cout << "Данные сохранены в файл: " << fileName << endl;

	record.close();
}
