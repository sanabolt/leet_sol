class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leaders;

    TopVotedCandidate(vector<int>& persons, vector<int>& t) {
        times = t;

        unordered_map<int, int> count;
        int leader = -1;

        for (int i = 0; i < persons.size(); i++) {
            count[persons[i]]++;

            // >= is important because latest vote wins in a tie
            if (count[persons[i]] >= count[leader]) {
                leader = persons[i];
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int left = 0;
        int right = times.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (times[mid] <= t) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        // right = last index where times[right] <= t
        return leaders[right];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */