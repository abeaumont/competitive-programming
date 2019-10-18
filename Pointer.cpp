#include <iostream>
using namespace std;


void update(int *a,int *b) {
    // Complete this function 
    int c,d;   
    c=(*a)+(*b);
    d=(*a)-(*b);
    *a=c;
    *b=d;


}

int main() {
    int a, b;
    cin>>a>>b;
    int x;
    int *pa = &a, *pb = &b;
    
    
    update(pa, pb);

    cout<<a<<"\n";
    if(b>0)
    cout<<b;
    
    else 
    {
        x=-b;
    cout<<x;
    }

    

    return 0;
}

