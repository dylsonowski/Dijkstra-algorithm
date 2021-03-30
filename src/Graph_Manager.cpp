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
	connections = { std::make_pair("Kielce", 4), std::make_pair("Kraków", 2), std::make_pair("Łódź", 7) };
	_graph.insert({ "Katowice", connections });

	connections.clear();
	connections = { std::make_pair("Wrocław", 2), std::make_pair("Łódź", 7) };
	_graph.insert({ "Opole", connections });

	connections.clear();
	connections = { std::make_pair("Opole", 7), std::make_pair("Katowice", 7), std::make_pair("Warszawa", 6), std::make_pair("Bydgoszcz", 8), std::make_pair("Poznań", 8) };
	_graph.insert({ "Łódź", connections });

	connections.clear();
	connections = { std::make_pair("Łódź", 6), std::make_pair("Kielce", 6), std::make_pair("Lublin", 6), std::make_pair("Białystok", 10), std::make_pair("Gdańsk", 14), 
		std::make_pair("Bydgoszcz", 11) };
	_graph.insert({ "Warszawa", connections });

	connections.clear();
	connections = { std::make_pair("Warszawa", 10), std::make_pair("Olsztyn", 11) };
	_graph.insert({ "Białystok", connections });

	connections.clear();
	connections = { std::make_pair("Białystok", 11), std::make_pair("Gdańsk", 5) };
	_graph.insert({ "Olsztyn", connections });

	connections.clear();
	connections = { std::make_pair("Warszawa", 11), std::make_pair("Łódź", 8), std::make_pair("Poznań", 4), std::make_pair("Gdańsk", 8) };
	_graph.insert({ "Bydgoszcz", connections });

	connections.clear();
	connections = { std::make_pair("Bydgoszcz", 4), std::make_pair("Łódź", 8), std::make_pair("Wrocław", 7), std::make_pair("Zielona Góra", 4), std::make_pair("Koszalin", 8) };
	_graph.insert({ "Poznań", connections });

	connections.clear();
	connections = { std::make_pair("Opole", 2), std::make_pair("Poznań", 7) };
	_graph.insert({ "Wrocław", connections });

	connections.clear();
	connections = { std::make_pair("Szczecin", 8), std::make_pair("Poznań", 4) };
	_graph.insert({ "Zielona Góra", connections });

	connections.clear();
	connections = { std::make_pair("Zielona Góra", 8), std::make_pair("Koszalin", 7) };
	_graph.insert({ "Szczecin", connections });

	connections.clear();
	connections = { std::make_pair("Szczecin", 7), std::make_pair("Poznań", 8), std::make_pair("Gdańsk", 7) };
	_graph.insert({ "Koszalin", connections });

	connections.clear();
	connections = { std::make_pair("Koszalin", 7), std::make_pair("Bydgoszcz", 8), std::make_pair("Warszawa", 14), std::make_pair("Olsztyn", 5) };
	_graph.insert({ "Gdańsk", connections });
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
		system("clear");
	}
	else if (correctConnections)
		_graph.insert({ name, connections });
	else {
		std::cout << "Not existing connection!!\n";
		system("pause");
		system("clear");
	}
}

void Graph_Manager::DijkstraAlgorithm(std::optional<std::string> startPoint) {
	_graph.find(startPoint.value_or(_graph.begin()->first));
}
