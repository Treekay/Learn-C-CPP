 #include <iostream>
#include "Solution.hpp"
using namespace std;
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  vector<Interval> final;
  for (int i = 0; i < intervals.size(); ++i) {
   if (newInterval.start > intervals[i].end) {
    Interval t(intervals[i].start, intervals[i].end);
    final.push_back(t);
   }
   else if (newInterval.end < intervals[i].start) {
    final.push_back(newInterval);
    for ( ; i < intervals.size(); ++i) {
     Interval t(intervals[i].start, intervals[i].end);
      final.push_back(t);
    }
    return final;
   }
   else {
      newInterval.start = intervals[i].start > newInterval.start ? newInterval.start : intervals[i].start;
      newInterval.end = intervals[i].end < newInterval.end ? newInterval.end : intervals[i].end;
   }
  }
  final.push_back(newInterval);
  return final;
}