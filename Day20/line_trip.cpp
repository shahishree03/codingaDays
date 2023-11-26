#include<iostream>
 
int main()
{
     int test_cases;
    std::cin>>test_cases;
    while(test_cases--)
    {
        int n, x, calculate_max=0, prev_value_i_have=0, store_diff=0;
        std::cin>>n>>x;
        
        while(n--)
        {
            int a;
            std::cin>>a;
            
            
            
                
                store_diff= a-prev_value_i_have;
                prev_value_i_have=a;
 
            
            //std::cout<<"\n store_diff "<<store_diff<<std::endl;
            if(calculate_max<store_diff)
            {
                calculate_max = store_diff;
                //std::cout<<"\n calculated_max: "<<calculate_max<<std::endl;
            }
            
            
        }
 
        store_diff=x-prev_value_i_have;
        store_diff=2*store_diff;
        //std::cout<<"\n store_diff "<<store_diff<<std::endl;
        if(calculate_max<store_diff)
            {
                calculate_max = store_diff;
               // std::cout<<"\n calculated_max: "<<calculate_max<<std::endl;
            }
        std::cout<<calculate_max<<std::endl;
    }
}
