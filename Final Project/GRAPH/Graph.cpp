#include "Graph.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <string> 


Graph::Graph(std::string headline, sf::Font &font) {

	aovel_sans = font;
	graphLabel.setFont(font);
	horizontalAxis = verticalAxis = graphLabel;

	sf::String word = headline;
	sf::Color countingColor = sf::Color(215, 215, 0);
	sf::Color insertionColor = sf::Color(144, 238, 144);
	sf::Color quicksortColor = sf::Color(255, 255, 0);
	sf::Color mergesortColor = sf::Color(255, 192, 203);

	

	colors.push_back(countingColor);
	colors.push_back(insertionColor);
	colors.push_back(quicksortColor);
	colors.push_back(mergesortColor);

	graphLabel.setString(word);
	graphLabel.setFillColor(sf::Color::Red);
}

Graph::~Graph(){

}

void Graph::addPoints(std::vector<std::vector<double>> data){

	dataPoints = data;
}

//prepares the graph to be drawn in a smaller format at one of either 3-4 positions
void Graph::drawSmall(int xPosition) {
	limit = 0;
	Velocity = 10;
	sf::Vector2f rectSize(3, 3);
	this->xSize = rectSize;
	this->ySize = rectSize;
	xAxis.setSize(rectSize);
	yAxis.setSize(rectSize);

	graphLabel.setCharacterSize(20);
	horizontalAxis.setCharacterSize(20);
	verticalAxis.setCharacterSize(20);

	sf::Vector2f setPosition(0, 500);

	

	if (xPosition >= 2) {

		xPosition == 3 ? setPosition.x = 950, setPosition.y = 950 : setPosition.x = 250, setPosition.y = 950;
	}
	else {
		xPosition == 1 ? setPosition.x = 740 : setPosition.x = 80;
	}

	graphLabel.setPosition(setPosition.x + 390 / 2, setPosition.y - 410);
	//verticalAxis.setPosition(setPosition.x , setPosition.y - 410);
	horizontalAxis.setPosition(setPosition.x + 390 , setPosition.y + 30);
	xAxis.setPosition(setPosition);
	yAxis.setPosition(setPosition);

	origin = horizontalAxis;

	origin.setString("0");
	origin.setPosition(setPosition.x - 10, setPosition.y + 10);

	small = true;
	medium = false;
	large = false;
	arrayDone = false;
}

//prepares the graph to be drawn in a medium-sized format at one of 2 positions
void Graph::drawMedium(int xPosition) {
	limit = 0;
	Velocity = 10;
	sf::Vector2f rectSize(3, 3);
	this->xSize = rectSize;
	this->ySize = rectSize;
	xAxis.setSize(rectSize);
	yAxis.setSize(rectSize);

	graphLabel.setCharacterSize(30);
	horizontalAxis.setCharacterSize(30);
	verticalAxis.setCharacterSize(30);

	sf::Vector2f setPosition(0, 900);
	
	xPosition == 1 ? setPosition.x = 840 : setPosition.x = 80;

	graphLabel.setPosition(setPosition.x + 530 / 2, setPosition.y - 650);
	verticalAxis.setPosition(setPosition.x - 30, setPosition.y - 600);
	horizontalAxis.setPosition(setPosition.x, setPosition.y + 10);

	xAxis.setPosition(setPosition);
	yAxis.setPosition(setPosition);

	origin = horizontalAxis;

	origin.setString("0");
	origin.setPosition(setPosition.x - 10, setPosition.y + 10);

	medium = true;
	small = false;
	large = false;
	arrayDone = false;
	}

void Graph::drawLarge() {
	limit = 0;
	Velocity = 10;
	sf::Vector2f rectSize(3, 3);
	this->xSize = rectSize;
	this->ySize = rectSize;
	xAxis.setSize(rectSize);
	yAxis.setSize(rectSize);

	graphLabel.setCharacterSize(40);
	horizontalAxis.setCharacterSize(40);
	verticalAxis.setCharacterSize(40);


	sf::Vector2f setPosition(130, 980);

	graphLabel.setPosition(setPosition.x + 1830 / 2, setPosition.y - 850);
	verticalAxis.setPosition(setPosition.x - 30, setPosition.y - 600);
	horizontalAxis.setPosition(setPosition.x, setPosition.y + 10);

	xAxis.setPosition(setPosition);
	yAxis.setPosition(setPosition);

	origin = horizontalAxis;

	origin.setString("0");
	origin.setPosition(setPosition.x - 10, setPosition.y + 10);

	medium = false;
	small = false;
	large = true;
	arrayDone = false;

}

