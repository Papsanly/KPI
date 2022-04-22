from source import *

filename1 = 'author_books.dat'
filename2 = 'last_years_books.dat'

mode = input(
    'Enter mode: \n'
    '    Create new file - w \n'
    '    Append to existing file - a \n'
    '    View existing file - v \n')

if mode != 'v':
    create_authors_file(filename1, mode)
    selective_copy_authors_file(filename1, filename2)

out_authors_file(filename1, '\nAuthor\'s books:', 1)
out_authors_file(filename1, '\nAuthor\'s books written in the last 4 years:', 1)
out_authors_file(filename1, '\nAuthor\'s books written more than 5 years after writing', 0)