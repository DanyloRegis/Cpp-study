#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n);

int main(){
    
    int array[]={10,3,4,1,5,9,2,6,8,7};

    int size=sizeof(array)/sizeof(array[0]);

    for(int element:array){
        cout<<element<<" ";
    }
    cout<<endl;
    bubbleSort(array,size);
    for(int element:array){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}