/*
 * Problem Name : D. Creating a Schedule
 * Problem Link : https://codeforces.com/contest/2111/problem/D
 * Video solution link : 
 * Write here if video solution doesn't exist : icodencode@gmail.com
 * Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Extracts floor number from classroom number
int get_floor(int classroom) {
    return classroom / 100;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int total_needed = n * 6;
        vector<int> classrooms(m);
        for (int i = 0; i < m; ++i)
            cin >> classrooms[i];

        sort(classrooms.begin(), classrooms.end(), [](int a, int b) {
            return get_floor(a) < get_floor(b);
        });

        vector<vector<int>> schedule(n, vector<int>(6));
        int left = 0, right = m-1;

        for (int i = 1; i < n; i+=2) {
        	schedule[i  ][0] = classrooms[left++];
            schedule[i-1][0] = classrooms[right--];
        }
        
        for(int k=1; k<6; k++) {
        	for(int i=1; i<n; i+=2) {
        		schedule[i  ][k] = schedule[i-1][k-1];
            	schedule[i-1][k] = schedule[i  ][k-1];
			}
		}
		
		if(n & 1) {
			for(int k=0; k<6; k++) {
				if(k & 1)
				schedule[n-1][k] = classrooms[left];
				else
				schedule[n-1][k] = classrooms[right];
			}
		}

        for (int i = 0; i < n; ++i) {
        	for (int k = 0; k < 6; ++k) {
        		cout << schedule[i][k] << " ";
	        }
            cout << '\n';
        }
        
    }

    return 0;
}
