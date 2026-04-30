#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    int secondmax=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            secondmax=max;
            max=arr[i];
        }
        else if(arr[i]>secondmax && arr[i]!=max){
            secondmax=arr[i];
        }
    }
    cout<<secondmax;

}