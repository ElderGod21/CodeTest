#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

class solution{
public:
    int removeDuplicate(vector<int>& nums){
        set <int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int k = s.size();
        auto it = s.begin();

        for(int i=0;i<k;i++,++it){
            nums[i]=*it;
        }

        return k;

    }

};