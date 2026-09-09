class Solution {
    public int longestPalindrome(String s) {

        HashMap <Character,Integer> hm = new HashMap <> ();
        int result = 0;
        int count = 0;

        for (int i = 0 ; i < s.length() ; i++ ) {
            hm.put(s.charAt(i),hm.getOrDefault(s.charAt(i),0)+1);
        }

        for (Map.Entry <Character,Integer> entry : hm.entrySet() ) {
            if (entry.getValue() % 2 == 0 ) {
                result +=entry.getValue();

            }
            else {
                result += entry.getValue()-1;
                count++;
            }
        }
        if (count > 0 && result % 2==0) {
            result++;
        }
        return result;
  
    }
}