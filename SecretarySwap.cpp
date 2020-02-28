#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n;
    int *a = new int [n];
    ifstream if_in;
    if_in.open("input.txt");
    if_in >> n;
    for(int i=0; i<n; i++){
        if_in >> a[i];
    }
    if_in.close();
    ofstream outfile;
    outfile.open("output.txt");
    int max, max_i, temp;
    bool flag;
    for(int i=n-1; i>0; i--){
        max = a[i];
        max_i = i;
        flag = false;
        for(int j=i-1; j>=0; j--){
            if(a[j] > max){
                max = a[j];
                max_i = j;
                flag = true;
            }
        }
        if(flag){
            temp = a[i];
            a[i] = max;
            a[max_i] = temp;
            outfile << "Swap elements at indices " << max_i+1 << " and " << i+1 << ".\n";
        }
    }
    outfile << "No more swaps needed." << "\n";
    for(int i=0; i<n; i++){
        outfile << a[i] << " ";
    }
    outfile.close();
}