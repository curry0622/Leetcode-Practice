class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2 = dist1;
        int curr1 = node1, curr2 = node2, d;

        d = 0;
        dist1[node1] = 0;
        while(edges[curr1] != -1 && dist1[edges[curr1]] == -1) {
            d++;
            dist1[edges[curr1]] = d;
            curr1 = edges[curr1];
        }

        d = 0;
        dist2[node2] = 0;
        while(edges[curr2] != -1 && dist2[edges[curr2]] == -1) {
            d++;
            dist2[edges[curr2]] = d;
            curr2 = edges[curr2];
        }

        int min = INT_MAX, idx = -1;
        for(int i = 0; i < edges.size(); i++) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int max = std::max(dist1[i], dist2[i]);
                if(max < min) {
                    min = max;
                    idx = i;
                }
            }
        }

        return idx;
    }
};