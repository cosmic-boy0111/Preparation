// PrepBuddy is playing a card game for the first time and needs your help. Let us tell you rules of this card game. In a pack of 
// 52
//  cards, each card has a suit (Diamonds — D, Clubs — C, Spades — S, or Hearts — H), and a rank (2, 3, 4, 
// 5
// , 
// 6
// , 
// 7
// , 
// 8
// , 
// 9
// , 
// T
// , 
// J
// , 
// Q
// , 
// K
// ,or 
// A
// )
// . At the start of the game, there is one card on the table and all the players have five cards in their hand. A player can play a card from her/his hand if and only if it has the same rank or the same suit as the card on the table.
// It is PrepBuddy's turn, there is a card on the table and five cards in her hand. Can you find out if she can play atleast one card?

// Input
// First line contains an integer 
// T
// , denoting the number of test cases.
// Each test case consists of two lines. 
// First line denotes the card on the table. 
// Second line denotes five cards in the hands of the player.
// Each card is denoted by rank and suit. For example, 
// 2
// H
//  - 
// 2
//  is rank and 
// H
//  is suit.

// Output
// For each test case on a new line, print YES or NO depending on the above mentioned condition.

// Constraints
// 1
// <=
// T
// <=
// 20

// Time Limit
// 1
//  second

// Example
// Input
// 2
// AS
// 2H 4C TH JH AD
// 2H
// 3D 4C AC KD AS

// Output
// YES
// NO

#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        string table;
        cin >> table;
        bool check = false;
        for(int i=0;i<5;i++){
            string card;
            cin >> card;
            if(card[0]==table[0]  or card[1] == table[1]){
                check = true;
                break;
            }
        }

        if(check) cout << "YES" << endl;
        else cout << "NO"  << endl;
    }
    
    
    
    return 0;
}