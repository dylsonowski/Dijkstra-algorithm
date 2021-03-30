#include <locale.h>
#include "Graph_Manager.h"

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "Polish");
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
	//graph.AddNode("Tarnowskie Góry", std::vector<std::pair<std::string, int>>({ std::make_pair("Berlin", 4) }));
	std::cout << graph;
	system("pause");
	return 0;
}