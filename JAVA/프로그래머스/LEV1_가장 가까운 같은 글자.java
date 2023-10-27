class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        for (int i = 0 ; i < s.length() ; i++) {
            int ret = -1;
            char now = s.charAt(i);
            for (int j = i-1 ; j >= 0 ; j--) {
                char before = s.charAt(j);
                if (now == before) {
                    ret = i - j;
                    break;
                }
            }
            answer[i] = ret;
        }
        return answer;
    }
}

import java.util.*;
class Solution {
    public int[] solution(String s) {
        int answer[] = new int[s.length()];
        answer[0] = -1;
        for (int i = 1 ; i < s.length() ; i++) {
            String sub = s.substring(0, i);
            int ret = sub.lastIndexOf(s.charAt(i));
            if (ret == -1) {
                answer[i] = ret;
            } else {
                answer[i] = i - ret;
            }

        }

        return answer;
    }
}