#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdbool>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define ALPHABETS_SIZE (26)
#define CHAR_TO_INDEX(c) ((int) c - (int) a)

using namespace std;

struct TrieNode {
    struct TrieNode *children[ALPHABETS_SIZE];
    // isLeaf is true if the node represent end of word
    bool isLeaf;
};

// return new trie node (intialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));
    if (pNode) {
        pNode->isLeaf = false;
        for (int i = 0; i < ALPHABETS_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// if not present, inserts key into trie
// if the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key) {
    int length = strlen(key);
    struct TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// return true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key) {
    int length = strlen(key);
    struct TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index]) return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isLeaf);
}

int main() {
    char keys[][1000];
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%s\n", keys[i]);
    struct TrieNode *root = getNode();
    for (int i = 1; i <= N; i++) insert(root, keys[i]);
    return 0;
}
