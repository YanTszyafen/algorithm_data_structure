#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;

void merge(int a[], int start, int end, int mid){
    int left_index = start;
    int right_index = mid+1;
    int temp[100000];
    for(int i=0; i<end-start+1; i++){
        if((right_index>end || (left_index<=mid && (a[left_index]<a[right_index])))){
            temp[i] = a[left_index];
            left_index++;
        }
        else{
            temp[i] = a[right_index];
            right_index++;
        }
    }
    for(int i=0; i<end-start+1; i++){
        a[start+i] = temp[i];
    }
    outfile << start+1 << " " << end+1 << " " << a[start] << " " << a[end] << endl;
}

void merge_sort(int a[], int start, int end){
    if(start>=end){
        return;
    }
    if(end - start == 1){
        if(a[start] > a[end]){
            swap(a[start], a[end]);
        }
        outfile << start+1 << " " << end+1 << " "<< a[start] << " " << a[end] << endl;
        return;
    }
    else{
        int mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,end,mid);
    }
}

int main() {
    ifstream if_in;
    if_in.open("input.txt");
    int n;
    if_in >> n;
    int a[100000];
    for(int i=0; i<n; i++){
        if_in >> a[i];
    }
    outfile.open("output.txt");
    merge_sort(a,0,n-1);
    for(int i=0; i<n; i++){
        outfile << a[i] << " ";
    }
    outfile.close();
    return 0;
}