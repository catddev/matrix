#include"matrix.h"
#include "Tree.h"

int main() {

	srand(time(NULL));

	Matrix<int> m1;
	//Matrix<char> m3;

	Tree t(2, "Asia");
	Matrix<Tree> mt(3, 3, t);
	for (int i = 0; i < mt.row_size(); i++) {
		for (int j = 0; j < mt.col_size(); j++) {
			cout << mt.at(i, j) << "		";
		}
		cout << endl;
	}
	cout << endl;

	Matrix<Tree> mt2;
	mt2 = mt;
	mt2.del_row();
	mt2.del_col();
	mt2(Tree(5, "Africa"));//operator()
	for (int i = 0; i < mt2.row_size(); i++) {
		for (int j = 0; j < mt2.col_size(); j++) {
			cout << mt2.at(i, j) << "	";
		}
		cout << endl;
	}
	cout << endl;


	Matrix<double> m(4, 5, 0);
	Matrix<double> mcopy(m);
	mcopy.print();

	m(4.5);
	mcopy = m;

	Matrix<int> m5(10, 10, 0);
	m5.random();
	m5.print();

	//friend operator>>
	/*cout << "fill your matrix manually: " << endl;
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
	double* d = new double[n] {1, 2, 3, 4, 5, 6};

	Matrix<double> m2(d, 6, 5);
	m2.print();

	++m2;
	m2.print();
	m2--;
	m2.print();

	Matrix<double> m3(d, 6);
	m3.print();
	Matrix<double>m4;
	m4 = (mcopy + m3);
	cout << "SUMMARY:" << endl;
	m4.print();

	m2 = m2 + 10;
	m2.print();

	Matrix <double> m111;
	m2.del_row();
	m2.del_col();
	m2.print();
	m111=m2.add_row();
	m111=m111.add_col();
	m111.print();

	system("pause");
	return 0;
}