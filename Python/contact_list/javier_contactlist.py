# Javier Hernandez
# javier_contactlist.py
#
# clf(contact list files) are comma separated values with 5 columns for contact info
# this program has the following options:
# create a clf file, open a clf file
# add new entries to bottom of list, print the entire contents of the list
# search contact inside list and edit a contact
# ex. python javier_contactlist.py


import sys
import csv #using csv library to read and write csv files
import re #using re library for string manipulation
import os #using os library to read/write files

class WorkingRow:
    def __init__(self, idnumber, firstname, lastname, email, phone):
        self.idnumber = int(idnumber)
        self.firstname = firstname
        self.lastname = lastname
        self.email = email
        self.phone = phone
   
    def ChangeValues(self, *sameid):
        if sameid:
            self.idnumber = self.idnumber
        else:
            self.idnumber = self.idnumber + 1
        #making sure that first and last name have capital letters
        #for their first letter, also truncating the inputs
        while True:    
            try:
                self.firstname = str(input("Enter first name: "))[:14]
                self.firstname = self.firstname.capitalize()
                if not self.firstname:
                    raise SyntaxError
                break
            except SyntaxError:
                print ("Invalid Syntax encountered at first name input")
                continue            
        while True:    
            try:
                self.lastname = str(input("Enter last name: "))[:14]
                self.lastname = self.lastname.capitalize()
                if not self.lastname:
                    raise SyntaxError
                break
            except SyntaxError:
                print ("Invalid Syntax encountered at last name input")
                continue            
        #making three groups of regex to validate syntax of email
        #raising an error if email input is too long to fit into formatted cell
        while True:
            try:
                self.email = str(input("Enter email address: "))[:29]
                #using regex *study
                match = re.match('^[_a-zA-Z0-9-]+(\.[_a-zA-Z0-9-]+)*@[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)*(\.[a-zA-Z]{2,4})$', self.email)
                if match == None or not match or len(self.email) > 29:
                    raise SyntaxError
                break
            except SyntaxError:
                print ("Invalid Syntax encountered at email input")
                continue
        #validating a phone number entered at most 10 digits
        while True:
            try:
                self.phone = str(input("Enter a 10 digit phone number: "))[:10]
                if len(self.phone) > 10 or not self.phone or not self.phone.isdigit():
                    raise SyntaxError
                break
            except SyntaxError:
                print ("Invalid Syntax encountered at phone number input")
                continue
            break
        
    def GetValues(self):
        return[self.idnumber, self.firstname, self.lastname, self.email, self.phone]

    def PrintAll(self):
        print("%5s"%self.idnumber,"%15s"%self.firstname,"%15s"%self.lastname,"%30s"%self.email,"%11s"%self.phone)


def Main():
    mainLoop = True
    while mainLoop:
        MainMenu()

def MainMenu():
    print ("""--------------MAIN-MENU-----------------
Input 1 to create new contact list file
Input 2 for contact list entry management
Input 0 to exit at any input
-----------------------------------------""")
    myChoice = input("Enter your choice: ")
    if myChoice == '1':
        CreateManager()
    elif myChoice == '2':
        EntryManager()
    elif myChoice == '0':
        sys.exit(0)
    else:
        print("Wrong option chosen. Try again")
       
def CreateManager():
    print ("-----------------FILE-CREATOR-----------------")
    print("Current contact list files in directory:")
    for dirFiles in os.listdir("."):
        if dirFiles.endswith(".clf"):
            print(dirFiles)
        if not dirFiles:
            print ("no clf files found")
    print ("-" * 46)    
    print ("Invalid characters will be removed from input")

    while True:
        filename = str(input("Input name of new contact list file: "))
        if filename =='0':
            print("Going back to main menu")
            return
        elif not filename:
            print("No value entered. Please try again")
            continue
        elif filename.endswith(".clf"):
            filename = filename
        # removing invalid characters from filename variable for Windows...
        elif filename:
            filename = re.sub(r'[\\/*?:"<>|]',"",filename)
            filename = filename + ".clf"
        try:
            open(filename, "x")
            print ("Contact list created with name: ", filename)
            print("Going back to main menu\n")
            #adding row 0 with info to new file
            Entrybook = WorkingRow(0, "First name", "Last Name", "Email", "Phone")
            WriteToFile(filename, Entrybook.GetValues())
        except FileExistsError:
            print("File with same name already exists")
            continue
        return

