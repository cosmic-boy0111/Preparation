# from ast import Num


# class Number : 
#     def sum(self) : 
#         return self.a + self.b

# num = Number()
# num.a = 12
# num.b = 34

# s = num.sum()

# print(s)


# from cmath import cos


# class Railway : 
#     formType = 'Railway form'

#     def printData(self) : 
#         print(f"name is {self.name}")
#         print(f"train is {self.train}")

# cosmic = Railway()
# cosmic.name = 'Gaurav'
# cosmic.train = 'MyTrain'

# cosmic.printData()



# class Employee : 
#     company = 'Google'

# Gaurav  = Employee()
# g1 = Employee()

# Employee.company = 'Gaurav'
# print(g1.company)


# class Employee : 
#     company = 'Google' 

#     def __init__(self,name,salary,subunit) :
#         print('Employee Created')
#         self.name = name
#         self.salary = salary
#         self.subunit = subunit

#     def getDetails(self) : 
#         print(f'name : {self.name} \nsalary : {self.salary} \nsubunit : {self.subunit}')

#     def getSalary(self)  : 
#         print(f'salary {self.salary}')

#     @staticmethod
#     def greet() : 
#         print('Good Morning Sir')

# cos = Employee('Gaurav',100,'YouTube')
# cos.getDetails()



# class Employee : 
#     company = 'Google'

#     def showDetails (self) : 
#         print('This is an employee')

# class Programmer(Employee) : 

#     language = 'Python'
#     company = 'YouTube'

#     def getLanguage (self) : 
#         print(f'This language is {self.language}')
    
#     def showDetails(self):
#         print('This is a programmer')

# e = Employee()
# e.showDetails()
# p = Programmer()
# p.showDetails()
# print(p.company)



# class Employee : 
#     company = 'Visa'
#     eCode = 120

# class Freelancer : 
#     company = 'Fiver'
#     level = 0

#     def upgradeLevel (self) : 
#         self.level += 1

# class Programmer ( Employee , Freelancer ) : 
#     name = "Rohit"

# p = Programmer()
# print(p.level)
# p.upgradeLevel()
# print(p.level)
# print(p.company)



