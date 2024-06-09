/*void NodeTrie::PrintAllWord(NodeTrie* Trie) {    ///Outer Function For
	char word[20];
	int level = 0;
	if (Trie == nullptr) {
		return;
	}
	void InnerNode(int level,NodeTrie* node){
		if (Trie->getCondition() == false) {
		word[level];
		cout << word;
		}
		for (int i = 0; i < 26; i++) {
			NodeTrie* child = node->getChildernChar(i);
			if (child != nullptr) {

			}


			InnerNode(level + 1, NodeTrie * node);
		}


}
*/

//void Delete_Word(NodeTrie* Trie, string);



/*bool NodeTrie::One_Search(NodeTrie* Trie, string word, int size) {
	if (Trie == nullptr) {
		return false;
	}
	if (size == 0) {
		return Trie->getCondition();
	}
	return One_Search(Trie->getChildrenChar(word[0] - 'a'), word, size - 1);
}*/



///Fuzzy Function Implementation 
/*string* NodeTrie::Fuzzy_Search(NodeTrie* Trie, LinkedList* Fuzzy) {
	Node* FuzzyNode = Fuzzy->getFirst();
	while (Trie != nullptr) {
		for (int i = 0; i < 26; i++) {
			if (Trie->getChildrenChar(i - 'a') == FuzzyNode->getData()) {

			}
		}

	}
}*/