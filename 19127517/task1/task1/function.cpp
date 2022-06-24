//
//  function.cpp
//  19127517
//
//  Created by jsn on 19/06/2021.
//

#include "function.hpp"
//TASK 1
void read(string filename,vector<string> &a)
{
    ifstream in(filename,ios::in);

    if (!in.is_open())
        cout << " FILE DOES NOT EXSIST!" << endl;
    string name;
    while(!in.eof()){
        getline(in,name,'\n');
        a.push_back(name);

        
        if(in.eof()) break;
    }
    in.close();
}
void bubble(vector<string>&a){
    for (int i=0; i<max-1; i++) {
        for (int j=max-1; j>=i+1; j--) {
            if (a[j-1]>a[j]) {
                std::swap(a[j-1], a[j]);
            }
        }
    }
}
int binarySearch(vector<string>&a, string item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ?
                (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}
// Function to sort an array a[] of size 'n'
void insertionSort(vector<string>&a, int n)
{
    int i, loc, j;
    string selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
void writeRandomly(string filename,vector<string>&a, int n){
    ofstream out(filename,ios::out);
    
    if (!out.is_open())
        cout << " FILE DOES NOT EXSIST!" << endl;

    for (int i = 0; i < n; i++)
    {
        out<<a[rand()%n]<<endl;
    }
    out.close();
}
void sorted(string filename,vector<string>&a){
    ofstream out(filename,ios::out);
    
    if (!out.is_open())
        cout << " FILE DOES NOT EXSIST!" << endl;

    //bubble(a);
    insertionSort(a, max);
    
    for (int i = 0; i < max; i++)
    {
        out<<a[i]<<endl;
    }
    out.close();
}
void reverse(string path, vector<string>&a, int n){
    ofstream out(path,ios::out);
    
    if (!out.is_open())
        cout << " FILE DOES NOT EXSIST!" << endl;
    
//    for (int i=0; i<=max-2; i++) {
//        for (int j=max-1; j>=i+1; j--) {
//            if (a[j-1]<a[j]) {
//                std::swap(a[j-1], a[j]);
//            }
//        }
//    }
    insertionSort(a, n);
    
    for(int i=0;i<n/2;i++){
        swap(a[i], a[n-i-2]);
    }
    for (int i=0; i<n; i++) {
        out<<a[i]<<endl;
    }
    out.close();
}
void numberOfSwap(string path, vector<string>&a, int n){
    int num=0;//max*0.1;
    ofstream out(path,ios::out);
    
    if (!out.is_open())
        cout << " FILE DOES NOT EXSIST!" << endl;
    

//        for(int i=0;i<=max-2;i++){
//            for(int j=i+1;j<max;j++){
//                if(a[i]>a[j]){
//                    swap(a[i],a[j]);
//                    num--;
//                    
//                    
//                }
//            }
//        }
    int i, loc, j;
    string selected;
 
    for (i = 1; i < n-n*0.1; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
    for(int i=0;i<max;i++)
        out<<a[i]<<endl;
    out.close();
}

//TASK 2
