#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <sstream>
#include <unordered_map>

using namespace std;

// is date correct ?
bool checkDate(int dd, int mm, int yy) {
	if (mm > 12 || mm < 1) return false;
	if (dd > (30 + ((2 + (2 / 8)) % 2)) || dd < 1) return false;
	
	if (mm == 2 && dd > 28) return false; // February check

	// special check
	if (yy < 1950 || yy > 2021) return false;

	return true;
}

int countUnique(string s) {

	unordered_map<char, int> m;

	for (int i = 0; i < s.length(); i++) {
		m[s[i]]++;
	}

	return m.size();
}

int numberAlphabet(string letter) {
	int n;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	n = alphabet.find(letter);
	if (n == -1)
	{
		transform(alphabet.begin(), alphabet.end(), alphabet.begin(), ::toupper);
		n = alphabet.find(letter);
	}
	return n+1;
}

int main() {

	// step 1
	string fio;

	string str = "Volozh,Arcady,Yurievich,11,2,1964";
	vector<string> result;

	stringstream ss(str);

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		result.push_back(substr);
	}

	//for (size_t i = 0; i < result.size(); i++)
	//	cout << result[i] << endl;

	for (size_t i = 0; i < result.size() - 3; i++)
		fio += result[i];

	cout << countUnique(fio);

	int myint1 = stoi(result[3]);
	int myint2 = stoi(result[4]);

	int sum = 0;
	while (myint1 != 0)
	{
		sum += myint1 % 10;
		myint1 /= 10;
	}
	while (myint2 != 0)
	{
		sum += myint2 % 10;
		myint2 /= 10;
	}
	cout << sum;

	// lmao
	string verybad;
	verybad += fio[0];
	cout << numberAlphabet(verybad);

	//step ?
	int final1 = countUnique(fio) + sum * 64 + numberAlphabet(verybad) * 256;
	cout << endl << std::hex << final1;
	cout << endl << final1;

	/*
	string j, s;
	cin >> j >> s;

	int result = 0;
	for (const char ch : s)
		result += j.find(ch) != string::npos;

	cout << result;

	*/

	return 0;
}
