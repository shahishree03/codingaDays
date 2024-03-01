#include<iostream>
#include<thread>
//callable thread object
//g++ -std=c++20 -Wall -pthread a1.cpp
class thread_obj{
public:

void operator()(int x)
{

for(int i=0;i<x;i++)
{
 std::cout<<"Thread using function objet callanoe\n";
}
}
};
int main()
{
std::thread thread1(thread_obj(), 3);
std::cout<<"\n Inside main()......";
thread1.join();

return 0;
}
