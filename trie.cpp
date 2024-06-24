#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;
typedef pair<int,int> pii;
#define MOD 1000000007

/* a-z == 0-25 */

struct Node {
    Node *links[26];
    bool flag = false;
    int ew = 0 , cp = 0;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){ 
        return flag;
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
            }
            node->setEnd();
        }

        bool searchWord(string word){
            Node* node = root;
            for(int i=0;i<size(word);i++){
                if(!node->containsKey(word[i])) return false;
                node = node->get(word[i]);
            }
            
            return node->isEnd();
        }

        bool startsWith(string word){
            Node* node = root;
            for(int i=0;i<size(word);i++){
                if(!node->containsKey(word[i])) return false;
                node = node->get(word[i]);
            }
            
            return true;
        }

        int countWordsEqual(string word){

        }
};


int main(){
    return 0;
}