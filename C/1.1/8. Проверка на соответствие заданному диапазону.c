int Inside(double x, double a, double b);
int Inside(double x, double a, double b) {
	int ans = 0;
	ans = (x > b) ? 1 : ((x < a) ? -1 : ans);
}
