// http://uva.onlinejudge.org/external/8/893.pdf
#include <iostream>

using namespace std;

int isleap(int year) {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int year2offset(int year) {
	int sum = 0;
	for (int i = 1998; i < year; i++)
		sum += isleap(i) ? 366 : 365;
	return sum;
}

int month2offset(int year, int month) {
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sum = month > 2 && isleap(year) ? 1 : 0;
	for (int i = 1; i < month; i++) sum += days[i-1];
	return sum;
}

int day2offset(int day) { return day - 1; }

int date2offset(int year, int month, int day) {
	return year2offset(year) + month2offset(year, month) + day2offset(day);
}

int offset2year(int offset) {
	int year = 1998;
	while (true) {
		int days = isleap(year) ? 366 : 365;
		if (offset < days) break;
		offset -= days;
		year++;
	}
	return year;
}

int offset2month(int offset, int year) {
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isleap(year)) days[1]++;
	for (int i = 0; i < 12; i++) {
		if (offset < days[i])  return i + 1;
		offset -= days[i];
	}
	return 12;
}

int main() {
	while (true) {
		int delta, day, month, year;
		cin >> delta >> day >> month >> year;
		if (!day) break;
		int offset = date2offset(year, month, day) + delta;
		year = offset2year(offset);
		offset -= year2offset(year);
		month = offset2month(offset, year);
		offset -= month2offset(year, month);
		cout << offset + 1 << " " << month << " " << year << endl;
	}
}
