# 프로그래머스 Lv.2 교점에 별 만들기

def solution(line):
    answer = []
    star = []
    for i in range(len(line)):
        for j in range(i+1, len(line)):
            x_up = line[i][1]*line[j][2] - line[i][2]*line[j][1]
            x_down = line[i][0]*line[j][1] - line[i][1]*line[j][0]
            
            if x_down == 0: continue
            x = x_up / x_down
            
            y_up = line[i][2]*line[j][0] - line[i][0]*line[j][2]
            y_down = line[i][0]*line[j][1] - line[i][1]*line[j][0]
            
            if y_down == 0: continue
            y = y_up / y_down

            if (x - int(x) == 0) and (y - int(y) == 0):
                star.append((int(x), int(y)))
                
    star.sort()
    x_min, x_max = star[0][0], star[len(star)-1][0]
    star.sort(key=lambda x:x[1])
    y_min, y_max = star[0][1], star[len(star)-1][1]

    for i in range(y_max, y_min-1, -1):
        row = ""
        for j in range(x_min, x_max+1):
            if (j, i) in star: row += '*'
            else: row += '.'
            
        answer.append(row)
        
    return answer
