#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, Slice) {
    EXPECT_EQ(StringUtils::Slice("Hello, World!", 1, 6), "ello,");

    EXPECT_EQ(StringUtils::Slice("", 0, 3), "");

    EXPECT_EQ(StringUtils::Slice("Testing", 3, 1), "");

    EXPECT_EQ(StringUtils::Slice("Hello, World!", -3, 6), "");

    EXPECT_EQ(StringUtils::Slice("Hello, World!", 1, -2), "");

    EXPECT_EQ(StringUtils::Slice("Hello", 10, 15), "");

    EXPECT_EQ(StringUtils::Slice("Hello", 1, 10), "ello");

    EXPECT_EQ(StringUtils::Slice("", 2, 5), "");

    EXPECT_EQ(StringUtils::Slice("Hello, World!", 7, 7), "");

    EXPECT_EQ(StringUtils::Slice("X", 0, 1), "X");

    EXPECT_EQ(StringUtils::Slice("Hello", 0, 0), "");

    EXPECT_EQ(StringUtils::Slice("Hello, World!", 7, 12), "World");

    EXPECT_EQ(StringUtils::Slice("Hello, World!", 0, 13), "Hello, World!");
}


TEST(StringUtilsTest, Capitalize) {
    EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");

    EXPECT_EQ(StringUtils::Capitalize("WORLD"), "World");

    EXPECT_EQ(StringUtils::Capitalize("   lowercase"), "   Lowercase");

    EXPECT_EQ(StringUtils::Capitalize(""), "");

    EXPECT_EQ(StringUtils::Capitalize("x"), "X");

    EXPECT_EQ(StringUtils::Capitalize("   multiple words"), "   Multiple Words");

    EXPECT_EQ(StringUtils::Capitalize("123number"), "123number");

    EXPECT_EQ(StringUtils::Capitalize("!@#$%^"), "!@#$%^");

    EXPECT_EQ(StringUtils::Capitalize("MiXeD CaSe"), "Mixed Case");   
}

TEST(StringUtilsTest, Upper) {
    EXPECT_EQ(StringUtils::Upper("hello"), "HELLO");

    EXPECT_EQ(StringUtils::Upper("WORLD"), "WORLD");

    EXPECT_EQ(StringUtils::Upper("   lowercase"), "   LOWERCASE");

    EXPECT_EQ(StringUtils::Upper(""), "");

    EXPECT_EQ(StringUtils::Upper("x"), "X");

    EXPECT_EQ(StringUtils::Upper("   multiple words"), "   MULTIPLE WORDS");

    EXPECT_EQ(StringUtils::Upper("123number"), "123NUMBER");

    EXPECT_EQ(StringUtils::Upper("!@#$%^"), "!@#$%^");

    EXPECT_EQ(StringUtils::Upper("MiXeD CaSe"), "MIXED CASE");    
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("Hello"), "hello");

    EXPECT_EQ(StringUtils::Lower("world"), "world");

    EXPECT_EQ(StringUtils::Lower("   UPPERCASE"), "   uppercase");

    EXPECT_EQ(StringUtils::Lower(""), "");

    EXPECT_EQ(StringUtils::Lower("X"), "x");

    EXPECT_EQ(StringUtils::Lower("   MULTIPLE WORDS"), "   multiple words");

    EXPECT_EQ(StringUtils::Lower("123NUMBER"), "123number");

    EXPECT_EQ(StringUtils::Lower("!@#$%^"), "!@#$%^");

    EXPECT_EQ(StringUtils::Lower("MiXeD CaSe"), "mixed case");

}

TEST(StringUtilsTest, LStrip) {
    EXPECT_EQ(StringUtils::LStrip("   Hello"), "Hello");

    EXPECT_EQ(StringUtils::LStrip("   "), "");

    EXPECT_EQ(StringUtils::LStrip("World"), "World");

    EXPECT_EQ(StringUtils::LStrip("\t\n\tText"), "Text");

    EXPECT_EQ(StringUtils::LStrip(""), "");

    EXPECT_EQ(StringUtils::LStrip("Space   "), "Space   ");

    EXPECT_EQ(StringUtils::LStrip(" \tMixed \nWhitespace"), "Mixed \nWhitespace");

}

