#include<iostream>
using namespace std;

template<class T>
void swap(T *a,int index1,int index2)
{
	T temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
}

template<class T>
void bubbleSort(T *a,int size)
{
	for(int j=0;j<size;j++)
	{
		for(int i=0;i<size-1-j;i++)
		{
			if(a[i] > a[i+1])
			{
				swap(a,i+1,i);
			}
			printArray(a,size);
		}
	}	
}

template<class T>
void selectionSort(T *a,int size)
{
	for(int j=0;j<size;j++)
	{
	int big = a[0];
	int bigindex = 0;
		for(int i=0;i<size-1-j;i++)
		{
			if(a[i+1]>a[i])
			{
				big = a[i+1];
				bigindex = i+1;
			}
		}
		swap(a,size-1-j,bigindex);
	printArray(a,size);
	}
}

template<class T>
void printArray(T *a, int start, int end)
{
	for(int i = start;i<=end;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
void insertionSort(T *a,int size)
{
	for(int i=0;i<size-1;i++)
	{
		int j = i;
		while(a[j]>a[j+1] && j>=0)
		{
			swap(a,j+1,j);
			j--;
		}
		printArray(a,size);
	}
}

template<class T>
void merge(T *a, int left, int endleft, int right, int endright)
{
	int templeft = left;
	cout << "Merge" << endl;
	printArray(a,left,endleft);
	printArray(a,right,endright);
	int c[10];
	int numc = 0;
	while(left <= endleft && right <= endright)
	{
		if(a[left]<=a[right])
		{
			c[numc] = a[left];
			left++;
		}
		else
		{
			c[numc] = a[right];
			right++;
		}
		numc++;
	}
	if(left<=endleft)
	{
		while(left<=endleft)
		{
			c[numc] = a[left];
			numc++;
			left++;
		}
	}
	if(right<=endright)
	{
		while(right<=endright)
		{
			c[numc] = a[right];
			numc++;
			right++;
		}
	}
	int j = 0;
	for(int i = templeft; i<=endright; i++)
	{
		a[i] = c[j];
		j++;
	}
	printArray(a,left,endright);
	cout << "------------------------"<< endl;
}

template<class T>
void mergeSort(T *a, int left, int right)
{
	if(left<right)
	{
		int center = (left+right)/2;
		mergeSort(a,left,center);
		mergeSort(a, center+1, right);
		merge(a, left, center, center+1, right);
	}
}

template<class T>
void split(T *arr, int &pointpivot, int first_index, int last_index)
{
	int pivot = arr[first_index-1];
	int pivot_index = first_index-1;
	while(first_index<=last_index)
	{
		while(arr[first_index] < pivot)
		{
			first_index++;
		}
		while(pivot < arr[last_index])
		{
			last_index--;
		}
		if(first_index<last_index)
		{
			swap(arr,first_index,last_index);
			printArray(arr,0 ,9);
		}
	}
	if(pivot > arr[last_index])
	{
		swap(arr, pivot_index, last_index);
	}
	pointpivot = last_index;
	cout << endl;
	printArray(arr,0 ,9);
	cout << endl;
}
template<class T>
void Quicksort(T *arr, int first_index, int last_index)
{
	int pointpivot = 0;
	if(first_index<last_index)
	{
		split(arr,pointpivot ,first_index+1, last_index);
		Quicksort(arr, first_index, pointpivot-1);
		Quicksort(arr, pointpivot+1, last_index);
	}
	
}

int main()
{
	const int size = 10;
	int a[size] = {5,4,2,10,3,6,9,8,7,1};

	/*cout << "Bubble Sort  "<< endl;
	bubbleSort(a,size);*/

	/*cout << "Selection sort" << endl;
	selectionSort(a,size);*/

	/*cout << "Insertion Sort" << endl;
	insertionSort(a,size);*/

	//cout << "Merge Sort" << endl;
	//mergeSort(a,0,size-1);

	/*cout << "Quick Sort" << endl;
	Quicksort(a, 0, size-1);*/
	
	printArray(a,0,size-1);
	return 0;
}