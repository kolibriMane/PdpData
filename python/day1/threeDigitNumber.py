import getNumber

def isValid(number):
    ''' Let the number is valid: '''
    ''' if divided into 3 and digits are not repeatable '''
    c = number % 10
    a = number // 100
    b = (number - 100 * a - c) // 10
    return a != b and a != c and b != c and number % 3 == 0

def getNumberCount(number):
    ''' Get count of valid numbers '''
    count = 0
    for i in range(100, number):
        if isValid(i):
            count += 1
    return count

def main():
    print('Enter 3-digit number: ', end = "")
    number = getNumber.getThreeDigitNumber()
    print("Count of Valid numbers:", getNumberCount(number))

if __name__ == "__main__":
    main()