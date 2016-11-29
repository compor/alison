
#include <iostream>
// using std::cout

#include <chrono>
// using std::chrono::system_clock::now
// using std::chrono::time_point
// using std::chrono::duration

#include <cstdlib>
// using std::malloc
// using std::free


class IMemoryManager {
public:
  virtual void *allocate(size_t size) = 0;
  virtual void free(void *) = 0;
};

class MemoryManager : public IMemoryManager {
public:
  MemoryManager() {}
  virtual ~MemoryManager() {}
  virtual void *allocate(size_t size) {
    return std::malloc(size);
  }

  virtual void free(void *ptr) {
    std::free(ptr);
  }
};

MemoryManager gMemoryManager;

void *operator new(size_t size) {
  return gMemoryManager.allocate(size);
}

void *operator new[](size_t size) {
  return gMemoryManager.allocate(size);
}

void operator delete(void *ptr) {
  gMemoryManager.free(ptr);

  return;
}

void operator delete[](void *ptr) {
  gMemoryManager.free(ptr);

  return;
}


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

  auto start = std::chrono::system_clock::now();
  auto end = std::chrono::system_clock::now();

  for (int i = 0; i < 50000; i++) {
    for (int j = 0; j < N; j++)
      a[j] = new Complex(i, j);

    for (int j = 0; j < N; j++)
      delete a[j];
  }

  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;

  std::cout << "elapsed time: " << elapsed.count() << " secs\n";

  return 0;
}

