
#include <SFML/Graphics.hpp>
#include "Array/array.h"
#include "Graph/Graph.h"
#include "Button/Button.h"
#include <iostream>
#include <vector>
#include <string>

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");


void Window(std::vector<std::vector<std::vector<double>>>& times);
void drawGraphs(Graph& one, Graph& two, Graph& three, Graph& four, bool partialSorted, bool Random, bool Reverse, bool Sorted);
void prepareSmall(Graph& one, Graph& two, Graph& three);
void prepareSmall(Graph& one, Graph& two, Graph& three, Graph& four);
void prepareMedium(Graph& one, Graph& two);
void prepareLarge(Graph& one);
void CheckforOptions(Graph& partialGraph, Graph& sortedGraph, Graph& randomGraph, Graph& reverseGraph, bool partialSorted, bool Random, 
                       bool Reverse, bool Sorted, bool& runGraphs, bool& smallGraphs, bool& mediumGraphs, bool& largeGraph);
void checkButtons(Graph& partialGraph, Graph& sortedGraph, Graph& randomGraph, Graph& reverseGraph, Button& dataSet_1, Button& dataSet_2, Button& dataSet_3, Button& dataSet_4, Button& dataSet_5);
void addPoints(Graph& one, Graph& two, Graph& three, Graph& four, std::vector<std::vector<std::vector<double>>>& times);



int main() {
    window.setFramerateLimit(60);
    

    unsigned int size = 2000;

    // this counter would serve as
    int counter = 0;
    // this is the declaration of the 3d vector, which would contain all the times for different sorting algor
    std::vector<std::vector<std::vector<double> > > times(4, std::vector<std::vector<double> >(4, std::vector<double>(5, 0.0)));
    // calling the array constructor with a size of 5000, counter would serve to know where the next num would be save in the 3d vector
    Array sample1((size * 1) / 5, counter, times);
    Array sample2((size * 2) / 5, counter, times);
    Array sample3((size * 3) / 5, counter, times);
    Array sample4((size * 4) / 5, counter, times);
    Array sample5((size * 5) / 5, counter, times);
    Window(times);

    return 0;
}

