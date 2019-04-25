#include"matrix.h"
#include "Tree.h"

int main() {

	//test with double, string, class

	srand(time(NULL));

	Matrix<int> m1;
	//Matrix<char> m3;
	//Matrix<Tree> m4;

	Matrix<double> m(4, 5, 0);
	Matrix<double> mcopy(m);
	mcopy.print();

	m();//why not ()()
	mcopy = m;

	/*cout << "fill your matrix: " << endl;
	for (int i = 0; i < m.row_size(); i++)
		for (int j = 0; j < m.col_size(); j++)
			cin >> m.at(i, j);*/

	cout << "MATRIX" << endl;
	for (int i = 0; i < m.row_size(); i++) {
		for (int j = 0; j < m.col_size(); j++) {
			cout << setw(3) << left << m.at(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	const int n = 6;
	double* d= new double[n]{1, 2, 3, 4, 5, 6};

	Matrix<double> m2(d, 6, 5);
	m2.print();

	//m2--;
	//m2.print();
	//m2++;
	//m2.print();

	Matrix<double> m3(d, 6);
	m3.print();

	//(mcopy + m3).print();
	(m2 + 10).print();

	m2.del_row();
	m2.del_col();
	m2.print();

	//Matrix<int> m;
	//Matrix<double> m;
	//Matrix<char> m;
	//Matrix<Tree> m;
	//int choice;
	//while (true) {
	//	cout << "Enter 1 to construct new matrix" << endl;
	//	cout << "Enter 2 to fill your matrix randomly" << endl;
	//	cout << "Enter 3 to add matrix with matrix or matrix with number" << endl;
	//	cout << "Enter 4 to add a new row" << endl;
	//	cout << "Enter 5 to add a new column" << endl;
	//	cout << "Enter 6 to delete a row" << endl;
	//	cout << "Enter 7 to delete a column" << endl;
	//	cout << "Enter 8 to fill your matrix manually" << endl;
	//	cout << "Enter 9 to print your matrix" << endl;
	//	cout << "Enter 0 to exit" << endl;
	//	cin >> choice;
	//	if (choice == 0) break;
	//	switch (choice)
	//	{
	//	case 1:
	//		cout << "Choose type of matrix:" << endl;
	//		cout << "1 - int" << endl;
	//		cout << "2 - double" << endl;
	//		cout << "3 - char/string" << endl;//???
	//		cout << "4 - class Tree" << endl;
	//		int x;
	//		cin >> x;
	//		if (x == 1)
	//		{
	//			Matrix<int> m1(4, 5, 0);
	//			//m = m1;
	//		}
	//		else if (x == 2)
	//		{
	//			Matrix<double> m2(5, 5, 0);
	//			//m = m2;
	//		}
	//		else if (x == 3)
	//		{
	//			Matrix<char> m3(6, 6, 'a');
	//			//m = m3;
	//		}
	//		else if (x == 4)
	//		{
	//			//Matrix<Tree> m4(3, 3, (4, "Derevo"));
	//			//m=m4;
	//		}
	//		break;
	//	case 2:
	//		m();
	//		break;
	//	case 3:
	//	
	//		break;
	//	case 4:
	//		
	//		break;
	//	case 5:
	//		
	//		break;
	//	case 6:
	//		
	//		break;
	//	case 7:
	//		break;
	//	case 8:
	//		cout << "fill your matrix: " << endl;
	//		for (int i = 0; i < m.row_size(); i++)
	//			for (int j = 0; j < m.col_size(); j++)
	//				cin >> m.at(i, j);
	//		break;
	//	case 9:
	//		cout << "MATRIX" << endl;
	//		for (int i = 0; i < m.row_size(); i++) {
	//			for (int j = 0; j < m.col_size(); j++) {
	//				cout << setw(3) << left << m.at(i, j) << " ";
	//			}
	//			cout << endl;
	//		}
	//		cout << endl;
	//		break;
	//	}
	//}

	system("pause");
	return 0;
}