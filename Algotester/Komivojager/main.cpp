/*
#include <iostream>
#include <vector>
using namespace std;
const int vsize = 8;

vector<int> getnext(int weights[vsize], int visited[vsize])   //vector of possible ways from here
{
    int i = 0, min = 10000, a=-1;
    vector<int> res;
    for (i = 0; i < vsize; i++)
        if ((weights[i] < min) && (visited[i] == 0))
        {
            min = weights[i];
            a = i;
        }
    for (i = 0; i < vsize; i++)
        if ((weights[i] == min) && (visited[i] == 0))
        {
            res.push_back(i);
        }

    return res;
}
vector<vector<int>>  getpath( int *weights1, int visited[vsize], vector<int> curpath)
{
    vector< vector<int>>res, ans;
    vector<int> vars;
    int cur,i,j;
    int weights[vsize][vsize];

    for (i = 0; i < vsize; i++)
        for (j = 0; j < vsize; j++)
            weights[i][j] = *(weights1+vsize*i+j);

    cur = curpath[curpath.size() - 1];
    if (curpath.size() == 8)
    {
        // curpath.push_back(curpath[0]);
        res.push_back(curpath);

    }
    else
    {
        vars = getnext(weights[cur], visited);

        cout << endl << "\tCurrent path is:";
        for (auto y : curpath) cout << y << "  ";
        cout << endl << "possible ways: ";
        for (auto y : vars) cout << y << "  ";
        cout << endl;


        for (i = 0; i < vars.size(); i++)
        {
            visited[vars[i]] = 1;
            curpath.push_back(vars[i]);
            ans = getpath(&weights[0][0], visited, curpath);

            curpath.pop_back();

            visited[vars[i]] = 0;

            for (int j = 0; j < ans.size(); j++)
                res.push_back(ans[j]);
        }
    }
    // cout << endl << endl << endl << "TEMP RESULT: " << res.size() << endl << endl << endl;
    return res;
}
int main()
{


    int weights[vsize]{ 1000 };
    int visited[vsize]{ 0 };
    int links[vsize]{ 0 };
    int mtr1[vsize][vsize]{ 0 };
    vector<int>res, curpath;
    vector<vector <int>> res1, ans;
    int vn, en, i, k, a1, a2, w, start, target;
    int turn;
    // cout << "Enter number of vertices:\n";
    //cin >> vn;
    vn = vsize;

    for (k = 0; k < vn; k++)
        for (i = 0; i < vn; i++)
        {
            cin >> w;
            mtr1[k][i] = w;
            if (k == i) mtr1[k][i] = 10000;
        }



    for (k = 0; k < vsize; k++)
    {
        for (int j = 0; j < vsize; j++) visited[j] = 0;
        visited[k] = 1;
        curpath.clear();
        curpath.push_back(k);
        ans.clear();
        ans = getpath(&mtr1[0][0], visited, curpath);


        for (int j = 0; j < ans.size(); j++) res1.push_back(ans[j]);
    }

    cout << endl << endl;
    for (int j, k = 0; k < res1.size(); k++)
    {
        cout << endl << k << "\t";
        for (auto y : res1[k]) cout << y << "  ";
    }
    cout << endl << endl << endl;


    int minw = 1000;
    for (int j, k = 0; k < res1.size(); k++)  //finish
    {
        res1[k].push_back(res1[k][0]);
        w = 0;
        // cout << "\t\t\tvector size:   " << res1[k].size() << endl;
        for (j = 0; j < vsize; j++) w += mtr1[res1[k][j]][ res1[k][j + 1]];

        if (minw > w)
        {
            curpath = res1[k];
            minw = w;
        }

        for (j = 0; j < vsize; j++)
            cout << res1[k][j]+1 << " --> ";
        cout << res1[k][j]+1 << "\tdist=  " << w <<  " z " << endl;

    }
    int j;
    cout << endl << endl << "min weight=  " << minw << endl;
    for (j = 0; j < vsize; j++)
        cout << curpath[j]+1 << " --> ";
    cout << curpath[j] + 1 << endl << endl << endl;


    for (j = 0; j < vsize; j++) cout << mtr1[curpath[j]][curpath[j + 1]]<<"   ";


}


/*

0 1 5 6 5 5 1 5
1 0 7 5 6 5 5 5
5 7 0 6 1 5 6 5
6 5 6 0 7 7 7 5
5 6 1 7 0 5 6 5
5 5 5 7 5 0 5 1
1 5 6 7 6 5 0 5
5 5 5 5 5 1 5 0



0 1 1 1 1 1 1 1
1 0 7 5 6 5 5 50 5 5 5 4 6 5 5
5 0 7 3 3 5 4 5
5 7 0 4 5 6 4 5
5 3 5 1 0 5 1 1
5 3 5 1 0 5 1 1
6 5 6 2 5 0 2 3
5 4 4 5 1 2 0 5
5 5 5 1 1 3 5 0
5 7 0 6 1 5 6 5
6 5 6 0 7 7 7 5
5 6 1 7 0 5 6 5
5 5 5 7 5 0 5 1
1 5 6 7 6 5 0 5
5 5 5 5 5 1 5 0

0 5 5 5 4 6 5 5
5 0 7 3 3 5 4 5
5 7 0 4 5 6 4 5
5 3 4 0 1 2 5 1
5 3 5 1 0 5 1 1
6 5 6 2 5 0 2 3
5 4 4 5 1 2 0 5
5 5 5 1 1 3 5 0
*/


#include <iostream>
#include <vector>
#define inf 99999999
using namespace std;

int i = 0;
int k = 1;
int minM = inf;
vector<vector<int>> arr{
        {inf, 5, 5, 5, 4, 6, 5, 5},
        {5, inf, 7, 3, 3, 5, 4, 5},
        {5, 7, inf, 4, 5, 6, 4, 5},
        {5, 3, 4, inf, 1, 2, 5, 1},
        {5, 3, 5, 1, inf, 5, 1, 1},
        {6, 5, 6, 2, 5, inf, 2, 3},
        {5, 4, 4, 5, 1, 2, inf, 5},
        {5, 5, 5, 1, 1, 3, 5, inf}
};

vector<int> withoutId(vector<int> v, int id) {
    v[id] = inf;
    return v;
}

void print(vector<int> line = {},vector<int> toAdd = arr[i]) {
    vector<int> id{};
    int minX = inf;
    // find all smallest variants
    for(auto x : toAdd) {
        minX = min(minX, x);
    }
//    cout << "min: " << minX << endl;
    if(minX == inf) {
        cout << k++ << ". " << i+1;
        for(auto x : line) {
            cout << "->" << x+1 ;
        }
        cout << "->" << i+1;
        cout << "\t" << arr[i][line[0]];
        int sum = arr[i][line[0]];
        for(int i = 0; i < line.size()-1; i++) {
            sum+=arr[line[i]][line[i+1]];
            cout << "+" << arr[line[i]][line[i+1]];
        }
        sum+=arr[line[line.size()-1]][i];
        cout << "+" << arr[line[line.size()-1]][i];
        cout << "=" << sum << endl;
        minM = min(minM,sum);
        return;
    }
    for (int j = 0; j < toAdd.size(); ++j) {
        if(minX == toAdd[j]) id.push_back(j);
    }
    for(auto x : id) {
        vector<int> newAdd = arr[x];
        for (int j = 0; j < toAdd.size(); ++j) {
            if( toAdd[j] == inf) {
                newAdd[j] = inf;
            }
        }
        vector<int> newLine = line;
        newLine.push_back(x);
        print(newLine,newAdd);
    }


}


void printM(vector<int> line = {},vector<int> toAdd = arr[i]) {
    vector<int> id{};
    int minX = inf;
    // find all smallest variants
    for(auto x : toAdd) {
        minX = min(minX, x);
    }
    if(minX == inf) {
        int sum = arr[i][line[0]];
        for(int i = 0; i < line.size()-1; i++) {
            sum+=arr[line[i]][line[i+1]];
        }
        sum+=arr[line[line.size()-1]][i];
        if( sum == minM) {
            cout << k << ". " << i+1;
            for(auto x : line) {
                cout << "->" << x+1 ;
            }
            cout << "->" << i+1;
            cout << "\t" << arr[i][line[0]];
            int sum = arr[i][line[0]];
            for(int i = 0; i < line.size()-1; i++) {
                sum+=arr[line[i]][line[i+1]];
                cout << "+" << arr[line[i]][line[i+1]];
            }
            sum+=arr[line[line.size()-1]][i];
            cout << "+" << arr[line[line.size()-1]][i];
            cout << "=" << sum << endl;
        }
        k++;
        return;
    }
    for (int j = 0; j < toAdd.size(); ++j) {
        if(minX == toAdd[j]) id.push_back(j);
    }
    for(auto x : id) {
        vector<int> newAdd = arr[x];
        for (int j = 0; j < toAdd.size(); ++j) {
            if( toAdd[j] == inf) {
                newAdd[j] = inf;
            }
        }
        vector<int> newLine = line;
        newLine.push_back(x);
        printM(newLine,newAdd);
    }


}


int main() {
    for(i = 0; i < arr.size(); i++) {
        print();
    }
    k = 1;
    cout << endl << "minM:" << minM << endl << endl;
    for(i = 0; i < arr.size(); i++) {
        printM();
    }

}

