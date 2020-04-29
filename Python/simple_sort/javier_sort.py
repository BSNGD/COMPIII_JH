# Javier Hernandez
# javier_sort.py
# this program will sort arguments from the command line in ascending order
# ex. python javier_sort.py lorem ipsum dolor sit amet
# output: [['amet', 'dolor', 'ipsum', 'lorem', 'sit']]
# -r, -reverse option will sort arguments in descending order
# output: [['sit', 'lorem', 'ipsum', 'dolor', 'amet']]

import argparse
# * in nargs adds to list if any arguments are found, + will expect an argument
parser = argparse.ArgumentParser()
parser.add_argument('-r','--reverse', help='Descending sort', required=False, action="store_true" )
parser.add_argument("input", nargs='*', help="List of arguments added to the list to sort")
args = parser.parse_args()


def my_sorter (arguments):
	for inputs in arguments:
		if args.reverse:
			inputs.sort(reverse=True)
		else:
			inputs.sort()
		if 2 > (len(inputs)):
			print ("Invalid command line arguments to program. Please, supply two or more strings to sort.")
		else:
			print ("Arguments are :", inputs)
			
my_sorter([args.input])