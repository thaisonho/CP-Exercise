// Bài 1 Đề thi HSG 12 Tin học TPHCM 2021

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 3;
    while(n > 0){
        i++;
        string str = to_string(i);
        n -= str.size();
    }
    cout << i;
}