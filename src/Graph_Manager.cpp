#include <algorithm>
#include "Graph_Manager.h"

Graph_Manager::Graph_Manager() : _pathCost(0) {
	std::vector<std::pair<std::string, int>> connections = { std::make_pair("Katowice", 2), std::make_pair("Kielce", 3), std::make_pair("Rzeszów", 5) };
	_graph.insert({ "Kraków", connections});

	connections.clear();
	connections = { std::make_pair("Kraków", 5), std::make_pair("Lublin", 4) };
	_graph.insert({ "Rzeszów", connections });

	connections.clear();
	connections = { std::make_pair("Rzeszów", 4), std::make_pair("Kielce", 6), std::make_pair("Warszawa", 6) };
	_graph.insert({ "Lublin", connections });

	connections.clear();
	connections = { std::make_pair("Lublin", 6), std::make_pair("Kraków", 3), std::make_pair("Warszawa", 6), std::make_pair("Katowice", 4) };
	_graph.insert({ "Kielce", connections });

	connections.clear();
	connections = { std::make_pair("Kielce", 4), std::make_pair("Kraków", 2), std::make_pair("£ódŸ", 7) };
	_graph.insert({ "Katowice", connections });

	connections.clear();
	connections = { std::make_pair("Wroc³aw", 2), std::make_pair("£ódŸ", 7) };
	_graph.insert({ "Opole", connections });

	connections.clear();
	connections = { std::make_pair("Opole", 7), std::make_pair("Katowice", 7), std::make_pair("Warszawa", 6), std::make_pair("Bydgoszcz", 8), std::make_pair("Poznañ", 8) };
	_graph.insert({ "£ódŸ", connections });

	connections.clear();
	connections = { std::make_pair("£ódŸ", 6), std::make_pair("Kielce", 6), std::make_pair("Lublin", 6), std::make_pair("Bia³ystok", 10), std::make_pair("Gdañsk", 14), 
		std::make_pair("Bydgoszcz", 11) };
	_graph.insert({ "Warszawa", connections });

	connections.clear();
	connections = { std::make_pair("Warszawa", 10), std::make_pair("Olsztyn", 11) };
	_graph.insert({ "Bia³ystok", connections });

	connections.clear();
	connections = { std::make_pair("Bia³ystok", 11), std::make_pair("Gdañsk", 5) };
	_graph.insert({ "Olsztyn", connections });

	connections.clear();
	connections = { std::make_pair("Warszawa", 11), std::make_pair("£ódŸ", 8), std::make_pair("Poznañ", 4), std::make_pair("Gdañsk", 8) };
	_graph.insert({ "Bydgoszcz", connections });

	connections.clear();
	connections = { std::make_pair("Bydgoszcz", 4), std::make_pair("£ódŸ", 8), std::make_pair("Wroc³aw", 7), std::make_pair("Zielona Góra", 4), std::make_pair("Koszalin", 8) };
	_graph.insert({ "Poznañ", connections });

	connections.clear();
	connections = { std::make_pair("Opole", 2), std::make_pair("Poznañ", 7) };
	_graph.insert({ "Wroc³aw", connections });

	connections.clear();
	connections = { std::make_pair("Szczecin", 8), std::make_pair("Poznañ", 4) };
	_graph.insert({ "Zielona Góra", connections });

	connections.clear();
	connections = { std::make_pair("Zielona Góra", 8), std::make_pair("Koszalin", 7) };
	_graph.insert({ "Szczecin", connections });

	connections.clear();
	connections = { std::make_pair("Szczecin", 7), std::make_pair("Poznañ", 8), std::make_pair("Gdañsk", 7) };
	_graph.insert({ "Koszalin", connections });

	connections.clear();
	connections = { std::make_pair("Koszalin", 7), std::make_pair("Bydgoszcz", 8), std::make_pair("Warszawa", 14), std::make_pair("Olsztyn", 5) };
	_graph.insert({ "Gdañsk", connections });
}

