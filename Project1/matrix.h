#pragma once
#include<iostream>
#include <iomanip>
#include<Windows.h>
#include<ctime>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdlib>
//#include"matrix.cpp"
// Для шаблонного класса ВСЕ ПРОПИСЫВАТЬ в файле .h, включая реализацию а не .cpp
using namespace std;

//Разработать шаблонный класс MATRIX(матрица) для представления двумерных динамических массивов.
//Класс должен обеспечить хранение данных любого типа  Т.
//Класс должен содержать :
//•	Конструктор по умолчанию
//•	Конструктор создающий матрицу заданного размера и инициализирующий все элементы указанным значением. По умолчанию значение равно нулю
//•	Конструктор создающий матрицу из существующего массива
//•	Конструктор копирования
//•	Перегрузить операцию присваивания
//•	Перегрузить операцию вызова функции
//•	Перегрузить операцию для сложения двух матриц
//•	Перегрузить операцию для сложения матрицы с числом
//•	Перегрузить операцию инкремента и декремента для матрицы
//•	Перегрузить операции ввода / вывода как дружественные функции
//•	Реализовать методы :
//o	Для добавления строки
//o	Для добавления столбца
//o	Для удаления строки
//o	Для удаления столбца
//o	Добавить методы set и get

template<typename T>
class Matrix {
private:
	T**els;
	int cols;
	int rows;

public:
	Matrix();
	Matrix(int rows, int cols, T value);
	Matrix(T *arr, int size);
	Matrix(T *arr, int size, int rows);
	Matrix(const Matrix<T>& obj);
	Matrix<T> operator=(const Matrix<T>& obj);
	void operator()();//перегрузка круглых скобок - вызов функции
	Matrix<T> operator+(Matrix<T> obj); //будет работать для классов, а не только для простых типов, только если в самих классах будет перегружен оператор+
	Matrix<T> operator+(int k); //сработает только для простых числовых типов, не для классов
	//унарные операторы ничего не принимают, только бинарные
	void operator++();
	void operator--();
	T& at(int row, int col);
	~Matrix();

	int row_size();//вместо геттеров
	int col_size();

	void add_row();
	void add_col();
	void del_row();
	void del_col();
	void print();

	friend istream& operator>>(istream& is, Matrix<T>& obj);
	friend ostream& operator<<(ostream& os, Matrix<T> obj);
};
//перегруженные функции ввода и вывода, даже шаблонные, ни в коем случае НЕ INLINE!!!!!!!!!!!!!
template<typename T>
istream& operator>>(istream& is, Matrix<T>& obj);
template<typename T>
ostream& operator<<(ostream& os, Matrix<T> obj);

template<typename T>
inline Matrix<T>::Matrix()
{
	els = 0;
	cols = 0;
	rows = 0;
}

template<typename T>
inline Matrix<T>::Matrix(int rows, int cols, T value)
{
	this->rows = rows;
	this->cols = cols;
	els = new T*[rows];
	for (int i = 0; i < rows; i++)
		els[i] = new T[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] = value;
}

template<typename T>
inline Matrix<T>::Matrix(T * arr, int size)
{
	int new_cols = 0;
	cout << "Enter needed columns number: ";
	cin >> new_cols;
	this->cols = new_cols;
	if (size%cols == 0)
	{
		this->rows = size / cols;
		els = new T*[rows];
		for (int i = 0; i < rows; i++)
			els[i] = new T[cols];

		int k = 0;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				els[i][j] = arr[k++];
	}
	else
	{
		this->rows = (size / cols) + 1;
		int sub_cols = size - cols*(rows-1);

		els = new T*[rows];
		for (int i = 0; i < rows; i++)
			els[i] = new T[cols];

		int k = 0;
		for (int i = 0; i < rows-1; i++)
			for (int j = 0; j < cols; j++)
				els[i][j] = arr[k++];

		for (int i = 0; i < cols; i++)
		{
			if(i>=sub_cols)
				els[rows - 1][i] = 0;//empty elements are filled with 0
			else
				els[rows - 1][i] = arr[k++];
		}	
	}
}

