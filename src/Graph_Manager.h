#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <optional>
#include <sstream>
#include <limits>

struct Path_Data_Array;

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
	inline std::vector<Path_Data_Array> GetFullPathTable() const { return _fullPathTable; }
	std::string ToString() const {
		std::stringstream ss;
		unsigned int counter = 0;
		for (const auto& it : _graph) {
			counter++;
			ss << counter << ") " << it.first << "\n";
			for (const auto& vecIt : it.second) {
				ss << " -> (" << vecIt.first << ", " << vecIt.second << ");\n";
			}
			ss << "\n\n";
		}
		return ss.str();
	}

private:
	std::map<std::string, std::vector<std::pair<std::string, int>>> _graph;
	int _pathCost;
	std::vector<std::pair<std::string, int>> _shortestPath;
	std::vector<Path_Data_Array> _fullPathTable;
};

inline std::ostream& operator<<(std::ostream& os, const Graph_Manager& data) { return os << data.ToString(); }

struct Path_Data_Array {
	Path_Data_Array() = delete;
	Path_Data_Array(std::string name, int cost = std::numeric_limits<int>::max(), std::string transitionalNode = "") 
		: _node(name), _cost(cost), _transitionalNode(transitionalNode) {}

	std::string _node, _transitionalNode;
	int _cost;
};