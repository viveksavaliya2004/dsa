#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;

        for (char ch : tasks)
            mp[ch]++;

        priority_queue<int> pq;

        for (auto &[ch, freq] : mp)
            pq.push(freq);

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int cycle = n + 1;
            int work = 0;

            while (cycle > 0 && !pq.empty()) {

                int freq = pq.top();
                pq.pop();

                freq--;
                work++;

                if (freq > 0)
                    temp.push_back(freq);

                cycle--;
            }

            for (int x : temp)
                pq.push(x);

            if (pq.empty())
                time += work;
            else
                time += n + 1;
        }

        return time;
    }
};