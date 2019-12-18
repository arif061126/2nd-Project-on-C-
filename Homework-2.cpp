/*
Task: H2
Family Name: AHMED
Given Name: Arif
Matriculation number: 3024970
Uni-Email: arif.ahmed@stud.uni-due.de
Course of Studies: ISE CE
*/

#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
//task-1:
struct point{
    string pName;
    double x,y;
    double oriDistance;
    point *next;
};

//point p1, p2;

//task-2:
double mDistance(point p1, point p2){
    double d;
    d=sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
    return d;
}

//task-3:
point nearDistance(point pt[], point p){
    point *ptr;
    double r,r1;
    r=mDistance(p,pt[0]);
    for(int i=1;i<n;i++){
        r1=mDistance(p,pt[i]);
        if(r1<r){
            if(r1!=0){
                r=r1;
//                ptr->listOfpoints[i];
            }
        }
    }
    return *ptr;
}

//task-4:
double sortPoints(point p1, point p2){
    point center={0,0};
    return (mDistance(center,p1)<mDistance(center,p2));
}

//task-5:
point *head;

void insertpoint(string pName, double x, double y)
{
    point *newPoint = new point;
    newPoint->pName=pName;
    newPoint->x = x;
    newPoint->y = y;
    newPoint->next = head;
    head = newPoint;
}

//task-6:
void deletePoints(point pName)
{
   point *del;
   while (head != 0){
      del = head;
      head = head->next;
      cout << "delete: " << del->pName << endl;
      delete del;
   }
}

//task-7:
int main(void){
    int endPoint;

    //struct point c[n];


    do{
            string pName, in;
            double x, y;
            point p1,p2;
            cout<<"string describing obstacle (\"end\" for end of input): ";
            cin>>in;
            if(in == "end"){
                cout<<"obstacle "<<in<<": ( "<<setprecision(2)<<x <<", " <<setprecision(2)<<y<<"), distance:  "<<setprecision(2)<<mDistance(p1, p2)<<"m, nearest to this: "<<in<<endl;
                deletePoints(p1);
                endPoint = 0;
            }
            else{
                cout<<"\n";
                cout<<"x and y coordinate: ";
                cin>>x;
                cout<<" ";
                cin>>y;
                insertpoint(pName, x, y);
                }
        }while(endPoint!=0);
    return 0;
}
