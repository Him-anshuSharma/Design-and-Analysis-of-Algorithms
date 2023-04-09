#include<iostream>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

int orientation(point p, point q, point r){
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val == 0)
        return 0;
    else if(val > 0)
        return 1; //clockwise
    else
        return 2; //counter clockwise
}

bool doIntersect(point p1,point q1, point p2, point q2){
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);
    if(o1 != o2 && o3 != o4)
        return true;
    if(o1 == 0 && (p2.x>=p1.x && p2.x<=q1.x) && (p2.y>=p1.y && p2.y<=q1.y))
        return true;
    if(o2 == 0 && (q2.x>=p1.x && q2.x<=q1.x) && (q2.y>=p1.y && q2.y<=q1.y))
        return true;
    if(o3 == 0 && (p1.x>=p2.x && p1.x<=q2.x) && (p1.y>=p2.y && p1.y<=q2.y))
        return true;
    if(o4 == 0 && (q1.x>=p2.x && q1.x<=q2.x) && (q1.y>=p2.y && q1.y<=q2.y))
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    point points[4];
    for (int i=0;i<4;i++){
        cin >> points[i].x >> points[i].y;
    }
    cout << doIntersect(points[0],points[1],points[2],points[3]);
    return 0;
}
