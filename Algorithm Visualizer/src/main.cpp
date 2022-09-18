#include <SFML/Graphics.hpp>

#include <vector>
#include <queue>
#include <iostream>

#include "Algorithms/Lists/BubbleSort.h"
#include "Algorithms/Lists/SelectionSort.h"
#include "Algorithms/Lists/InsertionSort.h"
#include "Rendering/Visualizers/ListSortVisualizer.h"

int main()
{
    srand(time(NULL));

    const int dataSetSize = 80;
    const float maxBlockHeight = 200;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    std::vector<float> dataSet(dataSetSize);
    for (int i = 0; i < dataSetSize; i++)
        dataSet[i] = (float)rand() / (float)RAND_MAX;

    ListSortVisualizer visualizer = createListVisualizer<InsertionSort>(dataSetSize);
    visualizer.setRenderTarget(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
                visualizer.play();
        }

        window.clear();
        
        visualizer.render();

        window.display();
    }
    

    return 0;
}