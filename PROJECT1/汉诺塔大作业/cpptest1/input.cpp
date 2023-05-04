while (1) {
	bool input = true;
	for (i = 0; i < 113000; i++)
		binary[i] = '0';
	cin >> binary;
	for (i = 1; i < 113; i++)
		if (binary[i] != '0' && binary[i] != '1' && binary[i] != 0)
			input = false;
	if (input && binary[0] == '.' && !cin.rdstate())
		break;
	cin.clear();
	cin.ignore(10000000, '\n');//É¾ÁËÕâ¸öÒÔºó»áËÀÑ­»·
	if (binary[0] != '.')
		cout << "²»ÊÇÒÔ.¿ªÍ·£¬ÇëÖØÊä" << endl;
	else
		cout << "ÊäÈëµÄ²»ÊÇ0/1£¬ÇëÖØÊä" << endl;

}