#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int length, int subSize)
{
    deque<int> snapshot;
    
    for (int x = 0; x < length; x++)
    {
        if (!snapshot.empty() && snapshot.front() == (x - subSize))
            snapshot.pop_front();
        
        while(!snapshot.empty() && arr[snapshot.back()] < arr[x])
            snapshot.pop_back();
        
        snapshot.push_back(x);
        
        if (x >= subSize - 1)
            cout << arr[snapshot.front()] << " ";
    }
    cout << endl;
}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}
