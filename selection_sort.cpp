#include <iostream>
#include<vector>
using namespace std;

void selection(vector<int>&a,int n){
    for(int i=0;i<n;i++){
        int temp=i;
        for(int j=i+1;j<n;j++){
            if(a[temp]>a[j])
                temp=j;
        }
        swap(a[temp],a[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}
