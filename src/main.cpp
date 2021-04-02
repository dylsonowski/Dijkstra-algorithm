#include <locale.h>
#include "Graph_Manager.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	std::string startPoint, endPoint;
	if (argc > 1) {
		for (int it = 0; it < argc; it++) {
			if (static_cast<std::string>(argv[it]) == "-s")
				startPoint = static_cast<std::string>(argv[it + 1]);

			if (static_cast<std::string>(argv[it]) == "-e")
				endPoint = static_cast<std::string>(argv[it + 1]);
		}
	}

	Graph_Manager graph;
	graph.DijkstraAlgorithm(startPoint, endPoint);
	std::vector<Path_Data_Array> result = graph.GetFullPathTable();
	std::pair<int, std::vector<std::pair<std::string, int>>> result2 = graph.GetFinalResult();
	//std::cout << graph;
	for (int it = result2.second.size() - 1; it >= 0; it--) {
		if(it == 0)
			std::cout << "(" << result2.second.at(it).first << ", " << result2.second.at(it).second << ") Cost: " << result2.first << "\n";
		else
			std::cout << "(" << result2.second.at(it).first << ", " << result2.second.at(it).second << ") -> ";
	}
	system("pause");
	return 0;
}