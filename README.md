# Leetcode

Repository of my Leetcode journey, starting September 23, 2023. 

Including my solutions for daily challenges, problems and contests. 

Leetcode is a website for technical interview preparation that offers coding problems, challenges, contests, enhancement of problem-solving skills, algorithms and data structures. 

My profile is linked below:

https://leetcode.com/Sshahryar/

Below will be updates on the Daily Challenge Solutions**. Info on other folders in the repository such as courses, challenges, etc. can be found in the wiki. 

**The daily challenge updates are based on this title format: Solution (date) (language, leetcode ide) (name of challenge) (difficulty). 

**The daily challenge solutions are designed to work on the leetcode ide, and may or may not work on ide's outside of leetcode. 

## Leetcode Daily Challenge Solutions:

### Solution Sept 23, 2023 (Java, leetcode ide) 1048. LongestStrChain (Medium): 

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

#### Concepts Applied:

Dynamic programming, arrays, map, hashmap, e.t.c
    
### Solution Sept 25, 2023 (Java, leetcode ide) 389. Find the Difference (Easy):

#### Prompt:

You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

#### Solution:

    public class Solution {
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

#### Concepts Applied:

Character arrays.

### Solution Sept 26, 2023 (Java, leetcode ide) 316. Remove Duplicate Letters (Medium): 

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

#### Concepts Applied:

CharacterArray and stack. 

### Solution Sept 27, 2023 (Java, leetcode ide) 880. Decoded String at Index (Medium):

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

#### Concepts Applied:

Strings, stack, character lengths, e.t.c
