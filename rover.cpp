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
    std::deque<char>  buffer{'N', 'W','S','E'};
    char back_ = buffer.back();

    void rotate_left() {
        buffer.pop_back();
        buffer.push_front(back_);
    }

    void rotate_right() {
        buffer.pop_front();
        buffer.push_back(back_);
    }
    char get_current() {
        return buffer.front();
    }
};

struct Rover {

    Coordinates coords = Coordinates(0,0);

    Buffer buf;

    void goForward() {
        coords.y++;
    }

    void goBackward() {
        coords.x++;
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
    void foForward() {
        buf.rotate_left();
    }
};


//---------------------------------------------------------------------
using namespace ::testing;



TEST(Empty, sanity)
{
    Rover rover;
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


