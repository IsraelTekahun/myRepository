#include <SFML\Graphics.hpp>
#include "primitiveGui.h"

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800,600), "Primitive Gui Example");

	pGui gui;

	pProgressBar progressBar(50, 20, 200, 50);
	pSlider slider(50, 100, 200, 40);

	pButton button1(400, 20, 200, 50);
	button1.setText( sf::String("Show/Hide Window 1") );

	pWindow window1(400, 250, 300, 300);
	window1.setWindowTitle( sf::String("Window No. 1") );
	pButton onWindow1Button(20, 20, 200, 40);
	onWindow1Button.setText( sf::String("Change text") );
	pTextEdit onWindow1TextEdit(20, 80, 200, 40);
	
	window1.addWidget( &onWindow1Button );
	window1.addWidget( &onWindow1TextEdit );

	pWindow window2(50, 250, 250, 300);
	window2.setWindowTitle( sf::String("Window No. 2") );
	pCheckBox onWindow2CheckBox(30, 30, 200, 30);
	onWindow2CheckBox.setText( sf::String("Check me :)") );

	window2.addWidget( &onWindow2CheckBox );

	gui.addWidget( &progressBar );
	gui.addWidget( &slider );
	gui.addWidget( &button1 );

	gui.addWindow( &window1 );
	gui.addWindow( &window2 );

	sf::Event event;
	while(mainWindow.isOpen())
	{
		while(mainWindow.pollEvent(event))
		{
			gui.update(event, mainWindow);

			if(onWindow1Button.widgetEvent == pWidget::WidgetClicked)
				onWindow1TextEdit.setText( sf::String("This is new text") );
			
			if(button1.widgetEvent == pWidget::WidgetClicked)
			{
				if(window1.visiblity)
					window1.setVisiblity( false );
				else
					window1.setVisiblity( true );
			}

			if(event.type == sf::Event::Closed)
				mainWindow.close();
		}

		progressBar.setValue( slider.getValue() );

		mainWindow.clear();
		mainWindow.draw( bgSprite );
		mainWindow.draw( gui );
		mainWindow.display();
	}
	return 0;
}