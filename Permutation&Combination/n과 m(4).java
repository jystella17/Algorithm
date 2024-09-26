// BOJ 15652 N과 M(4) (S3)
// 중복조합

import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static int[] selected; // 같은 숫자를 중복해서 선택할 수 있으므로, 선택 여부가 아닌 횟수를 저장

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        selected = new int[n];

        bw.write(combination(0, 0) + "\n");
        bw.flush();
        bw.close();
    }

    public static String combination(int idx, int cnt) {
        if(cnt == m) {
            String result = "";

            for(int i=0; i<n; i++) {
                for(int j=0; j<selected[i]; j++){
                    result += (i+1);
                    result += " ";
                }
            }
            result += "\n";
            return result;
        }

        String result = "";
        for(int i=idx; i<n; i++) {
            selected[i]++;
            // 중복 조합은 현재 선택한 숫자를 다시 선택 가능 => i+1가 아닌 i를 파라미터로 넘김
            result += combination(i, cnt+1);
            selected[i]--;
        }

        return result;
    }
}
