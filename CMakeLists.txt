cmake_minimum_required(VERSION 3.13)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)



add_executable(LinkList src/Lab1/LinkList.cpp)
add_executable(SeqList src/Lab1/SeqList.cpp)
add_executable(Lab2 src/Lab2/Palindrome.cpp)
add_executable(BR src/HomeWork/RBTreeTest.cpp)
add_executable(SplayTree src/HomeWork/SplayTreeTest.cpp)
add_executable(Hash src/Lab3/HashTest.cpp)


add_executable(Lab4 src/Lab4/BINTREE.cpp)
add_executable(Lab5 src/Lab5/BINTREE.C src/Lab5/STACKS.C)
add_executable(Lab6 src/Lab6/rbtree.c src/Lab6/set_test.c src/Lab6/set.h src/Lab6/set.c)
add_executable(Lab6_advance src/Lab6_advance/trie.h src/Lab6_advance/trie.c)