void Window(std::vector<std::vector<std::vector<double>>>& times) {

    sf::Font aovel_sans;
    if (!aovel_sans.loadFromFile("AovelSansRounded-rdDL.ttf")) {
        std::cout << "font not loaded" << '\n';
        throw ("COULD NOT LOAD FONT");
    }

    Graph partialGraph = Graph("Partially Sorted", aovel_sans);
    Graph sortedGraph = Graph("Sorted", aovel_sans);
    Graph randomGraph = Graph("Random", aovel_sans);
    Graph reverseGraph = Graph("Reversed", aovel_sans);

    addPoints(randomGraph, reverseGraph, sortedGraph, partialGraph, times);
   
    //buttons for Arrays
    Button partialButton = Button(300, 1525, 30, "Partial", aovel_sans);
    Button sortedButton = Button(300, 1630, 30, "Sorted", aovel_sans);
    Button randomButton = Button(300, 1735, 30, "Random", aovel_sans);
    Button reverseButton = Button(300, 1845, 30, "Reverse", aovel_sans);

    //buttons for data sets
    Button dataSet_1 = Button(400, 1585, 25, "5k", aovel_sans);
    Button dataSet_2 = Button(400, 1680, 25, "10k", aovel_sans);
    Button dataSet_3 = Button(400, 1780, 25, "15k", aovel_sans);
    Button dataSet_4 = Button(500, 1630, 25, "20k", aovel_sans);
    Button dataSet_5 = Button(500, 1735, 25, "25k", aovel_sans);

    sf::RectangleShape GUIcolumn, column;

    sf::Text Title, columnString;

    bool set_screen = false;

    GUIcolumn.setSize(sf::Vector2f(400, 1080));
    GUIcolumn.setPosition(1520, 0);
    GUIcolumn.setFillColor(sf::Color{ 211, 211, 211 });
    

    Title.setFont(aovel_sans);
    Title.setString("CSC 212 Final Project Sorting Algorithms");
    Title.setCharacterSize(48);
    Title.setPosition(280, 0);
    Title.setFillColor(sf::Color::Red);

    columnString.setFont(aovel_sans);
    columnString.setString("Select Array(s)");
    columnString.setCharacterSize(30);
    columnString.setPosition(1630, 200);
    columnString.setFillColor(sf::Color::Black);


    column.setSize(sf::Vector2f(400, 380));
    column.setPosition(1520, 200);
    column.setFillColor(sf::Color{ 211, 211, 211, 0 });
    column.setOutlineColor(sf::Color::Black);
    column.setOutlineThickness(3);

    int counter = 0;

    //bool ButtonPressed, all initiated as false
    bool partialSorted, Sorted, Random, Reverse, runGraphs, smallGraphs, mediumGraphs, largeGraph;
    partialSorted = Sorted = Random = Reverse = runGraphs = smallGraphs = mediumGraphs = largeGraph = false;
   
    //window execution
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:

                window.close();
                break;
                
            }
            if (sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

                    if (dataSet_1.isActive() || dataSet_2.isActive() || dataSet_3.isActive() || dataSet_4.isActive() || dataSet_5.isActive()) {
                        partialSorted = partialButton.isActive();
                        Sorted = sortedButton.isActive();
                        Random = randomButton.isActive();
                        Reverse = reverseButton.isActive();

                        checkButtons(partialGraph, sortedGraph, randomGraph, reverseGraph, dataSet_1, dataSet_2, dataSet_3, dataSet_4, dataSet_5);
                        CheckforOptions(partialGraph, sortedGraph, randomGraph, reverseGraph, partialSorted, Random, Reverse, Sorted, runGraphs, smallGraphs, mediumGraphs, largeGraph);
                    }
                    
                }
            }
            if (sf::Event::MouseButtonReleased) {

                //arrays
                if (!partialButton.isActive()){
                    partialButton.isPressed(sf::Mouse::getPosition(window));
                }
                else {
                    partialButton.isPressed(sf::Mouse::getPosition(window));
                }

                if (!sortedButton.isActive()){
                    sortedButton.isPressed(sf::Mouse::getPosition(window));
                   
                }
                else{
                    sortedButton.isPressed(sf::Mouse::getPosition(window));
                }

                if (!randomButton.isActive()){
                    randomButton.isPressed(sf::Mouse::getPosition(window));
                }
                else{
                    randomButton.isPressed(sf::Mouse::getPosition(window));
                }

                if (!reverseButton.isActive()){
                    reverseButton.isPressed(sf::Mouse::getPosition(window));
                }
                else{
                    reverseButton.isPressed(sf::Mouse::getPosition(window));
                }

                //data sets
                //1
                if (!dataSet_1.isActive()) {
                    dataSet_1.isPressed(sf::Mouse::getPosition(window));
                    if (dataSet_1.isActive()) {
                        dataSet_2.switchState();
                        dataSet_3.switchState();
                        dataSet_4.switchState();
                        dataSet_5.switchState();
                        
                    }
                }
                else {
                    dataSet_1.isPressed(sf::Mouse::getPosition(window));
                }
                //2
                if (!dataSet_2.isActive()) {
                    dataSet_2.isPressed(sf::Mouse::getPosition(window));
                    if (dataSet_2.isActive()) {
                        dataSet_1.switchState();
                        dataSet_3.switchState();
                        dataSet_4.switchState();
                        dataSet_5.switchState();

                    }
                }
                else {
                    dataSet_2.isPressed(sf::Mouse::getPosition(window));
                }
                //3
                if (!dataSet_3.isActive()) {
                    dataSet_3.isPressed(sf::Mouse::getPosition(window));
                    if (dataSet_3.isActive()) {
                        dataSet_2.switchState();
                        dataSet_1.switchState();
                        dataSet_4.switchState();
                        dataSet_5.switchState();

                    }
                }
                else {
                    dataSet_3.isPressed(sf::Mouse::getPosition(window));
                }
                //4
                if (!dataSet_4.isActive()) {
                    dataSet_4.isPressed(sf::Mouse::getPosition(window));
                    if (dataSet_4.isActive()) {
                        dataSet_2.switchState();
                        dataSet_3.switchState();
                        dataSet_1.switchState();
                        dataSet_5.switchState();

                    }
                }
                else {
                    dataSet_4.isPressed(sf::Mouse::getPosition(window));
                }
                //5
                if (!dataSet_5.isActive()) {
                    dataSet_5.isPressed(sf::Mouse::getPosition(window));
                    if (dataSet_5.isActive()) {
                        dataSet_2.switchState();
                        dataSet_3.switchState();
                        dataSet_4.switchState();
                        dataSet_1.switchState();

                    }
                }
                else {
                    dataSet_5.isPressed(sf::Mouse::getPosition(window));
                }
            }
        }
        //physics 

       
        
        if (runGraphs) {
            window.clear();
            
            
            drawGraphs(partialGraph, randomGraph, reverseGraph, sortedGraph, partialSorted, Random, Reverse, Sorted);
            if (partialGraph.line.size() > 0) {
                window.draw(Title);
            }
            window.draw(GUIcolumn);
            window.draw(column);
            partialButton.draw(window);
            randomButton.draw(window);
            sortedButton.draw(window);
            reverseButton.draw(window);
            dataSet_1.draw(window);
            dataSet_2.draw(window);
            dataSet_3.draw(window);
            dataSet_4.draw(window);
            dataSet_5.draw(window);
            window.draw(columnString);
            
            window.display();
        }
        else {
            window.clear();
            //window.draw(Title);
            window.draw(GUIcolumn);
            window.draw(column);partialButton.draw(window);
            randomButton.draw(window);
            sortedButton.draw(window);
            reverseButton.draw(window);
            dataSet_1.draw(window);
            dataSet_2.draw(window);
            dataSet_3.draw(window);
            dataSet_4.draw(window);
            dataSet_5.draw(window);
            window.draw(columnString);
            window.display();
        }
    }
}

