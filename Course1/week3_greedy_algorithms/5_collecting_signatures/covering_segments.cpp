#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool segmentCmp(Segment s1, Segment s2) {
    return s1.end < s2.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), segmentCmp);
  int n = segments.size();
  int i = 0;
  int current_point;
  while (i < n) {
      current_point = segments[i].end;
      points.push_back(current_point);
      while (i < n - 1 && current_point >= segments[i + 1].start) i++;
      i++;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
