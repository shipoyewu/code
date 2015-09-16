#include <cstdio>
#include <iostream>
#include <map>
#include <cstring> 
using namespace std;
int fa[1005];
int a[1005];
char ans[1005];
void fun(int l,int r,int loc,int f,char ch){
    //cout << l <<" "<<  r << endl;
    ans[a[loc]] = ch;
    fa[a[loc]] = f;
    int ls = a[loc] - l;
    if(ls > 0 )
    fun(l,a[loc]-1,loc+1,a[loc],'E');
    int rs = r - l - ls;
    if(rs > 0)
    fun(a[loc]+1,r,loc+ls+1,a[loc],'W');
}
int solve(int x){
    if(ans[x]){
        solve(fa[x]);
        printf("%c",ans[x]);
    }
} 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(fa,0,sizeof(fa));
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }

        fun(1,n,1,0,'\0');
        int m;
        cin >> m;
        for(int i = 0;i < m;i++){
            int x;
            scanf("%d",&x);
            solve(x);
            cout << endl;
        }
    }
    return 0;
} 
