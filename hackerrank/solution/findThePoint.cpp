#include <bits/stdc++.h>

using namespace std;

/* ******************************************************************************
*  GOAL: output the point reflection coordinates as rx ry 
*  INPUT: first value is the total number of test cases

*  2 // total number of test cases
*  0 0 1 1 // this is px py qx qy
*  1 1 2 2 // this is px py qx qy
*
*  OUTPUT: You are responsible for outputing each r coordinates on separate line
*  the total number of lines in the output should be the same as the total number of
*  test cases
*
*  2 2 // rx ry
*  3 3 // rx ry
*/

// declaring the function for handling input

vector<std::string> split_string(std::string);

// THIS CODE SNIPPET IS MY ACTUAL SOLUTION, EVERYTHING ELSE IS FROM HACKERRANK
vector<int> solve(int px, int py, int qx, int qy) {
    vector<int> result;

    int rx = (2 * qx) - px;
    int ry = (2 * qy) - py;

    result.push_back(rx);
    result.push_back(ry);

    return result;

}

// this is directly from hackerrank to handle input and format the output
int main() {
  /* this line of code is create an output file with the filename from the value 
  * from the environment variable OUTPUT_FILE
  */
  ofstream fout(getenv("OUTPUT_FILE"));
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < n; i++) {
    string pxPyQxQy_temp;
    getline(cin, pxPyQxQy_temp);

    vector<string> pxPyQxQy = split_string(pxPyQxQy_temp);

    // converting each element into an integer using stoi 
    int px = stoi(pxPyQxQy[0]);
    int py = stoi(pxPyQxQy[1]);
    int qx = stoi(pxPyQxQy[2]);
    int qy = stoi(pxPyQxQy[3]);

    
    vector<int> result = solve(px, py, qx, qy);

    // I think this part here is totally unnecessary, but hackerrank did it this way
    for (int result_itr = 0; result_itr < result.size; result_itr++) {
      fout << result[result_itr];

      if (result_itr != result.size() - 1) {
        fout << " ";
      }
    }

    fout << "\n";

  }
  fout.close();

  return 0;
}

// this is the definition of the function declared above
vector<int> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), []
  (const char &x, const char &y) {
    return x == y and x == " ";
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter, i);

  while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

