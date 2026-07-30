#include<bits/stdc++.h>
using namespace std;

struct node{
    int a, b, c;
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    /*
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    */
   

    //n = arr.size();
    vector<node> ans;

    for (int k = 0; k < n-2 ;k++){//我们需要遍历所有的a
        //if (k > 0 && arr[k] == arr[k - 1]) continue;
        //int a = arr[k];

        int left = k + 1;
        int right = n - 1;
        while(right>left&&right>=0&&left<n){
            //int b = arr[left];
            //int c = arr[right];
            int sum = arr[k] + arr[left] + arr[right];
            if(sum==0){
                ans.push_back({arr[k], arr[left], arr[right]});
                int pre_l=left;
                int pre_r = right;
                while (left < n&&arr[left]==arr[pre_l]){
                    left++;
                    //b = arr[right];
                }
                while(right>k&&arr[right]==arr[pre_r]){
                    right--;
                    //c = arr[left];
                }
            }
            else if(sum>0){
                right--;
                //c = arr[right];
            }
            else{
                left++;
                //b = arr[left];
            }
        }
    }
    if(!ans.size()) cout<<"";
    else{
        for(auto t:ans){
            cout << t.a << " " << t.b << " " << t.c;
            cout << endl;
        }

    }
    return 0;
}
/*
- 主要就是要了解unique这个函数的鹅实现方式
*/