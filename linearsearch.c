#include<stdio.h>

int linearsearch(int*arr,int n,int key){
	for(int i=0; i<n; i++){
		if(arr[i]==key)
		return i;
		
	}
	return -1;
}
int main(){
	int arr[]={10,20,30,70,80,20,90,40};
	int n=Size of(arr)/sizeof(arr[0]);
	int key;
	
printf("Enter the key element:");
scanf("%d",&key);
int i=linearsearch(arr,n,key);
if (i==1)
     printf("Key Not Found");
else
     printf("Key Founf at Indes:%d"i);
return 0;     
}

