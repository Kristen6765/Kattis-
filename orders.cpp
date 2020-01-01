
/**
 https://open.kattis.com/problems/virus
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//qsort
int compvar(const void *one, const void *two)
{
    int a = *((int*)one);
    int b = *((int*)two);
    if (a<b) return -1;
    if (a == b) return 0;
    return 1;

}

int main() {
    //stores the cost of items
    int num_iteams;
    cin >> num_iteams;
    vector<int> iteams(num_iteams);
    int max_valueC = -1;
    for (auto &i : iteams) {
        cin >> i;
        if (max_valueC < i)
            max_valueC = i;
    }

    //stores the cost of orders
    int num_order;
    cin >> num_order;
    int max_order = -1;
    vector<int> orders(num_order);
    for (auto &i : orders) {
        cin >> i;
        if (max_order < i)
            max_order = i;
    }

    //test the combination for all numbers and store in array
    //call the array "dictionary" so that we can check in the
    //"dictionary for its possible combination later
    vector<int> dictionary(max_order + max_valueC + 1, -2);
    dictionary[0] = 0;
    for (int i = 0; i < num_iteams; i++) {
        int cost = iteams[i];
        for (int j = 0; j <= max_order; j++) {
            if (dictionary[j] == -1) dictionary[j + cost] = -1;
            if (dictionary[j] >= 0) {
                if (dictionary[j + cost] != -2) dictionary[j + cost] = -1;
                else if (dictionary[j + cost] == -2) dictionary[j + cost] = i;
            }
        }
    }

    for (int k = 0; k < num_order; k++) {
        //-1, multiple combination exist, value set to -1 as enconuter second comb
        if (dictionary[orders[k]] == -1) {
            cout << "Ambiguous" << endl;
            continue;
        }else if (dictionary[orders[k]] == -2) {
            //if the slot that stores -2, then no viald combination exists
                   cout << "Impossible" << endl;
                   continue;
               }

        vector<int> comb;//calculate comb
        while (orders[k] > 0) {
            comb.push_back(dictionary[orders[k]]);
            orders[k] =orders[k]- iteams[dictionary[orders[k]]];
        }
    
        qsort(&comb[0], comb.size(), sizeof(int), compvar);
        
        for(int l=0;l< comb.size();l++){
            int c=comb[l];
            cout << c + 1 << " ";
        }

    }
}


