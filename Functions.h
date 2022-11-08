#pragma once

#include "Data.h"

//Прототипы функций
void DataEntry(Data* (&d), int& n); //Ввод данных вручную
void ReadingData(Data* (&d), int& n, string fileName); //Чтение данных из файла
void Print(Data* d, int n); //Вывод данных
void DataChange(Data* d, int n); //Изменение данных
void DeleteData(Data* (&d), int& n); //Удаление данных
void Copy(Data *d_n, Data *d_o, int n); //Копмя данных массива
void AddDate(Data* (&d), int& n); //Добавить данные
void DataSorting(Data* d, int n); //Сортировка данных
void SavingData(Data* d, int n, string fileName); //сохранение данных