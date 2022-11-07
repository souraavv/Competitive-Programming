
string toStr(int x)
{	
	string s = "";
	if (x < 0) {
		s += "-";
	}
	if (x == 0) return "0";
	while(x > 0)
	{
		s = (char)('0' + (x % 10)) + s;
		x /= 10;
	}
	return s;
}


int toNum(string s)
{	
	
	int x = 0;
	bool neg = false;
	for (int i = 0; i < (int)s.length(); i++) {
		if (i == 0 and s[i] == '-') {
			neg = true;
		}
		else {
			x = 10 * x + (int)(s[i] - '0');
		}
	}
	return neg ? -x : x;
}
