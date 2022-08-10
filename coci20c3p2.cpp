#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t ;};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define INF 2e18
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
struct node {
    node *children[26];
    bool nin = false;
    bool emi = false;
};
void insert(node *root, string s, bool nin){
    node *cur = root;
    for(auto c : s){
        if(nin) cur->nin = true;
        else cur->emi = true;
        if(cur->children[c - 'a'] == nullptr){
            cur->children[c - 'a'] = new node();
            if(nin) cur->children[c - 'a']->nin = true;
            else cur->children[c - 'a']->emi = true;
        }
            
        cur = cur->children[c - 'a'];
    }
}
bool winner(node *root, int turn){
    if(turn % 2 == 0){
        for(int i = 0; i < 26; i++){
            if(root->children[i] == nullptr) continue;
            if(!root->children[i]->emi && root->children[i]->nin) return true;
            else
                if(winner(root->children[i], turn + 1)) return true;
        }
       return false;
    }
    else{
        for(int i = 0; i < 26; i++){
            if(root->children[i] == nullptr) continue;
            if(root->children[i]->emi && !root->children[i]->nin) return false;
            else{
                if(!winner(root->children[i], turn + 1)) return false;
            }
        }
       return true;
    }
}
int n, n2;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    node *root = new node();
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        insert(root, s, true);
    }
    cin>>n2;
    for(int i = 0; i < n2; i++){
        string s;
        cin>>s;
        insert(root, s, false);
    }
    if(winner(root, 0)) cout<<"Nina"<<endl;
    else cout<<"Emilija"<<endl;
}