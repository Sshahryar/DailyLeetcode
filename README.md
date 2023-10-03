# Leetcode

Repository of my Leetcode journey, starting September 23, 2023. 

Including my solutions for daily challenges, problems and contests. 

Leetcode is a website for technical interview preparation that offers coding problems, challenges, contests, enhancement of problem-solving skills, algorithms and data structures. 

My profile is linked below:

https://leetcode.com/Sshahryar/

Below will be updates on the Daily Challenge Solutions**. Info on other folders in the repository such as courses, challenges, etc. can be found in the wiki. 

**The daily challenge updates are based on this title format: Solution (date) (language, leetcode) (name of challenge) (difficulty). 

**The daily challenge solutions are designed to work on the leetcode, and may or may not work on ide's outside of 
leetcode, because of test cases and specific parameters. 

## Leetcode Daily Challenge Solutions (From .LeetcodeDailySolution): 

### Solution Sept 23, 2023 (Java, leetcode) 1048. LongestStrChain (Medium): 

In .LeetcodeDailySolution folder as Sept23,2023.java

#### Prompt:

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

#### Solution:

    class Solution {
        public int longestStrChain(String[] words) {
            int ans = 0;
            Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));
        
        Map<String, Integer> dp = new HashMap<String, Integer>();
        
        for (String w: words) {
            int best = 0;
            for (int i = 0; i < w.length(); i++) {
                String prev = w.substring(0, i) + w.substring(i + 1);
                best = Math.max(best, dp.getOrDefault(prev, 0) + 1);
            }
            dp.put(w, best);
            ans = Math.max(ans, best);
        }
        return ans;
    }
    }

Runtime: 41 ms, beating 31.27% of leetcode users solutions using java.
Memory: 43.9 mb, beating 34.67% of leetcode users solutions using java.

#### Concepts Applied:

Dynamic programming, arrays, map, and hashmap.
    
### Solution Sept 25, 2023 (Java, leetcode) 389. Find the Difference (Easy):
In .LeetcodeDailySolution folder as Sept25,2023.java

#### Prompt:

You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

#### Solution:

    class Solution {
        public char findTheDifference(String s, String t) {
            int[] charCount = new int[26];
        
        for (char c : s.toCharArray()) {
            charCount[c - 'a']++;
        }
        
        for (char c : t.toCharArray()) {
            charCount[c - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (charCount[i] < 0) {
                return (char) (i + 'a');
            }
        }
        
        return ' ';
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abcd";
        String t = "abcde";
        char addedLetter = solution.findTheDifference(s, t);
        System.out.println("The added letter is: " + addedLetter);
    }
    }

Runtime: 1 ms, beating 100% of leetcode users solutions using java.
Memory: 40.9 mb, beating 20.52% of leetcode users solutions using java.

#### Concepts Applied:

Character arrays and for loop. 

### Solution Sept 26, 2023 (Java, leetcode) 316. Remove Duplicate Letters (Medium): 
In .LeetcodeDailySolution folder as Sept26,2023.java

#### Prompt:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order among all possible results.
 
#### Solution:

    import java.util.Stack;

    class Solution {
    public String removeDuplicateLetters(String s) {
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            if (used[c - 'a']) {
                continue;
            }

            while (!stack.isEmpty() && c < stack.peek() && count[stack.peek() - 'a'] > 0) {
                used[stack.pop() - 'a'] = false;
            }

            stack.push(c);
            used[c - 'a'] = true;
        }

        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }

        return result.toString();
    }
    }
    
Runtime: 2 ms, beating 96.27% of leetcode users solutions using java.
Memory: 41.1 mb, beating 62.98% of leetcode users solutions using java.

#### Concepts Applied:

CharacterArray and stack. 

### Solution Sept 27, 2023 (Java, leetcode) 880. Decoded String at Index (Medium):
In .LeetcodeDailySolution folder as Sept27,2023.java

#### Prompt:

You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

#### Solution:

    class Solution {
    public String decodeAtIndex(String encodedString, int k) {
       Stack<Long> characterLengths = new Stack<>();

        characterLengths.push(0L); 

        for (int i = 0; i < encodedString.length(); i++) {
            char c = encodedString.charAt(i);
            if (Character.isDigit(c)) {

                long length = characterLengths.peek() * (c - '0');
                characterLengths.push(length);
            } else {

                long length = characterLengths.peek() + 1;
                characterLengths.push(length);
            }
        }

        int ln = characterLengths.size();
        while (!characterLengths.isEmpty()) {
            k %= characterLengths.peek(); 
            ln--;

            if (k == 0 && Character.isLetter(encodedString.charAt(ln - 1))) {
                return String.valueOf(encodedString.charAt(ln - 1));
            }


            characterLengths.pop();
        }

        return ""; 
    }
    }

