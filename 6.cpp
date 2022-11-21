#include <bits/stdc++.h>
using namespace std;
bool deadlock(int start, int current, vector<vector<bool>> &depends, vector<bool> &visited, vector<int> &site)
{
     if (visited[current])
         return true;
         visited[current] = true;
         for (int i = 0; i < depends[current].size(); i++)
         {
             if (!depends[current][i])
                continue;
             if (i == current) 
                return true;
             if (site[current] != site[i])
             cout << "Probe is sent: (" << start + 1 << "," << current + 1 << "," << i + 1 << ")" << endl;
             return deadlock(start, i, depends, visited, site);

     }
     return false;
}
int main()
{
     int sites;
     vector<int> site;
     cout << "Enter number of sites: " << endl;
     cin >> sites;
     int total_no_of_events = 0;
     for (int i = 0; i < sites; i++)
     {
         int events;
         cout << "Enter number of events in site " << i + 1 << ": " << endl;
         cin >> events;
         for (int j = 0; j < events; j++)
             site.push_back(i);
         total_no_of_events += events;
     }
     cout << "So, we have " << sites << " sites and " << total_no_of_events << " events numbered " << endl;
     for (int i = 1; i <= total_no_of_events; i++)
        cout << i << " ";
     cout << endl;
     vector<vector<bool>> depends(total_no_of_events, vector<bool>(total_no_of_events, false));
     int m;
     cout << "Enter the no. of dependencies: " << endl;
     cin >> m;
     for (int i = 0; i < m; i++)
     {
         int a, b;
         cout << "Enter the Dependencies (If event 1 depends on event 2, enter 1 2):" << endl;
         cin >> a >> b;
         depends[a - 1][b - 1] = true;
     }
     cout << "Enter the Node to Start Probe: " << endl;
     int start;
     cin >> start;
     start--;
     vector<bool> visited(total_no_of_events, false);
     if (deadlock(start, start, depends, visited, site))
         cout << "A Deadlock exists" << endl;
     else
        cout << "No Deadlock doesn't exist" << endl;
     return 0;
}