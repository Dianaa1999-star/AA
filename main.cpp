#include <fstream>
#include <vector>
#include<iostream>
#include "algo.h"
using namespace std;

int main(int argc, const char *argv[]) {

    int x;
    int y;
    ifstream f;
    ofstream g;
    f.open(argv[1]);
    g.open(argv[2]);
    f >> x >> y;
    vector<int> vect;
    vector<pair<int, int>> queries;
    int value;
    int i = 0;
    while(i < x) {
        f >> value;
        vect.push_back(value);
        i++;
    }
    int left, right;
    int j = 0;
    while(j< y) {
        f >> left >> right;
        queries.push_back(make_pair(left, right));
        j++;
    }
    vector<int> result = rmq(vect, queries);
    for (auto it = result.begin(); it != result.end(); ++it){
         g << (*it);
         g << "\n";
    }
    
    f.close();
    g.close();
}