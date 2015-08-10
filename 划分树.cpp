#include <iostream>  
#include <string.h>  
#include <algorithm>  
#define maxn 100010  
#define mid ((L+R)>>1)  
using namespace std;  
int tree[20][maxn];//��ʾÿ��ÿ��λ�õ�ֵ  
int toleft[20][maxn];//20��ÿ��maxn t������ԭ��; toleft[p][i]��ʾ��P���i������ڵ��Ԫ�ظ���  
int sorted[maxn];//�Ѿ��������  
//����Ϊ���������kС������  
void build(int p,int L,int R) //p:�ڼ��� Ĭ��0��ʼ  ; L,R ���������[1,n]��ʼ��  
{  
    if(L==R) return;  //��������ϱ�ʡʱ  
    int lm=0,i,ls=L,rs=mid+1;//lm��ʾӦ������������������λ����ȵ����ж��ٸ���lsΪ����������ʼλ�ã�rsΪ����������ʼλ��  
    for(i=mid;i>=L;i--) //��lm ��2 3 3 4 4 5 5 7 9�õ���lm=2  
    {             
        if(sorted[i]==sorted[mid])  
        lm++;          //֮ǰ��һ��������뷨�� ����¼���lm  �ҵ�ʱ��ֱ����<=��  �������������  ���� 2 4 4 4 5 1     
        else         // ���� 1 2 4 4 4 5   ���������ֱ����<=�ģ�6/2=3�����Ļ� ���ҵ� 2 4 4�����ʹ������Ի���Ҫ��¼lm  
        break;  
    }  
    for(i=L;i<=R;i++)  
    {  
        if(i==L)//����Ҫ�������ۣ�ԭ�򣺼�ӵĶ����г�ʼ�� ��������������toleft[p][i]=toleft[p][i-1]��һ���Ĵ���  
        toleft[p][i]=0;     //  
        else  
        toleft[p][i]=toleft[p][i-1];//��һ���϶�����һ��+0��1  
          
        if(tree[p][i]==sorted[mid])//������λ��������ж��Ƿ�Ӧ�ñ�����������  
        {  
            if(lm)  
            {  
                lm--;  
                toleft[p][i]++;  //������� ˵���ֶ���һ��Ԫ�ط���ڵ���  
                tree[p+1][ls++]=tree[p][i];//������һ��t[]  
            }  
            else  
            tree[p+1][rs++]=tree[p][i];  
        }  
        else if(tree[p][i]<sorted[mid])//���������K��Ϊ>  
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
//��ѯ�����k�������[L,R]�Ǵ����䣬[l,r]��Ҫ��ѯ��С����  
int query(int p,int L,int R,int l,int r,int k)  
{  
    int s,ss;//s��ʾ[L,l-1]�����������ĸ�����ss��ʾ����[l,r]�������������ĸ���  
    if(L==R)//�ҵ��������  
    return tree[p][L];  
    if(l==L)  
    s=0,ss=toleft[p][r];  
    else  
    s=toleft[p][l-1],ss=toleft[p][r]-s;  
    if(k<=ss)//Ҫ�ҵ�������������  
    return query(p+1,L,mid,L+s,L+toleft[p][r]-1,k);  
    else//Ҫ�ҵ�������������  
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
