from source import *

out_filename = 'user_input.txt'
in_filename = 'manipulated.txt'

write_to_file(out_filename)
manipulate_file(out_filename, in_filename)
output_file('\nUser input text file:', out_filename)
output_file('\nUser input text file:', in_filename)