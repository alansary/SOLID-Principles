#include <iostream>
using namespace std;

/*
 * Single Responsibility Principle
 *
 * This principle suggests that a class should have only a single responsibility. In other
 * words, a class should only have one purpose and shouldn't do more than just that purpose,
 * so when a change in this purpose is needed, we have exactly one class to modify.
 *
 * Say we need to calculate the average tax from that average citizen income, a bad
 * approach contradicting the single responsibility principle would be to give each class
 * its own "CalcTax" member function. A good design approach, however, should be to make
 * a tax calculator class. This way whenever the tax calculation process needs a change,
 * we only need modify the tax calculator class and not modify 195 classes (a class for
 * each country.)
 *
 * So, as you can see the strategy for the calculation of each tax can be different from
 * one country to another, this TaxCalculator class could easily account for that. Assuming
 * a change in the policy of the taxes in a country, modifying the code to account for
 * that's takes only modifying one function, which is the case if each country had its
 * CalcuateTax member function too. What the single responsibility principle really added,
 * was that modifying a policy, doesn't really modify the whole country class, which could
 * be time consuming in a more realistic complex project.
 */

class TaxCalculator;

class UnitedStates {
private:
	friend TaxCalculator;
	uint16_t avg_citizen_income;
public:
	UnitedStates(uint16_t avg_income) : avg_citizen_income(avg_income) {}
};

class UnitedKingdom {
private:
	friend TaxCalculator;
	uint16_t avg_citizen_income;
public:
	UnitedKingdom(uint16_t avg_income) : avg_citizen_income(avg_income) {}
};

class TaxCalculator {
public:
	uint16_t CalculateTax(UnitedKingdom country) {
		return country.avg_citizen_income / 10;
	}

	uint16_t CalculateTax(UnitedStates country) {
		return country.avg_citizen_income / 8;
	}
};

int main() {
	return 0;
}
