#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "Israel", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	sf::Text playerText;
	player.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
			else if (evnt.type == evnt.Resized) {
				printf("width: %i height: %i\n",  evnt.size.width, evnt.size.height);
			}
		}
		window.draw(player); 
		window.display();
		window.draw(playerText);
	}
	return 0;
}


/*

sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);

while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

window.clear();
window.draw(shape);
window.display();
}
*/