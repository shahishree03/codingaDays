#include<iostream>
#include<thread>

//g++ -std=c++20 -Wall -pthread a1.cpp
auto f= [](int x)
{
std::cout<<"\n Inside Lamda exp";
};
int main()
{
std::thread thread_object(f, 0);
std::cout<<"\n Inside main()......";
thread_object.join();

return 0;
}
