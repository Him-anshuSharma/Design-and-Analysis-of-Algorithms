#include<iostream>

using namespace std;

int fmin,fmax;
int arr[100];

void min_max(int s, int e){
    if(s == e){
        fmin = s;
        fmax = s;
    }
    else if(s == e-1){
        if(arr[s]>arr[e]){
            fmin = e;
            fmax = s;
        }
        else{
            fmin = s;
            fmax = e;
        }
    }
    else{
        int min,max;
        int mid = (s+e)/2;
        min_max(s,mid);
        min = fmin;
        max = fmax;
        min_max(mid+1,e);
        min<fmin?fmin = min:NULL;
        max>fmax?fmax = max:NULL;
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    min_max(0,size-1);
    cout << "MIN "<< arr[fmin] << " MAX " << arr[fmax];
    return 0;
}
