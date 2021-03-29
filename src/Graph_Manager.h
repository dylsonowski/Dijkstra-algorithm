#pragma once
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <optional>

class Graph_Manager {

public:
	Graph_Manager();
	~Graph_Manager() = default;

	void AddNode(std::string name, std::vector<std::pair<std::string, int>> connections);
	void RemoveNode(std::string name) { _graph.erase(name); }

	void DijkstraAlgorithm(std::optional<std::string> startPoint);
	void DijkstraAlgorithm(std::optional<std::string> startPoint, std::optional<std::string> endPoint);

	inline std::vector<std::pair<std::string, int>> GetCity(std::string name) const { return _graph.at(name); }
	inline std::pair<int, std::vector<std::pair<std::string, int>>> GetFinalResult() const { return std::make_pair(_pathCost, _shortestPath); }

private:
	std::map<std::string, std::vector<std::pair<std::string, int>>> _graph;
	int _pathCost;
	std::vector<std::pair<std::string, int>> _shortestPath;
};