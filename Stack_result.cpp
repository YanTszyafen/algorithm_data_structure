#include <iostream>
#include <fstream>
#include <sstream>

const int maxsize=1000000;

using namespace std;

class Stack{
public:
    Stack(){
        a=new int[maxsize];
        top=0;
    }
    ~Stack(){}
    void Push(int e);
    int Pop();
    bool isEmpty();
    bool isFull();

private:
    int *a;
    int top;
};

void Stack::Push(int e) {
    if(!isFull()) a[top++] = e;
}

int Stack::Pop() {
    if(!isEmpty()){
        int e;
        e = a[top-1];
        top--;
        return e;
    }
    return 0;
}

bool Stack::isEmpty() {
    return (top==0);
}

bool Stack::isFull() {
    return (top>=maxsize);
}

bool strIsDigit(string str){
    return (str.at(0) >= '0' && str.at(0)<= '9');
}

int main() {
    ifstream if_in;
    if_in.open("input.txt");
    int n;
    if_in >> n;
    Stack stack;
    for(int i=0; i<n; i++){
        string str;
        if_in >> str;
        if(strIsDigit(str)){
            stringstream st;
            st << str;
            int number;
            st >> number;
            stack.Push(number);
        }
        else {
            int a, b, sum;
            b = stack.Pop();
            a = stack.Pop();
            if(str == "+"){
                sum = a+b;
            }else if(str == "-"){
                sum = a-b;
            } else if(str == "*"){
                sum = a*b;
            }else sum = a/b;
            stack.Push(sum);
        }
    }
    ofstream outfile;
    outfile.open("output.txt");
    outfile << stack.Pop();
    return 0;
}