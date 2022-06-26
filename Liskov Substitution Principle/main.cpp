#include <iostream>
using namespace std;

/*
 * Liskov Substitution Principle
 *
 * This principle states that every derived class should be substitutable for their base
 * class. In other words, derived classes should behave correctly, as expected and avoid
 * logical errors due to their parent class.
 *
 * Say we have a Rectangle class, which is a basic class that has width and height
 * attributes, set and get width functions, set and get height functions and a calculate
 * area function.
 */

class Rectangle {
protected:
	uint16_t width;
	uint16_t height;

public:
	Rectangle(uint16_t width, uint16_t height): width(width), height(height) {}
	virtual ~Rectangle() {}
	virtual void SetWidth(uint16_t width) {
		this->width = width;
	}
	virtual void SetHeight(uint16_t height) {
		this->height = height;
	}
	virtual uint16_t GetWidth() { return width; }
	virtual uint16_t GetHeight() { return height; }
	virtual uint16_t CalculateArea() { return width * height; }
};

/*
 * If we want to add a Square subclass based on this class, the new class will go like this.
 */

class Square : public Rectangle {
public:
	Square(uint16_t length) : Rectangle(length, length) {}
	void SetWidth(uint16_t width) override {
		this->width = width;
		this->height = width;
	}
	void SetHeight(uint16_t height) override {
		this->width = height;
		this->height = height;
	}
	uint16_t GetWidth() override { return width; }
	uint16_t GetHeight() override { return height; }
};

/*
 * So, what's the problem with that code? Isn't the square correctly handling the
 * dimension inequality case?
 *
 * Well, the problem is that the user using "SetWidth" and "SetHeight" functions might not
 * get that they change the other attribute, so the user might get unexpected results when
 * calling "CalculateArea" function.
 *
 * So, to sum it up, This Square class isn't substitutable for the Rectangle class, and
 * thereby breaks Liskov principle.
 */

int main() {
	return 0;
}
