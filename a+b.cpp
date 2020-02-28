#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int a, b, sum;
    ifstream if_in;
    if_in.open("input.txt");
    if_in >> a;
    if_in >> b;
    if_in.close();
    sum = a+b;
    ofstream outfile;
    outfile.open("output.txt");
    outfile << sum;
    outfile.close();
    return 0;
}