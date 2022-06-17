//
//  main.cpp
//  task4
//
//  Created by jason on 08/06/2022.
//

#include "function.h"
void readFile(string path,string* arr, int n){
    ifstream in(path,ios::in);

    if(!in.is_open()) cout<<"file does not exist";

    int i=0;

    while(!in.eof()){
        getline(in,arr[i]);
        //arr[i] = word;
        i++;
        if (i==n) break;
    }
    in.close();
}
void outFile(string path,string* arrFile, int n){
    ofstream out;
    out.open(path,ios::out);
    
    if(!out.is_open()) cout<<"file does not exist";
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        out << arrFile[rand() % MAX] << endl;
    }out.close();
}
int main() {
    string *arr = new string[MAX];
    readFile("/Users/jason/Downloads/task1/task1/englishword.txt", arr, MAX);
//    for (int i = 0; i < 102; i++){
//        cout << arr[i] << endl;
//    }
    //100 txt
    //string *a = new string[100];
    outFile("/Users/jason/Downloads/task4/task4/100.txt",arr,100);
//
//    //1k txt
//    string *b = new string[1000];
    outFile("/Users/jason/Downloads/task4/task4/1k.txt",arr,1000);
//
//    //10k txt
//    string *c = new string[10000];
    outFile("/Users/jason/Downloads/task4/task4/10k.txt",arr,10000);
//
//    //50k txt
//    string *d = new string[50000];
    outFile("/Users/jason/Downloads/task4/task4/50k.txt",arr,50000);
    delete []arr;
    //delete []a;
//    delete []b;
//    delete []c;
//    delete []d;
    return 0;
}
