#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <tuple>
#include <queue>
#include <memory>


using namespace ::testing;
using namespace std;
using Maze = vector< vector<char> >;
using Position = pair< int,  int > ;

string toString(Maze& mz);
string toString(Position& mz);
 int countRows(const Maze& mz);
 int countColumns(const Maze& mz);
Position findStart(const Maze& mz, const char start_symbol);
char getField(Position position, const Maze& mz);
void setFieldVisited(Position position, Maze& mz);
Position move(Position curr_position, Position next_position, Maze& mz);
Position goRight(Position curr_position, Maze& mz);
Position goDown(Position curr_position, Maze& mz);

string toString(Position& position) {
    stringstream stm;
    stm << "x:" << position.first << "  y:" << position.second ;
    return stm.str();
}

string toString(Maze& mz) {
    stringstream  stm ;
    for(auto& row:mz)  {
        for(auto& col:row) {
            stm << col << " " ;
        }
    stm << endl ;
    }
return stm.str();
}

 int countRows(const Maze& mz) { return mz.size(); }
 int countColumns(const Maze& mz) { return mz[0].size(); }

Position findStart(Maze& mz, const char start_symbol) {
    for( int i = 0 ; i < countRows(mz) ; i++) {
        for( int j = 0 ; j < countColumns(mz) ; j++) {
            if(mz[i][j] == start_symbol) {
                mz[i][j] = 'X';
                return make_pair(i,j);
                }
        }
    }
    return make_pair(-1,-1);
}
//Todo: function template
char getField(Position position, const Maze& mz) {
    if( (position.first < countRows(mz)) and (position.second < countColumns(mz)) and (position.second >= 0) and position.first >= 0)     {
                return mz[position.first][position.second];
    }
    else {
        return '1';
    }
}

bool wasVisited(Position position, vector<vector< bool > >& mz) {
    if(position.first < mz.size() and position.second < mz[0].size() and position.second >= 0 and position.first >= 0)     {
                return mz[position.first][position.second];
    }
    else {
        return false;
    }
}

vector<Position> lookAround(Position& position, Maze& mz, vector<vector< bool >>& visited) {
    vector<Position> possibleMoves;
    //Look right
    Position right = make_pair(position.first+1, position.second);
    Position left = make_pair(position.first-1, position.second);
    Position up = make_pair(position.first, position.second-1);
    Position down = make_pair(position.first, position.second+1);

    if(getField(right, mz) != '1' && !wasVisited(right, visited))  {
        possibleMoves.push_back(right);
    }
    if(getField(left, mz) != '1' && !wasVisited(left, visited))  {
        possibleMoves.push_back(left);
    }
    if(getField(up, mz) != '1' && !wasVisited(up, visited))  {
        possibleMoves.push_back(up);
    }
    if(getField(down, mz) != '1' && !wasVisited(down, visited) )  {
        possibleMoves.push_back(down);
    }
    return possibleMoves;
}


void setFieldVisited(Position position, Maze& mz) {
    mz[position.first][position.second] = 'X';
}

Position move(Position curr_position, Position next_position, Maze& mz){
 if(getField(next_position, mz) != '1') {
       setFieldVisited(next_position, mz);
        return next_position;
    }
    return curr_position;
}

Position goRight(Position curr_position, Maze& mz) {
    return move(curr_position, make_pair(curr_position.first, curr_position.second + 1), mz);
}

Position goDown(Position curr_position, Maze& mz) {
    return move(curr_position, make_pair(curr_position.first+1, curr_position.second), mz);
}


struct Node {
    Position position;
    vector<shared_ptr<Node>> children;
    shared_ptr<Node> parent;
};

shared_ptr<Node> insertNode(shared_ptr<Node> root, Position& position) {
    shared_ptr<Node> tmp = make_shared<Node>();
//    shared_ptr<Node>  tmp =  new Node;
    tmp->position = position;
    tmp->parent = root;
    root->children.push_back(tmp);
    return tmp;
}


struct MazeTest : public ::testing::Test {
        Maze maze = {{ 'S', '0', '1'},
                     { '1', '0', '1'},
                     { '1', '0', 'E'}};

    Maze maze_solved = {{ 'X', 'X', '1'},
                        { '1', 'X', '1'},
                        { '1', 'X', 'X'}};

};
TEST_F(MazeTest, treeSimplePrintTest) {

    vector<vector<bool> > visited;
    visited.resize(maze.size(), vector<bool>(maze[0].size(), false));


    Position start = {0,0};
    shared_ptr<Node> current = make_shared<Node>();
    current->parent = nullptr;
    current->position = start;

    shared_ptr<Node> tmp = make_shared<Node>();
    queue< shared_ptr<Node>> nodes;
    nodes.push(current);
    while(!nodes.empty()) {
        for(auto v : lookAround(current->position, maze, visited)) {
                    tmp = insertNode(current, v);
                    cout << toString(tmp->position) << endl;
                    nodes.push(tmp);
            }
    visited[current->position.first][current->position.second]  = true;
    current = nodes.front();
    nodes.pop();
    }
}


TEST_F(MazeTest, getFieldInMaze) {
    Position start = {0,0};
    ASSERT_EQ(getField(start, maze), 'S');
}

TEST_F(MazeTest, getFieldInMazeOnRight) {
    Position start = {0,1};
    ASSERT_EQ(getField(start, maze), '0');
}

TEST_F(MazeTest, getFieldOffMazeOnLeft) {
    Position start = {0,-1};
    ASSERT_EQ(getField(start, maze), '1');
}

TEST_F(MazeTest, getFieldOffMazeUp) {
    Position start = {1,0};
    ASSERT_EQ(getField(start, maze), '1');
}

TEST_F(MazeTest, getFieldOnMazeDown) {
    Position start = {-1,0};
    ASSERT_EQ(getField(start, maze), '1');
}

TEST_F(MazeTest, getFieldOutsideMaze) {
    Position start = {100,100};
    ASSERT_EQ(getField(start, maze), '1');
}

TEST_F(MazeTest, givenPossibleMoveRightGoRightFromStart) {
     Maze mazeAfterMoveRight = {{ 'X', 'X', '1'},
                              { '1', '0', '1'},
                              { '1', '0', 'E'}};
     Position currentPosition = goRight(findStart(maze, 'S'), maze);
     move(currentPosition, currentPosition, maze);
     ASSERT_EQ(mazeAfterMoveRight, maze);
     ASSERT_EQ(currentPosition, make_pair(0,1));
}


TEST_F(MazeTest, goDownFromGivenPosition) {
     Maze mazeAfterMoveDown ={{ 'X', 'X', '1'},
                              { '1', 'X', '1'},
                              { '1', '0', 'E'}};
     Position currentPosition = goRight(findStart(maze, 'S'), maze);
     move(currentPosition, currentPosition, maze);
     currentPosition = goDown(currentPosition, maze);
     cout << toString(maze) << endl;
     cout << toString(mazeAfterMoveDown) << endl;
     ASSERT_EQ(mazeAfterMoveDown, maze);
     ASSERT_EQ(currentPosition, make_pair(1,1));
}


TEST_F(MazeTest, findStartPositionInMaze) {
    Position start = {0,0};
    ASSERT_EQ(findStart(maze, 'S'), start);
}

TEST_F(MazeTest, lookAround) {

    vector<vector<bool> > visited;
    visited.resize(maze.size(), vector<bool>(maze[0].size(), false));


    Position start = {0,0};
    vector<Position> positions = lookAround(start, maze, visited);
    vector<Position> result = {make_pair(0,1)};
    ASSERT_EQ(positions, result);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


