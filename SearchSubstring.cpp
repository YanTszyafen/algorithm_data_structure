#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream if_in;
    if_in.open("input.txt");
    string p, t;
    if_in >> p;
    if_in >> t;
    cout << p << endl;
    cout << t << endl;
    int m = p.length();
    int n = t.length();
    ofstream outfile;
    outfile.open("output.txt");
    if(m > n) outfile << 0;
    else{
        int result[10000];
        int temp = 0;
        for(int i=0; i<=n-m; i++){
            bool ok = true;
            for(int j=0; j<m; j++){
                if(t[i+j] != p[j]){
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result[temp] = i+1;
                temp++;
            }
        }
        outfile << temp << endl;
        for(int a=0; a<temp; a++){
            outfile << result[a] << " ";
        }
    }
    return 0;
}