#include<iostream>

using namespace std;

int input[100];
int n,d=0,c=0;

bool solutions(int index, int sum, int* sol){
    if(sum == d){
        for(int i=0;i<n;i++){
            cout << sol[i] << " ";
        }
        cout << endl;
        c++;
        return c>=2;
    }
    if(index == n){
        return false;
    }
    if(sum>d){
        return false;
    }
    sol[index ] = 1;
    if(solutions(index +1,sum+input[index],sol)){
        return true;
    }
    sol[index] = 0;
    return solutions(index +1,sum,sol);
}

int main()
{
    n = 5; d= 8;
    input[0] = 1;
    input[1] = 2;
    input[2] = 3;
    input[3] = 4;
    input[4] = 6;
    int sol[100] = {0};
    if(!solutions(0,0,sol))
        cout  << "Sol cant be found";
    return 0;
}
