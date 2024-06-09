#include <iostream>
#include <fstream>
#include "NodeTrie.h"
using namespace std;

int String_Size(string word);

int main() {
	///Reading the File First Then take an object from the NodeTrie class and insert the words[char] in its data node.
	NodeTrie* Trie = new NodeTrie();
	string item;
	fstream file;
	file.open("dataSet.txt", ios::in);
	if (file.is_open()) {
		while (file >> item) {
			Trie->InsertChar(Trie, item, String_Size(item));   ///Insert Function
			//cout << item << "\n";
		}
	}
	file.close();



///Test Functions 
	cout << Trie->One_Search(Trie, "cat", 3) << endl;  ///Single Serach Function 

	string word[] = { "apple","cat","apply" };
	int number_word = 3;
	bool* result = Trie->Multiple_Search(Trie, word, number_word);  ///Multiple Serach Function 
	for (int i = 0; i < number_word; i++) {
		cout << "Search for \"" << word[i] << "\": " << (result[i] ? "Found" : "Not Found") << endl;
	}
	string prefix = { "com" };
	cout << Trie->Prefix_Search(Trie, prefix)<<endl;    ///Prefix Serach Function 

	string missed = { "acc" };
	cout << Trie->Misspelled_Search(Trie, missed);

	string suffix = "ple";       ///Suffix Serach Function 
	string* suffix_results = Trie->Suffix_Search(Trie, suffix, String_Size(suffix), true);
	cout << "Words ending with \"" << suffix << "\":" << endl;
	for (int i = 0; suffix_results[i] != ""; i++) {
		cout << suffix_results[i] << endl;
	}
	delete[] suffix_results;
}


int String_Size(string word) {
	int index = 0;
	while (word[index]) {
		index++;
	}
	return index;
}