void Graph_Manager::AddNode(std::string name, std::vector<std::pair<std::string, int>> connections) {
	bool correctConnections = true;
	for (const auto& it : connections) {
		if (_graph.find(it.first) == _graph.end())
			correctConnections = false;
	}

	if (_graph.find(name) != _graph.end()) {
		std::cout << "This node already exist!!\n";
		system("pause");
	}
	else if (correctConnections)
		_graph.insert({ name, connections });
	else {
		std::cout << "Not existing connection!!\n";
		system("pause");
	}
}

void Graph_Manager::DijkstraAlgorithm(std::optional<std::string> startPoint) {
	if (_graph.find(startPoint.value_or(_graph.begin()->first)) != _graph.end()) {
		std::vector<std::string> visitedNodes;
		for (const auto& it : _graph) {
			if (it.first == startPoint.value_or(_graph.begin()->first))
				_fullPathTable.emplace_back(Path_Data_Array(it.first, 0));
			else
				_fullPathTable.emplace_back(Path_Data_Array(it.first));
		}
	
		//std::map<std::string, std::vector<std::pair<std::string, int>>>::iterator examinatedNode;
		do {
			auto examinatedNode = std::min_element(_fullPathTable.begin(), _fullPathTable.end(), [&](Path_Data_Array row1, Path_Data_Array row2) {
				return row1._cost < row2._cost && std::find(visitedNodes.begin(), visitedNodes.end(), row1._node) == visitedNodes.end() &&
					std::find(visitedNodes.begin(), visitedNodes.end(), row2._node) == visitedNodes.end(); });
			//auto examinatedNode = _graph.at(examinatedNodeName);
			for (const auto& it : _graph.at(examinatedNode->_node)) {
				auto secondNode = std::find_if(_fullPathTable.begin(), _fullPathTable.end(), [&](Path_Data_Array row) {return row._node == it.first; });
				if (examinatedNode->_cost + it.second < secondNode->_cost) {
					secondNode->_cost = examinatedNode->_cost + it.second;
					secondNode->_transitionalNode = examinatedNode->_node;
				}
			}
			visitedNodes.push_back(examinatedNode->_node);
		} while (visitedNodes.size() <= _graph.size());
	}
	else {
		std::cout << "Incorrect starting point!!\n";
		system("pause");
	}
}

void Graph_Manager::DijkstraAlgorithm(std::optional<std::string> startPoint, std::optional<std::string> endPoint) {
	DijkstraAlgorithm(startPoint.value_or(_graph.begin()->first));
	auto endNode = std::find_if(_fullPathTable.begin(), _fullPathTable.end(), [&](Path_Data_Array row) {return row._node == endPoint.value_or(_graph.begin()->first); });
	auto transitionNode = _graph.at(endNode->_transitionalNode);
	/*_shortestPath.push_back(std::make_pair(endNode->_node, std::find_if(transitionNode.begin(), transitionNode.end(), [&](std::pair<std::string, int> row) {
		return row.first == endNode->_node; })->second));*/
	_pathCost = endNode->_cost;

	do {
		std::string prewIterationNode = endNode->_node;
		endNode = std::find_if(_fullPathTable.begin(), _fullPathTable.end(), [&](Path_Data_Array row) { return row._node == endNode->_transitionalNode; });
		transitionNode = _graph.at(endNode->_node);
		_shortestPath.push_back(std::make_pair(prewIterationNode, std::find_if(transitionNode.begin(), transitionNode.end(), [&](std::pair<std::string, int> row) {
			return row.first == prewIterationNode; })->second));
	} while (endNode->_node != startPoint.value_or(_graph.begin()->first));

	_shortestPath.push_back(std::make_pair(startPoint.value_or(_graph.begin()->first), std::find_if(_fullPathTable.begin(), _fullPathTable.end(), [&](Path_Data_Array row) {
		return row._node == startPoint.value_or(_graph.begin()->first); })->_cost));
}
