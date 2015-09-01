#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
char  s[105][10];
char op[105][10];
int d[105];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%s %s %d",s[i],op[i],&d[i]);
    }
    map<double,int> ma;
    for(double i = -1;i <= 1001;i += 0.5){
        ma[i] = 0;
    }
    for(int i = 0;i < n;i++){
        if(strcmp(op[i],"<") == 0){
            for(double j = -1;j < d[i];j+=0.5){
                ma[j] ++;
            }
        }
        if(strcmp(op[i],"<=") == 0){
            for(double j = -1;j <= d[i];j+=0.5){
                ma[j]++;
            }
        }
        if(strcmp(op[i],">") == 0){
            for(double j = d[i]+0.5;j <= 1001; j+= 0.5){
                ma[j] ++;
            }
        }
        if(strcmp(op[i],">=") == 0){
            for(double j = d[i];j <= 1001;j+=0.5){
                ma[j] ++;
            }
        }
        if(strcmp(op[i],"=") == 0){
            ma[d[i]]++;
        }
    }
    int maxw = 0;
    for(double i = -1;i <= 1001;i += 0.5){
        if(ma[i] > maxw){
            maxw = ma[i];
        }
    }
    cout << maxw << endl;
    return 0;
}
