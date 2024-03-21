cmake_minimum_required(VERSION 3.28)
project(algorithm)

set(CMAKE_CXX_STANDARD 26)

add_executable(algorithm main.cpp
        oj/leetcode/1101-1200/1157/1157_1.cpp
        oj/leetcode/1101-1200/1157/1157_2.cpp
        oj/leetcode/301-400/303/303.cpp
        oj/leetcode/1-100/1/1.cpp
        oj/leetcode/1-100/2/2.cpp
        oj/leetcode/1-100/3/3.cpp
        oj/leetcode/1901-2000/1969/1969.cpp
        oj/leetcode/1601-1700/1669/1669.cpp
        oj/leetcode/2601-2700/2671/2671.cpp
        oj/leetcode/201-300/206/206.cpp
        oj/leetcode/601-700/699/699.cpp
)
