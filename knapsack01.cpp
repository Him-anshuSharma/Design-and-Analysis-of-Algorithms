#include<iostream>
using namespace std;

#define MAX(a,b) ((a>b)?a:b)

int n, W;
int w[100], v[100];
int arr[100][100];

int fractionalKnapsack(int i, int j)
{
    if(i == n) return 0;
    if(arr[i][j] != -1) return arr[i][j];
    if(j + w[i] > W) return arr[i][j] = fractionalKnapsack(i + 1, j);
    else return arr[i][j] = MAX(fractionalKnapsack(i + 1, j), fractionalKnapsack(i + 1, j + w[i]) + v[i]);
}

int main()
{
    cin>>n;
    cin>>W;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= W; j++)
            arr[i][j] = -1;
    fractionalKnapsack(0,0);        
    int i = 0, j = 0;
    while(i < n)
    {
        if(arr[i][j] == arr[i + 1][j]){
          i++;
          cout<<"0 ";
        } 
        else
        {
            cout<<"1 ";
            j += w[i];
            i++;
        }
    }
    return 0;
}