void Graph::draw(sf::RenderTarget &window) {
	double destination;
	if (small) {

		destination = 400;
		if (limit < destination){

			limit += Velocity;
			xSize.x += Velocity;
			ySize.y -= Velocity;
			xAxis.setSize(xSize);
			yAxis.setSize(ySize);
			horizontalAxis.setPosition(xAxis.getPosition().x + xAxis.getSize().x,xAxis.getPosition().y + 10);
			drawAlgorithms(window, limit);
			//line.push_back(xAxis);
		}
		else if (!arrayDone) {
			//line.clear();
			drawAlgorithms(window, destination);

		}
	}
	else if (medium) {
		destination = 600;
		if (limit < destination) {

			limit += Velocity;
			xSize.x += Velocity;
			ySize.y -= Velocity;
			xAxis.setSize(xSize);
			yAxis.setSize(ySize);
			horizontalAxis.setPosition(xAxis.getPosition().x + xAxis.getSize().x, xAxis.getPosition().y + 10);
			drawAlgorithms(window, limit);
			//line.push_back(xAxis);
		}
		else if (!arrayDone) {
			//line.clear();
			drawAlgorithms(window, destination);

		}
	}
	else if (large) {
		destination = 900;
		if (limit < destination) {

			limit += Velocity;
			xSize.x += Velocity;
			ySize.y -= Velocity;
			xAxis.setSize(xSize);
			yAxis.setSize(ySize);
			horizontalAxis.setPosition(xAxis.getPosition().x + xAxis.getSize().x + 20, xAxis.getPosition().y - 25);
			drawAlgorithms(window, limit);
			//line.push_back(xAxis);
		}
		else if (!arrayDone) {
			//line.clear();
			drawAlgorithms(window, destination);
			
		}
	}

	sf::Vertex test[] =
	{
		sf::Vertex(sf::Vector2f(0,   0), sf::Color::Red),
		sf::Vertex(sf::Vector2f(1000, 1000), sf::Color::Red),
	};

	
	window.draw(xAxis);
	window.draw(yAxis);
	window.draw(graphLabel);
	window.draw(horizontalAxis);
	window.draw(verticalAxis);
	window.draw(origin);

}

void Graph::setHorizontal(std::string headline) {
	sf::String word = headline;

	horizontalAxis.setString(word);
	horizontalAxis.setFillColor(sf::Color::Red);
}

void Graph::setVertical(std::string headline) {
	sf::String word = headline;

	verticalAxis.setString(word);
	verticalAxis.setFillColor(sf::Color::Red);
}

void Graph::drawAlgorithms(sf::RenderTarget& window, int length) {

	double increaseY = 0;
	double destination = -1, increaseX = 0;
	double amountLines = 15;
	int temp = length;
	increaseX = floor(length / amountLines);
	for (int j = 0; j < dataPoints.size();j++) {
		if (dataPoints[j][dataSet] > destination) {
			destination = dataPoints[j][dataSet];
		}
	}

	int increaseY1 = length * (destination / dataPoints[0][dataSet]);
	int increaseY2 = length * (destination / dataPoints[1][dataSet]);
	int increaseY3 = length * (destination / dataPoints[2][dataSet]);
	int increaseY4 = length * (destination / dataPoints[3][dataSet]);

	sf::Vector2f start(xAxis.getPosition().x, xAxis.getPosition().y);

		std::string s = std::to_string(dataPoints[0][dataSet]);
		sf::String sample(s);
		s = std::to_string(dataPoints[1][dataSet]);
		sf::String sample1(s);
		s = std::to_string(dataPoints[2][dataSet]);
		sf::String sample2(s);
		s = std::to_string(dataPoints[3][dataSet]);
		sf::String sample3(s);

		sf::Text text, text2, text3, text4;

		

		text.setFont(aovel_sans);
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::Red);

		text2 = text3 = text4 = text;

		text.setString(sample);
		text2.setString(sample1);
		text3.setString(sample2);
		text4.setString(sample3);
		text.setPosition(sf::Vector2f(start.x + length, start.y + increaseY1));
		text2.setPosition(sf::Vector2f(start.x + length, start.y - increaseY2));
		text3.setPosition(sf::Vector2f(start.x + length, start.y + increaseY3));
		text4.setPosition(sf::Vector2f(start.x + length, start.y + increaseY4));
	
		sf::Vertex one[] = {

			sf::Vertex(start, colors[0]),
			sf::Vertex(sf::Vector2f(start.x + length, start.y - increaseY1), colors[0]),
		};
		sf::Vertex two[] = {

			sf::Vertex(start, colors[1]),
			sf::Vertex(sf::Vector2f(start.x + length, start.y - increaseY2), colors[1]),
		};
		sf::Vertex three[] = {

			sf::Vertex(start, colors[2]),
			sf::Vertex(sf::Vector2f(start.x + length, start.y - increaseY3), colors[2]),
		};
		sf::Vertex four[] = {

			sf::Vertex(start, colors[3]),
			sf::Vertex(sf::Vector2f(start.x + length, start.y - increaseY4), colors[3]),
		};
		

		//window.draw(one, 2, sf::Lines);
		window.draw(two, 2, sf::Lines);
		//window.draw(three, 2, sf::Lines);
		//window.draw(four, 2, sf::Lines);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
	
	//arrayDone = true;
}