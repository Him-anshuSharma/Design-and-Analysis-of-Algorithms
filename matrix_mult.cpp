#include<iostream>
#include<cmath>

using namespace std;

#define INF 1e4;

const int N = 100;

int dim[N];
int dp[N][N];

int mcm(int i,int j){
    if( i==j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = INF;
    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j],mcm(i,k)+mcm(k+1,j)+dim[i-1]*dim[k]*dim[j]);
    }
    return dp[i][j];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n=4;
    int dimen = 0;
    int k=0;
    for(int i=0;i<=n;i++){
        cin >> dimen;
        dim[k++] = dimen;
    }
    cout << mcm(1,n-1) << endl;
    return 0;
}