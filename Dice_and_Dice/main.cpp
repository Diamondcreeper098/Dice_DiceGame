#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <random>
#include <cstring>
#include <algorithm>

using namespace std;

std::vector<std::string> split(const std::string& s, char delimiter)//splitter
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int roll_dice(const char* eq){
    vector<string> a;
    vector<int> dices;
    int sum;
    if(strstr(eq,"d") != NULL){
        a = split(eq,'d');
        int b = stoi(a[0]);
        int c = stoi(a[1]);
        if(c == 1){
            return -2; //Are you insane. dice with 1 face is impossible
        }
        for (int i = 0; i < b; ++i) {
            int tmp = (rand() % c) + 1;
            dices.insert(dices.end(),tmp);
        }
        int i = 1;
        for (auto &&item : dices) {
            printf("dice %d is %d \n",i,item);
            sum += item;
            ++i;

        }
        return sum;
    }
    else{
        return -1;//Incorrect syntax. syntax is number1dnuber2. d should be included
    }
    return 0;
}

int main() {
    srand(time(0));

    string ae;
    printf("Input your Command(dices d faces): ");
    std::getline(cin, ae);
    ae.erase(remove(ae.begin(),ae.end(),' '),ae.end());
    int a = roll_dice(ae.c_str());
    vector<string> af = split(ae.c_str(),'d');
    if(a > 0){
        printf("Sum of %s dices with %s faces is %d \n",af[0].c_str(),af[1].c_str(),a);
    }
    else if(a == -2){
        printf("Are you insane. dice with 1 face is impossible");
    }
    else{
        printf("Syntax of %s is incorrect \n",ae.c_str());
    }
    return 0;
}