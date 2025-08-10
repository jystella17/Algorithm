// 기존 풀이에서 verbose한 코드를 수정한 버전

import java.util.*;

class Music {
    int number;
    int playCnt;
    
    public Music(int number, int playCnt) {
        this.number = number;
        this.playCnt = playCnt;
    }
}

class MusicComparator implements Comparator<Music> {
    @Override
    public int compare(Music m1, Music m2) {
        if(m1.playCnt == m2.playCnt) {
            return m1.number - m2.number;
        }
        return m2.playCnt - m1.playCnt;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        
        HashMap<String, Integer> totalPlay = new HashMap<>();
        HashMap<String, List<Music>> musicLists = new HashMap<>();
        
        for(int i=0; i<genres.length; i++) {
            totalPlay.merge(genres[i], plays[i], Integer::sum);
            musicLists.computeIfAbsent(genres[i], mList -> new ArrayList<>()).add(new Music(i, plays[i]));
        }
        
        List<String> genreList = new ArrayList<>(totalPlay.keySet());
        genreList.sort((o1, o2) -> totalPlay.get(o2) - totalPlay.get(o1));
        
        for(String genre: genreList) {
            List<Music> musicList = musicLists.get(genre);
            Collections.sort(musicList, new MusicComparator());

            for(int i=0; i<Math.min(musicList.size(), 2); i++) {
                answer.add(musicList.get(i).number);
            }
        }

        return answer.stream().mapToInt(i->i).toArray();
    }
}
