#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

class selectionSort
{
    
public:
    void static sort1(int arr[], int n)
    {
        for(int i = 0 ; i < n ; i ++)
        {
            // 寻找[i, n)区间里的最小值
            int minIndex = i;
            for( int j = i + 1 ; j < n ; j ++ )
                if( arr[j] < arr[minIndex] )
                    minIndex = j;
            
            swap( arr[i] , arr[minIndex] );
        }
    }
};


void sort1TestCase()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    cout << "排序前的数组" << endl;
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
    
    cout << "排序好的数组" << endl;
    selectionSort::sort1(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
}