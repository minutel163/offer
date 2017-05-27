#include <iostream>
using namespace std;

class Sort{
public:
	Sort(){}
    void outputArray(int arr[]){
    	int len = sizeof(arr)/sizeof(arr[0]);
    	for(int i = 0;i<len;i++){
    		cout<< i<<" : "<<arr[i]<<endl;
    	}
    }
};
int main(){
	Sort so = new Sort;
	int len = 10;
	int arr[len];
	for(int i = 0; i < 10 ; i++){
		arr[i] = rand();
	}
	so.outputArray(arr);
	return 0;
}
