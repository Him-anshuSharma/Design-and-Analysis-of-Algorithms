#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int initial[10];
    int end[10];
    int n,arr;
    cin>>n>>arr;

    for(int k=0;k<n;k++)
    {
        cin>>initial[k];
    }

    for(int k=0;k<n;k++)
    {
        cin>>end[k];
    }

    int i=0;
    cout<<0;
    for(int j=1;j<=arr;j++)
    {
        if(initial[j]>=end[i])
        {
            cout<<j<<" ";
            i=j;
        }
    }


    return 0;
}
