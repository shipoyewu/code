#include <iostream>  
#include <string.h>  
#include <algorithm>  
#define maxn 100010  
#define mid ((L+R)>>1)  
using namespace std;  
int tree[20][maxn];//表示每层每个位置的值  
int toleft[20][maxn];//20层每层maxn t用来放原序; toleft[p][i]表示第P层第i个放左节点的元素个数  
int sorted[maxn];//已经排序的数  
//以下为查找区间第k小划分树  
void build(int p,int L,int R) //p:第几层 默认0开始  ; L,R 左右区间从[1,n]开始建  
{  
    if(L==R) return;  //这个放最上边省时  
    int lm=0,i,ls=L,rs=mid+1;//lm表示应被放入左子树且与中位数相等的数有多少个，ls为左子树的起始位置，rs为右子树的起始位置  
    for(i=mid;i>=L;i--) //求lm ；2 3 3 4 4 5 5 7 9得到的lm=2  
    {             
        if(sorted[i]==sorted[mid])  
        lm++;          //之前有一个错误的想法： 不记录这个lm  找的时候直接找<=的  但是这样会出错  比如 2 4 4 4 5 1     
        else         // 排序： 1 2 4 4 4 5   那如果我们直接找<=的（6/2=3）个的话 会找到 2 4 4这样就错了所以还是要记录lm  
        break;  
    }  
    for(i=L;i<=R;i++)  
    {  
        if(i==L)//这里要特殊讨论（原因：间接的对所有初始化 我们这样做便于toleft[p][i]=toleft[p][i-1]这一部的处理）  
        toleft[p][i]=0;     //  
        else  
        toleft[p][i]=toleft[p][i-1];//下一个肯定是上一个+0或1  
          
        if(tree[p][i]==sorted[mid])//若与中位数相等则判断是否应该被放入左子树  
        {  
            if(lm)  
            {  
                lm--;  
                toleft[p][i]++;  //如果满足 说明又多了一个元素放左节点了  
                tree[p+1][ls++]=tree[p][i];//放入下一个t[]  
            }  
            else  
            tree[p+1][rs++]=tree[p][i];  
        }  
        else if(tree[p][i]<sorted[mid])//查找区间第K大即为>  
        {  
            toleft[p][i]++;  
            tree[p+1][ls++]=tree[p][i];  
        }  
        else  
        tree[p+1][rs++]=tree[p][i];  
    }  
    build(p+1,L,mid);  
    build(p+1,mid+1,R);  
}  
//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间  
int query(int p,int L,int R,int l,int r,int k)  
{  
    int s,ss;//s表示[L,l-1]放入左子树的个数，ss表示区间[l,r]被放入左子树的个数  
    if(L==R)//找到所求的数  
    return tree[p][L];  
    if(l==L)  
    s=0,ss=toleft[p][r];  
    else  
    s=toleft[p][l-1],ss=toleft[p][r]-s;  
    if(k<=ss)//要找的数在左子树中  
    return query(p+1,L,mid,L+s,L+toleft[p][r]-1,k);  
    else//要找的数在右子树中  
    return query(p+1,mid+1,R,mid+1-L+l-s,mid+1-L+r-toleft[p][r],k-ss);  
}  
int main()  
{  
   int i,n,m;  
   cin>>n>>m;  
   for(i=1;i<=n;i++)  
   {  
       cin>>tree[0][i];  
       sorted[i]=tree[0][i];  
   }  
   sort(sorted+1,sorted+n+1);  
   build(0,1,n);  
   while(m--)  
   {  
       int l,r,k;  
       cin>>l>>r>>k;  
       int ans=query(0,1,n,l,r,k);  
       cout<<ans<<endl;  
   }  
    return 0;  
}  
