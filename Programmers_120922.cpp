#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(int M, int N) 
{
  int answer = 0;
  answer += ((M - 1) + (N - 1) * M);
  cout << answer;
}

int main() {
  solution(2, 2);
  return 0;
}