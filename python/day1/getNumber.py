def get_number():
    ''' Enter only integer number(not other charecter) '''
    ''' Number must be greater then 0 '''
    number = 0
    while number < 1:
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            print("Try again: ", end = "")
            number = 0
        else:
            if number < 1:
                print("Number must be great then 0!")
                print("Try again: ", end = "")
                number = 0
            else:
                return number

def get_three_digit_number():
    ''' Enter only integer number(not other charecter) '''
    ''' Number must be in range [100, 999] '''
    number = 0
    while number < 100 or number > 999:
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            print("Try again: ", end = "")
            number = 0
        else:
            if number < 100 or number > 999:
                print("Number must have 3 digits!")
                print("Try again: ", end = "")
                number = 0
            else:
                return number