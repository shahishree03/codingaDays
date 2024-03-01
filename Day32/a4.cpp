#include<iostream>
#include<thread>

//g++ -std=c++20 -Wall -pthread a1.cpp

void foo()
{

std::cout<<"\n Inside the routine foo....";
}


int main()
{
std::thread first(foo);

std::cout<<"\n Inside main()......";
first.detach();
if(first.joinable())
  first.join();
std::cout<<"\nfoo() completed";
std::cout<<"\n main completed";

return 0;
}