template<typename T>
inline Matrix<T>::Matrix(T *arr, int size, int rows)//просто размножаем переданный массив, тем самым создавая матрицу
{
	this->rows = rows;
	this->cols = size;
	els = new T*[rows];
	for (int i = 0; i < rows; i++)
		els[i] = new T[cols];

	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] = arr[j];

}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T> & obj)
{
	rows = obj.rows;
	cols = obj.cols;
	els = new T*[rows];
	for (int i = 0; i < rows; i++)
		els[i] = new T[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] = obj.els[i][j];
}

template<typename T>
inline Matrix<T> Matrix<T>::operator=(const Matrix<T> & obj)
{
	rows = obj.rows;
	cols = obj.cols;
	els = new T*[rows];
	for (int i = 0; i < rows; i++)
		els[i] = new T[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] = obj.els[i][j];

	return *this;
}

template<typename T>
inline void Matrix<T>::operator()()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] = rand() % 21;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(Matrix<T> obj)
{
	Matrix tmp;
	tmp.rows = rows > obj.rows ? rows : obj.rows;
	tmp.cols = cols > obj.cols ? cols : obj.cols;
	tmp.els = new T*[tmp.rows];
	for (int i = 0; i < tmp.rows; i++)
		els[i] = new T[tmp.cols];

	for (int i = 0; i < tmp.rows; i++) {
		for (int j = 0; j < tmp.cols; j++) {
			if (!els[i][j])//???
				tmp.els[i][j] = obj.els[i][j];
			if (!obj.els[i][j])//???
				tmp.els[i][j] = els[i][j];
			tmp.els[i][j] = els[i][j] + obj.els[i][j];
		}
	}

	return tmp;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(int k)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			els[i][j] += k;
	return *this;
}

template<typename T>
inline void Matrix<T>::operator++()//добавляем строку в конец
{
	add_row();
	//return *this;
}

template<typename T>
inline void Matrix<T>::operator--()//удаляем строку с конца
{
	del_row();
	//return *this;
}

template<typename T>
inline T & Matrix<T>::at(int row, int col)
{
	return els[row][col];
}


template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] els[i];
	delete[] els;
}

template<typename T>
inline int Matrix<T>::row_size()
{
	return rows;
}

template<typename T>
inline int Matrix<T>::col_size()
{
	return cols;
}

template<typename T>
inline void Matrix<T>::add_row()
{
	Matrix tmp;
	tmp.rows = rows + 1;
	tmp.cols = cols;
	tmp.els = new T*[tmp.rows];
	for (int i = 0; i < rows; i++)
		tmp.els[i] = els[i];

	tmp.els[rows] = new T[cols];

	for (int i = 0; i < cols; i++)
		tmp.els[rows][i] = 0;

	delete[] els;
	els = tmp.els;
	rows++;
}

template<typename T>
inline void Matrix<T>::add_col()
{
	Matrix tmp;
	tmp.rows = rows;
	tmp.cols = cols + 1;
	tmp.els = new T*[tmp.rows];
	for (int i = 0; i < rows; i++)
		tmp.els[i] = new T[tmp.cols];

	for (int i = 0; i < tmp.rows; i++) {
		for (int j = 0; i < tmp.cols; i++) {
			tmp.els[i][j] = els[i][j];
			tmp.els[i][tmp.cols - 1] = 777;
		}
	}
	delete[] els;
	els = tmp.els;
	cols++;
}

template<typename T>
inline void Matrix<T>::del_row()
{
	rows--;
}

template<typename T>
inline void Matrix<T>::del_col()
{
	cols--;
}

template<typename T>
inline void Matrix<T>::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << left << els[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//перегруженные функции ввода и вывода, даже шаблонные, ни в коем случае НЕ INLINE!!!!!!!!!!!!!
template<typename T>
istream & operator>>(istream & is, Matrix<T>& obj)
{
	for (int i = 0; i < obj.rows; i++)
		for (int j = 0; j < obj.cols; j++)
			is >> obj.els[i][j];

	return is;
}
template<typename T>
ostream & operator<<(ostream & os, Matrix<T> obj)
{
	for (int i = 0; i < obj.rows; i++)
		for (int j = 0; j < obj.cols; j++)
			os << obj.els[i][j];
	//нельзя еще что-то в отдельный os<< считать, только в одну строку, в один беспрерывный поток, чтобы его вернуть

	return os;
}