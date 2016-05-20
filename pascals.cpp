#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class pascal_triangle {
private:
	int num_rows;
	vector<vector<int> > matrix;
	friend ostream& operator<<(ostream &out, pascal_triangle pascal);
public:
	pascal_triangle(int rows);
	int value_at_index(int i, int j) const;
};
ostream& operator<<(ostream &out, pascal_triangle pascal){
	int num_spaces = pascal.num_rows - 1;
	for (int i = 0; i < pascal.num_rows; i++) {
		for (int j = 0; j < num_spaces; j++){
			out << setw(3) << ' ';
		}
		for (int j = 0; j <= i; j++){
			out << setw(3) << pascal.matrix[i][j] <<
				std::setw(3) << ' ';
		}
		out << endl;
		num_spaces--;
	}
	return out;
}
pascal_triangle::pascal_triangle(int num_row):num_rows(num_row),matrix(vector<vector<int> >(num_rows,vector<int>(num_rows, 0))){
	for (int n = 0; n < num_rows; n++)
		for (int r = 0; r <= n; r++) {
			if (n == 0 && r == 0) {
				matrix[n][r] = 1;
			} else if (r == 0 || r == n) {
				matrix[n][r] = 1;
			} else {
				matrix[n][r] = matrix[n - 1][r] + matrix[n - 1][r - 1];
			}
		}
}

int pascal_triangle::value_at_index(int i, int j) const{
	return matrix[i][j];
}

int nCr(int n, int r){
	if (n == 0 && r == 0) {
		return 1;
	}
	else if (r == 0 || r == n) {
		return 1;
	}
	else {
		return nCr(n - 1, r) + nCr(n - 1, r - 1);
	}
}

int main(void){
	cout << "Enter the no. of rows: ";
	int row;
	cin >> row;
	cout<<endl;
	pascal_triangle pascal(row);
	cout << pascal;
	cout << "\nFor combination,\n";
	cout << "Enter n and r: ";
	int n,r;
	cin >> n ;
	cin >> r;
	cout<<endl;
	int val = nCr(n, r);
	cout << "The value we got after evaluation : "<<val <<endl;
	if (val == pascal.value_at_index(n, r))
		cout << "It matches.\n";
	else
		cout << "It does not match.\n";
	return 0;
}

