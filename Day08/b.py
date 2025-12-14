from collections import defaultdict

import math
import sys

def redirect_IO_to_file():
    sys.stdin = open('in.txt', 'r')
    sys.stdout = open('out.txt', 'w')

def closeIO():
    sys.stdin.close()
    sys.stdout.close()

def read_lines_from_file(sep = None):
    if(sep == None):
        sep = '\n'
    with open('in.txt') as f:
        lines = f.read().split(sep)
    return lines


def solve():
    def find(x):
        if(parent[x] != x):
            parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        rootX = find(x)
        rootY = find(y)

        # print(rootX, rootY)

        if(rootX == rootY):
            return False

        if(size[rootX] < size[rootY]):
            rootX, rootY = rootY, rootX

        parent[rootY] = rootX
        size[rootX] += size[rootY]

        return True

    def calc_dist(p1, p2):
        return math.sqrt(((p1[0] - p2[0]) * (p1[0] - p2[0])) + 
                    ((p1[1] - p2[1]) * (p1[1] - p2[1])) + 
                    ((p1[2] - p2[2]) * (p1[2] - p2[2])))

    junction_boxes = [list(map(int, line.split(','))) for line in read_lines_from_file()]
    # print(junction_boxes)

    parent = list(range(len(junction_boxes)))
    size = [1] * len(junction_boxes)

    # print(parent)
    # print(size)

    dist = defaultdict(list)

    for i in range(len(junction_boxes)):
        for j in range(i + 1, len(junction_boxes)):
            dist[calc_dist(junction_boxes[i], junction_boxes[j])].append([i, j])

    dist = dict(sorted(dist.items()))
    # print(dist)

    done = False

    for dist, point_grps in dist.items():
        if(done):
            break
        for point_grp in point_grps:
            union(point_grp[0], point_grp[1])
            if(max(size) == len(junction_boxes)):
                print(junction_boxes[point_grp[0]][0] * junction_boxes[point_grp[1]][0])
                done = True
                break
                


    # print(size)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()

