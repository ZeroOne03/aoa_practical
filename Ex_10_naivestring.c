/*
                       EXP 10
AIM : IMPLEMENTION AND ANALYSIS OF NAIVE STRING MATCHING ALGORITHM


THEORY :
The naive string matching algorithm, also known as the brute force or straightforward string matching algorithm,
is a simple and straightforward approach for finding occurrences of a pattern within a text.
It works by systematically comparing the pattern with substrings of the text to determine if there is a match.
*/

/*
ALGORITHM:
Algorithm:
Iterate Through Text:

Start with the first character of the text.
Move one character at a time, comparing substrings of the text with the pattern.
Comparison:

At each position in the text, compare the characters of the text starting from that position with the characters of the pattern.
If all characters of the pattern match the corresponding characters in the substring of the text, a match is found.
Finding Matches:

If a match is found, record the position where the match starts in the text.
Move to the next position in the text and repeat the comparison process.
Repeat:

Continue this process until either the entire text is processed or a match is found.

Example:
Let's say we have a text: "ABABABCABABABABD" and a pattern: "ABAB".

Start comparing the pattern "ABAB" with substrings of the text.
At position 0, compare "ABAB" with "ABAB" in the text. They match.
Record the match at position 0.
Move to the next position in the text.
At position 1, compare "ABAB" with "BABA" in the text. They don't match.
Repeat this process until the end of the text is reached.
*/

/******************* CODE ******************/
#include <stdio.h>
#include <string.h>
void naive_string_matcher(char text[], char pat[])
{
  char temp[100];
  int n = strlen(text);
  int m = strlen(pat);
  int i, j, s, k, count = 0;
  for (s = 0; s <= n; s++)
  {
    for (j = s, k = 0; j < m; j++, k++)
      temp[k] = text[s + k];
    temp[k] = '\0';
    if (strcmp(pat, temp) == 0)
    {
      printf("\n Pattern found at index : %d ", s);
      count++;
    }
    m++;
  }
  printf("\n\n No Of Times Pattern Occurs  %d:", count);
}
int main()
{
  char text[100], pat[100];
  printf("\n ENTER THE TEXT    : ");
  gets(text);
  printf("\n ENTER THE PATTERN : ");
  gets(pat);
  naive_string_matcher(text, pat);
  return 0;
}

/*
OUTPUT:
ENTER THE TEXT    : ababcababa

ENTER THE PATTERN : aba

 Pattern found at index : 0
 Pattern found at index : 2
 Pattern found at index : 7

 No Of Times Pattern Occurs  3:
*/

/*ANALYSIS:
Complexity Analysis:
Time Complexity: The worst-case time complexity of the naive string matching algorithm is O((n-m+1)*m), where:
n is the length of the text.
m is the length of the pattern.
The algorithm compares the pattern with all possible substrings of the text, resulting in (n-m+1) iterations, and each iteration involves comparing m characters.
Space Complexity: The space complexity is O(1) since the algorithm only uses a constant amount of extra space regardless of the size of the input.
*/
