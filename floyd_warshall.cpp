#include <cstdio>
#include <iostream>

using namespace std;

//���нڵ�����·������ 
int floyd_warshall(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				w[i][j] = min(w[i][k] + w[k][j],w[i][j]);
			}
		}
	}
}

//����ͼ�Ĵ��ݱհ����� 
int transitive_closure(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(j  = 0;j < n;j++){
				w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
			}
		}
	}
}

//pre[i][j]�����ŵ���i-j·�������һ���ڵ�Ҳ����j��ǰ���ڵ� 
void print_path(int i,int j){
	if(i == j){
		cout << i << endl;
	}
	else if(pre[i][j] == -1){
		printf("no path!!!");
	}
	else {
		print_path(i,pre[i][j]);
	}
	cout << j << endl; 
} 

int find_pre(int u,int v){
	if(u == v){
		pre[i][j] = -1;
	}
	for(int i = 0;i < n;i++){
		if(G[i][v] && w[u][i] + G[i][v] == w[u][v]){
			pre[u][v] = i;
			find_pre(u,i);
		}
	}
} 

int find(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(pre[i][j]){
				find_pre(i,j);
			}
		}
	}
}
int main(){
	
} 
