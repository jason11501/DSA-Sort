#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "Queue.h"
#define LETTER 26
#define ALGO_AMOUNT 6
using namespace std;

string sorting[]{ "Bubble sort", "Selection sort", "Insertion sort", "Merge sort", "Quick sort", "Radix sort" };
string searching[]{ "LS", "BS" };

struct Array
{
	string* arr;
	int size;

	Array()
	{
		arr = nullptr;
		size = 0;
	}

	Array(int newSize)
	{
		size = newSize;
		arr = new string[size];
	}

	string& operator[](const int& index)
	{
		return arr[index];
	}
	~Array()
	{
		if (arr)
			delete[] arr;
	}
};

void swap(string& firstWord, string& secondWord)
{
	string temp = firstWord;
	firstWord = secondWord;
	secondWord = temp;
}

void bubble(Array& arr)
{
	for (int i = 0; i < arr.size - 1; i++)
	{
		for (int j = arr.size - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

int getMin(const Array& a, const int& start)
{
	int min = start;
	for (int i = start + 1; i < a.size; i++)
	{
		if (a.arr[i] < a.arr[min])
			min = i;
	}

	return min;
}

void selection(Array& a)
{
	int min;
	for (int i = 0; i < a.size - 1; i++)
	{
		min = getMin(a, i);
		if (min != i)
			swap(a[i], a[min]);
	}
}

void insertion(Array& arr)
{
	int j;
	string temp;
	for (int i = 1; i < arr.size; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (i != j + 1)
			arr[j + 1] = temp;
	}
}

void Merge(Array& a, const int& start, const int& mid, const int& end)
{
	Array left(mid - start + 1);
	Array right(end - mid);
	for (int i = 0; i < left.size; i++)
		left[i] = a[start + i];
	for (int i = 0; i < right.size; i++)
		right[i] = a[start + i + left.size];

	int indexL = 0, indexR = 0, index = start;
	while (indexL < left.size && indexR < right.size)
	{
		if (left[indexL] < right[indexR])
			a[index] = left[indexL++];
		else
			a[index] = right[indexR++];
		index++;
	}

	//Left still remains
	while (indexL < left.size)
		a[index++] = left[indexL++];

	//Right still remains
	while (indexR < right.size)
		a[index++] = right[indexR++];
}

void merge(Array& a, const int& start, const int& end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
        //chia đôi mảng
		merge(a, start, mid);
		merge(a, mid + 1, end);
		Merge(a, start, mid, end);// nhập các sub array đã tách theo thứ tự
	}
}

void MergeSort(Array& a)
{
	merge(a, 0, a.size - 1);
}

int partition(Array& arr, const int& start, const int& end)
{
	int mid = (end + start) / 2;
	string pivot = arr[mid];

	swap(arr[mid], arr[start]);

	int last = start + 1;

	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] < pivot)
			swap(arr[last++], arr[i]);
	}

	swap(arr[start], arr[last - 1]);

	return last - 1;
}

void quick(Array& arr, const int& start, const int& end)
{
	if (start < end)
	{
		int pivot = partition(arr, start, end);
		quick(arr, start, pivot - 1);
		quick(arr, pivot + 1, end);
	}
}

void quick(Array& arr)
{
	quick(arr, 0, arr.size - 1);
}

string getMax(Array& a)
{
	int max = 0;
	for (int i = 1; i < a.size; i++)
	{
		if (a[i] > a[max])
			max = i;
	}
	return a[max];
}

void radix(Array& arr)
{
	int maxLetter = getMax(arr).length();
	Queue q[LETTER + 1]; //+1 for words not enough letters
	int i, indexOfQueue;
	char temp;
	for (int unitDigit = maxLetter - 1; unitDigit >= 0; unitDigit--)
	{
		for (i = 0; i < arr.size; i++)
		{
			if (unitDigit < arr[i].length())
				temp = tolower(arr[i][unitDigit]) - 'a'; //Get index from 0
			else
				temp = LETTER; //Not enough character => the char < 'z'
			q[temp].enqueue(arr[i]); 
		}

		for (i = 0, indexOfQueue = 0; indexOfQueue <= LETTER && i < arr.size; indexOfQueue++)
		{
			while (!q[indexOfQueue].isEmpty())
				arr[i++] = q[indexOfQueue].dequeue();
		}
	}
}

int binarySearch(Array& a, string checking)
{
    int i=0, l=i, r=a.size-1;
    while(l<r){
        int mid=(l+r)/2;
        if(checking<a[mid]) r=mid-1;
        else if (checking>a[mid]) l=mid+1;
        else return i;
        i++;
    }return-1;
}

