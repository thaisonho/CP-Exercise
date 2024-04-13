// Link: https://vn.spoj.com/PTIT/problems/PTIT121K/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[102][102];
string f[102][102];

string binToHex(string binNum)
{
    string hexNum = "";
    while (binNum.length() % 4 != 0)
        binNum = "0" + binNum;
    for (int i = 0; i < binNum.length(); i += 4)
    {
        string tmp = binNum.substr(i, 4);
        // if else quằn quá :) cần cải tiến
        if (tmp == "0000")
            hexNum += "0";
        else if (tmp == "0001")
            hexNum += "1";
        else if (tmp == "0010")
            hexNum += "2";
        else if (tmp == "0011")
            hexNum += "3";
        else if (tmp == "0100")
            hexNum += "4";
        else if (tmp == "0101")
            hexNum += "5";
        else if (tmp == "0110")
            hexNum += "6";
        else if (tmp == "0111")
            hexNum += "7";
        else if (tmp == "1000")
            hexNum += "8";
        else if (tmp == "1001")
            hexNum += "9";
        else if (tmp == "1010")
            hexNum += "A";
        else if (tmp == "1011")
            hexNum += "B";
        else if (tmp == "1100")
            hexNum += "C";
        else if (tmp == "1101")
            hexNum += "D";
        else if (tmp == "1110")
            hexNum += "E";
        else
            hexNum += "F";
    }
    if (hexNum == "")
        return "0";
    else
    {
        while (1)
        {
            if (hexNum.length() - 1 == 0 || hexNum[0] != '0')
                break;
            else
                hexNum.erase(hexNum.begin(), hexNum.begin() + 1);
        }
    }
    return hexNum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];
    }
    for (int i = 0; i <= n; ++i)
        f[0][i] = f[i][0] = "";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + to_string(arr[i][j]);
    }
    cout << binToHex(f[n][n]);
}