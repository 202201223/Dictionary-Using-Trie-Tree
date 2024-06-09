#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

class NodeTrie {
	///Private Members
private:
	bool flag;
	NodeTrie* children_Arr[26];

	///Public Members
public:
	///Defualte Constructor
	NodeTrie();

	///Paramitraized Constructor 
	NodeTrie(bool Flag);

	///Setters Methods 
	void setCondition(bool Flag);
	void setChildrenChar(int index, NodeTrie* child);

	///Getters Methods 
	bool getCondition();
	NodeTrie* getChildrenChar(int index);

	///Needed Methods 
	int String_Size(string word);
	void InsertChar(NodeTrie* Trie, string word, int size);
	bool One_Search(NodeTrie* Trie, string word, int size);
	bool* Multiple_Search(NodeTrie* Trie, string wordArr[], int numb_Words);
	void PrintAllWord(NodeTrie* Trie, string collecting, string* result, int index);
	bool Prefix_Search(NodeTrie* Trie, string Prefix);
	string* Fuzzy_Search(NodeTrie* Trie, LinkedList* Fuzzy,int counter);
	bool Misspelled_Search(NodeTrie* Trie, string missed);
	string* Suffix_Search(NodeTrie* Trie, string suffix, int size, bool flag = true);
	void Delete(NodeTrie*& Trie, string word, int size);
	
};