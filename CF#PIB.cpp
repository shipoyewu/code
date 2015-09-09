#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set> 
#include <vector> 
using namespace std;
int re[1005];
char a[1000][100];
int d[1000]; 
int main(){
    int n;
    cin >>n;
    set<int> in;
    vector<int> vec;

    int ans[1000] = {0};
    for(int i = 1;i <= n;i++){
        scanf("%s %d",a[i],&d[i]);
        if(a[i][0] == '+'){
            in.insert(d[i]);
        }
        if(a[i][0] == '-'){
            if(in.find(d[i]) != in.end()){
                in.erase(d[i]);
            }
            else{
                vec.push_back(d[i]);
            }
        }
    }
    in.clear();
    for(int i = 0;i < vec.size();i++){
        in.insert(vec[i]);
    }
    int ma = 0;
    for(int i = 1;i <= n;i++){
        if(in.size() > ma){
            ma = in.size();
        }
        if(a[i][0] == '+'){
            in.insert(d[i]);
        }
        else{
            in.erase(d[i]);
        }
        if(in.size() > ma){
            ma = in.size();
        }
    }
    cout << ma<< endl;
    return 0;
}
