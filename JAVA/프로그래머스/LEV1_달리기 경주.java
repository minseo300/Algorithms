import java.util.*;
class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        Map<String, Integer> nameRank = new HashMap();
        Map<Integer, String> rankName = new HashMap();
        for (int i = 0 ; i < players.length ; i++) {
            nameRank.put(players[i], i);
            rankName.put(i, players[i]);
        }
        for (int i = 0; i < callings.length ; i++ ) {
            int calleeRank = nameRank.get(callings[i]);
            String loserName = rankName.get(calleeRank - 1);
            // players[calleeRank] = loserName;
            // players[calleeRank - 1] = callings[i];
            nameRank.put(callings[i], calleeRank - 1);
            rankName.put(calleeRank - 1, callings[i]);
            nameRank.put(loserName, calleeRank);
            rankName.put(calleeRank, loserName);
        }

        for (int i = 0 ; i < players.length ; i++) {
            answer[i] = rankName.get(i);
        }

        return answer;
    }
}