#include <gmock/gmock.h>
#include <string>
#include <vector>
#include <deque>

template <class T>
void print_container(T const& v) {

    for(auto i : v) std::cout << i << " ";
    std::cout << std::endl;
}

struct Coordinates {
    int x;
    int y;
    Coordinates(int x, int y) : x(x), y(y) {};
};

struct Buffer
{
    Buffer() {};
    std::deque<char>  buffer{'N','W','S','E'};
    char tmp;

    void rotate_right() {
        tmp = buffer.front();
        buffer.pop_front();
        buffer.push_back(tmp);
    }

    void rotate_left() {
        tmp = buffer.back();
        buffer.pop_back();
        buffer.push_front(tmp);
    }
    char get_current() {
        return buffer.front();
    }
};

struct Rover {

    Coordinates coords = Coordinates(0,0);
    Buffer buf;

    Rover(int x, int y) : coords(x,y) {};
    Rover() {};

    void executeCommand(std::string str) {
        for( auto i : str) {
            if(i  =='R') this->turnRight();
            else if(i  =='L') this->turnLeft();
            else if(i  =='M') this->goForward();
        }
    }

    void goForward() {
        if(buf.get_current() == 'N') coords.y++;
        else if(buf.get_current() == 'W') coords.x++;
        else if(buf.get_current() == 'S') coords.y--;
        else if(buf.get_current() == 'E') coords.x--;
        else {}
    }

    char getDirection() {
        return 'N';
    }

    std::string get_position() {
        std::stringstream str;
        str << coords.x << ' ' << coords.y << ' ' << buf.get_current();
        return  str.str();
    }

    void turnRight() {
        buf.rotate_right();

    }
    void turnLeft() {
        buf.rotate_left();
    }
};


//---------------------------------------------------------------------
using namespace ::testing;

TEST(Empty, acceptance) {
    Rover rover(1,2);
    rover.executeCommand("LMLMLMLMM");
    EXPECT_EQ(rover.get_position(), "1 3 N");
}

TEST(Empty, testParser) {
    Rover rover;
    rover.executeCommand("RMMMM");
}


TEST(Empty, goForward) {
    Rover rover;
    rover.goForward();
    EXPECT_EQ(rover.get_position(), "0 1 N");
}

TEST(Empty, turnRightAndGoForward)
{
    Rover rover;
    rover.turnRight();
    rover.goForward();
    rover.goForward();
    rover.goForward();
    rover.goForward();
    EXPECT_EQ(rover.get_position(), "4 0 W");
}



TEST(Empty, turnRightAndGoForwardLeftForward)
{
    Rover rover;
    rover.turnRight();
    rover.goForward();
    rover.turnLeft();
    rover.goForward();
    EXPECT_EQ(rover.get_position(), "1 1 N");
}

TEST(Empty, sanity)
{
    Rover rover;
    EXPECT_EQ(rover.get_position(), "0 0 N");
}

TEST(Empty, turnRightAndBack)
{
    Rover rover;
    rover.turnRight();
    rover.turnLeft();
    EXPECT_EQ(rover.get_position(), "0 0 N");
}




TEST(Empty, turnRight2times)
{
    Rover rover;
    rover.turnRight();
    rover.turnRight();
    EXPECT_EQ(rover.get_position(), "0 0 S");
}


TEST(Empty, bufferInitialPosition) {

    Buffer buffer;
    EXPECT_EQ(buffer.get_current(), 'N');

}

TEST(Empty, bufferRotateright) {

    Buffer buffer;
    EXPECT_EQ(buffer.get_current(), 'N');
    buffer.rotate_right();
    EXPECT_EQ(buffer.get_current(), 'W');

}
TEST(Empty, bufferRotateLeft) {

    Buffer buffer;
    EXPECT_EQ(buffer.get_current(), 'N');
    buffer.rotate_left();
    EXPECT_EQ(buffer.get_current(), 'E');

}