Runtime: 1 ms, beating 13.46% of leetcode users solutions using java.
Memory: 40.8 mb, beating 8.48% of leetcode users solutions using java.

#### Concepts Applied:

Strings, stack, character lengths, e.t.c

### Solution Sept 28, 2023 (Java, leetcode) 905. Sort Array by Parity (Easy):
In .LeetcodeDailySolution folder as Sept28,2023.java

#### Prompt:

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

#### Solution:

    class Solution {
      public int[] sortArrayByParity(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;  

            } else if (nums[right] % 2 == 1) {
                right--;  

            } else {
                
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }

        return nums;
     }
    }

Runtime: 0 ms, beating 100% of leetcode users solutions using java.
Memory: 44.1 mb, beating 40.77% of leetcode users solutions using java.

#### Concepts Applied:

While loop, if and else-if. 

### Solution Sept 29, 2023 (Java, leetcode) 896. Monotonic Array (Easy):
In .LeetcodeDailySolution folder as Sept29,2023.java

#### Prompt: 

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

#### Solution:

    class Solution {
       public boolean isMonotonic(int[] nums) {
        boolean increasing = true;
        boolean decreasing = true;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) {
                increasing = false; 
            } else if (nums[i - 1] < nums[i]) {
                decreasing = false; 
            }
            
            if (!increasing && !decreasing) {
                return false;
            }
        }

        return true; 
      }
    }

Runtime: 2 ms, beating 58.97% of leetcode users solutions using java.
Memory: 54.4 mb, beating 73.26% of leetcode users solutions using java.

#### Concepts Applied:

Booleans, for loop, if, and else-if. 

### Solution Sept 30, 2023 (Java, leetcode) 456. 132 Pattern (Medium):
In .LeetcodeDailySolution folder as Sept30,2023.java

#### Prompt:

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

#### Solution:

    import java.util.Stack;

    class Solution {
       public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] minLeft = new int[n];
        minLeft[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            minLeft[i] = Math.min(minLeft[i - 1], nums[i]);
        }
        
        Stack<Integer> stack = new Stack<>();
        
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > minLeft[j]) {
                while (!stack.isEmpty() && stack.peek() <= minLeft[j]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() < nums[j]) {
                    return true;
                }
                stack.push(nums[j]);
            }
        }
        
        return false;
      }
    }

Runtime: 15 ms, beating 68.8% of leetcode users solutions using java.
Memory: 64.1 mb, beating 8.57% of leetcode users solutions using java.

#### Concepts Applied:

Stack, for and while loop. 

### Solution Oct 1, 2023 (Java, leetcode) 557. Reverse Words In a String III (Easy): 
In .LeetcodeDailySolution folder as Oct1,2023.java

#### Prompt:

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

#### Solution:

    public class Solution {
       public String reverseWords(String s) {
          String[] words = s.split(" "); 

        StringBuilder result = new StringBuilder();

        for (String word : words) {
            
            result.append(reverseWord(word)).append(" ");
        }

        return result.toString().trim(); 

    }

    private String reverseWord(String word) {
        char[] chars = word.toCharArray(); 
        int left = 0;
        int right = chars.length - 1;

        while (left < right) {

            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;

            left++;
            right--;
        }

        return new String(chars); 
      }
    }

Runtime: 4 ms, beating 87.77% of leetcode users solutions using java.
Memory: 43.9 mb, beating 85.88% of leetcode users solutions using java.

#### Concepts Applied:

Character arrays, for and while loop. 

### Solution Oct 2, 2023 (Java, leetcode) 2038. Remove Colored Pieces if Both Neighbors are the Same (Medium): 

#### Prompt:

There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

#### Solution:

    class Solution {
      public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int aliceCount = 0;
        int bobCount = 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (colors.charAt(i) == 'A' && colors.charAt(i - 1) == 'A' && colors.charAt(i +         1) == 'A') {
                aliceCount++;
            } else if (colors.charAt(i) == 'B' && colors.charAt(i - 1) == 'B' && colors.    charAt(i + 1) == 'B') {
                bobCount++;
            }
        }
        
        return aliceCount > bobCount;
      }
    }

Runtime 16 ms, beating 52.45% of leetcode users solutions using java.
Memory: 44.2 mb, beating 55.98% of leetcode users solutions using java. 

#### Concepts Applied:

Strings, for loop, if, else-if, and charAt. 
