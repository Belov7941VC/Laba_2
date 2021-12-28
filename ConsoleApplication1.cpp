#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isVowel(char c)
{
	return c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
		c == 'Y' || c == 'y' || c == 'U' || c == 'u' ||
		c == 'I' || c == 'i' || c == 'O' || c == 'o';
}

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in("tr.txt");
	if (!in.good()) return -1;
	char word[15];
	size_t words_vowel_count = 0;
	cout << "Слова,начинающиеся с гласных английских букв: \n";
	while (in >> word) {
		if (isVowel(word[0])) {
			cout << word << endl;
			++words_vowel_count;
		}
	}
	if (!words_vowel_count)
		cout << "Слов, начинающихся на гласные английские буквы, нет";
	system("pause");
	return 0;
}