void drawGraphs(Graph& one, Graph& two, Graph& three, Graph& four, bool partialSorted, bool Random, bool Reverse, bool Sorted) {
    
    if (partialSorted) {
        one.draw(window);
    }
    if (Random) {
        two.draw(window);
    }
    if (Reverse) {
        three.draw(window);
    }
    if (Sorted) {
        four.draw(window);
    }
}

void prepareSmall(Graph& one, Graph& two, Graph& three) {
    one.drawSmall(0);
    two.drawSmall(1);
    three.drawSmall(2);
}

void prepareSmall(Graph& one, Graph& two, Graph& three, Graph& four) {
    one.drawSmall(0);
    two.drawSmall(1);
    three.drawSmall(2);
    four.drawSmall(3);
}

void prepareMedium(Graph& one, Graph& two) {
    two.drawMedium(1);
    one.drawMedium(0);
    
}

void prepareLarge(Graph& one) {
    one.drawLarge();
}

void CheckforOptions(Graph& partialGraph, Graph& sortedGraph, Graph& randomGraph, Graph& reverseGraph, bool partialSorted, bool Random, bool Reverse, bool Sorted, bool& runGraphs, bool &smallGraphs, bool &mediumGraphs, bool &largeGraph) {
    unsigned int counter = 0;
    if (partialSorted) {
        counter++;
        partialGraph.line.clear();
    }
    if (Random) {
        randomGraph.line.clear();
        counter++;
    }
    if (Reverse) {
        reverseGraph.line.clear();
        counter++;
    }
    if (Sorted) {
        sortedGraph.line.clear();
        counter++;
    }
    if (counter > 0) {
        runGraphs = true;
    }
    else { runGraphs = false; }

    if (runGraphs) {

        if (counter >= 2) {

            if (counter == 2) {

                if (partialSorted) {

                    if (Random) {

                        prepareMedium(partialGraph, randomGraph);
                    }

                    else if (Reverse) {
                        prepareMedium(partialGraph, reverseGraph);
                    }

                    else{
                        prepareMedium(partialGraph, sortedGraph);
                    }
                }
                else if (Random) {

                    if (Reverse) {
                        prepareMedium(randomGraph, reverseGraph);
                    }

                    else{
                        prepareMedium(randomGraph, sortedGraph);
                    }
                }

                else {
                    prepareMedium(reverseGraph, sortedGraph);
                    
                }
                mediumGraphs = true;
            }
            else {

                if (partialSorted){

                    if (Random) {

                        if (Reverse && Sorted) {
                            prepareSmall(partialGraph, sortedGraph, randomGraph, reverseGraph);
                        }

                        else if (Reverse) {
                            prepareSmall(partialGraph, randomGraph, reverseGraph);
                        }

                        else if (Sorted) {
                            prepareSmall(partialGraph, randomGraph, sortedGraph);
                        }   
                    }

                    else {
                        prepareSmall(partialGraph, reverseGraph, sortedGraph);
                    }
                }

                else {

                    prepareSmall(randomGraph, reverseGraph, sortedGraph);
                    
                }

                smallGraphs = true;
            }
        }
        else {

            if (partialSorted) {
                prepareLarge(partialGraph);
            }

            else if (Random) {
                prepareLarge(randomGraph);
            }

            else if (Reverse) {
                prepareLarge(reverseGraph);
            }

            else {
                prepareLarge(sortedGraph);
            }

            largeGraph = true;
        }
    }
}