TEST(StringUtilsTest, RStrip) {
    EXPECT_EQ(StringUtils::RStrip("Hello   "), "Hello");

    EXPECT_EQ(StringUtils::RStrip("   "), "");

    EXPECT_EQ(StringUtils::RStrip("World"), "World");

    EXPECT_EQ(StringUtils::RStrip("Text\t\n\t"), "Text");

    EXPECT_EQ(StringUtils::RStrip(""), "");

    EXPECT_EQ(StringUtils::RStrip("   Space"), "   Space");

    EXPECT_EQ(StringUtils::RStrip("Whitespace \n\tMixed \n"), "Whitespace \n\tMixed");
 
}

TEST(StringUtilsTest, Strip) {
    EXPECT_EQ(StringUtils::Strip("   Hello   "), "Hello");

    EXPECT_EQ(StringUtils::Strip("   "), "");

    EXPECT_EQ(StringUtils::Strip("World"), "World");

    EXPECT_EQ(StringUtils::Strip("\t\n\tText\t\n\t"), "Text");

    EXPECT_EQ(StringUtils::Strip(""), "");

    EXPECT_EQ(StringUtils::Strip("   Space"), "Space");

    EXPECT_EQ(StringUtils::Strip("Text   "), "Text");

    EXPECT_EQ(StringUtils::Strip(" \tMixed \nWhitespace\t "), "Mixed \nWhitespace");

}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("Hello", 10, '*'), "**Hello***");

    EXPECT_EQ(StringUtils::Center("World", 5, '#'), "World");

    EXPECT_EQ(StringUtils::Center("", 8, '@'), "@@@@@@@@");

    EXPECT_EQ(StringUtils::Center("X", 7, '-'), "--X----");

    EXPECT_EQ(StringUtils::Center("Center", 8, '*'), "*Center*");

    EXPECT_EQ(StringUtils::Center("   Spaces   ", 15, '='), "==   Spaces   ");

    EXPECT_EQ(StringUtils::Center("\tTabbed\t", 12, '+'), "++\tTabbed\t");

    EXPECT_EQ(StringUtils::Center("!@#", 5, '+'), "+!@#+");


}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("Hello", 10, '*'), "Hello*****");

    EXPECT_EQ(StringUtils::LJust("World", 5, '#'), "World");

    EXPECT_EQ(StringUtils::LJust("", 8, '@'), "@@@@@@@@");

    EXPECT_EQ(StringUtils::LJust("X", 7, '-'), "X------");

    EXPECT_EQ(StringUtils::LJust("Left", 8, '*'), "Left****");

    EXPECT_EQ(StringUtils::LJust("   Spaces   ", 15, '='), "   Spaces   ==");

    EXPECT_EQ(StringUtils::LJust("\tTabbed\t", 12, '+'), "\tTabbed\t++");

    EXPECT_EQ(StringUtils::LJust("!@#", 5, '+'), "!@#++");

}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("Hello", 10, '*'), "*****Hello");

    EXPECT_EQ(StringUtils::RJust("World", 5, '#'), "World");

    EXPECT_EQ(StringUtils::RJust("", 8, '@'), "@@@@@@@@");

    EXPECT_EQ(StringUtils::RJust("X", 7, '-'), "------X");

    EXPECT_EQ(StringUtils::RJust("Right", 8, '*'), "****Right");

    EXPECT_EQ(StringUtils::RJust("   Spaces   ", 15, '='), "==   Spaces   ");

    EXPECT_EQ(StringUtils::RJust("\tTabbed\t", 12, '+'), "++\tTabbed\t");

    EXPECT_EQ(StringUtils::RJust("!@#", 5, '+'), "++!@#");

}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("Hello World", "World", "Universe"), "Hello Universe");

    EXPECT_EQ(StringUtils::Replace("apple apple apple", "apple", "orange"), "orange orange orange");

    EXPECT_EQ(StringUtils::Replace("The quick brown fox", "The", "A"), "A quick brown fox");

    EXPECT_EQ(StringUtils::Replace("This is a test", "test", "challenge"), "This is a challenge");

    EXPECT_EQ(StringUtils::Replace("", "pattern", "replacement"), "");

    EXPECT_EQ(StringUtils::Replace("No match here", "apple", "orange"), "No match here");

    EXPECT_EQ(StringUtils::Replace("Remove spaces", " ", ""), "Removespaces");

    EXPECT_EQ(StringUtils::Replace("!---Hello---!", "---", ""), "!Hello!");

    EXPECT_EQ(StringUtils::Replace("CaseSensitive", "s", ""), "CaeSenitive");

}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split("Hello World", " "), std::vector<std::string>{"Hello", "World"});

    EXPECT_EQ(StringUtils::Split("apple,orange,banana", ","), std::vector<std::string>{"apple", "orange", "banana"});

    EXPECT_EQ(StringUtils::Split("Tab\tSeparated\tValues", "\t"), std::vector<std::string>{"Tab", "Separated", "Values"});

    EXPECT_EQ(StringUtils::Split("", ","), std::vector<std::string>{""});

    EXPECT_EQ(StringUtils::Split("One,,Two,Three", ","), std::vector<std::string>{"One", "", "Two", "Three"});

    EXPECT_EQ(StringUtils::Split("Line1\nLine2\nLine3", "\n"), std::vector<std::string>{"Line1", "Line2", "Line3"});

    EXPECT_EQ(StringUtils::Split("   Spaces   Separated", " "), std::vector<std::string>{"", "", "", "Spaces", "", "", "Separated"});

    EXPECT_EQ(StringUtils::Split("NoDelimiterHere", ","), std::vector<std::string>{"NoDelimiterHere"});

}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(",", {"apple", "orange", "banana"}), "apple,orange,banana");

    EXPECT_EQ(StringUtils::Join(" ", {"Hello", "World"}), "Hello World");

    EXPECT_EQ(StringUtils::Join("-", {"one", "two", "three"}), "one-two-three");

    EXPECT_EQ(StringUtils::Join("", {"a", "b", "c"}), "abc");

    EXPECT_EQ(StringUtils::Join(",", {}), "");

    EXPECT_EQ(StringUtils::Join("!@#", {"alpha", "beta", "gamma"}), "alpha!@#beta!@#gamma");

    EXPECT_EQ(StringUtils::Join("\n", {"Line1", "Line2", "Line3"}), "Line1\nLine2\nLine3");

    EXPECT_EQ(StringUtils::Join("\t", {"Tabbed", "Separated", "Values"}), "Tabbed\tSeparated\tValues");

    EXPECT_EQ(StringUtils::Join(" - ", {"First", "Second", "Third"}), "First - Second - Third");

}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("Tab\tSeparated", 4), "Tab    Separated");

    EXPECT_EQ(StringUtils::ExpandTabs("Indented\tText", 2), "Indented  Text");

    EXPECT_EQ(StringUtils::ExpandTabs("NoTabsHere", 8), "NoTabsHere");

    EXPECT_EQ(StringUtils::ExpandTabs("\tStartsWithTab", 3), "   StartsWithTab");

    EXPECT_EQ(StringUtils::ExpandTabs("One\tTwo\tThree", 6), "One   Two   Three");

    EXPECT_EQ(StringUtils::ExpandTabs("", 4), "");

    EXPECT_EQ(StringUtils::ExpandTabs("Before\tAfter", 2), "Before  After");

    EXPECT_EQ(StringUtils::ExpandTabs("Ends\t", 5), "Ends     ");

    EXPECT_EQ(StringUtils::ExpandTabs("Small", 10), "Small");

}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("hello", "hello", false), 0);

    EXPECT_EQ(StringUtils::EditDistance("Hello", "hello", true), 0);

    EXPECT_EQ(StringUtils::EditDistance("Hello", "hello", false), 1);

    EXPECT_EQ(StringUtils::EditDistance("abc", "abcd", false), 1);

    EXPECT_EQ(StringUtils::EditDistance("ABC", "abcd", true), 1);

    EXPECT_EQ(StringUtils::EditDistance("", "", false), 0);

    EXPECT_EQ(StringUtils::EditDistance("!@#", "#@!", true), 2);

    EXPECT_EQ(StringUtils::EditDistance("!@#", "#@!", false), 2);

    EXPECT_EQ(StringUtils::EditDistance("this is a long string", "this is another string", true), 6);

}
