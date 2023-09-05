def solve():
    n, m = [int(x) for x in input().split()]
    maze = [[char for char in input()] for i in range(n)]

    explored = set()
    exploredDots = 0

    def isValid(x, y):
        if x >=n or x<0: return False
        if y>=m or y<0: return False
        if maze[x][y] == 'X': return False
        return True

    def floodFill(x, y):
        nonlocal exploredDots
        if (x, y) in explored: return
        if maze[x][y] == '.':
            exploredDots += 1
        explored.add((x, y))

        directions = [[1,0], [-1,0], [0,1], [0,-1]]
        for xChange, yChange in directions:
            if isValid(x + xChange, y+yChange) and (x+xChange, y+yChange) not in startPoints: floodFill(x + xChange, y + yChange)


    startPoints = set()

    # Find starting points
    for y in range(m):
        if maze[0][y] != 'X': startPoints.add((0, y))
        if maze[n-1][y] != 'X': startPoints.add((n-1, y))
    for x in range(n):
        if maze[x][0] != 'X': startPoints.add((x, 0))
        if maze[x][m-1] != 'X': startPoints.add((x, m-1))

    # Find total number of dots
    dots = 0
    for x in range(n):
        for y in range(m):
            if maze[x][y] == '.':
                dots += 1

    # Flood fill on each start point
    usefulPoints = 0
    for point in startPoints:
        curExplored = exploredDots
        x, y = point
        floodFill(x, y)

        if exploredDots > curExplored:
            usefulPoints += 1

    print(str(usefulPoints) + ' ' + str(dots - exploredDots))

if __name__ == "__main__":
    solve()