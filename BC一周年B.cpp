#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define INF 0x4fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
char str[] = "anniversary";
int a[300][4] = {};
char st[105];
int main(){
    int t;
    cin >> t;
    int len = strlen(str);
    int w = 0;
    for(int i = 0;i < len-2;i++){
        for(int j = i+1;j < len-1;j++){
                a[w][0] = i;
                a[w][1] = j;
                a[w][2] = len-1;
                w++;                            
        }
    } 
    while(t--){
        scanf("%s",st);
        len = strlen(st);
        int flag = 0; 
        int s,e,g,f;
        for(int i = 0;i < w;i++){
            s = 0;
            f = 0;
            g = 0;
            for(int j =  0;j < 3;j++){
                e = a[i][j];
                for(int k = g;k < len;k++){
                    int d = 0;
                    int status = 0;
                    while(str[s+d] == st[k+d] && s+d <= e && k+d < len){
                        if(s+d == e){
                            f ++;
                            s = a[i][j]+1;
                            g = k+d+1;
                            status = 1;
                            break;
                        }
                        d ++;
                    }
                    if(status){
                        break;
                    }
                }
            }
            
            if(f == 3){
                flag = 1;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
