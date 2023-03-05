def solution(n, m, x, y, r, c, k):
    def dfs(x, y, idx, path):
        if flag or abs(x - r) + abs(y - c) + idx > k:
            return

        if idx == k:
            if (x, y) == (r, c):
                flag = True
                answer.append(path)
            return

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                dfs(nx, ny, idx + 1, path + directions[i])

    z = k - abs(x - r) + abs(y - c)
    if z < 0 or z % 2 != 0:
        return 'impossible'

    flag = False
    directions = ['d', 'l', 'r', 'u']
    dx = [1, 0, 0, -1]
    dy = [0, -1, 1, 0]
    r, c = r - 1, c - 1

    answer = []
    dfs(x - 1, y - 1, 0, '')
    if not answer:
        return 'impossible'
    else:
        return answer[0]
