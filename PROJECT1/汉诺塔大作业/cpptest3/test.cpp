/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
#include<conio.h>
int main()
{



	int i;
	char input[3] = { 0 }, temp;

	for (i = 0; i < 3; i++) {
		cin >> input[i];
		if (i == 2) {
			for (i = 0; i < 3; i++)
				input[i] = 0;
			i = 0;
		}
		if ((input[0] == 'q' || input[0] == 'Q') && input[1] == 0)
			break;
		else if (input[0] == 'a' || input[0] == 'b' || input[0] == 'c' || input[0] == 'A' || input[0] == 'B' || input[0] == 'C') {
			switch (input[1]) {
				case'a':
					input[1] = 'A';
					break;
				case'b':
					input[1] = 'B';
					break;
				case'c':
					input[1] = 'C';
					break;
			}
			if ((input[1] == 'a' || input[1] == 'b' || input[1] == 'c' || input[1] == 'A' || input[1] == 'B' || input[1] == 'C') && input[1] != input[0] && input[1] != (input[0] - 'A' + 'a')) {



			}

		}

		i = 0;
		cct_goto()
		cct_showch()
	    cct_gotoxy()

	}
	cout << "ÓÎÏ·ÖÐÖ¹!!!!!" << endl << endl;
	return 0;
}