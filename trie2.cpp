#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;
typedef pair<int,int> pii;
#define MOD 1000000007

/* a-z == 0-25 */

struct Node {
    Node *links[26];
    int cntEndWith = 0 , cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void incPrefix(){
        cntPrefix++;
    }

    void incEnd(){
        cntEndWith++;
    }

    void redPrefix(){
        cntPrefix--;
    }

    void delEnd(){
        cntEndWith--;
    }
};

class Trie {

    private:
        Node* root;

    public:

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());  
                }    
                //move to new reference trie:   
                node->get(word[i]);
                node->incPrefix();
            }
            node->incEnd();
        }

        int countWords(string word){
            Node* node = root;
            for(int i=0;i<size(word);i++){
                if(!node->containsKey(word[i])) return 0;
                node = node->get(word[i]);
            }
            
            return node->cntEndWith;
        }

        int countPrefix(string word){
            Node* node = root;
            for(int i=0;i<size(word);i++){
                if(!node->containsKey(word[i])) return 0;
                node = node->get(word[i]);
            }
            
            return node->cntPrefix;
        }

        void deleteWord(string word){
            Node* node = root;
            for(int i=0;i<size(word);i++){
                if(!node->containsKey(word[i])) return;
                node = node->get(word[i]);
                node->redPrefix();
            }
            node->delEnd();
        }

};


int main(){
    return 0;
}