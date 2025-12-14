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
		val = int(line[1:])
		if(line[0] == 'L'):
			while(val > 0):
				if(pos == 0):
					pos = 100
				val -= 1
				pos -= 1
				if(pos == 0):
					pos = 100
					cntZero += 1

		else:
			while(val > 0):
				val -= 1
				pos += 1
				if(pos == 100):
					pos = 0
					cntZero += 1

		pos %= 100

		# print(line, pos, cntZero)

	print(cntZero)

if __name__ == '__main__':
	redirect_IO_to_file()

	solve()

	closeIO()

