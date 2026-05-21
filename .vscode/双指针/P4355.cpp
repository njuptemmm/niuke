#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n >> m;
    vector<char> arr(n,0);
    for (int i = 0; i < n;i++){
        char num;
        cin >> num;
        arr[i] = num;
    }
    vector<vector<int>> link(26, vector<int>(26,0));
    for (int i = 0; i < m;i++){
        char a, b;
        cin >> a >> b;
        link[a - 'A'][b - 'A'] = 1;
        link[b - 'A'][a - 'A'] = 1;
    }

    int left = 0;
    int count = 0;
    vector<int> last(26, -1);//last:表示上一次出现的字母的位置
    //right:表示在以right为结尾的部分中有多少是和谐的
    for (int right = 0; right < n;right++){
        char ch=arr[right];
        //判断是否存在与其不和谐的字母
        //找出和谐的最长子串
        for (int i = 0; i < 26;i++){
            if(link[ch-'A'][i]==1&&last[i]>=left){
                left = max(left, last[i]+1);
            }
        }
        count += (right - left + 1);//以right为结尾的部分中有多少是和谐的
        last[ch - 'A'] = right;
    }
    cout << count << endl;
    return 0;
}