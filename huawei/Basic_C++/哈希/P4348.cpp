#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> arr(26,0);
        string s1;
        cin >> s1;
        
        for(char ch:s1){
            arr[ch - 'a']++;
        }
        for (int i = 1; i < n;i++){
            string s2;
            cin >> s2;
            vector<int> arr1(26,0);
            
            for(char ch:s2){
                arr1[ch - 'a']++;
            }
            for (int j = 0; j < 26;j++){
                int num = min(arr[j], arr1[j]);
                arr[j] = num;
            }
        }

        string ans ;
        bool flag = false;
        for (int i = 0; i < 26;i++){
            if(arr[i]>0){
                ans.append(arr[i], 'a' + i);
                flag = true;
            }
            
        }
        if(flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    
    return 0;
}