def EntryManager():
    fileList = []
    # printing the files in directory with extension clf 
    # and storing them in a list
    print("Contact list files in directory: ")
    for dirFiles in os.listdir("."):
        if dirFiles.endswith(".clf"):
            fileList.append(dirFiles)    
            print(dirFiles)

    while True:
        addressFile = str(input("Enter the name of contact list file: "))
        if addressFile == '0':
            print("Going back to main menu")
            return
        elif not addressFile.endswith(".clf"):
            addressFile = addressFile + ".clf"
        if not (addressFile in fileList):
            print("no Match")
            continue
        else:
            break
   
    while True:
        #this should allow the line to be large enough to cover the filename
        print ("-" * (len(addressFile) + 35))
        print ("Working with dataset from: ", addressFile)
        print ("1 - add new entry to contact list")
        print ("2 - print contents of contact list")
        print ("3 - search for contacts")
        print ("4 - edit a contact")
        print ("-" * (len(addressFile) + 35))
        
        entryTemp = input("Enter your option: ")
        if entryTemp == '0':
            print("Going back to main menu")
            return
        if entryTemp == '1':
            AddNewRow(addressFile)
        elif entryTemp == '2':
            ReadBook(addressFile)
        elif entryTemp == '3':
            SearchContacts(addressFile)
        elif entryTemp == '4':
            EditRow(addressFile)
        else:
            print("Wrong option chosen. Try again")
            continue
  
def AddNewRow(addressFile):    
    print ("Working with dataset from: ", addressFile)  
    #Reading file and storing last row into WorkingRow class
    with open(addressFile, 'r') as csvFile:
        csvReader = csv.reader(csvFile, delimiter=',')
        for row in csvReader:
            Entrybook = WorkingRow(*row)

    Entrybook.ChangeValues()
    print("Adding entry to address book")
    WriteToFile(addressFile, Entrybook.GetValues())
    Entrybook.PrintAll()
    return

def EditRow(addressFile):
    query = input("Enter id number to edit: ")
    #opening working file and a temp file for storage
    with open(addressFile, 'r', newline = '') as csvFile, open("temp.clf", 'w', newline = '') as csvTemp:
        csvReader = csv.reader(csvFile, delimiter=',')
        csvWriter = csv.writer(csvTemp, delimiter=',')
        for row in csvReader:
            field = row[0]
            #changing the values of row that match with query
            #iterating all values and storing into tempfile
            if query in field.lower() or query in field.upper():
                Entrybook = WorkingRow(*row)
                Entrybook.PrintAll()
                Entrybook.ChangeValues(1)
                csvWriter.writerow(Entrybook.GetValues())
                break
            else:
                csvWriter.writerow(row)
        csvWriter.writerows(csvReader)
    #removing old file and renaming temp file to addressFile
    os.remove(addressFile)
    os.rename("temp.clf", addressFile)
    return
    
def SearchContacts(addressFile):
    tempField = []
    query = input("Search for a contact: ")
    with open(addressFile, 'r', newline = '') as csvFile:
        csvReader = csv.reader(csvFile, delimiter=',')
        #printing the first row
        row1 = next(csvReader)
        Entrybook = WorkingRow(*row1)
        Entrybook.PrintAll()
        #printing all rows that match with query
        for row in csvReader:
            for field in row:
                #moving onto next row if tempField has the sameid number :)
                if row[0] == tempField:
                    continue
                if query in (field.lower(), field.upper()):
                    Entrybook = WorkingRow(*row)
                    Entrybook.PrintAll()
                    tempField = row[0]
    return
                
def ReadBook(addressFile):
    counter = 0
    with open(addressFile, 'r') as csvFile:
        csvReader = csv.reader(csvFile, delimiter=',')
        for row in csvReader: 
                Entrybook = WorkingRow(*row)
                Entrybook.PrintAll()
                counter = (counter + 1)
                if counter == 20:
                    input("Press Enter to continue...")
                    counter = 0
    return

def WriteToFile(addressFile, writeValues):
        with open(addressFile, 'a', newline='') as csvFile:
            writer = csv.writer(csvFile, delimiter = ',')
            writer.writerow(writeValues)
        return
 
Main()