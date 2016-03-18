/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int validate(int d, int m, int y) {
	if (m > 12 || m < 1)
		return 0;
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0) {
				if (m == 2)  {
					if (d > 29)
						return 0;
				}
			}
		}
	}
	else {
		if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) {
			if (d > 31)
				return 0;
		}
		else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
			if (d > 30)
				return 0;
		}
		else if (m == 2 && d > 28)
			return 0;
	}
	return 1;
}
int isOlder(char *dob1, char *dob2) {
	int m1 = (dob1[3] - 48) * 10 + dob1[4] - 48;
	int m2 = (dob2[3] - 48) * 10 + dob2[4] - 48;
	int d1 = (dob1[0] - 48) * 10 + dob1[1] - 48;
	int d2 = (dob2[0] - 48) * 10 + dob2[1] - 48;
	int y1 = (dob1[6] - 48) * 1000 + (dob1[7] - 48) * 100 + (dob1[8] - 48) * 10 + (dob1[9] - 48);
	int y2 = (dob2[6] - 48) * 1000 + (dob2[7] - 48) * 100 + (dob2[8] - 48) * 10 + (dob2[9] - 48);
	if (validate(d1, m1, y1) != 1 || validate(d2, m2, y2) != 1)
		return -1;
	if (y1 > y2) return 2;
	if (y1 < y2) return 1;
	if (m1 > m2) return 2;
	if (m1 < m2) return 1;
	if (d1 > d2) return 2;
	if (d1 < d2) return 1;
	return 0;
}