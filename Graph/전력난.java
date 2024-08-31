// BOJ 6497 전력난 (G4)
// Kruskal 기본 문제 => PQ + Union Find

import java.io.*;
import java.util.*;

class Info {
    int distance, start, end;

    public Info(int distance, int start, int end) {
        this.distance = distance;
        this.start = start;
        this.end = end;
    }
}

class InfoComparator implements Comparator<Info> {

    @Override
    public int compare(Info i1, Info i2) {
        if(i1.distance == i2.distance) {
            if(i1.start == i2.start) {
                return i1.end - i2.end;
            } else {
                return i1.start - i2.start;
            }
        } else {
            return i1.distance - i2.distance;
        }
    }
}

public class Main {

    static int m, n;
    static int[] parents;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            
            if(m == 0 && n == 0) break;

            parents = new int[m];
            for(int i=0; i<m; i++) {
                parents[i] = i;
            }

            PriorityQueue<Info> pq = new PriorityQueue<>(new InfoComparator());
            int priceSum = 0;
            for(int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());

                pq.offer(new Info(z, x, y));
                priceSum += z;
            }

            int cost = 0;
            while(!pq.isEmpty()) {
                Info info = pq.poll();
                int start = info.start;
                int end = info.end;
                int distance = info.distance;

                if(find(start) == find(end)) continue;

                union(start, end);
                cost += distance;
            }
            bw.write((priceSum - cost) + "\n");
        }
        bw.flush();
        bw.close();
    }

    public static int find(int x) {
        if(x == parents[x]) {
            return x;
        }
        return find(parents[x]);
    }

    public static void union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;
        else if(px < py) parents[py] = px;
        else parents[px] = py;
    }
}
