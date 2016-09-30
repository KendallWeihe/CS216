Author: Kendall Weihe
Assignment: CS216 Fall 2016 Project 1
Purpose: Use linked list to implement a single line text editor



General pseudocode:
	Class DocumentList
		data:
			head --> points to beginning of linked list of Document nodes
		public:
			constructor: head = NULL 
			insert_line(): inserts line specified by line number
			delete_line(): deletes line specified by line number
			print_all_lines(): prints
			save_document()
			

	Class Document:
		data:
			string: line
			Document *next_line
		public:
			constructor: line, pointer to next basket
			get_line: returns line (text)
			get_next_line: returns pointer to next line

			
	main():
		functions:
			print_instructions()
			input_text_file():
				read in text file, getline()
				invoke DocumentList.insert_line(line, n)			

		loop until user enters q || Q
			print command prompt >
			if I
				cin user input 
				pass input and line number to DocumentList.insert_line()
			elif D
				invoke DocumentList.delete_line(n)
			elif P
				invoke DocumentList.print_all_lines()
			elif s
				invoke DocumentList.save_document(argv[1]) //file to save

