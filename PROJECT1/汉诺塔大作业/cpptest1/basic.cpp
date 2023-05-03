void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cout << " 1# " << src << arrow << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n << "# " << src << arrow << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}
