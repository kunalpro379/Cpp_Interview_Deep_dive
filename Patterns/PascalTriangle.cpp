#include <iostream>
using namespace std;
#include<vector>
int BinomialCoeff(int n, int r){
    if(r==0||r==n)return 1;
    return BinomialCoeff(n-1,r-1)+BinomialCoeff(n-1,r);
}
void print(int rows){
    for(int i=0;i<rows;i++){
        for(int space=0;space<rows-i-1;space++){
            cout<<"  ";
        }
        for (int r = 0; r <= i; r++) {
            cout << BinomialCoeff(i, r) << "   ";
        }
        cout << endl;
    }
}
//mamorization and DP
vector<vector<int>> mamo;
int BinomialCoeffmamo(int n, int r){
    if(r==0||r==n)return 1;
    if(mamo[n][r]!=-1)return mamo[n][r];
    mamo[n][r]= BinomialCoeffmamo(n-1,r-1)+BinomialCoeffmamo(n-1,r);
    return mamo[n][r];
}
void printmamo(int rows){
    mamo.resize(rows, vector<int>(rows,-1));
    for(int i=0;i<rows;i++){
        for(int space=0;space<rows-i-1;space++){
            cout<<"  ";
        }
        for (int r = 0; r <= i; r++) {
            cout << BinomialCoeffmamo(i, r) << "   ";
        }
        cout<<endl<<endl;
    }
}
void printDP(int rows){
    //create a DP table
    vector<vector<int>>DP(rows, vector<int>(rows,0));
    for(int n=0;n<rows;n++){
        
    }
}
int main(){
    print(32);
    cout<<endl;
    printmamo(32);
    printDP(32);

}