int linearSearch(Array& a, string checking)
{
    int i=1;
    checking=a[a.size];
    while(a[i].compare(checking)!=0){
        i++;
        if (a[i].compare(checking)==0) return 1;
        if (i==a.size) return 0;
    }
    return 0;
}

int getSizeWhileReadingFile(string fileName)
{
	ifstream inStream(fileName);
	string temp;
	int size = 0;
	while (inStream >> temp)
		size++;
	inStream.close();
	return size;
}

int CountSortingAndSearchingTime(Array& arr, int fileSize, string algo, string searchInput)
{
	void(*sort)(Array&) = nullptr;
	if (algo == sorting[0])
		sort = bubble;
	else if (algo == sorting[1])
		sort = selection;
	else if (algo == sorting[2])
		sort = insertion;
	else if (algo == sorting[3])
		sort = MergeSort;
	else if (algo == sorting[4])
		sort = quick;
	else if (algo == sorting[5])
		sort = radix;
    
    int(*search)(Array&, string) = nullptr;
    if (searchInput == searching[0])
        search = linearSearch;
    else if (searchInput == searching[1])
        search = binarySearch;
        
	clock_t start, end;
	start = clock();
	if (sort)
		sort(arr);
    if (search){
        for(int i=0;i<fileSize;i++){
            search(arr, arr[i]);
        }
    }
    end = clock();
	return (double(end - start) * 1000) / double(CLOCKS_PER_SEC);
}

bool ValidNameFile(const string& file)
{
	return file == "/Users/jason/Downloads/19127517/task2/task2/a.txt" || file == "/Users/jason/Downloads/19127517/task2/task2/task2/b.txt" || file == "/Users/jason/Downloads/19127517/task2/task2/task2/c.txt" || file == "/Users/jason/Downloads/19127517/task2/task2/d.txt" || file == "/Users/jason/Downloads/19127517/task4/task4/100.txt" || file == "/Users/jason/Downloads/19127517/task4/task4/1k.txt" || file == "/Users/jason/Downloads/19127517/task4/task4/10k.txt" || file == "/Users/jason/Downloads/19127517/task4/task4/50k.txt";
    
}

bool ValidAlgo(const string& algo)
{
	for (int i = 0; i < ALGO_AMOUNT; i++)
		if (sorting[i] == algo)
			return true;
	return false;
}

bool ValidSearch(const string& search)
{
    return search == "LS" || search == "BS";
}

bool ValidFileSize(const string& fileSize)
{
    return fileSize == "100" || fileSize == "1000" || fileSize == "10000" || fileSize == "50000";
}

void Input()
{
	string file;
	string alg;
    string search;
    string fileSize;
	bool valid;
	//Get and validate input
	do
	{
		cout << "Input file name: ";
		getline(cin, file);
		valid = ValidNameFile(file);
		if (!valid)
			cout << "Not a valid file. Please input again\n";
	} while (!valid);

	do
	{
		cout << "Input the algorithm: ";
		getline(cin, alg);
		valid = ValidAlgo(alg);
		if (!valid)
			cout << "Not a valid algorithm. Please input again\n";
	} while (!valid);
    
    do
    {
        cout << "Input the search: ";
        getline(cin, search);
        valid = ValidSearch(search);
        if (!valid)
            cout << "Not a valid search. Please input again\n";
    } while (!valid);

    do
    {
        cout << "Input the fileSize: ";
        getline(cin, fileSize);
        valid = ValidFileSize(fileSize);
        if (!valid)
            cout << "Not a valid search. Please input again\n";
    } while (!valid);

	//Get from file
	int size = getSizeWhileReadingFile(file);
	Array arr(size);
	ifstream in(file);
	if (in)
	{
		for (size_t i = 0; i < size; i++)
			in >> arr[i];
	}
	in.close();
    int numSize = stoi(fileSize);
	//Count time
	int time = CountSortingAndSearchingTime(arr, numSize, alg, search);
	cout << "Algorithm: " << alg << '\n'
		<< "The array: " << file[0] << '\n'
		<< "Execution time: " << time << '\n'
		<< "ID: 19127517" << '\n';
}

ostream& operator<<(ostream& dev, Array& a)
{
	for (int i = 0; i < a.size; i++)
		dev << a[i] << '\n';
	return dev;
}

int main()
{
	Input();
	return 0;
}
