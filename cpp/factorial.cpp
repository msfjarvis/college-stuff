#include<bits/stdc++.h>
#define ll long long int

using namespace std;

//recursive program to calculate factorial of a given number

ll fact(ll n){
    return(n==1 || n==0) ? 1 : n*fact(n-1);
}

int main(){
    ll n;
    cin>>n;
    cout<<fact(n);
    return 0;
}
