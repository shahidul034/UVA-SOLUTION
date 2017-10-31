#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iomanip>
#define inf 0xfffffff
typedef long long int ll;//1507034
using namespace std;
int n=8;
int value[10][10];
int board[10][10];
int ans=-789798;
vector<int>vec[100];
bool check(int row,int col)
{
    for(int i=0; i<col; i++)
    {
        if(board[row][i])return false;
    }
    for(int i=row,j=col; i>=0&& j>=0 ; i--,j--)
    {
        if(board[i][j])return false;
    }
    for(int i=row,j=col; i<n&& j>=0 ; i++,j--)
    {
        if(board[i][j])return false;
    }
    return true;
}

bool solve(int col)
{
    if(col==n)
    {
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==1)
                {
                    cnt+=value[i][j];
                }
            }
        }
        if(cnt>ans)ans=cnt;
        cnt=0;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        if(check(i,col))
        {
            board[i][col]=1;
            if(solve(col+1))
            {
                return 1;
            }
            board[i][col]=0;
        }
    }
    return 0;
}

int main()
{
  freopen("in.txt","r",stdin);
    int tc;
    cin>>tc;
    for(int t=0; t<tc; t++)
    {
    	memset(value,0,sizeof(value));
    	memset(board,0,sizeof(board));
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                cin>>value[i][j];
            }
        }
        solve(0);
        cout<<setw(5)<<setiosflags(ios::right)<<ans<<endl;
        ans=0;


    }

}
