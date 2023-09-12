template <typename Object>
void Matrix<Object>::add(Matrix& mat) {
	int rows = numrows();
	int cols = numcols();

	if (rows != mat.numrows() || cols != mat.numcols()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			array[i][j] = array[i][j] + mat[i][j];
		}
	}
}

template <typename Object>
Matrix<Object>& multiply(Matrix<Object>& a, Matrix<Object>& b) {
	if (a.numcols() != b.numrows()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

	for(int i = 0; i < a.numrows(); ++i) {
		for(int j = 0; j < b.numcols(); ++j) {
			(*mult)[i][j] = 0;
		}
	}

	for(int i = 0; i < a.numrows(); ++i) {
		for(int j = 0; j < b.numcols(); ++j) {
			for (int k = 0; k < b.numrows(); k++) {
				(*mult)[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return *mult;
}

template <typename Object>
void Matrix<Object>::transpose() {
	Object temp;
	int rows = numrows();
	int cols = numcols();
	int maxVal = max(rows,cols);

	if (rows != cols)
	{
		array.resize(maxVal);
		for (auto& r : array) {
			r.resize(maxVal);
		}
	}

	for (int i = 1; i < maxVal; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = temp;
		}
	}

	if (rows != cols)
	{
		array.resize(cols);
		for (auto& r : array) {
			r.resize(rows);
		}
	}
}

template <typename Object>
bool Matrix<Object>::findInSorted(Object x) {
	int rows = numrows();
	int cols = numcols();
	int row = rows;

	for (int i = 0; i < rows; i++)
	{
		if (array[i][0] > x)
		{
			row = i - 1;
			break;
		}
	}

	for (int i = 0; i < cols; i++)
	{
		if (array[row][i] == x)
		{
			return true;
		}
	}
	return false;
}