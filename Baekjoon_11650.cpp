// This code employs a randomized pivot.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<pair<int, int>> vec;

int partition(vector<pair<int, int>>& arr, int low, int high) {

    int i = low;
    int j = high + 1;

    int randomNumber = rand() % (high - low);

    swap(arr[low], arr[randomNumber + low]);
    pair<int, int>& pivot = arr[low];

    do {
        do
        {
            i++;
        } while (i <= high && arr[i] < pivot);

        do
        {
            j--;
        } while (j >= low && arr[j] > pivot);

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }

    } while (i < j);

    swap(arr[low], arr[j]);

    return j;
}

void quicksort(vector<pair<int, int>>& arr, int low, int high) {
    if (low < high) {
        int pivotindex = partition(arr, low, high);
        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex + 1, high);
    }
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    quicksort(vec, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++)
    {
        cout << vec[i].first << ' ' << vec[i].second << '\n';  // Access the pair elements using vec[i].first and vec[i].second
    }

    return 0;
}
