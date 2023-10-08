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

### Solution Sept 23, 2023 (Java, leetcode) 1048. LongestStrChain (Medium) 

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
    
### Solution Sept 25, 2023 (Java, leetcode) 389. Find the Difference (Easy)
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

### Solution Sept 26, 2023 (Java, leetcode) 316. Remove Duplicate Letters (Medium) 
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

### Solution Sept 27, 2023 (Java, leetcode) 880. Decoded String at Index (Medium)
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

### Solution Sept 28, 2023 (Java, leetcode) 905. Sort Array by Parity (Easy)
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

### Solution Sept 29, 2023 (Java, leetcode) 896. Monotonic Array (Easy)
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

### Solution Sept 30, 2023 (Java, leetcode) 456. 132 Pattern (Medium)
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

### Solution Oct 1, 2023 (Java, leetcode) 557. Reverse Words In a String III (Easy) 
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

    class Solution {
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

### Solution Oct 2, 2023 (Java, leetcode) 2038. Remove Colored Pieces if Both Neighbors are the Same (Medium) 
In .LeetcodeDailySolution folder as Oct2,2023.java

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

Runtime: 16 ms, beating 52.45% of leetcode users solutions using java.
Memory: 44.2 mb, beating 55.98% of leetcode users solutions using java. 

#### Concepts Applied:

Strings, for loop, if, else-if, and charAt. 

### Solution Oct 3, 2023 (Java, leetcode) 1512. Number of Good Pairs (Easy) 
In .LeetcodeDailySolution folder as Oct3,2023.java

#### Prompt:

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

#### Solution:

    class Solution {
       public int numIdenticalPairs(int[] nums) {
           int[] count = new int[101]; 

        for (int num : nums) {
            count[num]++;
        }
        
        int goodPairs = 0;
        
        for (int c : count) {
            if (c > 1) {
                goodPairs += (c * (c - 1)) / 2;
            }
        }
        
        return goodPairs;
      }
    }

Runtime: 0 ms, beating 100% of leetcode users solutions using java.
Memory: 40, beating 34.61% of leetcode users solutions using java. 

#### Concepts Applied:

For loop.

### Solution Oct 4, 2023 (Java, leetcode) 706. Design HashMap (Easy)
In .LeetcodeDailySolution folder as Oct4,2023.java

#### Prompt:

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

#### Solution

    import java.util.ArrayList;
    import java.util.List;
  
    class MyHashMap {

    private static final int SIZE = 1000;
    private List<List<int[]>> data;

    public MyHashMap() {
        data = new ArrayList<>(SIZE);
        for (int i = 0; i < SIZE; i++) {
            data.add(new ArrayList<>());
        }
    }

    private int getIndex(int key) {
        return Integer.hashCode(key) % SIZE;
    }

    public void put(int key, int value) {
        int index = getIndex(key);
        for (int[] entry : data.get(index)) {
            if (entry[0] == key) {
                entry[1] = value;
                return;
            }
        }
        data.get(index).add(new int[]{key, value});
    }

    public int get(int key) {
        int index = getIndex(key);
        for (int[] entry : data.get(index)) {
            if (entry[0] == key) {
                return entry[1];
            }
        }
        return -1;
    }

    public void remove(int key) {
        int index = getIndex(key);
        List<int[]> entries = data.get(index);
        for (int i = 0; i < entries.size(); i++) {
            if (entries.get(i)[0] == key) {
                entries.remove(i);
                return;
            }
        }
      }
    }

    public class Main {
      public static void main(String[] args) {
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1);
        myHashMap.put(2, 2);
        System.out.println(myHashMap.get(1)); 
        System.out.println(myHashMap.get(3)); 
        myHashMap.put(2, 1);
        System.out.println(myHashMap.get(2)); 
        myHashMap.remove(2);
        System.out.println(myHashMap.get(2)); 
      }
    }

Runtime: 17 ms, beating 65.77% of leetcode users using java.
Memory: 47.6 mb, beating 69.68% of leetcode users using java.

#### Concepts Applied:

Array, hash table, linked list, design, and hash function.

### Soluton Oct 5, 2023 (Java, leetcode) 229. Majorty Element II (Medium)
In .LeetcodeDailySolution folder as Oct5,2023.java