void checkButtons(Graph& partialGraph, Graph& sortedGraph, Graph& randomGraph, Graph& reverseGraph, Button& dataSet_1, Button& dataSet_2, Button& dataSet_3, Button& dataSet_4, Button& dataSet_5) {
    if (dataSet_1.isActive()) {
        partialGraph.setHorizontal("5k");
        sortedGraph.setHorizontal("5k");
        randomGraph.setHorizontal("5k");
        reverseGraph.setHorizontal("5k");

        partialGraph.dataSet = 0;
        sortedGraph.dataSet = 0;
        randomGraph.dataSet = 0;
        reverseGraph.dataSet = 0;
    }
    else if (dataSet_2.isActive()) {

        partialGraph.setHorizontal("10k");
        sortedGraph.setHorizontal("10k");
        randomGraph.setHorizontal("10k");
        reverseGraph.setHorizontal("10k");

        partialGraph.dataSet = 1;
        sortedGraph.dataSet = 1;
        randomGraph.dataSet = 1;
        reverseGraph.dataSet = 1;
    }
    else if (dataSet_3.isActive()) {

        partialGraph.setHorizontal("15k");
        sortedGraph.setHorizontal("15k");
        randomGraph.setHorizontal("15k");
        reverseGraph.setHorizontal("15k");

        partialGraph.dataSet = 2;
        sortedGraph.dataSet = 2;
        randomGraph.dataSet = 2;
        reverseGraph.dataSet = 2;
    }
    else if (dataSet_4.isActive()) {

        partialGraph.setHorizontal("20k");
        sortedGraph.setHorizontal("20k");
        randomGraph.setHorizontal("20k");
        reverseGraph.setHorizontal("20k");

        partialGraph.dataSet = 3;
        sortedGraph.dataSet = 3;
        randomGraph.dataSet = 3;
        reverseGraph.dataSet = 3;
    }
    else if (dataSet_5.isActive()) {

        partialGraph.setHorizontal("25k");
        sortedGraph.setHorizontal("25k");
        randomGraph.setHorizontal("25k");
        reverseGraph.setHorizontal("25k");

        partialGraph.dataSet = 4;
        sortedGraph.dataSet = 4;
        randomGraph.dataSet = 4;
        reverseGraph.dataSet = 4;
    }
}

void addPoints(Graph& one, Graph& two, Graph& three, Graph& four, std::vector<std::vector<std::vector<double>>>& times) {
    
    one.addPoints(times[0]);
    two.addPoints(times[1]);
    three.addPoints(times[2]);
    four.addPoints(times[3]);

}