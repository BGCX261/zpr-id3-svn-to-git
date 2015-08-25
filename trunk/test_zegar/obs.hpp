#ifndef OBS_H
#define OBS_H

#include <vector>

/** dostarcza klas abstrakcyjnych dla obserwatora */
class Observer {
 public:
	virtual void update() = 0; //wolana, gdy ob.obserwowany sie zmienil
	virtual ~Observer(){}
};
/** klasa abstrakcyjna dla obiektu obserwowanego */
class Subject {
public:
	typedef std::vector<Observer*> Observers;

	void add(Observer* o){ obs_.push_back(o); }
	void notify() {
		for(Observers::iterator it = obs_.begin(); it != obs_.end(); ++it)
			(*it)->update();
	}
	virtual ~Subject(){}
private:
	Observers obs_;
};

#endif
