#include <vector>
#include <deque>
#include "library.hpp"

namespace template_library {
    int josephus_problem(const std::vector<int>& nums, int K) {
        std::deque<int> dq(nums.begin(), nums.end());

        int index = 0;

        while (dq.size() > 1) {
            index += 1;
            if (index == K) {
                dq.pop_front();
                index = 0;
            }
            else {
                int frontElement = dq.front();
                dq.pop_front();
                dq.push_back(frontElement);
            }
        }
        return dq.front();
    }
}