#### Prompt:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#### Solution:

    import java.util.ArrayList;
    import java.util.List;

    class Solution {
      public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int n = nums.length;

        if (n == 0) return result;

        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        if (count1 > n / 3) {
            result.add(candidate1);
        }
        if (count2 > n / 3) {
            result.add(candidate2);
        }

        return result;
      }
    }

Runtime: 1 ms, beating 99.94% of leetcode users solutions using java. 
Memory: 47.2 mb, beating 10.66% of leetcode users solutions using java.

#### Concepts Applied:

Array, hash table, sorting, and counting.

### Solution Oct 6, 2023 (Java, leetcode) 343. Integer Break (Medium)
In .LeetcodeDailySolution folder as Oct6,2023.java

#### Prompt:

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

#### Solution:

    class Solution {
        public int integerBreak(int n) {
                if(n == 1) return 1;
                        int[] dp = new int[n + 1];
                                dp[1] = 1;
                                        for(int i = 2; i <= n; i++){
                                                    for(int j = 1; j < i; j++){
                                                                    dp[i] = Math.max(dp[i], Math.max(j * (i - j), j * dp[i - j]));
                                                                                }
                                                                                        }
                                                                                                return dp[n];
                                                                                                    }
                                                                                                    }
                                                                                                    
Runtime: 1 ms, beating 33.22% of leetcode users solutions using java.
Memory: 39.9 mb, beating 6.52% of leetcode users solutions using java.

#### Concepts Applied:

Dynamic programming and for loop.

### Solution Oct7, 2023 (Java, leetcode) 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons (Hard)
Im .LeetcodeDailySolution folder as Oct7,2023.java

#### Prompt:

You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

![image](https://github.com/Sshahryar/Leetcode/assets/123003299/213847ce-4a27-441a-9b8a-06910e1736ce)

You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

#### Solution:

    class Solution {
        public int numOfArrays(int n, int m, int k) {
        long[][][] dp = new long[n][k][m];
        long mod = 1000000007;
        Arrays.fill(dp[0][0], 1);
        
        for (int i = 1; i < n; i++) {
            for (int cost = 0; cost < Math.min(i + 1, k); cost++) {
                for (int max = 0; max < m; max++) {
                    dp[i][cost][max] = (dp[i][cost][max] + (max + 1) * dp[i - 1][cost][max]) % mod;
                    if (cost != 0) {
                        long sum = 0;
                        for (int prevMax = 0; prevMax < max; prevMax++) {
                            sum += dp[i - 1][cost - 1][prevMax];
                            sum %= mod;
                        }
                        dp[i][cost][max] = (dp[i][cost][max] + sum) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (int max = 0; max < m; max++) {
            ans += dp[n - 1][k - 1][max];
            ans %= mod;
        }
        return (int) ans;
      }
    }

Runtime: 27 ms, beating 85.37% of leetcode users solutions using java.
Memory: 43.6 mb, beating 24.29% of leetcode users solutions using java.

#### Concepts Applied:

Arrays, for loop, dynamic programming, and if statements.

### Solution Oct 8, 2023 (Java, leetcode) 1458. Max Dot Product of Two Subtances (Hard):
In .LeetcodeDailySolutions folder as Oct8,2023.java

#### Prompt:

Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

#### Solution:

    class Solution {
        public int maxDotProduct(int[] nums1, int[] nums2) {
        int[][] marks = new int[nums1.length][nums2.length];
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                int max = nums1[i] * nums2[j];
                if (i > 0 && j > 0) {
                    max = Math.max(max, max + marks[i - 1][j - 1]);
                }
                if (i > 0) {
                    max = Math.max(max, marks[i - 1][j]);
                }
                if (j > 0) {
                    max = Math.max(max, marks[i][j - 1]);
                }
                marks[i][j] = max;
            }
        }
        return marks[nums1.length - 1][nums2.length - 1];
      }
    }
    
Runtime: 10 ms, beating 81.94% of leetcode users solutions using java.
Memory: 42.9 mb, beating 80.56% of leetcode users solutions using java.

#### Concepts Applied:

Math, for-loop and if statements.
