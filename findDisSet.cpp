#include <bits/stdc++.h>

using namespace std;

vector<int> Union(vector<int> a, vector<int> b){
    map<int,int> m;
    int k = a.size();
    for(int i = 0; i<k;++i){
        if(a[i] == 1){
            m[i] = 1;
        }
        if(b[i] == 1){
            m[i] = 1;
        }
    }
    vector<int> ret(k);
    for (auto x : m){
        ret[x.first] = 1;
    }
    return ret;
}

int countOnes(vector<int> a){
    int k = a.size();
    int c = 0;
    for(int i = 0; i<k;++i){
        if(a[i] == 1){
            c+= 1;
        }
    }
    return c;
}

vector<int> Intersection(vector<int> a, vector<int> b){
    map<int,int> m;
    int k = a.size();
    for(int i = 0; i<k;++i){
        if(a[i] == 1 && b[i] == 1){
            m[i] = 1;
        }
    }
    vector<int> ret;
    for (auto x : m){
        ret.push_back(x.first);
    }
    return ret;
}

int main(){
    string filename = "175_72_1_1_72_175";
    ifstream inFile(filename + ".txt");

    string tmp;

    int n;
    inFile>>n;
    getline(inFile,tmp);

    vector<vector<int>> A;
    for(int i = 0; i<n; ++i){
        getline(inFile,tmp);
        vector<int> v;
        for (int  j = 0; j<n; ++j){
            if (tmp[j] == '1'){
                v.push_back(1);
            }
            else{
                v.push_back(0);
            }
        }
        A.push_back(v);
    }
    int mi2 = 100000000;
    for (int x = 0; x<n; ++x){
        for (int y = 0; y<n; ++y){
            if(A[x][y] == 1 && x != y){
                vector<int> un = Union(A[x],A[y]);
                int c = countOnes(un);
                if(c - 2< mi2){
                    mi2 = c-2;
                }
            }
        }
    }
    cout<<mi2<<"\n";

    int mi3 = 100000000;
    for(int x = 0; x<n; ++x){
        for (int y = 0; y<n; ++y){
            for (int z = 0; z<n; ++z){
                map<int,int> tm = {{x,1},{y,1},{z,1}};
                if(tm.size() != 3){
                    continue;
                }
                if(A[x][y] && A[y][z] && A[z][x]){
                    vector<int> un = Union(A[x],Union(A[y],A[z]));
                    int c = countOnes(un);
                    if(c - 3 < mi3){
                        mi3 = c - 3;
                    }
                }
            }
        }
    }
    cout<<mi3<<"\n";

    int mi4 = 100000000;
    for(int x = 0; x<n; ++x){
        for(int y = 0; y<n; ++y){
            for(int z = 0; z<n; ++z){
                for(int w = 0; w<n; ++w){
                    map<int,int> tm = {{x,1},{y,1},{z,1},{w,1}};
                    if(tm.size() != 4 ){
                        continue;
                    }
                    if(A[x][y] && A[y][z] && A[z][x] && A[z][w] && A[x][w] && A[w][y]){
                        vector<int> un = Union(A[x],Union(A[y],Union(A[z],A[w])));
                        int c = countOnes(un);
                        if(c - 4 < mi4){
                            mi4 = c - 4;
                        }
                    }
                }
            }
        }
    }
    cout<<mi4<<"\n";
    return 0;
}