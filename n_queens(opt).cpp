#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tc ll t; cin>>t;while(t--)
#define loop(variable,n) for(int variable=0;variable<n;variable++)
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,vector<int>&rl,vector<int>&ud,vector<int>&dd){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(rl[row]==0&&dd[col+row]==0&&ud[ n-1-row+col]==0){
            board[row][col]='Q';
            rl[row]=1;
            ud[n-1-row+col]=1;
            dd[col+row]=1;
            solve(col+1,ans,board,n,rl,ud,dd);
            board[row][col]='.';
            rl[row]=0;
            ud[n-1-row+col]=0;
            dd[col+row]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>>ans;
    vector<string>board(n);
    string str(n,'.');
    loop(i,n){
        board[i]=str;
    }
    vector<int>rowleft(n,0);
    vector<int>updig(2*n-1,0);
    vector<int>dowdig(2*n-1,0);
    solve(0,ans,board,n,rowleft,updig,dowdig);
    return ans;
}
int main(){
    fastIO();
    int n;cin>>n;
    vector<vector<string>>v=solveNQueens(n);
    loop(i,n){
        loop(j,n){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}
/*
1. Wrong Ans?
Did u read the Statement properly?
Did u miss any constraints?
Did u miss any corner case?
Are u sure about your Solution?
2. No Idea?
Try Greedy..
Try DP...
First Try Recursive DP..
Then Try Iterative DP..
If memory exceeds, then try to reduce it..
If not possible then, try to solve it using following way..
Try to solve it using Permutation ans Combination..
Try to find Sequence..
Try to Solve it using Algebra..
*/