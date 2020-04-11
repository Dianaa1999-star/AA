#include "algo.h"
#include <vector>
#include <stack>

#define MaxValue  2147483647

using namespace std;


int getMid(int s, int e) { return s + (e - s)/2; }

void Context (vector<int> &Segments, int position, int value, int node, int left, int right) {
    
    int aux ;
    if(left == right){
        aux = value;
        Segments[node] = aux;
        return;
    }
    int m = getMid(left,right);
    if(position > m) {
        Context(Segments, position, value, 2 * node + 1, m + 1, right);
        
    }
    else {
        Context(Segments, position, value, 2 * node, left, m);
    }

    if(Segments[2 * node] < Segments[2 * node + 1]){
        Segments[node] = Segments[2 * node];
    }
    else{
    Segments[node] = Segments[2 * node + 1];
    }
}
int verify(int start,int right,int end,int left){
if(start <= left && right <= end)
    return 1;
else 
    return 0;
}
void Find ( int start, int end,vector<int> &Segments,int node, int left, int right,int &Minimum) {
    int ok = verify(start,right,end,left);
    if(ok)
    {
        if(Segments[node] < Minimum) {
            Minimum = Segments[node];
        }
        return;
    }
    int m = getMid(left,right);
    if(m < end) {
        Find( start, end,Segments, 2 * node + 1, m + 1, right, Minimum);
    }
    if(start <= m) {
        Find(start, end, Segments, 2 * node, left, m,Minimum);
    }
}

std::vector<int> rmq(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries) {

    int  N = input.size();
    int  M = queries.size();
    vector <int> v = input;
    vector<int> result;
    vector<int> Segments;
  
    int i = 1;
    Segments.reserve(4 * N);
    while(i <= N){
        Context(Segments, i, input[i] , 1, 1, N);
        i++;
    }
    int Minimum;
    int j = 0;
    while(j < M) {
       bool type = false;
        if(type == false) {
            Minimum = MaxValue;
            Find( queries[j].first , queries[j].second ,Segments, 1, 1, N,Minimum);
           result.push_back(Minimum);
        }
        j++;
    }

    return result;
}

