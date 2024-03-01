#include<iostream>
#include<thread>

//g++ -std=c++20 -Wall -pthread a1.cpp

void foo()
{

std::cout<<"\n Inside the routine foo....";
}
void bar(int x)
{
std::cout<<"\n Inside the routine bar(int x).....";
std::cout<<x;
}

int main()
{
std::thread first(foo);
std::thread second(bar, 0);
std::cout<<"\n Inside main()......";
first.join();
second.join();
std::cout<<"\nfoo() and bar() completed";
std::cout<<"\n main completed";

return 0;
}
