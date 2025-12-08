import sys

def redirect_IO_to_file():
	sys.stdin = open('in.txt', 'r')
	sys.stdout = open('out.txt', 'w')

def closeIO():
	sys.stdin.close()
	sys.stdout.close()

def read_lines_from_file():
	with open('in.txt') as f:
		lines = f.read().split('\n')
	return lines


def solve():
	lines = read_lines_from_file()
	pos = 50
	cntZero = 0
	for line in lines:
		is_left_touched_zero = False
		if(line[0] == 'L'):
			pos -= int(line[1:])
			is_left_touched_zero = (pos + int(line[1:]) > 0 and pos <= 0)

		else:
			pos += int(line[1:])


		cntZero = cntZero + int(pos / 100) + is_left_touched_zero
		
		# print(line, pos, is_left_touched_zero, cntZero)

		pos = pos % 100
		
		# print(pos)

	print(cntZero)

if __name__ == '__main__':
	redirect_IO_to_file()

	solve()

	closeIO()

