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
std::thread second =move(first);
std::cout<<"\n Inside main()......";
if(first.joinable())
  first.join();
  
else if(second.joinable())
  second.join();
std::cout<<"\nfBoth Threads completed";

std::cout<<"\n main completed\n";

return 0;
}
