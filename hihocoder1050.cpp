#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> vec[100005];
int vis[100005];
int d[100005];

int dfs(int x,int st){
    vis[x] = 1;
    int si = vec[x].size();
    for(int i = 0;i < si;i++){
        int v = vec[x][i];
        if(!vis[v]){
            d[v] = st+1;
            dfs(v,st+1);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i < n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    dfs(1,0);
    int ma = -1;
    int x = 0;
    for(int i = 1;i <= n;i++){
        if(d[i] > ma){
            ma = d[i];
            x = i;
        }
    }
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    dfs(x,0);
    ma = -1;
    for(int i = 1;i <= n;i++){
        if(d[i]>ma){
            ma = d[i];
        }
    }
    cout << ma << endl;��*
    return 0;
}
//�ȴ�����һ�㿪ʼ��һ���·��Ȼ�������·���յ㿪ʼ���·��ʱ���ҵ����·����������������·
/*�����ԣ�������֮�����ľ���һ���Ǵ�ĳһ������ʼ���·���ϴγ�·�ģ�����ҵ��·Ȼ���ٴ��·�յ㿪ʼ���·��ôһ�����ҵ�������������������*/
