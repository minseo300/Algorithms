import java.util.*;


class Solution {
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];
        int sy = 0 , sx = 0, h = park.length, w = park[0].length();
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        char[][] parkMap = new char[50][50];
        for (int y = 0 ; y < h ; y++) {
            for (int x = 0 ; x < w ; x++) {
                parkMap[y][x] = park[y].charAt(x);
                if (parkMap[y][x] == 'S') {
                    sy = y;
                    sx = x;
                }
            }
        }

        for (int i = 0 ; i < routes.length ; i++) {
            String[] splited = routes[i].split(" ");
            String op = splited[0];
            int move = Integer.valueOf(splited[1]);
            int my = sy, mx = sx;
            int py = my, px = mx, possible = 1;

            for (int m = 0 ; m < move ; m++) {
                if (op.equals("N")) {
                    my = dir[0][0] + my;
                    mx = dir[0][1] + mx;
                } else if (op.equals("S")) {
                    my = dir[1][0] + my;
                    mx = dir[1][1] + mx;
                } else if (op.equals("W")) {
                    my = dir[2][0] + my;
                    mx = dir[2][1] + mx;
                } else if (op.equals("E")) {
                    my = dir[3][0] + my;
                    mx = dir[3][1] + mx;
                }
                if (my < 0 || mx < 0 || my >= h || mx >= w || parkMap[my][mx] == 'X') {
                    possible = 0;
                    break;
                }
            }
            if (possible == 1) {
                sy = my;
                sx = mx;
            }

        }
        answer[0] = sy;
        answer[1] = sx;
        return answer;
    }
}