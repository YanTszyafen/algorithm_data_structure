#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int max(int a, int b){
    return (a>b) ? a : b;
}

int min(int a, int b){
    return (a<b) ? a : b;
}

string multiply(string num1, string num2) {
    string res = "";
    int m = num1.size(), n = num2.size();
    vector<int> vals(m + n);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
            vals[p1] += sum / 10;
            vals[p2] = sum % 10;
        }
    }
    for (int val : vals) {
        if (!res.empty() || val != 0) res.push_back(val + '0');
    }
    return res.empty() ? "0" : res;
}

string reversestr(string str){
    int len = str.length();
    for(int i=0; i<=(len-1)/2; i++){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    return str;
}

string bigadd(string num1, string num2){
    num1 = reversestr(num1);
    num2 = reversestr(num2);
    /**cout << "bigadd:" << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;**/
    string res="";
    int m = num1.size(), n = num2.size();
    int maxlen = max(m,n), minlen = min(m,n);
    vector<int> vals(maxlen+1);
    for(int i = 0; i<minlen; i++){
        int sum = (num1[i]-'0') + (num2[i]-'0');
        vals[maxlen-i] += sum % 10;
        vals[maxlen-i-1] += sum / 10;
        /**cout << "vals[" << maxlen-i <<"]: " << vals[maxlen-i] << endl;
        cout << "vals[" << maxlen-i-1 <<"]: " << vals[maxlen-i-1] << endl;**/
    }
    for(int j = minlen; j<maxlen; j++){
        vals[maxlen-j] += (maxlen==m) ? (num1[j]-'0') : (num2[j]-'0');
        //cout << "vals[" << maxlen-j <<"]: " << vals[maxlen-j] << endl;
    }
    for (int val : vals) {
        if (!res.empty() || val != 0) res.push_back(val + '0');
    }
    //cout << "res: " << res << endl;
    return res.empty() ? "0" : res;
}

bool bigcompare(string num1, string num2){
    if(num1.length() == num2.length()){
        for(int i=0; i<num1.length(); i++){
            if(num1[i]!=num2[i]) return num1[i]>num2[i];
        }
    }
    return num1.length()>num2.length();
}

string bigminus(string num1, string num2){
    int flag = false;
    if(!bigcompare(num1,num2)){
        string str = num1;
        num1 = num2;
        num2 = str;
        flag = true;
    }
    num1 = reversestr(num1);
    num2 = reversestr(num2);
    string res="";
    int m = num1.length(), n = num2.length();
    int maxlen = max(m,n);
    vector<int> vals(maxlen);
    for(int i=0; i<min(m,n); i++){
        int dif, carry=0;
        if(((num1[i]-'0')+vals[maxlen-i-1]) < (num2[i]-'0')){
            dif = (num1[i]-'0')+10-(num2[i] - '0');
            carry = 1;
        }
        else{
            dif = (num1[i] - '0') - (num2[i] - '0');
        }
        vals[maxlen-i-1] += dif;
        vals[maxlen-i-2] -= carry;
    }
    for(int j=min(m,n); j<maxlen; j++){
        if((vals[maxlen-j-1]+(num1[j]-'0'))<0){
            vals[maxlen-j-1] += (num1[j]-'0')+10;
            vals[maxlen-j-2] -= 1;
        } else vals[maxlen-j-1] += (num1[j] - '0');
    }
    for(int val:vals){
        if(!res.empty() || val != 0) res.push_back(val+'0');
    }
    if(flag && !res.empty()) res.insert(0,"-");
    return res.empty() ? "0" : res;
}

int main(){
    string a, b, mul, sum;
    ifstream if_in;
    if_in.open("input.txt");
    if_in >> a;
    if_in >> b;
    bool flag = false;
    if(a[0]=='-'){
        a=a.substr(1,a.length()-1);
        flag = true;
    }
    if(b[0]=='-') b=b.substr(1,b.length()-1);
    mul = multiply(b, b);
    //cout << "product: " << mul << endl;
    //cout << "a: " << a << endl;
    if(flag) sum=bigminus(mul,a);
    else sum = bigadd(mul, a);
    if_in.close();
    ofstream outfile;
    outfile.open("output.txt");
    outfile << sum;
    outfile.close();
    return 0;
}
