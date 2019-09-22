import string
coords = open('test.txt').read().splitlines()

gridSize = 10
grid = [['.' for j in range(gridSize)] for i in range(gridSize)]

i = 0
for coord in coords:
    xy = coord.split(',')
    grid[int(xy[0][0])][int(xy[1][1:])] = string.ascii_letters[i]
    i += 1
