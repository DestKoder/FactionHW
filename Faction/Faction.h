#pragma once
#include <iostream>

using namespace std;

class Faction {
	int numenator, denumenator;

	public:
		Faction(int numenator, int denumenator) {
			this->numenator = numenator;
			this->denumenator = denumenator;
		}

		Faction(int number) {
			this->numenator = number;
			this->denumenator = 1;
		}

		int getNumenator() const {
			return this->numenator;
		}

		int getDenumenator() const {
			return this->denumenator;
		}

		friend ostream& operator<<(ostream& os, const Faction& faction) {
			os << faction.getNumenator() << "/" << faction.getDenumenator();
			return os;
		}

		const Faction operator+(const Faction add) const {
			if (this->denumenator == add.getDenumenator()) {
				return Faction(this->getNumenator() + add.getNumenator(), this->denumenator);
			}
			else {
				return Faction(this->getNumenator() * add.getDenumenator() + add.getNumenator() * this->getDenumenator(), this->getDenumenator() * add.getDenumenator());
			}
		}

		const Faction operator-(const Faction minus) const {
			if (this->denumenator == minus.getDenumenator()) {
				return Faction(this->getNumenator() + minus.getNumenator(), this->denumenator);
			}
			else {
				return Faction(this->getNumenator() * minus.getDenumenator() - minus.getNumenator() * this->getDenumenator(), this->getDenumenator() * minus.getDenumenator());
			}
		}

		const Faction operator*(const Faction umn) const {
			return Faction(this->numenator * umn.getNumenator(), this->denumenator * umn.getDenumenator());
		}

		const Faction operator/(const Faction del) const {
			return Faction(this->numenator * del.getDenumenator(), this->denumenator * del.getNumenator());
		}
};