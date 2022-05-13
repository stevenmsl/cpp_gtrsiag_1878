#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1878;

/*
Input: grid =  [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
*/

tuple<vector<vector<int>>, vector<int>>
testFixture1()
{
  auto grid = vector<vector<int>>{
      {3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
  auto output = vector<int>{228, 216, 211};
  return make_tuple(grid, output);
}

/*
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]

Output: [20,9,8]
*/

tuple<vector<vector<int>>, vector<int>>
testFixture2()
{
  auto grid = vector<vector<int>>{
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto output = vector<int>{20, 9, 8};
  return make_tuple(grid, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.getBigThree(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.getBigThree(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}