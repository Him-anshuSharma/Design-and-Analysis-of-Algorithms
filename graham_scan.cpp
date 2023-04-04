#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

point points[15];

stack<point> gs_stack;

point nextToTop(){
    point p;
    if(gs_stack.size()<2){
        return p;
    }
    p = gs_stack.top();
    gs_stack.pop();
    point res = gs_stack.top();
    gs_stack.push(p);
    return res;
}

int compare_y(const void* a, const void* b) {
    point* p1 = (point*) a;
    point* p2 = (point*) b;

    if (p1->y < p2->y) {
        return -1;
    } else if (p1->y > p2->y) {
        return 1;
    } else {
        return 0;
    }
}


int orientation(point p, point q, point r){
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val == 0)
        return 0;
    else if(val > 0)
        return 1; //clockwise
    else
        return 2; //counter clockwise
}

void gs(int n){
    gs_stack.push(points[0]);
    gs_stack.push(points[1]);
    gs_stack.push(points[2]);
    for(int i=3;i<n;i++){
        while(orientation(nextToTop(),gs_stack.top(),points[i])<2 && gs_stack.size()>1){
            gs_stack.pop();
        }
        gs_stack.push(points[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> points[i].x >> points[i].y;
    }
    qsort(points,10,sizeof(point),compare_y);
    gs(10);
    cout << endl;
    while(!gs_stack.empty()){
        point p = gs_stack.top();
        gs_stack.pop();
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}
