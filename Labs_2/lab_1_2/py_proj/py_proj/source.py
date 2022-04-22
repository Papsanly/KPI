def write_to_file(filename):
	'''Write user input to file'''
	
	mode = input('Enter mode'
		'\n    create new file - w'
		'\n    append to existing file - a\n')
	
	with open(filename, mode) as f:
		print('Enter text\nEnd with CTRL+S\n')
		text = ''
		while True:
			text += input()
			if text[-1] == '\x13':
				break
			else:
				text += '\n'
		text = text.replace('\x13', '')
	
		f.write(text)

def manipulate_file(in_filename, out_filename):
	'''Create manipulated file based on input file'''

	with open(out_filename, 'w') as fw:
		with open(in_filename, 'r') as fr:
			for line in fr:
				fw.write(manipulate(line) + '\n')

def manipulate(line):
	'''Manipulate single line string according to the task'''

	words = line.split();
	new_line = words[0]

	new_line += '  '.join(words[1:-1])
	new_line += words[-1]

	return new_line + f' [{len(words) - 3}]'

def output_file(message, filename):
	'''Output file content to the console'''

	print(message)
	with open(filename, 'r') as f:
		print(f.read())