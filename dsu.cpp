#include <bits/stdc++.h>
using namespace std;

class dsu{
    private:
        vector<int> rank,parent,size;
    public:
        dsu(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i] = i;

        }

        int findPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v) return ;

            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v) return ;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main(){
    
    return 0;
}