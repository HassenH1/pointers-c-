#include <iostream>

using namespace std;

void print(const int *const ray, size_t ray_size)
{
  for (auto i = 0; i < ray_size; i++)
  {
    cout << ray[i] << " ";
  }
  cout << endl;
}

int *apply_all(const int *const ray1, size_t ray1_size, const int *const ray2, size_t ray2_size)
{

  int *new_ray{nullptr};
  //allocating memory
  new_ray = new int[ray1_size * ray2_size];

  int length{0};

  for (auto i = 0; i < ray2_size; i++)
  {
    for (auto j = 0; j < ray1_size; j++)
    {
      new_ray[length++] = ray2[i] * ray1[j];
    }
  }

  return new_ray;
}

int main()
{
  const size_t array1_size{5};
  const size_t array2_size{3};

  int array1[]{1, 2, 3, 4, 5};
  int array2[]{10, 20, 30};

  cout << "Array 1: ";
  print(array1, array1_size);

  cout << "Array 2: ";
  print(array2, array2_size);

  int *results = apply_all(array1, array1_size, array2, array2_size);
  constexpr size_t results_size{array1_size * array2_size};

  cout << "result:";
  print(results, results_size);

  //deallocating memory
  delete[] results;
  cout << endl;

  return 0;
}