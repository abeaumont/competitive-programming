// https://onlinejudge.org/external/5/573.pdf
#include<bits/stdc++.h>
using namespace std;
int main(){
    double H, U, D, F;
    while(cin >> H >> U >> D >> F){
        if(H == 0) break;

        // height, day, slide
        double h=0, d=0, s=U*F/100;
        bool fail=true;
        
        while(h >= 0 && h <= H){
            d++;
            // day
            if((d-1)*s < U)
                h += U - (d-1)*s;
            if(h > H){fail=false; break;}
            // night
            h -= D;
        }

        if(!fail) cout << "success on day " << d << endl;
        else cout << "failure on day " << d << endl;
    }
}
