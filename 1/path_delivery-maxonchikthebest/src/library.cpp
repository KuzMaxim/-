#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdexcept>
#include <limits>

class Graph {
public:
    void add_edge(const std::string& from, const std::string& to, int cost) {
        adjacency_list[from][to] = cost;
        adjacency_list[to][from] = cost;
    }

    std::vector<std::string> find_shortest_path(const std::string& start, const std::string& end) {
        if (adjacency_list.find(start) == adjacency_list.end() || adjacency_list.find(end) == adjacency_list.end()) {
            throw std::invalid_argument("Both start and end cities must exist in the graph.");
        }

        std::unordered_map<std::string, int> distances;
        std::unordered_map<std::string, std::string> previous;
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

        for (const auto& pair : adjacency_list) {
            distances[pair.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [current_cost, current_city] = pq.top();
            pq.pop();

            if (current_city == end) {
                return reconstruct_path(previous, start, end);
            }

            if (current_cost > distances[current_city]) {
                continue;
            }

            for (const auto& neighbor : adjacency_list[current_city]) {
                const std::string& neighbor_city = neighbor.first;
                int edge_cost = neighbor.second;

                int new_cost = current_cost + edge_cost;

                if (new_cost < distances[neighbor_city]) {
                    distances[neighbor_city] = new_cost;
                    previous[neighbor_city] = current_city;
                    pq.emplace(new_cost, neighbor_city);
                }
            }
        }

        return {};
    }

private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> adjacency_list;

    std::vector<std::string> reconstruct_path(const std::unordered_map<std::string, std::string>& previous, const std::string& start, const std::string& end) {
        std::vector<std::string> path;
        for (std::string city = end; city != start; city = previous.at(city)) {
            path.push_back(city);
        }
        path.push_back(start);
        std::reverse(path.begin(), path.end());
        return path;
    }
};
