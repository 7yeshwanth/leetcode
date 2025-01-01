class Solution
{
public:
  double myPow(double x, long n)
  {
    if (n == 0)
    {
      return 1;
    }
    if (n >= 0)
    {
      if (n % 2 == 0)
      {
        auto t = myPow(x, n / 2);
        return t * t;
      }
      return x * myPow(x, n - 1);
    }
    else
    {
      return 1 / (x * myPow(x, abs(n) - 1));
    }
  }
};