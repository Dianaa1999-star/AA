#include <bits/stdc++.h>

using namespace std;



void Compute(int N, vector<int> v, vector<vector<int>> &SparseTable) {
    int j = 1;
    while((1 << j) <= N){
        int i = 0;
        int aux;
        while(i + (1 << j) - 1 < N) {
            if (v[SparseTable[i][j - 1]] > v[SparseTable[i + (1 << (j - 1))][j - 1]]) {
                aux = SparseTable[i + (1 << (j - 1))][j - 1];
                SparseTable[i][j] = aux;
            } else {
                SparseTable[i][j] = SparseTable[i][j - 1];
               
            }
            i++;
        }
        j++;
    }
}


int main(int argc, const char *argv[])
{
    ifstream f;
    ofstream g;
    f.open(argv[1]);
    g.open(argv[2]);

    int N;
    int M;
    f >> N >> M;

    vector<vector<int>> SparseTable;

    int value;
    vector<int> logaritm, v;

    logaritm.push_back(-1);
    int p  = 1;
    while(p <= N) {
        logaritm.push_back(logaritm[p / 2] + 1);
        p++;
    }
    SparseTable.assign(N, vector<int>(logaritm[N] + 1));
    int i = 0;
    while(i < N) {
        f >> value;
        v.push_back(value);
        SparseTable[i][0] = i;
        i++;
    }
    Compute(N, v, SparseTable);
    int left;
    int right;
    int j = 0;
    while(j< M) {
        f >> left >> right;

        int lg = logaritm[right - left + 1];
        int solution;
        if (v[SparseTable[left][lg]] < v[SparseTable[right - (1 << lg) + 1][lg]])
            {
                solution = v[SparseTable[left][lg]];
            }
        else {
            solution =  v[SparseTable[right - (1 << lg) + 1][lg]];
        }

        g << solution << "\n";
        j++;
    }


    f.close();
    g.close();
    return 0;
}