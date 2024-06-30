#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MOD 1000000007
#define MOD2 1000000033

/*        Rabin Karp Algorithm        */

pll compute(string a,ll m){
    ll hash1 = 0 , hash2 = 0 , f1 = 1 , f2 = 1 , r1 = 26 , r2 = 27;
    for(int i=m-1;i>=0;i--){
        
        hash1 += ((a[i]-'a')*f1)%MOD;
        f1 = (f1*r1)%MOD;

        hash2 += ((a[i]-'a')*f2)%MOD2;
        f2 = (f2*r2)%MOD2;

    }
    return {hash1,hash2};
}

int RabinKarp(string s,string p){
    ll n = size(s) , m = size(p);
    if(n < m) return -1;

    ll max_w1 = 1 , max_w2 = 1 , r1 = 26 , r2 = 27;
    for(int i=0;i<m;i++) max_w1 = (max_w1*r1)%MOD;
    for(int i=0;i<m;i++) max_w2 = (max_w2*r2)%MOD2;

    pll hash_p = compute(p,m) , hash_s;

    for(int i=0;i<=n-m;i++){
        if(i == 0){
            hash_s = compute(s,m);
        }
        else {
            hash_s.first = ((hash_s.first*r1)%MOD - ((s[i-1]-'a')*max_w1)%MOD + s[i+m-1] - 'a' + MOD)%MOD;
            hash_s.second = ((hash_s.second*r2)%MOD2 - ((s[i-1]-'a')*max_w2)%MOD2 + s[i+m-1] - 'a' + MOD2)%MOD2; 
        }
        if(hash_s.first == hash_p.first && hash_p.second == hash_s.second) return i;
    }

    return -1;
}


/*        KMP Algorithm       */


// String : a a b # a a b a a b a a b
// Lps    : 0 1 0 0 1 2 3 1 2 3 1 2 3

vector<int> kmp(string s){
    int n = size(s);
    vector<int> lps(n,0);

    for(int i=1;i<n;i++){
        int prev_idx = lps[i-1];
        while(prev_idx > 0 && s[i] != s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        lps[i] = prev_idx + (s[i] == s[prev_idx]);
    }

    return lps;
}



int main(){
    cout<<RabinKarp("abcdef","cd");
    return 0;
}