/** testuje zegar */
#include <iostream>
#include "zegar.hpp"

using namespace std;
int main() {
    Zegar zeg;
    Alarm alarm1(zeg,cout,19,5);
    Alarm alarm2(zeg,cout,19,7);
    Display display(zeg,cout);

    /** symulacja */
    for(int i=0;i<10;++i) {
		cout << "----takt-----" << endl;
		zeg.timer_tick();
    }

	system("pause");

    return 0;
}
