void hanoi(int n, char src, char tmp, char dst)
{
	static int num = 0;
	if (n == 1) {
		num++;
		cout << setw(5) << num << ":  1# " << src << arrow << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	cout << "µÚ" << setw(4) << num << " ²½( " << setw(2) << n << "#: " << src << "-->" << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}