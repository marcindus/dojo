#include <algorithm>
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
vector<pair<int,int>> answer(Table v);

constexpr auto SIZE = 5u;

vector<pair<int,int>> answer(Table v) {

    vector<pair<int,int>> result;
    vector<int> temporaryCol;
    int maxIndex;
    int minIndex;

    for(unsigned int i = 0 ; i < SIZE ; i++) {
        maxIndex = getMaxIndex(v[i]);
        temporaryCol = getCol(maxIndex,v);
        minIndex = getMinIndex(temporaryCol);

        cout <<  v[minIndex][i] << " == " <<  temporaryCol[minIndex] << endl;
        if(v[minIndex][i] == temporaryCol[minIndex]) {
            result.push_back(make_pair(minIndex, maxIndex));
        }

    }
    return result;
}


vector<int> getCol(int i, Table t) {
    vector<int> v;
    for(unsigned int k = 0 ; k < SIZE ; k++) {
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



TEST(saddle, findSaddlePointPlacedNotOnDiagonal){

Table table =  {{0, 0, 4, 0, 0},
                {1, 2, 3, 2, 1},
                {0, 0, 5, 0, 0},
                {0, 0, 6, 0, 0},
                {0, 0, 7, 0, 0}};

vector<pair<int,int>> result;
result.push_back(make_pair(1,2));
ASSERT_EQ(result, answer(table));
}





TEST(saddle, findSaddlePointPlacedOnDiagonal){

Table table =  {{0, 0, 4, 0, 0},
                {1, 2, 5, 2, 1},
                {0, 0, 3, 0, 0},
                {0, 0, 6, 0, 0},
                {0, 0, 7, 0, 0}};

vector<pair<int,int>> result;
result.push_back(make_pair(2,2));
ASSERT_EQ(result, answer(table));
}


TEST(saddle, getCol) {


Table table =  {{0, 0, 4, 0, 0},
                {1, 2, 5, 2, 1},
                {0, 0, 3, 0, 0},
                {0, 0, 6, 0, 0},
                {0, 0, 7, 0, 0}};

    vector<int> col = {0,1,0,0,0};
    ASSERT_EQ(col , getCol(0,table));
    col = {4,5,3,6,7};
    ASSERT_EQ(col , getCol(2,table));

}


TEST(saddle, getMaxFromVector) {
    vector<int> vec = {0,22,1};
    ASSERT_EQ(1, getMaxIndex(vec));
}

TEST(saddle, getMinFromVector) {
    vector<int> vec = {0,22,1};
    ASSERT_EQ(0, getMinIndex(vec));
}







