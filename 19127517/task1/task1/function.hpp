//
//  function.hpp
//  19127517
//
//  Created by jsn on 07/06/2022.
//

#ifndef function_hpp
#define function_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#define max 370105
using namespace std;

void read(string filename,vector<string> &a);
void bubble(vector<string>&a);
void writeRandomly(string filename,vector<string>&a, int n);
void sorted(string filename,vector<string>&a);
void reverse(string path, vector<string>&a, int n);
void numberOfSwap(string path, vector<string>&a, int n);

void insertionSort(vector<string>&a, int n);
int binarySearch(vector<string>&a, string item, int low, int high);
#endif /* function_hpp */
