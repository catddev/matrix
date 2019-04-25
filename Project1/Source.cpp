#include"matrix.h"

using namespace std;

int main() {

	//test with double, string, class
	//menu interface

	srand(time(NULL));
	Matrix<double> md(4, 5, 0);
	Matrix<char> mch(6, 6, 'a');
	//Matrix<Tree> mclass;

	md();//why ()()

	//md.print();
	for (int i = 0; i < md.row_size(); i++) {
		for (int j = 0; j < md.col_size(); j++) {
			cout << setw(3) << left << md.at(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}