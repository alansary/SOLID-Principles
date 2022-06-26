#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

/*
 * Dependency Inversion Principle
 *
 * This principle states that a higher level-module should not depend on a lower-level
 * module, but they both should depend on abstractions. It also states that abstractions
 * should not depend on details, but details should depend on abstractions.
 *
 * Suppose we have a "FruitBasket" class, which is a low-level module, where the user has
 * "AddToBasket" functionality that appends a tuple of strings containing the fruit and the
 * color to a vector.
 *
 * Now suppose we have a high-level class named "ColorSeracher" that has a "ListColor"
 * functionality, which goes through the vector item by item, then prints each found fruit
 * with the matching color given to the function.
 */

class FruitBasket { // Low-level module
public:
	 vector<tuple<string, string>> Basket;
	 void AddToBasket(const string &Fruit, const string &Color) {
		 Basket.push_back(make_tuple(Fruit, Color));
	 }
};

class ColorSearcher { // High-level module
public:
	void ListColor(FruitBasket fruit_basket, const string &color) {
		for (auto item : fruit_basket.Basket) {
			if (get<1>(item) == color) {
				cout << "Found " << get<0>(item) << endl;
			}
		}
	}
};

/*
 * The problem with this design is that the "ColorSeracher" high-level module depends
 * heavily on the low-level module, since it knows the details about the "Basket" object
 * found in it, as it knows it's a vector of tuples. Any modification to the low-level
 * class, will now affect the higher-level one.
 *
 * A simple solution would be to introduce an abstract class that both these modules
 * depend on. By doing so, the high level class is separated from the details. The code
 * given below follows the dependency inversion principle.
 */

class BasketSearcher { // Abstract module
public:
	virtual ~BasketSearcher() {}
	virtual vector<string> SearchByColor(const string &color) = 0;
};

class FruitBasketDIP : public BasketSearcher { // Low-level module
public:
	 vector<tuple<string, string>> Basket;
	 void AddToBasket(const string &Fruit, const string &Color) {
		 Basket.push_back(make_tuple(Fruit, Color));
	 }

	 vector<string> SearchByColor(const string &color) override {
		 vector<string> found;
		 for (auto item : Basket) {
			 if (get<1>(item) == color)
				 found.push_back(get<0>(item));
		 }

		 return found;
	 }
};

class ColorSearcherDIP { // High-level module
public:
	void ListColor(BasketSearcher &basket_searcher, const string &color) {
		for (auto item : basket_searcher.SearchByColor(color)) {
			cout << "Found " << item << endl;
		}
	}
};

/*
 * Note that this design approach also follows the single responsibility principle,
 * since it's the responsibility of the "FruitBasket" class to filter the items in it.
 * Now, the high-level module doesn't depend on the lower-level one and it only knows
 * that the "SearchByColor" member function returns a vector of strings of the found
 * objects.
 */

int main() {
	FruitBasket fruit_basket;
	fruit_basket.AddToBasket("Banana", "Yellow");
	fruit_basket.AddToBasket("Apple", "Red");
	ColorSearcher color_searcher;
	color_searcher.ListColor(fruit_basket, "Yellow");

	FruitBasketDIP fruit_basket_DIP;
	fruit_basket_DIP.AddToBasket("Banana", "Yellow");
	fruit_basket_DIP.AddToBasket("Apple", "Red");
	ColorSearcherDIP color_searcher_DIP;
	color_searcher_DIP.ListColor(fruit_basket_DIP, "Yellow");

	return 0;
}
