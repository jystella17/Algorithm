# 프로그래머스 Lv.3 베스트앨범
# 해시(dictionary)를 이용한 구현 문제

def solution(genres, plays):
    answer, times_played, music_info = [], {}, {}
    
    for i in range(len(genres)):
        if genres[i] in music_info:
            music_info[genres[i]].append([i, plays[i]])
        
        else:
            music_info[genres[i]] = [[i, plays[i]]]
    
    for i in range(len(genres)):
        if genres[i] in times_played:
            times_played[genres[i]] += plays[i]
        
        else:
            times_played[genres[i]] = plays[i]
            
    # 각 장르별로, 두 노래의 재생 횟수 합이 큰 장르부터 수록 
    times_played = sorted(times_played.items(), key=lambda x: -x[1])
    
    for genre in times_played:
        # 같은 장르 내에서는 재생 횟수가 더 많은 노래부터 수록
        # 두 노래의 재생 횟수가 같다면, 고유 번호가 작은 노래부터 수록
        music_rank = sorted(music_info[genre[0]], key=lambda x: (-x[1], x[0]))
        
        # 한 장르에 3개 이상의 노래가 수록되어 있다면, 재생 횟수가 가장 많은 2개의 노래만 고려
        if len(music_rank) > 2: 
            music_rank = music_rank[:2]
        
        for music in music_rank:
            answer.append(music[0])
    
    return answer
