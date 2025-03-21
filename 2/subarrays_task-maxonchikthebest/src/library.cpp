#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include "library.hpp"


namespace template_library {
    int longest_duplicate_subarray(const std::vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 1;
        int result = 0;

        auto has_duplicate = [&](int length) {
            std::unordered_set<std::string> seen;
            for (int i = 0; i <= n - length; ++i) {
                std::stringstream str;
                for (int j = 0; j < length; ++j) {
                    str << nums[i + j];
                    if (j < length - 1) str << ",";
                }
                std::string subarray = str.str();
                if (seen.find(subarray) != seen.end()) {
                    return true;
                }
                seen.insert(subarray);
            }
            return false;
            };

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (has_duplicate(mid)) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return result;
    }
}
