// https://chriskohlhepp.wordpress.com/advanced-c-lisp/convergence-of-modern-cplusplus-and-lisp/
// g++ --std=gnu++11 -c 1.cpp 

struct xplusone {
  template<typename T>
  auto operator() (const T& x) const -> decltype ( x + 1 ){
    return x + 1 ;
  };
} xplusone;

int main (int argc, char** argv)
{
  auto x = 2.0;
  auto y = xplusone(x);

  return 0;
}
