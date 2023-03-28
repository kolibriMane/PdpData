def get_number():
    ''' Enter only integer number(not other charecter) '''
    number = 0
    while number < 1:
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            number = 0
        else:
            return number

def check_range(number):
    ''' Check is the number in range '''
    ''' Return values: True or False '''
    return number in range(900, 1101) or number in range(1900, 2101)

def main():
    ''' Main function to check range of number '''
    print("*** Second way ***")
    ''' Get number '''
    print('Enter number: ', end = "")
    number = get_number()
    print(check_range(number))

if __name__ == "__main__":
    main()