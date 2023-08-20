#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> current;

    for (auto p : progresses)
        current.push(p);

    while (!current.empty()) {
        for (int i = 0; i < current.size(); i++)
        {
            int p = current.front();
            current.pop();
            current.push(p + speeds.at(i));
        }
        int count = 0;

        while (true)
        {
            if (current.size() > 0 && current.front() >= 100)
            {
                current.pop();
                speeds.erase(speeds.begin());
                count++;
                continue;
            }

            break;
        }
        if (count > 0)
            answer.push_back(count);
    }
    return answer;
}