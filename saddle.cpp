
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

using namespace ::testing;
using namespace std;
using Position = pair<int, int> ;
using Table = vector<vector<int>>;


int getMaxIndex(vector<int> v);
int getMinIndex(vector<int> v);
vector<int> getCol(int , Table );

constexpr auto SIZE = 5u;

vector<pair<int,int>> answer(Table v) { 

    vector<pair<int,int>> result;
    //fix that!
    for(int i = 0 ; i < SIZE ; i++) {
        if( max_element(v[i].begin(), v[i].end())
        == min_element(getCol(i, v).begin(), getCol(i, v).end()) ) {
            result.push_back(make_pair(getMaxIndex(v[i]) , getMinIndex(getCol(i, v))));
            cout << getMaxIndex(v[i])  << " " << getMinIndex(getCol(i, v)) << endl;
        }
    }
    return result;
}


vector<int> getCol(int i, Table t) {

    vector<int> v;
    for(int k = 0 ; k < SIZE ; k++) {
            v.push_back(t[k][i]);
            }


    return v;
}

int getMaxIndex(vector<int> v) {
    return distance(v.begin(), max_element(v.begin(), v.end()));
}

int getMinIndex(vector<int> v) {
    return distance(v.begin(), min_element(v.begin(), v.end()));
}



TEST(Hiker, Life_the_universe_and_everything){

Table table =        {{0, 0, 4, 0, 0},
        {1, 2, 3, 2, 1},
        {0, 0, 5, 0, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 7, 0, 0}};

vector<pair<int,int>> result;
result.push_back(make_pair(2,2));
ASSERT_EQ(result, answer(table));
}

TEST(Hiker, getCol) {


       Table table =        {{0, 0, 4, 0, 0},
        {1, 2, 3, 2, 1},
        {0, 0, 5, 0, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 7, 0, 0}};

    vector<int> col = {0,1,0,0,0};
    ASSERT_EQ(col , getCol(0,table));
}


TEST(Hiker, getMaxFromVector) {
    vector<int> vec = {0,22,1};
    ASSERT_EQ(1, getMaxIndex(vec));
}

TEST(Hiker, getMinFromVector) {
    vector<int> vec = {0,22,1};
    ASSERT_EQ(0, getMinIndex(vec));
}


