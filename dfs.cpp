#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs_has_path(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& current,
    const std::string& target,
    std::unordered_set<std::string>& visited
) {
    if (current == target) {
        return true;
    }

    visited.insert(current);

    for (const std::string& neighbor : graph.at(current)) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs_has_path(graph, neighbor, target, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool dfs_has_path_iterative(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& target
) {
    std::stack<std::string> s;
    std::unordered_set<std::string> visited;

    s.push(start);
    visited.insert(start);

    while (!s.empty()) {
        std::string current = s.top();
        s.pop();

        if (current == target) {
            return true;
        }

        for (const std::string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                s.push(neighbor);
            }
        }
    }
    return false;
}

bool dfs_has_path(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& target
) {
    std::unordered_set<std::string> visited;
    return dfs_has_path(graph, start, target, visited);
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph["A"] = {"B", "C"};
    graph["B"] = {"D"};
    graph["C"] = {"E"};
    graph["D"] = {};
    graph["E"] = {};

    std::cout << std::boolalpha;
    std::cout << "A -> E = " << dfs_has_path(graph, "A", "E") << '\n';
    std::cout << "B -> E = " << dfs_has_path(graph, "B", "E") << '\n';
    std::cout << "A -> A = " << dfs_has_path(graph, "A", "A") << '\n';
    std::cout << "iterative A -> E = " << dfs_has_path_iterative(graph, "A", "E") << '\n';
    std::cout << "iterative B -> E = " << dfs_has_path_iterative(graph, "B", "E") << '\n';
    std::cout << "iterative A -> A = " << dfs_has_path_iterative(graph, "A", "A") << '\n';

    return 0;
}
