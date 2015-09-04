#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
char pre[30];
char mid[30];
char ans[30];

void fun(int pl,int pr,int ml,int mr,int loc){
    int i;
    if(pr < pl) return ;
    if(mr < ml) return ;
    for(i = ml;i < mr;i++){
        if(mid[i] == pre[pl]){
            ans[loc] = mid[i];
            break;
        }
    }
    int lenl = i - ml;
    int lenr = mr - i-1;
    if(lenl > 0)
    fun(pl+1,pl+lenl+1,ml,i,loc-lenr-1);
    if(lenr > 0)
    fun(pl+lenl+1,pr,i+1,mr,loc-1);
}
int main(){
    scanf("%s%s",pre,mid);
    int len  = strlen(pre);
    fun(0,len,0,len,len-1);
    printf("%s\n",ans);
    return 0;
}
