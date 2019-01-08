#pragma once
#include <string>

// C++ implementation of search and insert operations on Trie 

using namespace std;
constexpr size_t ALPHABET_SIZE = 26;

// trie node 
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE]; 
	bool isEndOfWord;					// isEndOfWord is true if the node represents end of a word
};

// Returns new trie node (initialized to NULLs) 
TrieNode* getNode()
{
	TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;
	return pNode;
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just marks leaf node 
void insert(TrieNode* root, string key)
{
	TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf 
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false 
bool search(TrieNode* root, string key)
{
	TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != nullptr && pCrawl->isEndOfWord);
}
