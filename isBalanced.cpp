#include <gmock/gmock.h>
#include <string>
#include <stack>


bool isBalanced(const std::string& str)
{
    std::stack<char> st;
for(const char& c : str)
{
    if(c == '(')
    {
        st.push(c);
    }
    else if( c == ')')
    {
        if(!st.empty())
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }

}
    return st.empty();
}
using namespace ::testing;


TEST(Empty, testSimple)
{
     EXPECT_EQ(isBalanced("()"), true);
     EXPECT_EQ(isBalanced(")("), false);
     EXPECT_EQ(isBalanced("(((((( )))))))("), false);
}




