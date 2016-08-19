#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Node;
Node * ZERO;
Node * ROOT;

struct Node {
    Node * link;
    Node * child[256];
    vector<int> found;
    Node() {
        link = ROOT;
        for (int i = 0; i < 256; i++) {
            child[i] = NULL;
        }
    }
    void setChild(int childIdx, Node * id) {
        //cout << (int)this%99 << " " << char(childIdx) << " " << int(id)%99 << endl;
        child[childIdx] = id;
    }
    void setLink(Node * id) {
        //cout << (int)this%99 << " -> " << int(id)%99 << endl;
        link = id;
    }
};

void add(int id, char str[]) {
    Node * CUR = ROOT;
    int i = 0;
    while (str[i] != '\0') {
        char pos = str[i];
        if (CUR->child[pos] == NULL) {
            CUR->setChild(pos, new Node());
        }
        CUR = CUR->child[pos];
        i++;
    }
    CUR->found.push_back(id);
}

void initTrie() {
    ROOT = new Node();
    ZERO = new Node();
    ROOT->link = ZERO;
    for (int i = 0; i < 256; i++) {
        ZERO->child[i] = ROOT;
    }
}

void buildLinks() {
    queue<Node*> Q;
    Q.push(ROOT);
    while (!Q.empty()) {
        Node * CUR = Q.front();
        Q.pop();
        for (int i = 0; i < 256; i++) {
            if (CUR->child[i] == NULL) continue; // no such child, nothing to do here
            // CUR is parent
            Node * TMP = CUR;
            while (TMP->link->child[i] == NULL) TMP = TMP->link;
            CUR->child[i]->setLink(TMP->link->child[i]);
            Q.push(CUR->child[i]);
        }
    }
}

char ANS[2001];
int main() {
    initTrie();
    char TEXT[100001];
    scanf("%s",TEXT);
    int n;
    char PAT[2001];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%s",PAT);
        add(i, PAT);
    }
    buildLinks();
    int i = 0;
    Node * CUR = ROOT;
    while (TEXT[i] != '\0') {
        char id = TEXT[i];
        if (CUR->child[id] == NULL) {
            CUR = CUR->link;
        } else {
            // check whether we have some occurences
            CUR = CUR->child[id];
            Node * TMP = CUR;
            while (TMP->found.size() > 0) {
                for (int j = 0; j < TMP->found.size(); j++) {
                    ANS[TMP->found[j]] = 1;
                }
                TMP = TMP->link;
            }
            i++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ANS[i]) {
            printf("Yn");
        } else {
            printf("Nn");
        }
    }
    return 0;
}
