//https://codefun2000.com/p/P4532

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int a;
    int b;
    int c;
    int p;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    vector<Node> phones;
    int a2=0,b2=0,c2=0,p2=0;
    phones.push_back({a2, b2, c2, p2});
    for (int i = 0; i < K;i++){
        int a1,b1,c1,p1;
        cin >> a1 >> b1 >> c1 >> p1;
        phones.push_back({a1, b1, c1, p1});
    }

    int N;
    cin >> N;
    vector<Node> predicts;
    for (int i = 0; i < N;i++){
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        int p1 = 0;
        predicts.push_back({a1, b1, c1,p1});
    }

    vector<vector<double>> arr1(5, vector<double>(K + 1, 0));
    vector<vector<double>> arr2(K+1,vector<double>(5,0));
    vector<vector<double>> arrA(5,vector<double>(6,0));
    //这里不仅仅是用来表示矩阵A还要用来表示后面的增广矩阵

    // 4*K;
    for (int i = 1; i <= 4;i++){
        for (int j = 1; j <= K;j++){
            if(i==1)
                arr1[i][j] = 1;
            if(i==2)
                arr1[i][j] = phones[j].a;
            if(i==3)
                arr1[i][j] = phones[j].b;
            if(i==4)
                arr1[i][j] = phones[j].c;
        }
    }

    //K*4
    for (int i = 1; i <= K;i++){
        for (int j = 1; j <= 4;j++){
            if(j==1)
                arr2[i][j] = 1;
            if(j==2)
                arr2[i][j] = phones[i].a;
            if(j==3)
                arr2[i][j] = phones[i].b;
            if(j==4)
                arr2[i][j] = phones[i].c;
            
        }
    }
    
    //4*4
    //得出的是A（在添加赠官矩阵之前的矩阵A）
    for (int i = 1; i <= 4;i++){
        for (int j = 1; j <= 4;j++){
            for (int m = 1; m <= K;m++){
                arrA[i][j] += arr1[i][m] * arr2[m][j];
            }
        }
    }

    vector<double> arrP(K + 1, 0);
    for (int i = 1; i <= K;i++){
        arrP[i] = phones[i].p;
    }

    // Y=1*4
    // 在原有矩阵的后面添加增广矩阵
    vector<double> arrB(5,0);
    for (int i = 1; i <= 4;i++){
        for (int j = 1; j <= K;j++){
            arrB[i] += arr1[i][j] * arrP[j];
        }
    }
    
    //将增广矩阵添加到arrA中
    for (int i = 1; i <= 4;i++){
        arrA[i][5] = arrB[i];
    }

    //高斯消元
    for (int i = 1; i <= 4;i++){
        double pivot = arrA[i][i];
        for (int j = i; j <= 5;j++)
            arrA[i][j] /= pivot;
        for (int k = 1; k <= 4;k++){
            if(k!=i){
                double factor = arrA[k][i];
                for (int j = i; j <= 5;j++){
                    arrA[k][j] -= factor * arrA[i][j];
                }
            }
        }
    }

    vector<double> W(5, 0);
    for (int i = 1; i <= 4;i++){
        W[i] = arrA[i][5];
    }

    for (int i = 0; i < N; i++)
    {
        double price = W[1] + W[2] * predicts[i].a + W[3] * predicts[i].b + W[4] * predicts[i].c;
        int p = llround(price);
        cout << p << " ";
    }
    return 0;
}

/*
我们是有K个向量
使用的是矩阵的乘法将所有的向量结合到一起
*/