void hanoi(int n, char src, char tmp, char dst)
{
	int temp;

	if (n == 1) {
		num++;
		speedcontrol();
		switch (src) {
			case('A'):
				if (dst == 'C') {
					vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
					Cstack[Ctop++] = Astack[--Atop];

				}
				else {
					vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
					Bstack[Btop++] = Astack[--Atop];

				}
				break;
			case('B'):
				if (dst == 'C') {
					vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
					Cstack[Ctop++] = Bstack[--Btop];

				}
				else {
					vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
					Astack[Atop++] = Bstack[--Btop];

				}
				break;
			case('C'):
				if (dst == 'A') {
					vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
					Astack[Atop++] = Cstack[--Ctop];

				}
				else {
					vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
					Bstack[Btop++] = Cstack[--Ctop];

				}
				break;

		}

		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "第" << setw(4) << num << " 步" << "(1#: " << src << arrow << dst << ")  ";
		if (display == 1)
			horizontal();


		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	speedcontrol();
	switch (src) {
		case('A'):
			if (dst == 'C') {
				vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
				temp = (Cstack[Ctop++] = Astack[--Atop]);

			}
			else {
				vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
				temp = (Bstack[Btop++] = Astack[--Atop]);

			}
			break;
		case('B'):
			if (dst == 'C') {
				vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
				temp = (Cstack[Ctop++] = Bstack[--Btop]);

			}
			else {
				vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
				temp = (Astack[Atop++] = Bstack[--Btop]);

			}
			break;
		case('C'):
			if (dst == 'A') {
				vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
				temp = (Astack[Atop++] = Cstack[--Ctop]);

			}
			else {
				vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
				temp = (Bstack[Btop++] = Cstack[--Ctop]);

			}
			break;

	}

	cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
	cout << "第" << setw(4) << num << " 步" << "(" << temp << "#: " << src << arrow << dst << ")  ";
	if (display == 1)
		horizontal();

	hanoi(n - 1, tmp, src, dst);
	return;
}
