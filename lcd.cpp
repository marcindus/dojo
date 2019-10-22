#include <deque>
#include <gmock/gmock.h>
#include <string>
#include <unordered_map>
#include <vector>

static std::unordered_map<int, std::array<std::string, 3>>
                                    numbers = {{1, {"...", "..|", "..|"}},
                                               {2, {"._.", "._|", "|_."}},
                                               {5, {"._.", "|_.", "._|"}}};

// ._.   ...   ._.   ._.   ...   ._.   ._.   ._.   ._.   ._.
// |.|   ..|   ._|   ._|   |_|   |_.   |_.   ..|   |_|   |_|
// |_|   ..|   |_.   ._|   ..|   ._|   |_|   ..|   |_|   ..|

std::string endLine(std::string row)
{
    return row + "\n";
}




std::string LCD::print(int number)
{
    auto digits = getDigits(number);

    std::string row1{};
    std::string row2{};
    std::string row3{};

    for(auto digit : digits)
    {
        auto l_number = numbers.find(digit);
        if(l_number != numbers.end())
        {
            row1 += l_number->second[0];
            row2 += l_number->second[1];
            row3 += l_number->seond[2];
        }
    }
    return endLine(row1) + endLine(row2) + row3;
}

struct LCD
{
    std::string print(int number);
};


inline std::deque<int> getDigits(int num)
{
    std::deque<int> result;

    while(num > 10) {
        result.push_front(num%10);
        num = num / 10;
    }
    result.push_front(num);

return result;
}

using namespace ::testing;

namespace {

TEST(Empty, testSingleDigit)
{
     EXPECT_EQ(LCD().print(1), "...\n"
                               "..|\n"
                               "..|");
     EXPECT_EQ(LCD().print(2), "._.\n"
                               "._|\n"
                               "|_.");
    EXPECT_EQ(LCD().print(5), "._.\n"
                               "|_.\n"
                               "._|");
}

TEST(Empty, testDoubleDigits)
{
     EXPECT_EQ(LCD().print(15), "...._.\n"
                                "..||_.\n"
                                "..|._|");
}

TEST(Empty, testFourDigits)
{
     EXPECT_EQ(LCD().print(151515), "...._....._....._.\n"
                                    "..||_...||_...||_.\n"
                                    "..|._|..|._|..|._|");
}

TEST(Empty, testDigits) 
{
     EXPECT_EQ(getDigits(123), std::deque<int>({1,2,3}));
     EXPECT_EQ(getDigits(99712), std::deque<int>({9,9,7,1,2}));
}

}



