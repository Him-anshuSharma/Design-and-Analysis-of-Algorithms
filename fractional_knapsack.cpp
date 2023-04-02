#include<iostream>

using namespace std;

typedef struct {
    float val;
    float weight;
    float vw_ratio;
    int index;
}item;

void sort(item* arr, int size){
    for(int i=0;i<size-1;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j].vw_ratio<arr[min].vw_ratio){
                min = j;
            }
        }
        item temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int main(int argc, char const *argv[])
{
    float w;
    int tot_items;
    cin >> w >> tot_items;
    item items[tot_items];
    float bag[tot_items];
    for(int i=0;i<tot_items;i++){
        cin >> items[i].weight ;
    }
    for(int i=0;i<tot_items;i++){
        cin >> items[i].val ;
        items[i].vw_ratio = items[i].val/items[i].weight;
        items[i].index = i;
    }
    sort(items,tot_items);
    int k = tot_items-1;
    int tot_w = 0;
    while(w>0){
        //w = capacity of bag
        if(items[k].weight <= w){
            bag[items[k].index] = 1;
            w = w-items[k].weight;
            k = k -1;
        }
        else{
            bag[items[k].index] = (w/items[k].weight);
            k = k-1;
            w = 0;
        }
    }
    for(float i:bag){
        cout << i << " ";
    }
    return 0;
}
