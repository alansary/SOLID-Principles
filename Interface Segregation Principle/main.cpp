#include <iostream>
using namespace std;

/*
 * Interface Segregation Principle
 *
 * This principle states that a client should never be forced implement an interface that
 * it doesn't use. In other words, If a class has a function public to the user, it must be
 * callable.
 *
 * Now, the "SetWidth" and "SetHeight" functions do, basically nothing, while the
 * "GetWidth" and "GetHeight" functions call "GetLength" under the hood. So, what's
 * the problem witht this design? Does our square class follow Liskov principle, now?
 * Actually, our class follows it indeed, by making the square class not behave in an
 * unexpected way as the Width and height functions have been emptied, they could also be
 * redesigned to print a warning or throw an exception when used. Still, this square class
 * provides interfaces that aren't usable by the user, which is confusing and requires
 * wasting lots of time both reading and writing the accompanying documentation.
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

class Square : public Rectangle {
public:
	Square(uint16_t length) : Rectangle(length, length) {}
	void SetLength(uint16_t length) { width = length; height = length; }
	void SetWidth(uint16_t width) override { (void)width; }
	void SetHeight(uint16_t height) override { (void)height; }
	uint16_t GetLength() { return width; }
	uint16_t GetWidth() override { return GetLength(); }
	uint16_t GetHeight() override { return GetLength(); }
};

/*
 * A better approach would be to redesign the whole thing by simply making a 2D simple
 * shape base class that has all the basic functionalities, then each child class adds
 * its own specific functions. That way each class has no unused interfaces and follows
 * the interface segregation principle. This can be seen in the code below.
 */

class TwoDSimpleShape {
protected:
	uint16_t width;
	uint16_t height;
public:
	TwoDSimpleShape(uint16_t width, uint16_t height) : width(width), height(height) {}
	virtual ~TwoDSimpleShape() {}
	virtual uint32_t CalculateArea() { return width * height; }
};

class Rectangle2D : public TwoDSimpleShape {
public:
	Rectangle2D(uint16_t width, uint16_t height) : TwoDSimpleShape(width, height) {}
	void SetWidth(uint16_t width) {
		this->width = width;
	}
	void SetHeight(uint16_t height) {
		this->height = height;
	}
	uint16_t GetWidth() { return width; }
	uint16_t GetHeight() { return height; }
};

class Square2D : public TwoDSimpleShape {
public:
	Square2D(uint16_t length) : TwoDSimpleShape(length, length) {}
	void SetLength(uint16_t length) { width = length; height = length; }
	uint16_t GetLength() { return width; }
};

int main() {
	return 0;
}
