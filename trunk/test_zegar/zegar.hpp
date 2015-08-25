#ifndef ZEGAR_H
#define ZEGAR_H

#include <ostream>
#include "obs.hpp"

//konkretny obiekt obserwowany
class Zegar : public Subject {
 public:
	Zegar() : h(19), m(1) {}
	int min() const { return m; }
	int hour() const { return h; }
	void timer_tick() { ++m; notify(); } //uzywane do symulacji
private:
	int h;
	int m;
};

//konkretny obserwator
class Alarm : public Observer {
public:
	Alarm(Zegar& z, std::ostream& os, int h, int m) : zeg_(z), os_(os), h_(h), m_(m) { zeg_.add(this); }
	virtual void update() {
		if(zeg_.min() == m_ && zeg_.hour() == h_ )
			//wykonaj alarm
			os_ << "Alarm!!!" << h_ << ":" << m_ << std::endl;
	}
private:
	Zegar& zeg_;
	std::ostream& os_;
	int h_;
	int m_;
};

//konkretny obserwator
class Display : public Observer {
public:
	Display(Zegar& z, std::ostream& os) : zeg_(z), os_(os) { zeg_.add(this); }
	virtual void update() {
		os_ << zeg_.hour() << ":" << zeg_.min() << std::endl;
	}
private:
	Zegar& zeg_;
	std::ostream& os_;
};


#endif
