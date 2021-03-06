from flask import Flask, request


class ComplexNumber:
    def __init__(self, real = 0, imaginary = 0):
        self.real = real
        self.imaginary = imaginary

    def __str__(self):
        if self.imaginary >= 0:    
            return "({0}+{1}i)".format(self.real, self.imaginary)
        else:
            return "({0}{1}i)".format(self.real, self.imaginary)
    
    def __add__(self, other):
        realResults = self.real + other.real
        imaginaryResults = self.imaginary + other.imaginary
        return ComplexNumber(realResults,imaginaryResults)
    
    def __sub__(self,other):
        realResults = self.real - other.real
        imaginaryResults = self.imaginary - other.imaginary
        return ComplexNumber(realResults,imaginaryResults)

    def __mul__(self,other):
        realResults = (self.real * other.real) + (self.imaginary * (other.imaginary * - 1))
        imaginaryResults = (self.real * other.imaginary) + (self.imaginary * other.real)
        return ComplexNumber(realResults,imaginaryResults)
    
    def __truediv__(self,other):
        # checking for zeros and giving correct ouput when division of zeroes happens
        # (0+2i)/(0+0i) = infinity
        # (1+2i)/(0+0i) = infinity
        if (other.real == 0 and other.imaginary == 0) or (other.real == 0 and other.imaginary == 0 and self.real == 0):
            return ("Infinity")
        
        # catching division of real components when equal to 0
        # (0+4)/(0+5i) = 0.8 
        # Python will check the input first??? before perfoming divison and if it finds zeros then
        # it will throw the zero divison error
        elif (self.real == 0 and other.real == 0):
            realResults = ((self.real * other.real) + ((self.imaginary * (other.imaginary * -1))*-1)) / ((pow(other.real, 2)) + (pow(other.imaginary, 2)))
            imaginaryResults = ((self.real * (other.imaginary * -1)) + (self.imaginary * other.real)) / ((pow(other.real, 2)) + (pow(other.imaginary, 2)))
        else:
            realResults = ((self.real * other.real) + ((self.imaginary * (other.imaginary * -1))*-1)) / ((pow(other.real, 2)) + (pow(other.imaginary, 2)))
            imaginaryResults = ((self.real * (other.imaginary * -1)) + (self.imaginary * other.real)) / ((pow(other.real, 2)) + (pow(other.imaginary, 2)))
        return ComplexNumber(realResults,imaginaryResults)

    
app = Flask(__name__)
@app.route('/results')
def results(complexnum1, complexnum2):
    if request.method == 'POST':
        try:
            #getting real and imaginary parts
            number1 = int(request.form['number1'])
            number2 = int(request.form['number2'])
            number3 = int(request.form['number3'])
            number4 = int(request.form['number4'])
            #creating complex numbers
            complexnum1 = ComplexNumber(number1, number2)
            complexnum2 = ComplexNumber(number3, number4)
        except ValueError:
            sumResults = "Invalid input detected"
            subResults = "Invalid input detected"
            mulResults = "Invalid input detected"
            divResults = "Invalid input detected"
            pass
    #performing operations
    sumResults = complexnum1 + complexnum2
    subResults = complexnum1 - complexnum2
    mulResults = complexnum1 * complexnum2
    divResults = complexnum1 / complexnum2
    
    return '''
<html>
    <head>
        <title>Javier Hernandez Week 6 - Python Web app </title>
    </head>
    <body>
        <h1>Complex number basic calculator</h1>
        <p>Enter 2 complex numbers i.e. (2+9i), (10-5i)</p>
        <p>Do not include the imaginary unit</p>
        <h3>Enter your complex numbers below to perform operations: </h3>
        <form method = "post">        
        <p>Complex 1 - Real part: <input type = "text" name = "number1"/>   Imaginary part: <input type = "text" name = "number2"/></p>
        <p></p>
        <p>Complex 2 - Real part: <input type = "text" name = "number3"/>   Imaginary part: <input type = "text" name = "number4"/></p>
        <p></p>
        <p><input type = "submit" value = "submit" /></p>
        <h3>Your results for ''' +str(complexnum1)+''' and '''+str(complexnum2)+'''are:</h3>
        <p>Addition: ''' +str(sumResults)+'''</p>
        <p>Substraction: ''' +str(subResults)+'''</p>
        <p>Multiplication: ''' + str(mulResults)+'''</p>
        <p>Division: ''' +str(divResults)+'''</p>
      </form>
    </body>
</html>'''


@app.route('/', methods = ['POST', 'GET'])
@app.route('/index', methods = ['POST', 'GET'])
def index():  
    allResults = "Waiting on input"
    complexnum1 = ComplexNumber(0,0)
    complexnum2 = ComplexNumber(0,0)
    if request.method == 'POST':
        try:
            #getting real and imaginary parts
            number1 = int(request.form['number1'])
            number2 = int(request.form['number2'])
            number3 = int(request.form['number3'])
            number4 = int(request.form['number4'])
            #creating complex numbers
            complexnum1 = ComplexNumber(number1, number2)
            complexnum2 = ComplexNumber(number3, number4)
            return results(complexnum1,complexnum2)
        except ValueError:
            allResults = "Invalid input detected"
            pass
    
    return '''
<html>
    <head>
        <title>Javier Hernandez Week 6 - Python Web app </title>
    </head>
    <body>
        <h1>Complex number basic calculator</h1>
        <p>Enter 2 complex numbers i.e. (2+9i), (10-5i)</p>
        <p>Do not include the imaginary unit</p>
        <h3>Enter your complex numbers below to perform operations: </h3>
        <form method = "post">        
        <p>Complex 1 - Real part: <input type = "text" name = "number1"/>   Imaginary part: <input type = "text" name = "number2"/></p>
        <p></p>
        <p>Complex 2 - Real part: <input type = "text" name = "number3"/>   Imaginary part: <input type = "text" name = "number4"/></p>
        <p></p>
        <p><input type = "submit" value = "submit" /></p>
        <h3>'''+str(allResults)+'''</h3>
        </form>
    </body>
</html>'''
