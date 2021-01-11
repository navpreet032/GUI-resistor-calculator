#include<string>
#include <iomanip>
#include <sstream>
#include<math.h>
using namespace std;

string unit(unsigned long long x) {
	x; unsigned long long temp = x; double ans{};
	int countK = 0; std::string s;
	to_string(temp); stringstream stream;
	while (x != 0)
	{
		x = x / 10;
		countK++;
	}
	if (countK >= 4 && countK <= 6) {

		ans = temp / 1000;

		if (countK == 4) {
			stream << fixed << setprecision(1) << ans;
			s = stream.str(); return s + "K ohm";
		}
		else
		{
			stream << fixed << setprecision(0) << ans;
			s = stream.str(); return s + "K ohm";
		}

	}
	if (countK >= 7 && countK <= 9) {
		ans = temp / 1000000;
		if (countK >= 7 && countK <= 9) {
			ans = temp / 1000000;
			if (countK == 7) {
				stream << fixed << setprecision(1) << ans;
				s = stream.str(); return s + "M ohm";
			}
			else {
				stream << fixed << setprecision(0) << ans;
				s = stream.str(); return s + "M ohm";
			}
		}

	}
	if (countK <= 1000) {
		ans = temp / 1000000000;
		stream << fixed << setprecision(1) << ans;
		s = stream.str(); return s + "G ohm";
	}
}
