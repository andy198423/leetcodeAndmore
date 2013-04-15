/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct startcom{
	    bool operator()(Interval a, Interval b){return (a.start<b.start);}
	} start_compare;
	
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.size()<2) return intervals;
		sort(intervals.begin(),intervals.end(),start_compare);
		vector<Interval> result;
		vector<Interval>::iterator it=intervals.begin();
		Interval cur;
		while(it!=intervals.end()){
		  if(it==intervals.begin()){
		    cur=*it;
		  }
		  else if((*it).start<=cur.end) cur.end=((*it).end>cur.end) ? (*it).end : cur.end;
		  else if(((*it).start)>cur.end){
		     result.push_back(cur);
			 cur=*it;
		  }
		  it++;
		}
		result.push_back(cur); // dont forget to push the last current interval
		return result;
    }
};