#include <map>

class MyCalendarThree {
private:
    std::map<int, int> timeline; // Map to store the timeline of events

public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        timeline[startTime]++; // Increment the count at the start time
        timeline[endTime]--; // Decrement the count at the end time

        int maxBooking = 0;
        int ongoingBooking = 0;

        for (const auto& [time, count] : timeline) {
            ongoingBooking += count; // Update the ongoing booking count
            maxBooking = std::max(maxBooking, ongoingBooking); // Update the maximum booking count
        }

        return maxBooking;
    }
};
