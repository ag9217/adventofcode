coords = open('test.txt').read().splitlines()

gridSize = 10
grid = [['.' for j in range(gridSize)] for i in range(gridSize)]

for coord in coords:
    xy = coord.split(',')
    grid[int(xy[0][0])][int(xy[1][1:])] = 'X'

print(grid)
