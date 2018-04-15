#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void rand_input(int* arr, int nod, int len){
  int dtr = 2 * pow(10, nod) - 1;
  for (int i = 0; i < len; i++){
    arr[i] = (rand() % dtr) + 1 - pow(10, nod);
  }
}

void print(int* arr, int len){
  cout << endl;
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void Countig_sort_part(int* arr, int digit_number, int len){
  int result_arr[len] = {};
  int dtr = pow(10,digit_number - 1); // dtr - delimiter
  int min = (arr[0] / dtr) % 10;
  int max = (arr[0] / dtr) % 10;
  for (int i = 0; i < len; i++){
    if ((arr[i] / dtr) % 10 < min) min = (arr[i] / dtr) % 10;
    if ((arr[i] / dtr) % 10 > max) max = (arr[i] / dtr) % 10;
  }
  int c_len = max - min + 1;
  int counting_array[c_len] = {};
  for (int i = 0; i < len; i++){
    counting_array[(arr[i] / dtr) % 10 - min]++;
  }
  for (int i = 1; i < c_len; i++){
    counting_array[i] += counting_array[i - 1];
  }
  for (int i = len - 1; i >= 0; i--){
    result_arr[counting_array[(arr[i] / dtr) % 10 - min] - 1] = arr[i];
    counting_array[(arr[i] / dtr) % 10 - min]--;
  }
  for (int i = 0; i < len; i++) arr[i] = result_arr[i];
}

void Radix_sort(int* arr, int nod, int len){
  for (int i = 1; i <= nod; i++){
    Countig_sort_part(arr, i, len);
  }
}
int main(){
  srand(time(NULL));
  cout << endl << "Please, input number of elements: ";
  int LEN; // length of input array;
  cin >> LEN;
  cout << endl << "Please, input number of digits: ";
  int NOD; // Number Of digits
  cin >> NOD;
  int *array = new int[LEN];
  rand_input(array, NOD, LEN);
  print(array, LEN);
  Radix_sort(array, NOD, LEN);
  print(array, LEN);
}
