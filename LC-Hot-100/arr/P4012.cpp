#include<bits/stdc++.h>
using namespace std;

struct node{
    int a, b;
};

int main(){
    int n;
    cin >> n;
    vector<node> arr;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    auto cmp = [](node &s, node &t) {
       if(s.a==t.a){
           return s.b > t.b;
       }
       return s.a < t.a;
    };

    sort(arr.begin(), arr.end(),cmp);
    vector<node> ans;

    int left = 0;
    int right = 0;
    for (int i = 0; i < n;i++){
        if(i==0){
            left = arr[i].a;
            right = arr[i].b;
        }
        else{
            if(right>=arr[i].a){
                right = max(right, arr[i].b);
                left = min(left, arr[i].a);
            }
            else{
                ans.push_back({left, right});
                left = arr[i].a;
                right = arr[i].b;
            }
        }
    }
    ans.push_back({left, right});

    for(auto op:ans){
        cout << op.a << " " << op.b << endl;
    }

    return 0;
}