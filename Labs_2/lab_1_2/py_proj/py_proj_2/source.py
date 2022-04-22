import pickle

def create_authors_file(filename, mode):
	'''Create or append to file user input about the book'''

	active = 'y'
	books = []
	with open(filename, mode + 'b') as f:
		while active.lower() == 'y':
			name = input('Enter book name: ')
			write_year = int(input('Enter year of writing: '))
			publish_year = int(input('Enter year of publishing: '))
			
			books.append({'name': name, 'write_year': write_year, 'publish_year': publish_year})
			pickle.dump(books, f)
			
			active = input('Continue? (y/n) ' )

def selective_copy_authors_file(filename, copy_filename):
	'''Copy books that are written less then 4 years ago to a new file'''
	
	with open(filename, 'rb') as fr:
		with open(copy_filename, 'wb') as fw:
			books = pickle.load(fr)
			last_year_books = []
			for book in books:
				if 2022 - book['write_year'] <= 4:
					last_year_books.append(book)

def out_authors_file(filename, message, full_out):
	'''Output the file content to the command line'''

	print(message)
	print(30 * '-')

	with open(filename, 'rb') as f:
		books = pickle.load(f)
		
		count = 0
		for book in books:
			diff = book['publish_year'] - book['write_year']
			if full_out or diff >= 5:
				print(f'Book name: {book["name"]}')
				print(f'\tYear of writing: {book["write_year"]}')
				print(f'\tYear of publishing: {book["publish_year"]}\n')
				count += 1
		
		if not count:
			print('[Empty]')

		print(30 * '-')