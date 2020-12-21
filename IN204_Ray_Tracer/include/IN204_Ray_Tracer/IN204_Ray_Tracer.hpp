#ifndef IN204_Ray_Tracer_HPP
#define IN204_Ray_Tracer_HPP

#include <SFML/Window.hpp>

class IWindow {
public:
	virtual bool IsOpen() const = 0;
	virtual bool Open() const = 0;
};

class ImplSfmlWindow : public IWindow {
private:
	sf::Window _window;

public:
};

#endif // !IN204_Ray_Tracer_HPP