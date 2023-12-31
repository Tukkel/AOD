#ifndef _MATRIX_H_
#define _MATRIX_H_

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>

template <typename Object>
class Matrix {
	private:
		vector<vector<Object>> array;

	public:
		Matrix() {};

		Matrix(int rows, int cols) : array(rows) {
			for(auto& r : array) {
				r.resize(cols);
			}
		}

		Matrix(vector<vector<Object>> v) : array{v} { }

		//matrix_class.h

		bool isElementStored(const Object object)
		{
			int numrows = this->numrows();
			int numcols = this->numcols();
			if (numrows == 0 || numcols == 0)
			{
				return 0;
			}
			else if (numrows == numcols)	//check if matrix is N*N
			{

				for (int i = 0; i < numrows; i++)	//run through last element in every row
				{
					if (array[i][numrows-1] >= object) //if element is larger than object
					{
						for (int j = 0; j < numcols; j++) //run through every element in every column
						{
							if (array[i][j] == object)
								return true;
						}
						return false;
					}
				}
			}
			return false;
		}

		int numrows() const { return array.size( ); }

		int numcols() const {
			if (numrows() > 0) {
				return array[0].size();
			}
			return 0;
		}

		const vector<Object>& operator[](int row) const {
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
			return array[row];
		}

		vector<Object>& operator[](int row) {
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
			return array[row];
		}

		friend ostream& operator<<(ostream& t, Matrix<Object>& mat) {
			cout << fixed;
			cout.precision(2);
			for(int i = 0; i < mat.numrows(); ++i) {
				cout << "|";
				for(int j = 0; j < mat.numcols(); ++j) {
					cout << " " << setw(6) << mat[i][j] << " ";
				}
				cout << "|" << endl;
			}
			return t;
		}

		void add(Matrix& mat);
};

#include "matrix_class.tpp"

#endif
