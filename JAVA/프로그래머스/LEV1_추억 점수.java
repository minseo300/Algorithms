import java.util.*;
class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        Map<String, Integer> nameYearningMap = new HashMap();
        for (int i = 0 ; i < yearning.length ; i++) {
            String n = name[i];
            int y = yearning[i];
            nameYearningMap.put(n,y);
        }
        for (int i = 0 ; i < photo.length ; i++) {
            int score = 0;
            for (int j = 0 ; j < photo[i].length ; j++) {
                String n = photo[i][j];
                if (nameYearningMap.get(n) != null) {
                    score += nameYearningMap.get(n);
                }
            }
            answer[i] = score;
        }
        return answer;
    }
}