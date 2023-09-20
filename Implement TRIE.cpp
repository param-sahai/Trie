#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* arr[26];
    bool flag = false;
    
    TrieNode* get(char key){
        return arr[key-'a'];
    }
    
    void put(char key, TrieNode* node){
        arr[key-'a'] = node;
    }
    
    bool containsKey(char key){
        return arr[key-'a']!=nullptr;
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    TrieNode* root;
    
    public:
    Trie(){
        root = new TrieNode();
    }
    
    //Inserting string in TrieNode
    void insert(string word){
        //dummy node pointing to the root initially
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    
    //Checking whether the entire string is present or not
    bool isPresent(string word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i])))
            return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    
    bool startsWith(string word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i])))
            return false;
            node = node->get(word[i]);
        }
        return true;
    }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.isPresent(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
