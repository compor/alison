
class Complex {
public:
  Complex(double r, double i): m_r(r), m_i(i) {}

private:
  double m_r, m_i;
};


const int N = 1000;


int
main(int argc, char **argv) {
  Complex *a[N];

  for (int i = 0; i < 50000; i++) {
    for (int j = 0; j < N; j++)
      a[j] = new Complex(i, j);

    for (int j = 0; j < N; j++)
      delete a[j];
  }

  return 0;
}

