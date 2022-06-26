#include <iostream>
using namespace std;

/*
 * Open Closed Principle
 *
 * This principle states that your code should generally be open for extension, yet closed
 * for modification.
 *
 * Let's say we have a class named "StringAdder" that has a member function called
 * "AddToText" which takes two strings and appends the second to the first.
 *
 */

//class TextAdder {
//public:
//	string AddToText(const string &original, const string &new_string) {
//		return original + new_string;
//	}
//};

/*
 * Now, say we want to add another functionality to the TextAdder, for example adding
 * the functionality of adding the new string before the original one. Extending the class
 * through adding another function named "AddBeforeText" is the wrong way to extend the
 * functionalities of the class, since we had to modify the class.
 *
 * Following the Open/Closed Principle, this class should be extended making the AddToText
 * function take a third argument specifying what kind of string addition the user wants
 * done. This can be done using polymorphism. A base class is passed to the "AddToText"
 * function, then its own "add" function is called. Let's implement that.
 */

class TextAddType {
public:
	virtual ~TextAddType() {}
	virtual string add(const string &original, const string &new_string) = 0;
};

class TextAdder {
public:
	string AddToText(const string &original, const string &new_string, TextAddType &adder) {
		return adder.add(original, new_string);
	}
};

class TextAppend : public TextAddType {
public:
	string add(const string &original, const string &new_string) {
		return original + new_string;
	}
};

class TextPrepend : public TextAddType {
public:
	string add(const string &original, const string &new_string) {
		return new_string + original;
	}
};

int main() {
	return 0;
}
