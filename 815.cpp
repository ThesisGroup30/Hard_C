class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Create a map to store the list of routes that visit each stop
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                stopToRoutes[routes[i][j]].push_back(i);
            }
        }

        // Create a set to store the routes that we have taken so far
        unordered_set<int> takenRoutes;

        // Create a queue for BFS and add the source stop to it
        queue<int> q;
        q.push(source);

        // Keep track of the number of buses taken so far
        int buses = 0;

        while (!q.empty()) {
            buses++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                int currStop = q.front();
                q.pop();

                // Get the list of routes that visit the current stop
                vector<int> currRoutes = stopToRoutes[currStop];

                // Check if any of these routes goes to the target stop
                for (int j = 0; j < currRoutes.size(); j++) {
                    int currRoute = currRoutes[j];

                    if (takenRoutes.count(currRoute)) continue;

                    for (int k = 0; k < routes[currRoute].size(); k++) {
                        if (routes[currRoute][k] == target) return buses;

                        q.push(routes[currRoute][k]);
                    }

                    takenRoutes.insert(currRoute);
                }
            }
        }

        return -1;
    }
};
