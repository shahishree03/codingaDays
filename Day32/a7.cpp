#include<iostream>
#include<thread>

//g++ -std=c++20 -Wall -pthread a1.cpp


int main()
{
std::cout<<"Number of Threads ="<<std::thread::hardware_concurrency()<<std::endl;
}
