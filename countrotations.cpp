#include <iostream>
using namespace std;

int *OriginalArray (int &size){

    int *arr=new int [size];
    for (int i=0;i<size;i++){
        cout<<"Enter element of array= "<<endl;
        cin>>arr[i];
    }
    return arr;
}

int *SortingArray(int arr[], int &size){
    int temp=0;
    for (int i=0;i<size-1;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}

void CountRotation(int arr[],int arr2[], int size){
    int numrot=0;
    int count=0;
    
        for (int j=0;j<size;j++){
            if (arr[0]==arr2[j]){
                numrot=j;
            }
        }
    
    for (int i=0;i<size-numrot;i++){
        if (arr[i]!=arr2[i+numrot]){
            count++;
            break;
        }
    }
    if (count!=0){
        cout<<"Arrays not equal. "<<endl;
    }
    else {
        cout<<"Arrays have been rotated "<<numrot<<" times."<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter size of array= "<<endl;
    cin>>size;
    int *arr=OriginalArray(size);
    arr=SortingArray(arr,size);
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Enter Rotated Array= "<<endl;
    int *arr2=OriginalArray(size);
    for (int i=0;i<size;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    
    CountRotation(arr, arr2, size);
    
    cout<<endl;
}
