def get_min_list(char_dict):
	min_val = min(char_dict.items(), key = lambda item: item[1])[1]
	min_list = [k for k, v in char_dict.items() if v == min_val]
	return min_val, min_list

def get_max_list(char_dict):
	max_val = max(char_dict.items(), key = lambda item: item[1])[1]
	max_list = [k for k, v in char_dict.items() if v == max_val]
	return max_val, max_list

print('Reading... ', end = '')
with open('pi_billion.txt') as file_obj:
	string = file_obj.read()
string = string.replace('\n', '')
string = string.replace('.', '')
print('Done')

print('Getting char dictionary ', end = '')
char_dict = {}
i = 0
while string:
	char = string[i]
	char_dict[char] = string.count(char)
	string = string.replace(char, '')
	i += 1
	print('-', end = '')
print(' Done')

char_dict = {k: v for k, v in sorted(char_dict.items(), key = lambda item: item[1])}
print('\nCharacter dictionary:', char_dict)

min_val, min_list = get_min_list(char_dict)
print ('Character(s) with minimum amount of occurance (no spaces):', min_list, f'- {min_val} time(s)')

max_val, max_list = get_max_list(char_dict)
print ('Character(s) with maximum amount of occurance (no spaces):', max_list, f'- {max_val} time(s)')