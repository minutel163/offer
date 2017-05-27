#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
using namespace std;

class Sort{
public:
	Sort(){}
    void outputArray(int arr[]){
		cout<<"start output"<<endl;
		int size1 = sizeof(arr);
		int size2 = sizeof(arr[0]);
		cout<<"size1"<<size1<<endl;
		cout<<"size2"<<size2<<endl;
    	int len = sizeof(arr)/sizeof(arr[0]);
		cout<<"len"<<len<<endl;
    	for(int i = 0;i<len;i++){
    		cout<< i<<" : "<<arr[i]<<endl;
    	}
    }
};
int main(){
	Sort so;
	int len = 10;
	int arr[len];
	cout<<"start"<<endl;
	for(int i = 0; i < 10 ; i++){
		arr[i] = rand();
		cout<<arr[i]<<endl;
	}
	cout<<"middle"<<endl;
	so.outputArray(arr);
	return 0;
}
