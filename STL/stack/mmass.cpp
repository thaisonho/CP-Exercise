// Link: https://oj.vnoi.info/problem/mmass

#include <iostream>
#include <stack>

using namespace std;

string compound;
stack<int> ele;

int main() {
    cin >> compound;
    int i = 0, size = compound.size();
    int tmpSum, totalSum = 0;
    while (i < size)
    {
        switch (compound[i])
        {
        case 'C':
            ele.push(12);
            break;
        case 'H':
            ele.push(1);
            break;
        case 'O':
            ele.push(16);
            break;
        case '(':
            ele.push(0);
            break;
        case ')':
            tmpSum = 0;
            while (ele.top() != 0) {
                tmpSum += ele.top();
                ele.pop();
            }
            ele.pop();
            ele.push(tmpSum);
            break;
        default:
            tmpSum = 0;
            tmpSum += ((int)compound[i] - '0');
            tmpSum *= ele.top();
            ele.pop();
            ele.push(tmpSum);
            break;
        }
        ++i;
    }

    while (!ele.empty())
    {
        totalSum += ele.top();
        ele.pop();
    }
    cout << totalSum;
}
