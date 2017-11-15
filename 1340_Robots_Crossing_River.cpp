#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

/*
a->b 2/1 0
b->c 4/2 2
1. Each boat can take 20 robots at most.

2. On each boat if there are more than 15 robots, no single kind of robots can exceed 50% of the total amount of robots on that boat.

3. At most 35 robots are allowed to be stranded at B. If a robot goes on his journey to C as soon as he arrives at B he is not considered stranded at B.

Given the number of three kinds robots what is the minimum hours to take them from A to C? 
*/
//as we kan see the a->b and b->c is just 2times and the bottleneck is the b->c
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);// use this to qsort
}

int main()
{
    int num[3];
    int ans=0;
    cin>>num[0]>>num[1]>>num[2];
    if(num[0]+num[1]>=num[2])
    {
        ans=ceil((num[0]+num[1]+num[2])/20);
    }
    else
    {
        while(num[2] >= 10 && num[1] >= 10)
        {
            ++ans;
            num[2] -= 10;
            num[1] -= 10;
            qsort(num, 3, sizeof(num[0]), cmp);
        }
        if(num[2] >= 10)
        {
            if( num[1] + num[0] >= 10 )
            {
                num[2] -= 10;
                num[1] -= (10 - num[0]);
                num[0] = 0;//move all the num[0]
                ++ans;
            }else 
            {
                if(num[1] + num[0] >= 8)
                {
                    num[2] -= ( num[1] + num[0] );
                    num[1] = num[0] = 0;
                    ++ans; 
                }
            }
            ans += ( num[2] + num[1] + num[0] ) / 15;
            if( ( num[2] + num[1] + num[0] )%15 != 0 )
            {
                ++ans;
            }
            
        }
    }
    ans = 4 * ans + 2*(ans - 1) + 2;
    cout<<ans;
    getchar();
    return 0;
}

