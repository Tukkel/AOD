#include <iostream>
#include <vector>
using namespace std;
//----------------------------
// Returns a vector containing the zero based index of
// the start of each match of the string K in S.
// Matches may overlap
//----------------------------
vector<int> KMP(string S, string K)
{
	vector<int> T(K.size() + 1, -1);
	vector<int> matches;
	if (K.size() == 0) {
		matches.push_back(0);
		return matches;
	}
	for (int i = 1; i <= K.size(); i++) {
		int pos = T[i - 1];
		while (pos != -1 && K[pos] != K[i - 1])
			pos = T[pos];
		T[i] = pos + 1;
	}
	int sp = 0;
	int kp = 0;
	while (sp < S.size()) {
		while (kp != -1 && (kp == K.size() || K[kp] !=
			S[sp]))
			kp = T[kp];
		kp++;
		sp++;
		if (kp == K.size())
			matches.push_back(sp - K.size());
	}
	return matches;
}

void test() {
	string str = "Abekat";
	string contain = "kat";
	vector<int> result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected: 3" << endl << endl;

	str = "abbbcgbbab";
	contain = "bb";
	result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected: 1 2 6" << endl << endl;

	str = "iiiii";
	contain = "i";
	result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected: 0 1 2 3 4" << endl << endl;

	str = "";
	contain = "abc";
	result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected:" << endl << endl;

	str = "abc";
	contain = "";
	result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected:" << endl << endl;

	str = "ababababa";
	contain = "aba";
	result = KMP(str, contain);
	cout << "Result:   ";
	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "Expected: 0 2 4 6" << endl << endl;
}


int main(void)
{
	test();
	return 0;
}