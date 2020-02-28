#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    int n;
    double a[9999], temp;
    int b[9999], temp_;
    ifstream if_in;
    if_in.open("input.txt");
    if_in >> n;
    for(int i=0; i<n; i++){
        b[i] = i+1;
        if_in >> a[i];
        if(i != 0){
            //cout << i << endl;
            for(int j=i; j>0; j--){
                if(a[j]<a[j-1]){
                    temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                    temp_ = b[j];
                    b[j] = b[j-1];
                    b[j-1] = temp_;
                }
            }
        }
    }
    if_in.close();
    string line;
    ostringstream os1, os2, os3;
    string min, mid, max;
    os1 << b[0];
    min = os1.str();
    os2 << b[(1+n)/2-1];
    mid = os2.str();
    os3 << b[n-1];
    max = os3.str();
    line += min + " " + mid + " " + max;
    ofstream outfile;
    outfile.open("output.txt");
    outfile << line;
    outfile.close();
}