#include<iostream>
using namespace std;
int main() {
    char st[] = "CodingNinjas";
    for(int i = 0; st[i]; i++) 
        cout << st[i] << *(st+i) << *(i+st) << i[st] << endl;
    return 0;
}

