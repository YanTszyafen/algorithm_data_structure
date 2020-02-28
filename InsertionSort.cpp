#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    int n;
    string temp;
    ifstream if_in;
    if_in.open("input.txt");
    if_in >> n;
    string a[1000], b[1000];
    b[0] = "1";
    for(int i=0; i<n; i++){
        if_in >> a[i];
        if(i>=1){
            istringstream is(a[i]), is_(a[i-1]);
            int c, d;
            is >> c;
            is_ >> d;
            ostringstream os;
            if(c < d){
                for(int j=i; j>=0; j--){
                    if(j == 0){
                        b[i] = "1";
                        break;
                    }else{
                        istringstream is2(a[j]), is2_(a[j-1]);
                        int c_, d_;
                        is2 >> c_;
                        is2_ >> d_;
                        if(c_ < d_){
                            temp = a[j];
                            a[j] = a[j-1];
                            a[j-1] = temp;
                        }else{
                            os << j+1;
                            b[i] = os.str();
                            break;
                        }
                    }
                }
            }else{
                os << i+1;
                b[i] = os.str();
            }
        }
    }
    if_in.close();
    ofstream outfile;
    outfile.open("output.txt");
    string line1="", line2="";
    for(int i=0; i<n; i++){
        line1 += b[i] + " ";
        line2 += a[i] + " ";
    }
    line1.pop_back();
    line2.pop_back();
    outfile << line1 << '\n' << line2;
    outfile.close();
    return 0;
}
