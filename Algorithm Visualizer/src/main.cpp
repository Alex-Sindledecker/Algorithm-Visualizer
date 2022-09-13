#include <SFML/Graphics.hpp>

#include <vector>
#include <queue>
#include <iostream>

#include "Algorithms/Lists/BubbleSort.h"

int main()
{
    srand(time(NULL));

    const int dataSetSize = 80;
    const float maxBlockHeight = 200;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    std::vector<float> dataSet(dataSetSize);
    for (int i = 0; i < dataSetSize; i++)
        dataSet[i] = (float)rand() / (float)RAND_MAX;

    BubbleSort visualizer(dataSet);
    visualizer.sort();

    sf::RectangleShape rect;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                    visualizer.dequeueState();
            }
        }

        window.clear();
        
        if (visualizer.isStateRemaining())
        {
            auto state = visualizer.peek();

            for (int i = 0; i < state.data.size(); i++)
            {
                const int blockWidth = 8;
                const int blockHeight = state.data[i] * maxBlockHeight + 10;

                rect.setFillColor(sf::Color::White);
                rect.setPosition(sf::Vector2f(i * 10 + 1, window.getSize().y - blockHeight));
                rect.setSize(sf::Vector2f(blockWidth, blockHeight));

                window.draw(rect);
            }
        }

        window.display();
    }
    

    return 0;
}