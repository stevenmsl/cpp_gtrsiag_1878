#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol1878;
using namespace std;

/*takeaways
  - brute force
    - iterate through all the possible centers given a dimension k
      - you walk k-1 steps from the center to reach each corner
        of a diamond shape in 4 directions
    - again the indexes are tedious to get it right; watch for that
*/

vector<int> Solution::getBigThree(vector<vector<int>> &grid)
{
  const int m = grid.size(), n = grid[0].size();
  auto sums = vector<int>();

  /* rhombus that only has an area of 0
     - just include one coordinate
  */
  for (auto i = 0; i < m; i++)
    for (auto j = 0; j < n; j++)
      sums.push_back(grid[i][j]);

  /* stretch in all 4 directions so that
     it will have k cells from the
     center to the corner in all 4 directions
     - k will never be as big as min(m,n)
     - but we will kick it out if the rhombus
       is out of bound
  */
  for (auto k = 2; k <= min(m, n); k++)
    /* cy is the row
       - from 0 to the smallest cy you need to have k
         cells: cy - 0 + 1 = k => cy = k-1
       - from the largest cy to m-1 you need to have k
         cells: m-1 - cy + 1 = k => cy + k = m
       - so the eligible cy's are within k-1 <= cy <= m-k
    */
    for (auto cy = k - 1; cy <= m - k; cy++)
      for (auto cx = k - 1; cx <= n - k; cx++)
      {
        /* corners are k-1 steps away from the center */
        auto s =
            /* walk k-1 step to the left */
            grid[cy][cx - (k - 1)] +
            /* right */
            grid[cy][cx + (k - 1)] +
            /* down */
            grid[cy + k - 1][cx] +
            /* up */
            grid[cy - (k - 1)][cx];
        /* everthing else on the border
           - you can only make k - 2 moves
             as the corners have been accounted
             for
        */
        for (auto step = 1; step < k - 1; step++)
          s +=
              /* move cy up and down and look for the left and right
                - the border will be one step closer to cx
              */
              /* move cy up
                 - corner at the left need to walk "step" steps
                   to the right cx - (k-1) + step
                 - corner at the right need to walk "step" steps
                   to the left cx + (k-1) - step
              */
              grid[cy - step][cx - (k - 1) + step] +
              grid[cy - step][cx + (k - 1) - step] +
              /* move cy down
               */
              grid[cy + step][cx - (k - 1) + step] +
              grid[cy + step][cx + (k - 1) - step];

        sums.push_back(s);
      }

  /* pick up top three if possible  */
  sort(sums.rbegin(), sums.rend());
  auto tops = vector<int>();
  for (auto s : sums)
  {
    if (tops.empty() || tops.back() != s)
      tops.push_back(s);
    if (tops.size() == 3)
      break;
  }

  return tops;
}