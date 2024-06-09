#include "NodeTrie.h"
#include "LinkedList.h"
#include "Node.h"
#include "Stack.h"
#include <iostream>
using namespace std;
int NodeTrie::String_Size(string word) {
	int lenght = 0;
	while (word[lenght]) {
		lenght++;
	}
	return lenght;
}
///Defualte Constructor
NodeTrie::NodeTrie() {
	flag = false;
	for (int i = 0; i < 26; i++) {
		children_Arr[i] = nullptr;
	}
}

///Paramitraized Constructor 
NodeTrie::NodeTrie(bool Flag) {
	flag = Flag;
	for (int i = 0; i < 26; i++) {
		children_Arr[i] = nullptr;
	}
}

///Setters Methods
void NodeTrie::setCondition(bool Flag) {
	flag = Flag;
}
void NodeTrie::setChildrenChar(int index, NodeTrie* child) {
	if (index >= 0 && index < 26) {
		children_Arr[index] = child;
	}
}

///Getters Methods 
bool NodeTrie::getCondition() {
	return flag; 
}
NodeTrie* NodeTrie::getChildrenChar(int index) {
	if (index >= 0 && index < 26) {
		return children_Arr[index];
	}
	return nullptr;
}


///Needed Methods 

///Insert Function Implementation
void NodeTrie::InsertChar(NodeTrie* Trie, string word, int size) {
	for (int i = 0; i < size; i++) {
		if (Trie->getChildrenChar(word[i] - 'a') == nullptr) {
			Trie->setChildrenChar(word[i] - 'a', new NodeTrie());
		}
		Trie = Trie->getChildrenChar(word[i] - 'a');
	}
	Trie->setCondition(true);
}


///Single Search Implementation
bool NodeTrie::One_Search(NodeTrie* Trie, string word, int size) {
	for (int i = 0; i < size; i++) {
		if (Trie->getChildrenChar(word[i] - 'a') == nullptr) {
			return false;
		}
		Trie = Trie->getChildrenChar(word[i] - 'a');
	}
	return Trie->getCondition();

}

///Multiple_Search Implementation
bool* NodeTrie::Multiple_Search(NodeTrie* Trie, string wordArr[], int numb_Words) {
	bool* outPut = new bool[numb_Words];
	for (int i = 0; i < numb_Words; i++) {
		outPut[i] = Trie->One_Search(Trie,wordArr[i], String_Size(wordArr[i]));
	}
	return outPut;
}
///Print All Function
void NodeTrie::PrintAllWord(NodeTrie* Trie, string collecting, string* result, int index) {
	if (Trie->getCondition()) {
		result[index++] = collecting;
	}
	for (int i = 0; i < 26; i++) {
		if (Trie->getChildrenChar(i) != nullptr) {
			PrintAllWord(Trie->getChildrenChar(i), collecting + char('a' + i), result, index);
		}

	}
}
///Prefix Function Implementation 
bool NodeTrie::Prefix_Search(NodeTrie* Trie, string Prefix) {
	int OutputSize = 100;
	string* Output_Word = new string[OutputSize];
	int size_prefix = String_Size(Prefix);
	for (int i = 0; i < size_prefix; i++) {
		if (Trie->getChildrenChar(Prefix[i] - 'a') == nullptr) {
			return false;
		}
		Trie = Trie->getChildrenChar(Prefix[i] - 'a');
	}
	return true;
}


/// Suffix Function Implementation
string* NodeTrie::Suffix_Search(NodeTrie* Trie, string suffix, int size, bool flag) {
	flag = true;
	int OutputSize = 100;
	string* Output_Word = new string[OutputSize];
	int index = 0;
	if (size == 0) {
		PrintAllWord(Trie,"", Output_Word, index);
		return Output_Word;
	}
	if (flag) {
		if (Trie->getChildrenChar(suffix[size - 1] - 'a') != nullptr) {
			return Suffix_Search(Trie->getChildrenChar(suffix[size - 1] -'a'), suffix, size - 1, false);
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (Trie->getChildrenChar(i) != nullptr) {
				string* result_temp = Suffix_Search(Trie->getChildrenChar(i), suffix, size - 1, flag);
					for (int j = 0; result_temp[j] != ""; j++) {
						Output_Word[index++] = result_temp[j];
					}
					delete[] result_temp;
				}
			}
		}
	return Output_Word;
}

///Misspelled Function Implementation 
bool NodeTrie::Misspelled_Search(NodeTrie* Trie, string missed) {
	int OutputSize = 100;
	string* Output_Word = new string[OutputSize];
	int size_prefix = String_Size(missed);
	for (int i = 0; i < size_prefix; i++) {
		if (Trie->getChildrenChar(missed[i] - 'a') == nullptr) {
			return false;
		}
		Trie = Trie->getChildrenChar(missed[i] - 'a');
	}
	return true;
}

///Fuzzy Function Implementation
string* NodeTrie::Fuzzy_Search(NodeTrie* Trie, LinkedList* Fuzzy, int counter) {
	Node* FuzzyNode = Fuzzy->getFirst();
	int OutputSize = 100;
	string* Output_Word = new string[OutputSize];
	string word_prefix = "";
	while (Fuzzy != nullptr) {
		char data = FuzzyNode->getItem();
		if (data == '?') {
			cout << "Its a Fuzzy Search" << endl;
			for (int i = 0; i < 26 < i++;) {
				if (Trie->getChildrenChar(i) != nullptr) {
					string* tempResult1 = new string[OutputSize];
					int counter = 0;
					LinkedList* Remain_String = new LinkedList();
					Node* temp = FuzzyNode->getPointer();
					while (temp != nullptr) {
						Remain_String->insert(temp->getItem());
						temp = temp->getPointer();
					}
					string* tempResult2 = Fuzzy_Search(Trie->getChildrenChar(i), Remain_String, counter);
					for (int j = 0; j < counter; j++) {
						Output_Word[counter++] = tempResult2[j];
					}
					delete[] tempResult2;
				}
			}
			return Output_Word;
		}
		else {
			Trie = Trie->getChildrenChar(data - 'a');
			if (Trie == nullptr) {
				return nullptr;
			}
			word_prefix += data;
		}
		FuzzyNode = FuzzyNode->getPointer();
	}
	PrintAllWord(Trie, word_prefix, Output_Word, counter);
	return Output_Word;
}

///Delete Function Implementation
void NodeTrie::Delete(NodeTrie*& Trie, string word, int size) {
	bool flag = One_Search(Trie, word, 4);
	if (flag) {
		for (int i = 0; i < size; i++) {
			Trie = Trie->getChildrenChar(word[i] - 'a');
		}
		flag = false;
		Trie->setCondition(flag);
		cout << "Deletion succeeded" << endl;
	}
	else cout << "The Word is not Found" << endl;
}