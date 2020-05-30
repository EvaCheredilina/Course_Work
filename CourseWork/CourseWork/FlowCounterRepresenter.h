#pragma once
#include <fstream>
#include "List.h"
#include<string>
#include"Map.h"
using namespace std;

template<typename T>
T min(T a, T b) {
	return a > b ? b : a;
}

class FlowCounterRepresenter {
private:
	int* redundantFlow;
	int** edgesCapacity;
	int* height;
	int vertexCounter;
	int vertexFrom;
	int vertexTo;
	
protected:
	void pushFlow(int edge, int vertex)
	{
		int f = min(redundantFlow[edge], edgesCapacity[edge][vertex]);
		redundantFlow[edge] -= f;
		redundantFlow[vertex] += f;
		edgesCapacity[edge][vertex] -= f;
		edgesCapacity[vertex][edge] += f;
	}

	void edgeUpcoming(int edge)
	{
		int min = 2 * vertexCounter + 1;

		for (int i = 0; i < vertexCounter; i++)
			if (edgesCapacity[edge][i] && (height[i] < min))
				min = height[i];
		height[edge] = min + 1;
	}

	void pushingToLimit(int edge)
	{
		int vertex = 0;
		while (redundantFlow[edge] > 0)
		{
			if (edgesCapacity[edge][vertex] && height[edge] == height[vertex] + 1)
			{
				pushFlow(edge, vertex);
				vertex = 0;
				continue;
			}
			++vertex;
			if (vertex == vertexCounter)
			{
				edgeUpcoming(edge);
				vertex = 0;
			}
		}
	}

	void checkStringCorrectness(int currentStringNumber, string fullCurrentLineString)
	{
		if (!((fullCurrentLineString[0] >= 'A' && fullCurrentLineString[0] <= 'Z') && (fullCurrentLineString[1] == ' '))) {
			throw std::exception(string(("Error occuried while reading line " + to_string(currentStringNumber))).c_str());
		}
		if (!((fullCurrentLineString[2] >= 'A' && fullCurrentLineString[2] <= 'Z') && (fullCurrentLineString[3] == ' '))) {
			throw std::exception(string(("Error occuried while reading line " + to_string(currentStringNumber))).c_str());
		}
		string currentLineWithNoSpaces;
		for (int i = 4; i < fullCurrentLineString.size(); ++i) {
			if (fullCurrentLineString[i] >= '0' && fullCurrentLineString[i] <= '9')
				currentLineWithNoSpaces += fullCurrentLineString[i];
			else {
				throw std::exception(string(("Error occuried while reading line " + to_string(currentStringNumber))).c_str());
			}
		}
	}
public:
	int countMaxFlow() {
		if (vertexCounter > 2) {
			for (int i = 0; i < vertexCounter; i++)
			{
				if (i == vertexFrom)
					continue;
				redundantFlow[i] = edgesCapacity[vertexFrom][i];
				edgesCapacity[i][vertexFrom] += edgesCapacity[vertexFrom][i];
			}
			height[vertexFrom] = vertexCounter;
			List<int> temporaryList;
			int current;
			int currentIndex = 0;
			int oldHeight;
			for (int i = 0; i < vertexCounter; i++)
				if (i != vertexFrom && i != vertexTo)
					temporaryList.push_front(i);
			current = temporaryList.at(0);
			while (currentIndex < temporaryList.get_size())
			{
				oldHeight = height[current];
				pushingToLimit(current);
				if (height[current] != oldHeight)
				{
					temporaryList.push_front(current);
					temporaryList.remove(++currentIndex);
					current = temporaryList.at(0);
					currentIndex = 0;
				}
				++currentIndex;
				if (currentIndex < temporaryList.get_size())
					current = temporaryList.at(currentIndex);

			}
			if (redundantFlow[vertexTo] > 0)
				return redundantFlow[vertexTo];
			else
				throw std::exception("Can't reach sink vertex form source.");
		}
		else
			return edgesCapacity[0][1];
	}

	~FlowCounterRepresenter() {
		if(redundantFlow)
		delete[] redundantFlow;
		
		if(height)
		delete[] height;
		
		for(int i=0;i<vertexCounter;++i)
			delete[] edgesCapacity[i];
	}
	FlowCounterRepresenter(ifstream& file)
	{
		Map<char, int>* charToNumMap = new Map<char, int>();
		vertexCounter = 0;
		int currentStringNumber = 1;
		while (!file.eof()) {
			string fullCurrentLineString;
			getline(file, fullCurrentLineString);
			if (fullCurrentLineString.size() >= 5) {
				
				checkStringCorrectness(currentStringNumber, fullCurrentLineString);

				if (!charToNumMap->contains(fullCurrentLineString[0])) {
					charToNumMap->insert(fullCurrentLineString[0], vertexCounter);
					++vertexCounter;
				}
				if (!charToNumMap->contains(fullCurrentLineString[2])) {
					charToNumMap->insert(fullCurrentLineString[2], vertexCounter);
					++vertexCounter;
				}

			}
			else
			{
				throw std::exception(string(("Error occuried while reading line " + to_string(currentStringNumber))).c_str());
			}
			++currentStringNumber;
		}
		if (charToNumMap->contains('S'))
			vertexFrom = charToNumMap->find('S');
		else {
			throw std::exception("No source vertex");
		}

		if (charToNumMap->contains('T'))
			vertexTo = charToNumMap->find('T');
		else {
			throw std::exception("No sink vertex");
		}
		file.clear();
		file.seekg(ios::beg);
		redundantFlow = new int[vertexCounter];
		height = new int[vertexCounter];
		edgesCapacity = new int* [vertexCounter];
		for (int i = 0; i < vertexCounter; ++i) {
			redundantFlow[i] = 0;
			height[i] = 0;
		}
		for (int i = 0; i < vertexCounter; ++i) {
			edgesCapacity[i] = new int[vertexCounter];
			for (int j = 0; j < vertexCounter; ++j)
				edgesCapacity[i][j] = 0;
		}
		currentStringNumber = 1;
		while (!file.eof()) {
			string s1;
			int vert1, vert2, cap;
			getline(file, s1);
			vert1 = charToNumMap->find(s1[0]);
			vert2 = charToNumMap->find(s1[2]);
			if(vert1==vert2)
				throw std::exception(string("Error occuried while reading line "+to_string(currentStringNumber)).c_str());
			edgesCapacity[vert1][vert2] = stoi(s1.substr(4));
			++currentStringNumber;
		}
	}
};