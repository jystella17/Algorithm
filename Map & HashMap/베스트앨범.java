// 프로그래머스 Lv.3 베스트앨범
// HashMap 정렬 (Sort by Value) & Comparator 구현

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
            if(totalPlay.containsKey(genres[i])) {
                int count = totalPlay.get(genres[i]);
                List<Music> mList = musicLists.get(genres[i]);
                mList.add(new Music(i, plays[i]));
                
                totalPlay.replace(genres[i], count+plays[i]);
                musicLists.replace(genres[i], mList);
            }
            
            else {
                totalPlay.put(genres[i], plays[i]);
                List<Music> mList = new ArrayList<>();
                mList.add(new Music(i, plays[i]));
                musicLists.put(genres[i], mList);
            }
        }

        List<Map.Entry<String, Integer>> genreList = new LinkedList<>(totalPlay.entrySet());
        genreList.sort(((o1, o2) -> totalPlay.get(o2.getKey()) - totalPlay.get(o1.getKey())));
        
        for(Map.Entry<String, Integer> genre: genreList) {
            List<Music> musicList = musicLists.get(genre.getKey());
            Collections.sort(musicList, new MusicComparator());
            
            int length = musicList.size() >= 2 ? 2 : 1;
            for(int i=0; i<length; i++) {
                Music music = musicList.get(i);
                answer.add(music.number);
            }
        }

        return answer.stream().mapToInt(i->i).toArray();
    }
}
