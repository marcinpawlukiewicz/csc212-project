#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Graph {
private:
	std::vector<std::vector<double>> dataPoints;
	std::vector<sf::Color> colors;
	
	sf::Vector2f xSize;
	sf::Vector2f ySize;
	int limit = 0;
	int Velocity = 0;
	
	bool small = false;
	bool medium = false;
	bool large = false;
	bool arrayDone = false;

	sf::Vertex counting;
	sf::Vertex insertion;
	sf::Vertex quicksort;
	sf::Vertex mergesort;


	sf::Font aovel_sans;
	sf::RectangleShape xAxis;
	sf::RectangleShape yAxis;

	sf::Text graphLabel, horizontalAxis, verticalAxis, origin;

public: 
	int dataSet;
	std::vector<sf::Vertex> line;
	Graph(std::string headline, sf::Font &font);
	~Graph();
	void addPoints(std::vector<std::vector<double>> data);
	void drawSmall(int xPosition);
	void drawMedium(int xPosition);
	void drawLarge();
	void draw(sf::RenderTarget& window);
	void setHorizontal(std::string headline);
	void setVertical(std::string headline);
	void drawAlgorithms(sf::RenderTarget& window, int length);


};
#endif // !GRAPH_H