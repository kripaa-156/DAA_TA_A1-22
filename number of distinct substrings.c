#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26

typedef struct TrieNode {
    struct TrieNode *edge[MAX];
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i=0;i<MAX;i++) {
        node->edge[i]=NULL;
    }
    return node;
}
int insertSuffix(TrieNode *root,char *str,int pos) {
    TrieNode *curr=root;
    int newNodes=0;
    for (int i=pos;str[i]!='\0';i++) {
        int index=str[i]-'a';
        if (curr->edge[index]==NULL) {
            curr->edge[index]=createNode(); 
            newNodes++; 
        }
        curr=curr->edge[index];
    }
    return newNodes;
}
int countDistinctSubstrings(char *str) {
    TrieNode *root=createNode();
    int count=0;
    int n=strlen(str);
    for (int i=0;i<n;i++) {
        count=count+insertSuffix(root,str,i);
    }
    return count+1;
}
int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    int result = countDistinctSubstrings(str);
    printf("Number of distinct substrings are %d",result);
    return 0;
}
